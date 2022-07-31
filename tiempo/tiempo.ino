unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempoSegundos = 0;

void setup() {
  Serial.begin(9600);
  tiempo1 = millis();

}

void loop() {

  tiempo2 = millis();
  Serial.print("tiempo1 : ");
  Serial.print(tiempo1);
  Serial.print("tiempo2 : ");
  Serial.print(tiempo2);
  Serial.println("");
  if(tiempo2 > (tiempo1+1000)){  //Si ha pasado 1 segundo ejecuta el IF
    tiempo1 = millis(); //Actualiza el tiempo actual
    tiempoSegundos = tiempo1/1000;
    Serial.print("Ha transcurrido: ");
    Serial.print(tiempoSegundos);
    Serial.println(" desde que se encendio el Arduino");
    
  }
}
