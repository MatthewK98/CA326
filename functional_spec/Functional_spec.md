# Tables of Contents
1. Introduction
1.1 Overview
1.2 Business Context
1.3 Glossary

2. General Description
2.1 Product / System Functions	
2.2 User Characteristics and Objectives	
2.3 Operational Scenarios	
2.4 Constraints*	

3. Functional requirements
3.1 Flora Board System	
3.2 Microphone
3.3 Accelerometer
3.4 LED Matrix
3.5 Use Cases
3.6 Animation Diagrams

4. System Architecture
             System Architecture Diagram

5. High-Level Design
             Data Flow Diagram	

6. Preliminary Schedule
             Gantt Chart
7. Appendices

# 1 Introduction
## 1.1 Overview 
The following functional specification discusses our third-year project which is based on the “Clothing-based Wearable Technology “ idea. In essence, the product we will be developing is a mask with a responsive LED light strip using a flora arduino board with a microphone that will light up to emulate a mouth speaking or head movement using various animations depending on sound volume , head motion and what words are used as input.

## 1.2 Business Context
(N/A) to this project as this product will be merely used for DCU computing staff and students to test and review.

## 1.3 Glossary
* Accelerometer :- Electromechanical device to help track the movement/motion of the user head to alter animations.
* Arduino Ide :- Integrated development environment that will be used to execute programs.
* Arduino unique C/C++ language :- Specialised language that will be used in the Integrated development environment to develop the certain animations in the flora arduino board
* Bread Board :- Conductive Board to be used in the testing phase 
* Conductive thread :- Thread to sew the board and modules to the mask to allow for current to flow.
* Flora Arduino board :- Wearable microprocessor board sew to the mask , also with usb to connect to machine/pc for programming.
* Filter :- Extra layer to help prevent soakage, damage and passing bacteria.
* Wires :- Wires used to solder parts to the flora board
* Jumper wires :- Used to connect components for testing at breaborad
* Programmable LED matrix :- A matrix (grids) of LEDS that are programmable , more practical than programming individual LED
* Mask :- Physical covid mask to be used
* Microphone (sound sensor) :- Will detect frequencies input 
* Non Talking animations :- When the user doesn’t speak Non talking animation will be displayed.
* Talking animations :- When the user does speak talking animations will be displayed.
* lithium battery :- Battery to power flora arduino board
* Soldering Kit :- Equipment that will be used to solder parts to the flora arduino board and other specific modules
* Solder :- Metal alloy used to do the soldering


# General Description
## 2.1 Product/System functions

The general functionality of the product will be built on using a Flora Arduino board with incorporating programmable LED lights matrix into masks that will mimic a mouth moving whenever the wearer speaks or has head movement (non talking). The LED lights will mimic the mouth's movement with various animations, that are programmed in the arduino ide.The Arduino programming language runs machine code and it will function based on the Arduino ide using an unique Arduino C/C++ programming language. The main system of the product will be tested using a breadboard , once it has passed the testing phase the flora arduino board will incorporate into the mask using conductive thread and soldered wires. The parts will be sewed using a sewing machine and therefore when the user attaches the mask to his/her face it will be well stable. To prevent damage and soakage to the parts a filter will be added as an extra layer.
.The Flora Arduino Board will be programmed using arduino IDE specific language that incorporates a mixture of C/C++.Within the mask’s layers, it will have an Arduino Kit, accelerometer, microphone module, programmable LED strips, and a filter. The mask is a pouch-like design where the electronics will reside so that it can be easily removed and replaced and so that mask can be re-washed and re-used. The lights will be sewed using conductive thread as it's a more practical than ordinary thread , as electrical current will be applied via the arduino board.


## 2.2 User Characteristics and Objectives
The System/Product we are creating does not require any technical software knowledge or skills in order to use the product. The user simply uses the switch to turn the flora Arduino board on and depending on movement or what the user says will output a certain animation.

## 2.3 Operational Scenarios
For the best performance from this product have two users preferably in a quite dry area (empty computing labs room). User A will wear the electronic mask while engaging in conversation with User B , User B will be able to see the different animations from the mask as User A speaks or has head movement.

## 2.4 Constraints
Planning and designing the product within a group remotely does bring challenges as in communication and it’s more difficult doing so rather than doing a group project in person. Arduino IDE has its own version of C/C++ programming language , this will be a completely new concept as it's not a programming language that has been taught in the course. The project mainly uses hardware and parts will need to be sewed to the fabric. Neither group members have experience with sewing or using these specific hardware parts , this will clearly bring more challenges and a new learning curve.

# 3. Functional Requirements
## 3.1 Flora Board System
**Description** - Flora Arduino Board
The flora Arduino board is powered by a lithium battery. The LED matrix will be connected to the board by a conductive thread, the microphone module and the accelerometer will be soldered to the Arduino board by wires. The LED matrix and will be sewn to the mask by a conductive thread. The Flora Arduino board will be programmed using C/C++ (Arduino Ide has its own language that uses a mixture of C/C++) via Arduino IDE version 1.6x IDE((integrated development environment)) as it is recommended to use by the manufacturers of the Adafruit Flora Board to write code that will play the sequence of how the LED will light up depending on the accelerometer and the microphone.

**Criticality**
The Flora board system is very essential as it is the backbone of the product. Without the Flora board connecting all of the components and providing the program to tell each component what to do or this product will not work

**Technical Issues**
Issues that may arise would be buying parts arriving could be faulty due to many reasons such as complications with delivery.

