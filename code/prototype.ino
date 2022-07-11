#include "FastLED.h"
#include <Adafruit_CircuitPlayground.h>

#define NUM_LEDS 64
#define DATA_PIN 12
#define BRIGHTNESS 64

const int speaker = 5; 
const int leftButton = 4;
const int rightButton = 19;


CRGB red = CRGB(0,255,0); //red is for frown and smile animation
CRGB green = CRGB(230,0,0); //green is for normal speaking and continuous sounds
CRGB blue = CRGB(00,0,255); //blue is for pattern matching

boolean isStationary = false;
boolean isFrowning = false;

int timeSpeaking;
int dbCounter;


//Declare global variables
float X, Y, Z;


//Set min and max range for all sensors 
float Xmin = 0.36,Ymin = 0.07,Zmin = 0.47;
float Xmax = 9.97,Ymax = 9.70,Zmax = 9.83;

CRGB leds[NUM_LEDS]; //Setting led pins 

void setup() { 
    CircuitPlayground.begin(); // initialize the CircuitPlayground library
    Serial.begin(9600); // Serial monitor at 9600 baud rate
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering
    FastLED.setBrightness(BRIGHTNESS);
}

//This method will give a more accurate input for the accelerometer sensors 
float calibrateInputs(float value, float minimum, float maximum){
  float range = maximum - minimum;
  return (value - minimum) / range;
}

//The createNoise function creates a tone by setting the Higher 
void createNoise (unsigned char speaker, int hertzFreq, long milliSec) {
  int x;   
  long delayAmount = (long)(1000000/hertzFreq);
  long loopTime = (long)((milliSec*1000)/(delayAmount*2));
  for (x=0; x<loopTime; x++) {        
     digitalWrite(speaker,HIGH);  
     delayMicroseconds(delayAmount);  
     digitalWrite(speaker,LOW); 
     delayMicroseconds(delayAmount);
  } 
}

//Our program consists of 12 various animations 

//Animation #0 => When user is not speaking or tilting head upwards or downwards (basically in a neutral position)
void Stationary()
{
  FastLED.clear();  //Clear the entire led matrix (turn off led lights)
  int start = 23; //Start at led 23 and loop 16 times 
  for (int i=0; i < 16; i++)
  {
    start = start + 1;
    leds[start] = green;
  }
}

//Animation #1 => When user is not speaking or tilting head upwards or downwards (in pattern matching mode)
void Stationary_pm()
{
  FastLED.clear();  //Clear the entire led matrix (turn off led lights)
  int start = 23; //Start at led 23 and loop 16 times 
  for (int i=0; i < 16; i++)
  {
    start = start + 1;
    leds[start] = blue;
  }
}

//Animation #2 => When user is speaking at normal volume
void Normal()
{
    FastLED.clear();
    #define SIZE 18 //Declare size of array
    int LED_pins[SIZE] = {16,17,18,19,20,21,22,23,24,31,32,39,41,42,43,44,45,46};
    for (int i=0; i < SIZE; i++){
      int pins = LED_pins[i];
      leds[pins] = green;
    }
}

//Animation #3 => When user is speaking at normal volume (in pattern matching mode)
void Normal_pm()
{
    FastLED.clear();
    #define SIZE 18 //Declare size of array
    int LED_pins[SIZE] = {16,17,18,19,20,21,22,23,24,31,32,39,41,42,43,44,45,46};
    for (int i=0; i < SIZE; i++){
      int pins = LED_pins[i];
      leds[pins] = blue;
    }
}

//Animation #4 => Animation used for various volume inputs 
void tinyCircle()
{
  FastLED.clear();
  #define SIZE 8  //Declare size of array
  int LED_pins[SIZE] = {19,20,26,29,34,37,43,44};
  for (int i=0; i < SIZE; i++){
    int pins = LED_pins[i];
    leds[pins] = green;
  }
}

//Animation #5 => Animation used for various volume inputs (in pattern matching mode)
void tinyCircle_pm()
{
  FastLED.clear();
  #define SIZE 8  //Declare size of array
  int LED_pins[SIZE] = {19,20,26,29,34,37,43,44};
  for (int i=0; i < SIZE; i++){
    int pins = LED_pins[i];
    leds[pins] = blue;
  }
}

