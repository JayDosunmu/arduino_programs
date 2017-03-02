int ledPin=13;
int sensorPin=0;

double alpha=0.75;
int period=20;
double change=0.0;
double seconds=0;
double beats=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Running.");
}

void loop() {
  // put your main code here, to run repeatedly:
  static double oldValue=0;
  static double oldChange=0;
  int rawValue=analogRead(sensorPin);
  double newValue=alpha * oldValue+(1-alpha)*rawValue;
  change=newValue-oldValue;

  Serial.println(change);
  
  bool cond = (change<0.0 && oldChange>0.0);
  digitalWrite(LED_BUILTIN, cond);
  if(cond){
    beats++;
  }
  
  if(seconds >= 1000){
    float bpm = float(beats)/float(seconds) * 60;
    //Serial.println(bpm);
    seconds = 0;
    beats = 0;
  }
  oldValue=newValue;
  oldChange=change;
  seconds += period;
  delay(period);
}
