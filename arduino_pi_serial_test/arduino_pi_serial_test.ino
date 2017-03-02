const int ledPin = 2;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    light(Serial.read() - '0');
  }

  delay(500);
}

void light(int n){
  for(int i=0; i<n; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

