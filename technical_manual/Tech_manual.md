# 0. Tables of Contents
### 1. Introduction
1.1 Glossary  
1,2 Overview
### 2. System Architecture
2.1 Figure 1
### 3. High-Level Design
3.1 Microphone Data Flow Diagram  
3.2 Accelerometer Data Flow Diagram
### 4. Problems and Resolution
4.1 The cable  
4.2 Problems with the PINS  
4.3 Trouble with the accelerometer  
4.4 Multitasking issue with void loop() function  
4.5 Activating button function issue  
4.6 Arduino ide stuck uploading  
### 5. Installation Guide
5.1 Software Required  
5.2 Hardware Required  
5.3 Set Up  
5.4 Arduino Software IDE Installation Guide.  
### 6.1 Unit Testing
6.1 Unit Testing  
6.2 Manual Testing  


# 1. Introduction
## 1.1 Glossary
* **Arduino Circuit Playground Classic** -This is the component responsible for processing code and communicating with other components.
* **DIN** - DIN refers to Data Input. It allows input such as code or signals to be received from another component such as an Arduino board.
* **WS218** - This component is a light emitting diode that lights up when current is running through it. This specific LED is 64 x 64 in size and can change in colours.
* **Accelerometer** - A sensor that measures a force thats acting on it to determine the objects position.
*   **Arduino IDE** - Used to write and upload code into compatible Arduino Boards. You are able to download specific libraries for the specific board.
## 1.2 Overview
The product developed is a responsive LED Mask. It incorporates an Arduino Circuit Playground Classic and WS218 64 LED Panel.
The Arduino board has built-in sensors such as the accelerometer and the microphone that is essential for this product. The accelerometer measures the tilt, angular velocity and orientation which determines if the user is facing upwards or downwards to display a frown or smile on the LED. The microphone measures the sound pressure whenever the user speaks.

# 2.System Architecture
#### 2.1 Figure 1

![system_architecture](/uploads/c7c938dfc64dc1ace1eaa31f51acbb9e/system_architecture.png)

The System Architecture has two components. The Arduino Circuit Playground Classic and the WS218 64 LED Panel. The panel is connected and powered by the microcontroller and the inputs from the microphone and accelerometer will determine which animations are to be played in the LED.

# 3. High-Level Design
### 3.1 Figure 2 (Microphone) Data Flow Diagram
The image that can be seen below is a data flow diagram when the user speaks into the microphone. As the user speaks the microphone process the sound and turns it into a decibel value. Within the Arduino board it counts up the different values of the decibels within a certain time frame. It also checks if its met certain conditions and if it has will display the corresponding animation.

![data_flow_microphone](/uploads/300b721cc273e76d2f93748015d69458/data_flow_microphone.png)

### 3.2 Figure 2 (Accelerometer) Data Flow Diagram
Below is another data flow diagram for the accelerometer. It starts when the user changes the position of where the Arduino board is situated in which is within the mask and near the mouth. The accelerometer checks the orientation in X,Y,Z values. The value that we are interested in is the X value and is processed within the arduino board also checking set conditions and displaying the animations needed for that conditon.
![data_flow_accel](/uploads/008e163d8a446c35d000d4ae1a44f33a/data_flow_accel.png)

# 4. Problems and Resolution
## 4.1 The cable
**Problem:** Initially when we plugged our Arduino Board into our laptop the ports were not being detected and so we could not program any code into the board. This delayed as we thought that we bought faulty parts.

**Resolution:** We researched the problems in Arduino forums and found out that the problem we were having was with the cable we are using. It was a power cable and instead, we needed a data transfer cable.

## 4.2 Problems with the PINS

**Problem:** We had trouble understanding which Pins we needed to use to connect the LED Matrix to the microcontroller.

**Resolution:** Examples provided by the LED Matrix's library provided us with the pins we needed and we researched using guides and forums to find out what each pin does.

## 4.3 Trouble with the accelerometer

