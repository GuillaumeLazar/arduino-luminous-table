arduino-luminous-table
======================
Create a low-cost luminous table with a lot of RGB leds and an Arduino!


![alt tag](https://github.com/neuronalmotion/arduino-luminous-table/raw/master/img/20131202_143621.jpg)


### Description
I would like to customize my IKEA coffee table with RGB leds. I already saw many kind of projects/videos like this but I want share my modest work. I'm currently using 200 RGB leds (resolution: 20 x 10). I also added two buttons and an potentiometer to control the display mode and the brightness. All this stuff is used with an Arduino. My current aim is to add an interactive system (infrared light based ?) to control LEDs by touching the table with the hand.


### Shopping list
* Arduino (I'm using an Arduino Uno R3, but it should work with any kind of Arduino I think...) (~ $30.00)
* [4x] 50 RGB led string: "WS2811 DC5V full color 50pcs a string led pixel module" (4 x $13.00 = $52.00)
* Led power supply: "5V 12A 60W Switching Power Supply 120 / 240V AC" (~ $8.00)
* PMMA sheet 90 x 55 cm (Poly methyl methacrylate: is a transparent thermoplastic) (~ $50.00)
* Ikea table 'LACK model': 90 x 55 cm (~$35.00)
* Linear potentiometer 10kΩ (~ $0.90)
* [2x] Press button 28.5mm (~ $0.50)
* Some screws, batten woods, cardboard

### Hardware

#####Arduino
Arduino is a open-source single-board microcontroller. You can start to use it immediately. All you need is an USB cable, a computer with the software Arduino IDE and an Arduino. The source code present on this repository is for the microcontroller of an Arduino board.

#####RGB led string
I need what it's called 'individually addressable RGB LED'. I don't want that all leds bright the same colors. What a pain if I should link all my 200 leds on my Arduino! And it's required too many outputs on the Arduino Uno... One way is to use WS2811 led modules. All modules ared composed by a RGB led and a WS2811 control chip. All control chips are linked together by 3 wires (V+, GND and DATA). And the best part... because WS2811 use a serial protocol, you only need 1 wire (DATA) to control the individual RGB value of each led of your string! The V+ (in my case +5V) is provided by an external power supply. The GND is the ground of the Arduino and the external power supply. You can find this led string already linked by 10, 25, 50 or even 100! You can cut the led string between 2 modules, you can link many led string together.

#####Led power supply
Although the Arduino board is capable power several leds, when you aim to bright 200 RGB leds. You should definitively use an external power supply.

TODO

#####Ikea table 'LACK model'
TODO

### Software

##### Arduino IDE
I'm using Arduino IDE v1.0.5. You can download it here : http://arduino.cc/en/Main/Software

##### Library : FastSPI_LED2
FastSPI_LED2 is the LOW LEVEL library that help you to communicate with yours LED. The work of this library is just amazing! I'm using the FastSPI_LED2 "Release Candidate 5" that I think can be always found at http://code.google.com/p/fastspi/downloads/list. But I recently discovered that the project is now on GitHub too :) https://github.com/FastLED/FastLED. I will try, as soon as possible, to integrate and test the "Final version" from GitHub.

Basically, you just need to extract the folder "FastSPI_LED2" inside the "libraries" folder of ArduinoIDE.


### Howto
TODO
