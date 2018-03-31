#include<dht.h>
#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

const int MAX_HUM = 25;

const int MAX_TEMP = 25;

Servo myservo;  
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;

#define DHT11_PIN 8

int pos = 0;

void setup() {
 myservo.attach(9);
 
 lcd.begin(16, 2);

 DHT.read11(DHT11_PIN);

 lcd.print("H :" + String(DHT.humidity));

 lcd.setCursor(0, 1);
 
 lcd.print("T :" + String(DHT.temperature));
 
}

void loop() {
 lcd.begin(16, 2);

 DHT.read11(DHT11_PIN); 
 
 lcd.print("H :" + String(DHT.humidity) + ((DHT.humidity > MAX_HUM) ?  "!!!": ""));

  if(DHT.humidity> MAX_HUM){
    for (pos = 90; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      
    
    }
    delay(1000);
    
    for (pos = 160; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  
  }


 lcd.setCursor(0, 1);
 
 lcd.print("T :" + String(DHT.temperature) + ((DHT.temperature > MAX_TEMP) ?  "!!!": ""));

 delay(1000);
}
