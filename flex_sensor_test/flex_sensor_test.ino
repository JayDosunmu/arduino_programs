int sensorPin = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("ready...");

}

void loop() {
  // put your main code here, to run repeatedly:
  int rawValue = analogRead(sensorPin);

  Serial.println(rawValue);
}
