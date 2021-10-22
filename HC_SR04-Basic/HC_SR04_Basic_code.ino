
const int trigPin = 9;   //assigning 9 to variable trigPin in order to ease editing of pin for later purpose
const int echoPin = 10;    //assigning 10 to variable trigPin in order to ease editing of pin for later purpose

float duration, distance;  // initializing variables duration and distance for later use

void setup() {
  pinMode(trigPin, OUTPUT);   // initializing trigPin of the sensor which is connected to digital pin 9
  pinMode(echoPin, INPUT);    //initializing echoPin of the sensor which is connected to digital pin 10
  Serial.begin(9600);         // Switching on the Serial Monitor with baud rate 9600
}

void loop() {
  digitalWrite(trigPin, LOW);     // 
  delayMicroseconds(2);           //
  digitalWrite(trigPin, HIGH);     //  // code for constantly sending ultrasonic waves in the forward direction fo the sensor for 10 seconds with 2 second delay
  delayMicroseconds(10);          //
  digitalWrite(trigPin, LOW);       //

  duration = pulseIn(echoPin, HIGH);   // turning echo pin high for receiving feedback which is in terms of time taken by the waves to travel and get reflected back from the obstacle back to the sensor
  distance = (duration*.0343)/2;       // the time taken is used to calculate the distance using speed of the ultrasonic waves
  Serial.print("Distance: ");   /     // printing the distance on serial Monitor
  Serial.println(distance);           //
  delay(100);                         // giving a 100 milisecond delay until the next distance is printed
}
