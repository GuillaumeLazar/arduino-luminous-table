arduino-luminous-table
======================
Create a low-cost luminous table with a lot of RGB leds and an Arduino!


![alt tag](https://github.com/neuronalmotion/arduino-luminous-table/raw/master/img/20131202_143621.jpg)


### Description
I would like to customize my IKEA coffee table with RGB leds. I already saw many kind of projects/videos like this but I want share my modest work. I'm currently using 200 RGB leds (resolution: 20 x 10). I also added two buttons and an potentiometer to control the display mode and the brightness. All this stuff is used with an Arduino. My current aim is to add an interactive system (infrared light based ?) to control LEDs by touching the table with the hand.


### Shopping list
* [4x] 50 RGB led string: "WS2811 DC5V full color 50pcs a string ws2801 led pixel module" (4 x $13.00 = $52.00)
* Led power supply: "5V 12A 60W Switching Power Supply 120 / 240V AC" (~ $8.00)
* Arduino (I'm using an Arduino Uno R3, but it should work with any kind of Arduino I think...) (~ $20.00)
* PMMA sheet 90 x 55 cm (Poly methyl methacrylate: is a transparent thermoplastic) (~ $50.00)
* Ikea table 'LACK model': 90 x 55 cm (~$35.00)
* Linear potentiometer 10kΩ (~ $0.90)
* [2x] Press button 28.5mm (~ $0.50)
* Some screws, batten woods, cardboard

### Hardware
#####RGB led string
I need what it's called 'individually addressable RGB LED'. I don't want that all leds bright the same colors. What a pain if I should link all my 200 leds on my Arduino! And it's required too many outputs on the Arduino Uno... One way is to use WS2811 led modules. All modules ared composed by a RGB led and a WS2811 control chip. All control chips are linked together by 3 wires (V+, GND and DATA). And the best part... because WS2811 use a serial protocol, you only need 1 wire (DATA) to control the individual RGB value of each led of your string! The V+ (in my case +5V) is provided by an external power supply. The GND is the ground of the Arduino and the external power supply. You can find this led string already linked by 10, 25, 50 or even 100! You can cut the led string between 2 modules, you can link many led string together.


### Software
TODO


### Howto
TODO
