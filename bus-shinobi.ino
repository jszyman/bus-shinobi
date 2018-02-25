/*
Blinks LED connedected to pin 13 every second 
https://www.arduino.cc/en/tutorial/blink

Reads a digital input on pin 2, prints the result to the Serial Monitor
http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

#define CMD_LEN 5u
char cmd_buf[CMD_LEN + 1] = {0};
bool doIt = 0;


// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
const int ledPwmPin = 9;
const int ledDigitalPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
    pinMode(pushButton, INPUT);
    pinMode(ledDigitalPin, OUTPUT);
    pinMode(ledPwmPin, OUTPUT);

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
    // parse command
    CMD_generalParse(cmd_buf, CMD_LEN);
    // execute command
    // respond to host
    Serial.write(cmd_buf, CMD_LEN);
    doIt = 0;    
  }

}

void CMD_generalParse(char * cmd, unsigned char len)
{
    char kind = cmd[1];
    if(kind == 'D')
    {
        CMD_digitalParse(cmd, len);
    }
    else if (kind == 'A')
    {
        CMD_analogParse(cmd, len);
    }
    else
    {
        /* do nothing */
    }

}

void CMD_digitalParse(char * cmd, unsigned char len)
{
    if(cmd[4] == 'H')
    {
      digitalWrite(ledDigitalPin, HIGH);
    }
    else if (cmd[4] == 'L')
    {
      digitalWrite(ledDigitalPin, LOW);
    }
    else 
    {
        /* do nothing */
    }
}

void CMD_analogParse(char * cmd, unsigned char len)
{
    int duty;
    duty = (255 * ( cmd[4] - '0' )) / 9;
    analogWrite(ledPwmPin, duty);
}