#include <Servo.h>

int ENA = 3;
int IN1 = 4;
int IN2 = 5;
int ENB = 6;
int IN3 = 7;
int IN4 = 2;
int infrarrojo = 8;
int valor = 0;
Servo servobase;
Servo servo1;
Servo servo2;
Servo garra;

void setup() {  
  Serial.begin(9600);
  servobase.attach(9,400,2600);
  servo1.attach(10,500,2500);
  servo2.attach(11,500,2500);
  garra.attach(12);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  valor = digitalRead(infrarrojo);
if(valor == HIGH){     
  medio();
  cintamueve();  
}
if(valor == LOW){
  cintaespera();
  recibo();
  delay(2000);
  //mid();
  entrega();
}
}
void cintamueve() {
  Serial.println("HIGH");
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 130); 
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 130);
  //Conveyor belt delivers a load.
}
void cintaespera() {
  if(valor == LOW){ 
  Serial.println("LOW");
  analogWrite(ENA, 0);
  analogWrite(ENB, 0); 
  }//The belt awaits the arm.
}
void medio() {
  Serial.println("Moving to center");
  servobase.write(90);
  delay(1000);
  servo1.write(180);
  servo2.write(0);  
}//Retraer al medio

void recibo() {  
  Serial.println("Searching conveyor");
  delay(1000);
  servobase.write(34);
  delay(2000);
  servo2.write(70);
  servo1.write(130);
  garra.write(90);
  delay(2000);
  garra.write(0);
  delay(3000);
  servo1.write(180);
  servo2.write(0);
}//Retract to the middle

void entrega() {
  Serial.println("Delivering");
  delay(1000);
  servobase.write(180);  
  servo1.write(180);
  servo2.write(0);
  delay(1000);
  delay(2000);
  servo2.write(70);
  servo1.write(130);
  delay(1000);
  garra.write(90);
  delay(1000); 
  servo1.write(180);
  servo2.write(0);
  delay(1000); 
}//Arm delivers the load