**Problem:** The accelerometer was stopping the LED Matrix from lighting up whenever you initialize the library needed for the accelerometer as it had conflicting SPI Pins.

**Resolution:** We researched ways of picking the code within the library that we needed and change the SPI dependency so that it won’t be conflicting with the Accelerometer. It did not work so we decided to buy a different led matrix which is the WS218 panel and this solved the problem.

## 4.4 Multitasking issue with void loop() function
**Problem:** Our project is based on doing multiple factors such as showing animations for head movement , sound volume and specific phrases .In Arduino there is only loop funcion "void loop()" you can do multiple things , although it must done sequentially. Meaning following a order , for the user to activate specific animations they must meet a condition.Our issue was with the user sound volume and pattern matching , as both these factors use the built in microphone and both would be operating on the same conditions. 

**Resolution:** We resolved this by creating a new condition for the pattern matching, which was allowing the user to press the left circuit button , then the right circuit button once the speaker started playing and this activated the pattern matching mode.

## 4.5 Activating button function issue
**Problem:** Orignally we wanted the user to press any button to activate the pattern matching mode and then press any button to leave. Once nce the button was pressed you enter the pattern matching mode , although it was quite difficult to leave as pressing the button was too fast to meet the condition to break it and exit the pattern matching mode.

**Resolution:** Creating extra variables , so once the button was pressed it will be stored in a variable and will meet a condition to break it. So once the left button is pressed it will alert the user with a sound from the speaker which means the must press the right button before the sound ends to activate the pattern matching mode. The exit the pattern matching mode the user can press left or right button.

## 4.6 Arduino ide stuck uploading
**Problem:** Occasionally the Arduino ide would be stuck on uploading after pressing the upload button due to various software reasons.

**Resolution:** Open Arduino ide ->File -> preferences -> show verbose output during compilation and click both boxes. This would show any error in communication between the port and ide , if this would not work then pressing reset when uploading could resolve also.



# 5. Installation Guide
## 5.1 Software Required
Arduino IDE 1.8.13
## 5.2 Hardware Required
* Arduino Circuit Playground Classic
* WS218 64 LED Panel
* Laptop
* Lithium Battery (Power Supply)
* Data Transfer Cable
* Jumper wires
* 
## 5.3 Set Up
### Steps to assemble the components:
1. Take the parts out of their packaging.
2. Connect the male to male wires from the Arduino Board to the LED Matrix, The Pins must connect to DIN -> #12, GRND -> GRND, 5V -> VBATT.
3. Connect Arduino board to the laptop using a micro-USB data transfer cable and upload code.
4. Once uploaded take the data transfer out and insert the lithium battery into the JST Battery Input.
5. Place all components in the mask.

## 5.4 Arduino Software IDE Installation Guide.
### Steps:
1. Install the Arduino IDE from the website (https://www.arduino.cc/en/software).
2. Go to the link provided https://gitlab.computing.dcu.ie/ocionnm3/2021-ca326-mkenny-clothing-basedwearabletechnology/blob/master/code/prototype.ino and copy the code.
3. Open the Arduino IDE and click new sketch.
4. Paste the code into the sketch.
5. Save and name the sketch to whatever you like.
6. Click compile and wait till fully compiled.
7. Click Upload.

# 6 Testing
## 6.1 Unit Testing
**ArduinoUnit:**  Using a library called ArduinoUnit. We created tests for different situations that the microphone is going to be in such as when someone is speaking, room volume, loud-speaking volume and having asserts to check the integer that is correlated to the different situations for example room volume would have an AssertLess of 57 decibels


## 6.2 Manual Testing
**Looking at values:** For the course of this project each of the components was rigorously tested with the help of the serial monitor. Manually testing the accelerometer involved seeing real-time values in the accelerometer and manoeuvering the board in the position that it is going to be at and taking notes of the values. Testing the microphone and coming up with a system to pattern match also involved looking at the serial monitor and seeing real-time values and figuring out if there’s a trend between the values in decibels that we see when speaking 1 syllable words, 2 syllable words and 3 syllable words. 



