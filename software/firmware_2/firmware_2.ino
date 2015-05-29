const int pingPin = 4;
const int triggerPin = 5;
const int leftWheel = 7;
const int rightWheel = 8;
const int proximity_threshold = 150;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(leftWheel, OUTPUT);
  pinMode(rightWheel, OUTPUT);
}

void loop()
{
  // check sonar
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  // for debugging
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  // if we get too close to something, take action
  if(cm < proximity_threshold){
    // stop
    digitalWrite(leftWheel, LOW);
    digitalWrite(rightWheel, LOW);
    // fire
    digitalWrite(triggerPin, HIGH);
    // delay
    delay(1000);
    // stop firing
    digitalWrite(triggerPin, LOW);
    // turn
    digitalWrite(leftWheel, HIGH);
    delay(1000);
    digitalWrite(leftWheel, LOW);
  }
  
  // drive forward
  digitalWrite(leftWheel, HIGH);
  digitalWrite(rightWheel, HIGH);
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
