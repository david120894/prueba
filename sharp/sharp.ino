#include<Servo.h>
 Servo servo;
void setup() {
  // Comunicación seria a 9600 baudios
  servo.attach(4);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servo.write(4);
}
void loop() {
  
  long tiempo=millis(); //tiempo antes de iniciar la lectura
  int D_cm=distancia(20); //lectura de distancia
  tiempo=millis()-tiempo; //milisegundos que duró la lectura
  Serial.print("Tiempo de lectura: ");
  Serial.print(tiempo); 
  Serial.print("ms  Distancia: ");
  Serial.print(D_cm);
  Serial.println("  cm");
  delay(100);
  if(D_cm<=8){
    for(int i=0; i<90;i=i+1){//0 i=0+1,i=1+1 i=2+1,i=3+1
      servo.write(i);
      delay(10); 
    }
    D_cm=0;
    cerrar(D_cm);
  }
  delay(100);
}
float distancia(int n)
{
  long suma=0;
  for(int i=0;i<n;i++)
  {
    suma=suma+analogRead(A0);
  }  
  float adc=suma/n;
  float distancia_cm = 17569.7 * pow(adc, -1.2062);
  return(distancia_cm);
}
void cerrar(int k){
  
  while(k==0){
  long tiempo=millis(); //tiempo antes de iniciar la lectura
  int D_cm=distancia(20); //lectura de distancia
  tiempo=millis()-tiempo; //milisegundos que duró la lectura
  Serial.print("Tiempo de lectura2: ");
  Serial.print(tiempo); 
  Serial.print("ms  Distancia2: ");
  Serial.print(D_cm);
  Serial.println("  cm");
  delay(100);
  tiempo=millis();
   if(D_cm>=15 && D_cm<=25)
    {
      for(int i=80; i>4;i=i-1){//i=80-1,i=79-1
        servo.write(i);
        delay(10);
      }
      k=1;
      if(k==1){
      break;
    }
    }
    delay(100);
   
  }
}
