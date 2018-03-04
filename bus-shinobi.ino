/*
Blinks LED connedected to pin 13 every second 
https://www.arduino.cc/en/tutorial/blink

Reads a digital input on pin 2, prints the result to the Serial Monitor
http://www.arduino.cc/en/Tutorial/DigitalReadSerial

Turns on the built-in LED on pin 13 when you press the button.
https://www.arduino.cc/en/Tutorial/Button
*/

#include "arduino.h"
#include "commands.h"

#define CMD_LEN 5u
char cmd_buf[CMD_LEN + 1] = {0};
bool doIt = 0;

void setup() {
    pinMode(pushButtonPin, INPUT);
    pinMode(ledDigitalPin, OUTPUT);
    pinMode(ledPwmRedPin, OUTPUT);
    digitalWrite(ledPwmRedPin, HIGH);
    pinMode(ledPwmGrnPin, OUTPUT);
    digitalWrite(ledPwmGrnPin, HIGH);
    pinMode(ledPwmBluPin, OUTPUT);
    digitalWrite(ledPwmBluPin, HIGH);

    doIt = 0;
  
    Serial.begin(9600);
}

void loop() {
  // read command from serial
  if (Serial.available() == CMD_LEN)
  {
      Serial.readBytes(cmd_buf, CMD_LEN);
      doIt = 1;
  }
  if (doIt == 1)
  {
    // parse and execute command
    CMD_generalParse(cmd_buf, CMD_LEN);
    // respond to host
    Serial.write(cmd_buf, CMD_LEN);
    doIt = 0;    
  }

}
