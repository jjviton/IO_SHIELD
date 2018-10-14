/*
 * 
 * I/O_shield  (https://github.com/jjviton/IO_SHIELD/blob/master/Esquema_Shield_Arduino_clase_V2.2.pdf)
 * 
 * Probando el hardware de la placa.
 *    1) LEDs ROJO / GREEN   pin 10 / pin 11
 *    2) PushBotton SW1 SW2  pin 2 / pin 3
 *    

*/




#define RED_LED     10
#define GREEN_LED   11
#define SW01        2
#define SW02        3
#define buzzer      9
#define POTENCIOMETRO 0
#define LDR         1




// the setup function runs2once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(SW01, INPUT);
  pinMode(SW02, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(POTENCIOMETRO, INPUT);

  buzzerTEST();

  Serial.begin(9600);
  
}


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

void buzzerTEST(){
  byte i;

  for(i=0;i<2;i++){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
  } 
}// buzzerTEST (fin)

int poteciometroTEST(void){
  byte dato;
  dato = analogRead(POTENCIOMETRO); 
  Serial.println(dato, HEX); 
}//poteciometroTEST FIN


int ldrTEST(void){
  byte dato;
  dato = analogRead(LDR); 
  Serial.println(dato, HEX);
  delay(400); 
}//ldrTEST FIN


// the loop function runs over and over again forever
void loop() {
  //Pushbotton_Test();
  //buzzerTEST();
  //LED_Test();
  //poteciometroTEST();
  ldrTEST();

  while(0);
                    
}// loop_FIN
