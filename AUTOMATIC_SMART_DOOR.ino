#include <Servo.h>

#include <LiquidCrystal.h>


int pin2=2;

int trigPin=5;

int echoPin=3;

int pingTime;

float distance;



int rs=7;

int e=8;

int d4=9;

int d5=10;

int d6=11;

int d7=12;

LiquidCrystal lcd(rs,e,d4,d5,d6,d7);


Servo myServo;



void setup() {

  // put your setup code here, to run once:

  myServo.attach(6);

  myServo.write(0);       

  lcd.begin(16,2);

  pinMode(trigPin,OUTPUT);

  pinMode(echoPin,INPUT);

  pinMode(pin2,OUTPUT);

  Serial.begin(9600);

  delay(100);

}

void loop() {


  digitalWrite(trigPin,LOW);

  delayMicroseconds(10);

  digitalWrite(trigPin,HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);

  distance=pingTime*(0.0343/2);

  Serial.println(distance);



  if (distance<15){

    myServo.write(90);

    lcd.setCursor(0,0);

    lcd.print("DOOR OPENED");

    digitalWrite(pin2,HIGH);

    delay(6000);

    lcd.clear();
  

  }

  if (distance>=15){

    myServo.write(0);

    lcd.setCursor(0,0);

    lcd.print("DOOR CLOSED");

     digitalWrite(pin2,LOW);

    delay(30);

    lcd.clear();


  }

// put your main code here, to run repeatedly:

}