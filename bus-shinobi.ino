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

#define CMD_LEN_MAX SERIAL_RX_BUFFER_SIZE
char cmdBuf[CMD_LEN_MAX] = {0};

/* indicates action is required according to received command */
bool doIt = 0;

void setup() {
	analogInPin = A0;

	pinMode(ledSegmA, OUTPUT);
	pinMode(ledSegmB, OUTPUT);
	pinMode(ledSegmC, OUTPUT);
	pinMode(ledSegmD, OUTPUT);
	pinMode(ledSegmE, OUTPUT);
	pinMode(ledSegmF, OUTPUT);
	pinMode(ledSegmG, OUTPUT);
	pinMode(ledSegmDP, OUTPUT);
	digitalWrite(ledSegmA, HIGH);
	digitalWrite(ledSegmB, HIGH);
	digitalWrite(ledSegmC, HIGH);
	digitalWrite(ledSegmD, HIGH);
	digitalWrite(ledSegmE, HIGH);
	digitalWrite(ledSegmF, HIGH);
	digitalWrite(ledSegmG, HIGH);
	digitalWrite(ledSegmDP, HIGH);

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

	if (Serial.available() > 0)
	{
		Serial.readBytesUntil('\n', cmdBuf, CMD_LEN_MAX);
		doIt = 1;
	}
	if (doIt == 1)
	{
		// parse and execute command
		CMD_generalParse(cmdBuf, CMD_LEN_MAX);
		// respond to host
		Serial.println(cmdBuf);
		doIt = 0;
	}

}
