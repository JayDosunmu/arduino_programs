#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
<<<<<<< HEAD

  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Let's go!");

}

void loop() {
  // put your main code here, to run repeatedly:
=======
  
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  
  Serial.println("Let's go");
}

void loop() {
>>>>>>> cf4e6344ac2ff6e5c636a1c3b28c5323e94e40e4
  delay(100);
}

void receiveData(int byteCount){
  while(Wire.available()){
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);
<<<<<<< HEAD

    if(number == 1){
      if(state == 0){
=======
    
    if(number == 1){
      if(number == 0){
>>>>>>> cf4e6344ac2ff6e5c636a1c3b28c5323e94e40e4
        digitalWrite(2, HIGH);
        state = 1;
      } else {
        digitalWrite(2, LOW);
<<<<<<< HEAD
        state = 0;
      }
    }
  }
}

void sendData(){
  Wire.write(number);
}




=======
        state= 0;
      }
    }
  } 
}

void sendData(){
  Wire.write(number)
}
>>>>>>> cf4e6344ac2ff6e5c636a1c3b28c5323e94e40e4
