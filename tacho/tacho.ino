#include<Servo.h>
 Servo servo;
int echo = 6;
int tig = 5;
unsigned long tiempo=0;
void setup() {
  tiempo=millis();
  Serial.begin(9600);
  servo.attach(3);
  pinMode(echo, INPUT);// input es entrada
  pinMode(tig,OUTPUT);//output es salidares  
  servo.write(68);
}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tig,LOW);
  delayMicroseconds(4);
  digitalWrite(tig,HIGH);
  delayMicroseconds(10);
  digitalWrite(tig,LOW);

  long lectura=pulseIn(echo,HIGH);
  long Distancia=lectura/2;
  Distancia=Distancia/29;
  Serial.print("Distancia1: ");
  Serial.println(Distancia);
  if(Distancia<=100){
    
    for(int i=68; i>4 ;i=i-1){
        servo.write(i);
        delay(5);
      } 
    Distancia=0;
    cerrar(Distancia);
    
  }
  delay(100);
}
void cerrar(int k){
  
  while(k==0){
      delay(5000);
      for(int i=0; i<69;i=i+1){
      servo.write(i);
      delay(5);
      
    } 
      k=1;
      if(k==1){
      break;   
      }
  }
  }
