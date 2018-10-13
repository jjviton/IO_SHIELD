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
#define SW01        02
#define SW02        03




// the setup function runs2once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(SW01, INPUT);
  pinMode(SW02, INPUT);
}


void LED_Test(void){
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(GREEN_LED, LOW);
  delay(400);                       // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);   
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



// the loop function runs over and over again forever
void loop() {

  LED_Test();
  Pushbotton_Test();
                    
}// loop_FIN