//Animation #6 => Animation used for various volume inputs 
void Oval()
{
  FastLED.clear();
  #define SIZE 16  //Declare size of array
  int LED_pins[SIZE] = {24,17,18,19,20,21,22,31,32,39,41,42,43,44,45,46};
  for (int i=0; i < SIZE; i++){
    int pins = LED_pins[i];
    leds[pins] = blue;
  }
}



//Animation #7 => For continuous sounds
void Circle()
{
  FastLED.clear();
  #define SIZE 12 //Declare size of array
  int LED_pins[SIZE] = {11,12,18,21,25,30,33,38,42,45,51,52};
  for (int i=0; i < SIZE; i++){
    int pins = LED_pins[i];
    leds[pins] = green;
  }
}

//Animation #8 => For pattern matching 
void Circle_pm()
{
  FastLED.clear();
  #define SIZE 12 //Declare size of array
  int LED_pins[SIZE] = {11,12,18,21,25,30,33,38,42,45,51,52};
  for (int i=0; i < SIZE; i++){
    int pins = LED_pins[i];
    leds[pins] = blue;
  }
}


//Animation #9 => When user tilts head upwards
void Smile()
{
    FastLED.clear();
    #define SIZE 9 //Declare size of array
    int LED_pins[SIZE] = {24,32,41,50,51,52,31,39,46};
    for (int i=0; i < SIZE; i++){
      int pins = LED_pins[i];
      leds[pins] = red;
    }
}


//Animation #10 => When user tilts head downwards
void Frown()
{
    FastLED.clear();
    #define SIZE 10 //Declare size of array
    int LED_pins[SIZE] = {26,27,28,29,33,38,40,47,48,55};
    for (int i=0; i < SIZE; i++){
      int pins = LED_pins[i];
      leds[pins] = red;
    }
}

//Animation #11 => When user is speaking at high volume
void Shouting(){
    FastLED.clear();
    #define SIZE 20 //Declare size of array
    int LED_pins[SIZE] = {8,9,10,11,12,13,14,15,16,23,24,31,32,39,41,46,50,51,52,53};
    for (int i=0; i < SIZE ; i++){
      int pins = LED_pins[i];
      leds[pins] = green;
    }
}

