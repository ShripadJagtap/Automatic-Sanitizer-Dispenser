//contributions by ShripadJagtap & Phantonym21

#define echoPin 2
#define trigPin 3

long duration;  // for storing amount of time
int distance;   // for storing distance

void setup() {
  pinMode(trigPin, OUTPUT);   //initializing trigger pin of Sensor
  pinMode(echoPin, INPUT);    //initializing echo pin of Sensor
 
  pinMode(5, OUTPUT);   //initializing pin 5 of arduino board which is connected to the pump
  Serial.begin(9600);   //Starting Serial Monitor at baud rate 9600
}
void loop() {
 
  digitalWrite(trigPin, LOW);         //
  delayMicroseconds(2);               //
  digitalWrite(trigPin, HIGH);        // // code for continuously monitoring the time taken by the US waves to reflect from the nearby object
  delayMicroseconds(10);              //
  digitalWrite(trigPin, LOW);         //
  duration = pulseIn(echoPin, HIGH);     // time stored in the duration variable

  distance = duration * 0.034 / 2;       // calculating distance using predefined formula
  Serial.print("Distance: ");             // 
  Serial.print(distance);                 // // printing distance in centimeters
  Serial.println(" cm");                  //
  if (distance<=3)
  {
    digitalWrite(5, HIGH);
    Serial.print("Pump On");
    delay(150);                  //
    digitalWrite(5, LOW);       //   // if distance is less than 3 the pump turns on for a few miliseconds to dish out the sanitizer
    Serial.print("Pump OFF");
    delay(2000);
  }
  else
  {
    digitalWrite(5, LOW);         // if distance greater than 3 pump remains off 
    Serial.print("Pump OFF");
  
  }
  delay(50);
}
