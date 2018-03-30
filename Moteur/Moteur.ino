#include <LiquidCrystal.h>

int M1REV = 0;
int M1FWD = 0;
int M2REV = 0;
int M2FWD = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop() //fonction principale, elle se répète (s’exécute) à l'infini
{

  //contenu du programme


  M1REV = digitalRead(12);
  M1FWD = digitalRead(11);
  M2REV = digitalRead(10);
  M2FWD = digitalRead(9);
//---------------------------M1
  if (M1FWD == HIGH)
  {
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }
  else if(M1REV == HIGH)
  {
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }

  else 
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
//---------------------------M2
  if (M2FWD == HIGH)
  {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  }
  else if(M2REV == HIGH)
  {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  }

  else 
  {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }



  

   Serial.print("PIN12");       // prints a label
   Serial.print("\t");
   Serial.println(M1REV);
   delay(1000);        // delay in between reads for stability
   Serial.print("PIN10");       // prints a label
   Serial.print("\t");
   Serial.println(M2REV);
   delay(1000);        // delay in between reads for stability




  
}












