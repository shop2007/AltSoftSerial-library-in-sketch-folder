/*
Questo sketch consente di incorporare le librerie necessarie nella cartella dello sketch, per non essere dipendenti dalla versione e dalla cpu.
E' una alternativa a SerialSoftware.
*/


#include "AltSoftSerial.h"

// AltSoftSerial always uses these pins:
//
// Board          Transmit  Receive   PWM Unusable
// -----          --------  -------   ------------
// Teensy 3.0 & 3.1  21        20         22
// Teensy 2.0         9        10       (none)
// Teensy++ 2.0      25         4       26, 27
// Arduino Uno        9         8         10
// Arduino Leonardo   5        13       (none)
// Arduino Mega      46        48       44, 45
// Wiring-S           5         6          4
// Sanguino          13        14         12

// This example code is in the public domain.

AltSoftSerial altSerial;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(57600);
  while (!Serial) ; // wait for Arduino Serial Monitor to open
  Serial.println("AltSoftSerial Test Begin");
  altSerial.begin(9600);
  //altSerial.println("Hello World");
}

void loop() {
  for (int pic = 1; pic < 10; pic++) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW


    altSerial.print("pic 0,0,");
    altSerial.print(pic);
    altSerial.write(0xff);
    altSerial.write(0xff);
    altSerial.write(0xff);

    //faccio l'echo
    Serial.print("pic ");
    Serial.println(pic);

    delay(1000);
    
    //ScreenBlack();
    //delay(1000);    
  }


  ScreenBlack();
  TestEmeBlinking();

  
}

  
  

void ScreenBlack(){
    altSerial.print("cls BLACK");
    altSerial.write(0xff);
    altSerial.write(0xff);
    altSerial.write(0xff);

    //faccio l'echo
    Serial.println("cls BLACK");
  
}



void  TestEmeBlinking(){
  for (int i = 1; i < 20; i++) {

    altSerial.print("pic 0,0,3");
    altSerial.write(0xff);
    altSerial.write(0xff);
    altSerial.write(0xff);

    //faccio l'echo
    Serial.println("eme blinking ");
    
    delay(500);
    
    
    ScreenBlack();
    delay(500);
    
    
  }

  


  
}

  
  
