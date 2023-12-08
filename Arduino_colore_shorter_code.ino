#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo topServo;
Servo bottomServo;

int frequency = 0;
int color=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(7);
  bottomServo.attach(8);

  Serial.begin(9600);
}

void loop() {

  topServo.write(115);
  delay(500);
  
   topServo.write(140);
  delay(500);
  topServo.write(65);
  delay(5000);
  
  color = readColor();
  delay(10);  
  Serial.print("\ncolor = ");Serial.println(color); 
  switch (color) {
    

    case 2:
    bottomServo.write(50);
    delay(500);
    break;

    case 3:
    bottomServo.write(75);
    delay(500);
    break;

    //case 4:
    //bottomServo.write(100);
    //break;

    case 5:
    bottomServo.write(125);
    delay(500);
    break;

    
    
    case 0:
    bottomServo.write(90);
    break;
  }
  //delay(300);
  

  topServo.write(25);
  delay(500);
  color=0;
}

// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);

  //if(R<45 & R>32 & G<65 & G>55){
    //color = 1; // Red
  //}
  if(R<88 & R>59 ){
    color = 2; // Orange
  }
  if( G<25 & G>10){
    color = 3; // Green
  }
  //if(R<38 & R>24 & G<44 & G>30){
    //color = 4; // Yellow
  //}
  if(B<61 &B>55){
    color = 5; // Brown
  }
  //if (G<58 & G>45 & B<40 &B>26){
    //color = 6; // Blue
  //}
  return color;  
}