void loop() { 
    //db is short for decibel 
    int db = CircuitPlayground.mic.soundPressureLevel(10);
    pinMode(speaker, OUTPUT);     // We will write out to the speaker
    pinMode(leftButton, INPUT);   // We'll read in from the buttons
    pinMode(rightButton,INPUT);
    int counter = 0;
    int timer = 0;
    int counter2 = 0;

    X = calibrateInputs(CircuitPlayground.motionX(),Xmin,Xmax);
    Y = calibrateInputs(CircuitPlayground.motionY(),Ymin,Ymax);
    Z = calibrateInputs(CircuitPlayground.motionZ(),Zmin,Zmax);
    
    //print this to test volume input
    //Serial.println(db);

    if (CircuitPlayground.leftButton() == 1) // If you click the left button 
    {
    unsigned long currentTime = millis();
    unsigned long projectedTime = currentTime + 2000;
    
    
    while (millis() < projectedTime)
    {
      createNoise(speaker,440,100); 
      if (CircuitPlayground.rightButton())
      {
        createNoise(speaker,0,0);
//        Serial.println(counter);
        counter = counter + 1; 
      }      
    }


    int i = 0;
    int fourty = 0;
    int fifty = 0;
    int sixty = 0;
    int seventy_plus = 0;
    int eighty = 0;


      //Start of pattern matching
     while (counter >= 1)
     {
         //For testing
//      Serial.println("You pressed it !!!!!!!");

      FastLED.clear();
      Stationary_pm();
      FastLED.show();

//      Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      int db4 = CircuitPlayground.mic.soundPressureLevel(10);
      Serial.println(db4);
      //This condition was added as the user must speak to activate the pattern matching also. Otherwise the patten matching would never reset correctly.
      if (db4 >= 55)
      {
          
        unsigned long patternMatchingTime = millis();
        unsigned long calculateTime = patternMatchingTime + 500;
        while (millis() < calculateTime)
        {
          int db3 = CircuitPlayground.mic.soundPressureLevel(10); //tmp variable
          Serial.println("YOUR IN MILLIS");
          Serial.println(db3);
  
           if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton())
           {
            counter = 0;
            counter2 = 1;
            delay(1000);
            break;
           }
  
          if (db3 >= 40 && db3 <= 49)
          {
            fourty = fourty + 1;
          }
      
          
          if (db3 >= 50 && db3 <= 59)
          {
            fifty = fifty+ 1;
          }
      
          if (db3 >= 60 && db3 <= 69)
          {
            sixty = sixty + 1;
          }
      
          if (db3 >= 70 && db3 <= 79)
          {
            seventy_plus = seventy_plus + 1;
          }

          if (db3 > 80){
            eighty = eighty + 1;
          }
      }
      }
      
      //Line 313 to 322 is used mainly to program and test the pattern matching system
      Serial.print("fourty ");
      Serial.println(fourty);
      Serial.print("fifty ");
      Serial.println(fifty);
      Serial.print("sixty ");
      Serial.println(sixty);
      Serial.print("seventy_plus ");
      Serial.println(seventy_plus);
      Serial.print("Eighty");
      Serial.println(eighty);
    //Conditions needed for a 1 Syllable Word
    if (fourty >= 10 && fourty < 25 && fifty >= 2 && sixty >= 2 && seventy_plus >= 2 && seventy_plus <= 16 && eighty >= 4)
     {
      Serial.println("1 SYLLABLE");
      FastLED.clear();
      Oval();
      FastLED.show();
      delay(400);
     }
  //Conditions needed for a 2 Syllable Word
   if (fourty >= 1 &&fourty <= 15 && sixty >= 3 && seventy_plus >= 2 && eighty >= 2)
     {
      Serial.println("2 Syllable");
       FastLED.clear();
       Normal_pm();
       FastLED.show();
       delay(400);
       FastLED.clear();
       tinyCircle_pm();
       FastLED.show();
       delay(400);
     }
    //Conditions needed for a 3 Syllable Word
    if (sixty + seventy_plus + eighty > 30)
     {
      Serial.println("3 Syllable");
      FastLED.clear();
      tinyCircle_pm();
      FastLED.show();
      delay(400);
      FastLED.clear();
      Circle_pm();
      FastLED.show();
      delay(400);
     }

      fourty = 0;
      fifty = 0;
      sixty = 0;
      seventy_plus = 0;
      eighty = 0;

      
      if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton())
      {
        counter = 0;
        counter2 = 1;
        delay(1000);
        break;
      }
     }

     if (counter == 0)
     {
      counter = 0;
      counter2 = 1;
      delay(1000);
     }
    
  }

    if (db > 57 && isStationary == false && X < 0.20)
    {
      FastLED.clear();
      Normal();
      FastLED.show();
      timeSpeaking = timeSpeaking + 1;
      
      //For testing purposes 
      //Serial.println(timeSpeaking);
      if (timeSpeaking == 20)
      {
        
      FastLED.clear();
      tinyCircle();
      FastLED.show();
      
      while (true)
      {
        int db2 = CircuitPlayground.mic.soundPressureLevel(10); //tmp variable 
        FastLED.clear();
        tinyCircle();
        FastLED.show();


        if (db2 >= 57)
        {
          FastLED.clear();
          tinyCircle();
          FastLED.show();
          timeSpeaking  = timeSpeaking + 1;

          Serial.println(timeSpeaking );

          if (db2 >= 57 && timeSpeaking >= 30)
          {
          FastLED.clear();
          Circle();
          FastLED.show();

          }
          
        }
        else
        {
          break;
        }

      }

      }
    }


    if (db <= 55)
    {
      Serial.println("Testing");
      FastLED.show();
      FastLED.clear();
      isStationary = true;
      Stationary();
      timeSpeaking = 0;
    }

    // replaced Serial.println(CircuitPlayground.motionX()); with Serial.println(X);
    // As CircuitPlayground.motionX() is used when calling the calibrateInputs method 
//    Serial.println(X);

    // X replaces CircuitPlayground.motionX() again
    Serial.print("Y: ");
    Serial.println(Y);
    Serial.print("Z: ");
    Serial.println(Z);

    //Detects the tilt of the head upwards and displays smile animation
    if (Z > 0.30 && Y < -0.10 && isStationary == true)
    {
      FastLED.clear();
      Smile();
      FastLED.show();
      isFrowning = true;
    }
    //Detects the tilts of the head downwards and displays frown animation
    if (Z < -0.20 && Y > -0.45 && isStationary == true)
    {
      FastLED.clear();
      Frown();
      FastLED.show();
      isFrowning = true;
    }
    isStationary = false;

}