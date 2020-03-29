/*
 Controlando a posição de um servo usando um potenciômetro (resistor variável)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
 adaptado por Renato Aloi https://github.com/renatoaloi/sige-shield-robotica

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob

 modified on 29 Mar 2020
 by Renato Aloi
 
 Plataforma SIGE Robótica por Fernando Neves
 https://www.youtube.com/channel/UC7KlkgM_nJrSNnrlB0nPNLw
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 1;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 120);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
