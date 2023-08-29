/*
 For L298N:
 ENA 5
 IN1  6
 IN2  7
 IN3  8
 IN4  9
 ENB 10

 For HC-SR04:
 Echo 4
 TRIG 3
 VCC to arduino 5V
 GND to arduino GND
 
 Motor A is for rear, Motor B is for front
 */
 
 #define trigPin 3
 #define echoPin 4
  
 int enA = 5;
 int in1 = 6;
 int in2 = 7;
 int in3 = 8;
 int in4 = 9;
 int enB = 10;
 long duration, distance;

 void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
 }

 void loop() {
  //Detect Distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  //Decide based on distance
  if (distance <= 35){
    Serial.println("Reversing");
    //Reverse  A(rear motor) to the left if distance is less than 15 cm
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 250);
    //turn B(front motor) tires leftward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 250);
    delay(750);
    //Turn off both motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else {
    Serial.println("Driving");
    //Drive forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 225);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(100);
  }  
 }
  
