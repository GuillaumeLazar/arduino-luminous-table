#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

int sendDataValue = 0;

void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);         // start serial for output
    // initialize i2c as slave
    Wire.begin(SLAVE_ADDRESS);

    // define callbacks for i2c communication
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);

    Serial.println("Ready!");
}

void loop() {
    delay(5);
}

// callback for received data
void receiveData(int byteCount){

    while(Wire.available()) {
        number = Wire.read();
        Serial.print("Receive data from RPI: 0x");
        Serial.println(number, HEX);

        if (number == 1){

            if (state == 0){
                digitalWrite(13, HIGH); // set the LED on
                state = 1;
            }
            else{
                digitalWrite(13, LOW); // set the LED off
                state = 0;
            }
         }
     }
     
     Serial.println();
}

// callback for sending data
void sendData(){
    Serial.print("Send data from Arduino to RPI: ");
    Serial.println(sendDataValue);
    Wire.write(sendDataValue);
    sendDataValue ++;
}


