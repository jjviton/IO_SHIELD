/*
 * 
 * I/O_shield  (https://github.com/jjviton/IO_SHIELD/blob/master/Esquema_Shield_Arduino_clase_V2.2.pdf)
 * 
 * Probando el hardware de la placa.
 *    1) LEDs ROJO / GREEN   pin 10 / pin 11
 *    2) PushBotton SW1 SW2  pin 2 / pin 3
 *    

*/




#define RED_LED     11
#define GREEN_LED   10
#define SW01        2
#define SW02        3
#define buzzer      9
#define POTENCIOMETRO 0
#define LDR         1
#define POTENCIA_5  5
#define POTENCIA_6  6


///////////////////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
///////////////////////////////////////////////////////////////////////
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(SW01, INPUT);
  pinMode(SW02, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(POTENCIOMETRO, INPUT);
  pinMode(POTENCIA_5, OUTPUT);
  pinMode(POTENCIA_6, OUTPUT);

  buzzerTEST();

  Serial.begin(9600);
  
}
////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Funcion para probar los leds de la I/O
void LED_Test(void){

  byte i;

  for(i=0;i<6;i++){
        digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(GREEN_LED, LOW);
        delay(400);                       // wait for a second
        digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(GREEN_LED, HIGH);
        delay(1000);   
  }
}//LED_Test FIN

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Funcion para probar los pulsadores de la I/O
void Pushbotton_Test(){

  if(digitalRead(SW02)){
       digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
       digitalWrite(GREEN_LED, LOW);
  }

  if(digitalRead(SW01)){
       digitalWrite(RED_LED, LOW);   // turn the LED on (HIGH is the voltage level)
       digitalWrite(GREEN_LED, HIGH);
  } 
} // PushBotton (FIN)


////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Funcion para el zumbador de la I/O
void buzzerTEST(){
  byte i;

  for(i=0;i<3;i++){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
  } 
}// buzzerTEST (fin)

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Funcion para probar el potenciometro de la I/O
//////////////////////The default analogRead() resolution for these boards is 10 bits
int poteciometroTEST(void){
  int dato;
  dato = analogRead(POTENCIOMETRO); 
  Serial.print(dato, HEX); Serial.print("   ");
  Serial.println(dato, DEC); 
}//poteciometroTEST FIN


////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Funcion para probar el LDR de la I/O
int ldrTEST(void){
  byte dato;
  dato = analogRead(LDR); 
  Serial.println(dato, HEX);
  delay(400); 
}//ldrTEST FIN



///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Funcion para probar la etapa de Potencia tipo A de la I/O
int potenciaTEST(void){
  byte dato,i;

  for(i=0;i<250;i+=2){
    analogWrite(POTENCIA_5,i);
    analogWrite(POTENCIA_6,(250-i));
    Serial.println(i, HEX);
    delay(100);
    
  }

}//ldrTEST FIN

/////////////////////////////////////////////////////
// the loop function runs over and over again forever
////////////////////////////////////////////////////
void loop() {
  //Pushbotton_Test();
  //buzzerTEST();
  //LED_Test();
  poteciometroTEST();
  //ldrTEST();
  //potenciaTEST();

  while(0);
                    
}// loop_FIN
