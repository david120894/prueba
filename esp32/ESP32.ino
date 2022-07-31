const int pinLED = 2;
const int pinled=4;//Define la salida del circuito el PIN 13 es LED de la placa de Arduino
const int pinMicrophone = 5; //Pin de entrada del módulo de sonido
bool state1 = false;  //se evita que cualquier sonido active el sonido
bool state2 = false;  //solo tres sonidos seguidos activan el sonido
bool state3 = false;
bool stateLED = false; //pin de salida
bool soundDetected = false; // guarda las lecturas del PIN de salida
unsigned long tem; //guarda el tiempo en el que se recoge el sonido
 
void setup(){
  pinMode(pinLED, OUTPUT);
  pinMode(pinled, OUTPUT);// se define como salida ,
  pinMode(pinMicrophone, INPUT); //se define como pin de entrada
  Serial.begin(9600);
}
 
void loop(){
soundDetected = digitalRead(pinMicrophone);  // lee la entrada

  if ((soundDetected==true) && (state1==false) && (state2==false) && (state3==false)) {
  state1 = true;
  Serial.println("Estado1 true");
  tem = millis();
  delay (200);
  } else if ((soundDetected == true) && (state1==true) && (state2==false) && (state3==false) ) {
  state2 = true; 
  Serial.println("Estado2 true");
  delay (200);
  } else if ((soundDetected == true) && (state1==true) && (state2==true) && (state3==false) ) {
  state3 = true; 
  Serial.println("Estado3 true");
  delay (200);  
  }
//activa y desactiva sonidos
  if ((state1==true) && (state2==true) && (state3==true)){
  stateLED = !stateLED;
  digitalWrite(pinLED , stateLED);
  digitalWrite(pinled , stateLED);
  Serial.println("Reset");
  state1 = false; 
  state2 = false;
  state3 = false; 
  }
// se hace reset de los estados
  if (((millis()-tem) >= 500) && (state1==true) && (state2==false || state3==false)){ // Reseteamos estados al pasar 500 ms
  Serial.println("Reset Time");
  Serial.println((millis()-tem));
  state1 = false; 
  state2 = false;
  state3 = false;  
  }
}
  
