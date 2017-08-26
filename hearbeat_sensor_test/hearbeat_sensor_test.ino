int ledPin=13;
int sensorPin=0;

double alpha=0.75;
int period=20;
int scale = 100;
double change=0.0;
double seconds=0;
double bpm = 0;
boolean pulse = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Running.");
}

void loop() {
  static double oldValue=0;
  static double oldChange=0;
  
  int rawValue=analogRead(sensorPin);
  double newValue=alpha * oldValue+(1-alpha)*rawValue;
  change=min(newValue-oldValue, 1) * scale;
  
  int low_threshold = 40;
  int high_threshold = 90;

  if(change < 0){
    change = 0;
  } else {
    Serial.println(change);
  }
  
  oldValue=newValue;
  oldChange=change;

  delay(period);
}
