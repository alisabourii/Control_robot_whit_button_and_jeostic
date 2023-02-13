#include<Servo.h>

Servo srv;

const int Enable_A = 10;
const int Enable_B = 11;
const int inputA1 = 3;
const int inputA2 = 5;
const int inputB1 = 6;
const int inputB2 = 9;

int forward_btn = 2;
int backward_btn = 4;


void setup() {
  pinMode(Enable_A,OUTPUT);
  pinMode(inputA1,OUTPUT);
  pinMode(inputA2,OUTPUT);
  pinMode(Enable_B,OUTPUT);
  pinMode(inputB1,OUTPUT);
  pinMode(inputB2,OUTPUT);
  Serial.begin(9600);
  srv.attach(12);
  pinMode(2, INPUT); //ّFORWARD
  pinMode(4, INPUT); // BACKWARD
}


void loop() {
  forward();
  move_servo();
  Serial.println(digitalRead(2));
  delay(100);
}

void forward(){
    if(digitalRead(2) == 1){
      analogWrite(Enable_A, 150);
      analogWrite(Enable_B, 255);
      digitalWrite(inputA1, HIGH);
      digitalWrite(inputA2, LOW);
      digitalWrite(inputB1, HIGH);
      digitalWrite(inputB2, LOW);
      }
   
   else if(digitalRead(4) == 1){
      analogWrite(Enable_A, 150);
      analogWrite(Enable_B, 255);
      digitalWrite(inputA1, LOW);
      digitalWrite(inputA2, HIGH);
      digitalWrite(inputB1, LOW);
      digitalWrite(inputB2, HIGH);
      }
   else{
      analogWrite(Enable_A, 0);
      analogWrite(Enable_B, 0);
      }
      
      
    
 
}

void move_servo(){
  int data = map(analogRead(A0), 0,1023,0,180);
  srv.write(data);
  }
