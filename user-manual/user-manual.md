# 0. Tables of Contents
### 1. Introduction
1.1 Glossary
### Components
### 2.1 Components
2.1 Wiring  
2.2 How to turn on device  
2.3 Normal Mode  
2.4 Pattern Matching Mode

# 1. Introduction
1.1 Glossary
* **Arduino Circuit Playground Classic** -This is the component responsible for processing code and communicating with other components.
* **DIN** - DIN refers to Data Input. It allows input such as code or signals to be received from another component such as an Arduino board.
* **WS218** - This component is a light emitting diode that lights up when current is running through it. This specific LED is 64 x 64 in size and can change in colours.

# 2. Components
## 2.1 Wiring
The Arduino Circuit Playground Classic is easy to use once it is opened from its packaging locate the VBATT, #12 and GND. On the backside of the WS218 LED Panel locate pins 5V, DIN and GND. Using a soldering machine and few wires connect the 5V -> VBATT, DIN -> #12 and GND -> GND as shown in the image below.
![ports_needed](/uploads/a1adf1ca569af5df7063f20a56c4d623/ports_needed.jpg)
![20210310_232038](/uploads/3fa3561d204b146a2c1b100849ed17f1/20210310_232038.jpg)
![20210310_232217](/uploads/491cb6c4e98e61ff648fb252e8a31640/20210310_232217.jpg)

## 2.2 How to turn on the device
To turn on the device you can use an external power supply such as a lithium battery or a Micro-USB cable. The drawbacks of having the USB cable to power the board is that it will be sticking out of the mask too much. A battery can be concealed within the mask and is more mobile. Connecting either one of these power supplies the board will flash green indicating that it is powered.
![micro_battery](/uploads/c2d8dc408718543074b90a44023769c7/micro_battery.jpg)
## 2.3 Normal Mode
Once the code is fully complied with and uploaded into the board the mask is automatically in Normal mode. Normal mode has LED colour of green .Speaking will display animations from Stationary to mouth movement. Tilting your head upwards will display a smiling animation and tilting your head downwards will display a frowning animation.
![normal_mode](/uploads/5686ad1dab13ab62c71ff34c7fc150d9/normal_mode.jpg)

## 2.4 Pattern Matching Mode
Pressing the left button in the Arduino Circuit Playground will create a buzzing sound once you hear this sound immediately press the right button (while sound is on). You entered the pattern matching mode. Once in this mode, the colours of the animations are blue. Speaking words with 1 syllable will display an animation with 1 movement. Speaking words with 2 syllables will display an animation with 2 movement

**Note : if right button is not pressed when buzzing sound is on , you will be brought back to normal mode (green animations)**
**Note: in this mode tilting head upwards or downwards will not display a frowning or smiling animation**

![button](/uploads/6838d646ce2d239585f6e51820896d5d/button.jpg)
![pattern_mode](/uploads/51fa49b77e9b7acd8c3b4398c9af82da/pattern_mode.jpg)