**Dependencies**
Dependencies with other parts as all the other modules depend on the flora board to function properly.

## 3.2 Microphone
**Description** - Microphone
The microphone module will recognize the decibel value of the person speaking and the LED matrix will play an animation while the person speaks. The animation will differ depending on the pronunciation of the sound, there will be different types of animation.  For example, a word with “ssh” will play the first animation which represents a quiet sound by using a small circular shape. If the user is speaking at a normal tone example the word “how”  would play the second animation in a regular circular shape. If a continuous sequence of letters or high-level sound is spoken into the microphone the third animation will play a large circular shape. As well as that if the person is not speaking a stationary animation of a mouth closed is being played. 

**Criticality**
The microphone is essential as it takes the inputs of a voice’s decibel value which is then used to determine which type of animation is going to be played either animation 0,1 or 2 as shown in diagrams below.

**Technical Issues**
For all the components the issues that can arise will all be the probability of the part being ordered will be faulty.

**Dependencies**
The mic will be dependent on the Arduino board as it will be powered by it. While the LED Matrix is dependent on the Microphone to differentiate which type of light sequence is going to be played depending on the decibel value.

## 3.3 Accelerometer
**Description** - Accelerometer
The accelerometer will also be connected to the Arduino board and check for forces such as movements like tilting your head downwards or upwards. The axis x,y and z will change depending on the angle it is at. If you have the accelerometer position flat with z-axis pointing up it will have a value of 1 and the rest will have 0 if it is pointing down it will have a value of -1. If you tilt your head upwards an animation of the LED will take the form of a smile while you tilt your head downwards it will take the form of a frown. 

**Criticality**
The accelerometer is essential to simulate emotions when using this product. 

**Dependencies**
The LED Matrix will be dependent on the Accelerometer as it will display the type of animation either smiling or frowning depending on the angle the accelerometer is facing.

## 3.4 LED Matrix
**Description** - LED Matrix
The LED Matrix emits light whenever current passes through it. The LED will light up in different sequences to display different animations such as the diagrams shown in the page below.

**Criticality**
The LED Matrix will be critical as it is what is going to be viewed by other people whenever the wearer of the product either speaks or tilts their head up or down.

**Technical Issues**
Issues that may arise would be human error causing the LED matrix to burn out if too much power is passed through it.

**Dependencies**
The LED Matrix is dependent on the accelerometer and the microphone module as it will display the animation 0,1,2  depending on the input of the mic and displays animations 3 and 4 depending on the orientation of the accelerometer. It will also be dependent on the Flora Arduino Board

## 3.5 Use Cases
### Use Case 1
![scrabbleClassDIagram](/uploads/145695995f4c023cf4c8fd282e3b7201/scrabbleClassDIagram.png)
**Brief Desctiption:**

As the user speaks it will detect the frequency of the user and turn the specific frequency into an image(i.e an animation) Any sounds containing A,I,E will match animation 1 in the diagrams below, O will match animation 2 etc. It will then display that specifc animation as the user speaks on the LED Matrix.
### Use Case 2
![scrabbleClassDIagram__1_](/uploads/a956c0c75bb26e95e51ecabb057ebfb2/scrabbleClassDIagram__1_.png)
**Brief Description:**

As the user tilt their head upwards or downwards the accelerometer checks the orientation if X value is greater than 0 then it will generate the animation for smiling if its less than it will generate a frowning animation.

### Use Case 3
![non-speaking](/uploads/5a3742c78b23e3ed15bb56d6a2d348ea/non-speaking.jpeg)
**Brief Description:**
The user can either input sound frequency or not , the microphone is basically the sound and will detect level the volume. If sound frequency of zero is detected they appropriate patted will  be played

### Use Case 4
![use_case4](/uploads/3d8b9c1986362868c0c3b02570862242/use_case4.jpeg)
**Brief Description:**

When a user speaks, different pronunciations and syllables will be used depending on the word(s) that is said. This use case shows the process of the Arduino IDE when taking in sound input and a loop will be ran as long as the user speaks for, in other words "processing data on the go" rather than storing in memory as it with too much too data to process


## 3.9 Animation Diagrams
![animation1](/uploads/14f97e579d997c54eb49a05d7a96a67f/animation1.png)

![animation2](/uploads/eebb0a163e0f7ec2b577f256869fc5a5/animation2.png)

![animation3](/uploads/9c4eaf0b49a5b7745020daf2171e4594/animation3.png)

![8](/uploads/32224334e395b12f3cf56ba8f14c36a0/8.jpg)

![7](/uploads/cfa1d07d02380ae37fcc2f21b5db6408/7.jpg)

![6](/uploads/d572842501d145c9eb787e9048bdf8bb/6.jpg)
# 4 System Architecture
![systemarchit](/uploads/6223cc5f93ea9d4f3f05d0dcf5f67cd9/systemarchit.png)
# 5 High Level Design
## Data Flow Diagram
![dataflow](/uploads/10c724d7f477a9853595aa643cef6f66/dataflow.png)

# 6 Preliminary Schedule
## Gantt Chart
!![ganntchart](/uploads/6c7ecfe09c3791aaa9712d6778e9ad8b/ganntchart.png)

# 7 Appendices
![mouthshapes](/uploads/8782bbb1370def62062a11a4a45d6d38/mouthshapes.png)

The image above showcases the mouth shape as a person speaks. We match the outline of the mouths as a template for different animation that the LED Matrix will display.


