//MX1508_ControllerSimplev0.ino

/*
This is a quick Demo sketch for control of a low voltage
brushed DC motor using the MX1508 breakout board.

We will only control one motor but drive it forward and reverse.
To keep it simple(ish), no input from the user is used.

Motor maximum voltage is 3V

Pin connections (Arduino Nano):
D9  To Motor Controller Port IN2
D10 To Motor Controller Port IN1
*/

const int FwdPin = 6; //Forward Motor Pin
const int BwdPin = 7;  //Backward Motor Pin

long ActTime = 3000; // The time for a particular part of the cycle.

int MaxSpd = 180; //Top speed (0-255)

boolean DirFlag = true; //Flag for direction

void setup()
{
  pinMode(FwdPin, OUTPUT);
  pinMode(BwdPin, OUTPUT);
}

void loop()
{
  if(DirFlag)
  {
    analogWrite(FwdPin,MaxSpd);  //Send instructions to Forward motor pin
    delay(ActTime);
    analogWrite(FwdPin,0);
    DirFlag =! DirFlag; //Toggle Direction flag
    delay(20);
  }
  else
  {
    analogWrite(BwdPin,MaxSpd);  //Send instructions to Backward motor pin
    delay(ActTime);
    analogWrite(BwdPin,0);
    DirFlag =! DirFlag; //Toggle Direction flag
    delay(20);
  }
}
