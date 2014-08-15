#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int data = 0;
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
  byte currentData[6];
  int  idx = 0;

  //Serial.print("byte count: ");
  //Serial.println(byteCount);
  
    while(Wire.available()) {
        
        data = Wire.read();
        
        if (byteCount == 6){
            currentData[idx] = data;
            //Serial.println(currentData[idx], HEX);
            idx++;
            
        } 
        //Serial.print("Receive data from RPI: 0x");
        //Serial.println(number, HEX);
    }
    
    // request data size verification
    if (byteCount != 6){
      Serial.println("IOError: bad data size");
      return;
    }
    
    // checksum verification
    byte checkSum = 0;
    for(int i=1; i<5; i++){
      //Serial.println(currentData[i], HEX);
      checkSum += currentData[i];
    }
    
    if (checkSum != currentData[5]){
      Serial.print("IOError: bad checksum (");
      Serial.print(checkSum, HEX);
      Serial.println(")");
      return;
    }
    
    // all is OK print request
    Serial.print("Receive data from RPI: ");
    
    Serial.print("[0x");
    Serial.print(currentData[0], HEX);
    
    Serial.print(", 0x");
    Serial.print(currentData[1], HEX);
    
    Serial.print(", 0x");
    Serial.print(currentData[2], HEX);
    
    Serial.print(", 0x");
    Serial.print(currentData[3], HEX);
    
    Serial.print(", 0x");
    Serial.print(currentData[4], HEX);
    
    Serial.print(", 0x");
    Serial.print(currentData[5], HEX);
    Serial.println("]");
    
    /*
    if (currentData[1] == 19){
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
    }
    */
      
}

// callback for sending data
void sendData(){
    Serial.print("Send data from Arduino to RPI: ");
    Serial.println(sendDataValue);
    Wire.write(sendDataValue);
    sendDataValue ++;
}


