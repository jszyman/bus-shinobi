
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arduino.h"
#include "commands.h"

void cmd2upper(char * cmd);
unsigned char ascii2digit(char c);
uint8_t ascii2hexDigit(char c);
uint8_t getPinNumber(uint8_t * cmdPin);


void CMD_generalParse(char * cmd, unsigned char len)
{
    char direction;
    char kind;

    cmd2upper(cmd);

    direction = cmd[0];
    kind = cmd[1];
    if(direction == 'W')
    {
        if(kind == 'D')
        {
            CMD_writeDigitalParse(cmd, len);
        }
        else if (kind == 'A')
        {
            CMD_writeAnalogParse(cmd, len);
        }
        else if (kind == 'H')
        {
            CMD_writeHexValue(cmd, len);
        }
        else
        { /* do nothing */ }
    }
    else if (direction == 'R')
    {
        if (kind == 'D')
        {
            CMD_readDigital(cmd, len);
        }
        else if (kind == 'A')
        {
        	CMD_readAnalog(cmd, len);
        }
        else
        { /* do nothing */ }
    }
    else
    { /* do nothning */ }
}

void CMD_writeDigitalParse(char * cmd, unsigned char len)
{
    int pin;

    pin = (ascii2digit(cmd[2]) * 10) + ascii2digit(cmd[3]);

    if(cmd[4] == 'H')
    {
        digitalWrite(pin, HIGH);
    }
    else if (cmd[4] == 'L')
    {
        digitalWrite(pin, LOW);
    }
    else
    { /* do nothing */ }
}

void CMD_writeAnalogParse(char * cmd, unsigned char len)
{
    int duty;
    int pin;

    pin = (ascii2digit(cmd[2]) * 10) + ascii2digit(cmd[3]);
    duty = (255 * (ascii2digit( cmd[4] ) ) ) / 9;
    analogWrite(pin, duty);
}

void CMD_writeHexValue(char * cmd, unsigned char len)
{
	/* hex values of pin states used for control segment LED displaying
	 * values 0 - 9 and A - F */
	unsigned char hexCodes[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
								0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

	uint8_t startPin = 2;
	uint8_t hexCode = 0;
	uint8_t pinState = 0;

	startPin = getPinNumber( (uint8_t *)&cmd[2] );
	hexCode = hexCodes[ ascii2hexDigit(cmd[4]) ];

	for (int i = 0; i < 8; i++)
	{
		pinState = (hexCode >> i) & 1U;
		digitalWrite(i + startPin, pinState);
	}
}

void CMD_readDigital(char * cmd, unsigned char len)
{
    int state;

    state = digitalRead(pushButtonPin);
    cmd[4] = state == HIGH ? 'H' : 'L';
    cmd[5] = '\0';    // terminate response string
}

void CMD_readAnalog(char * cmd, unsigned char len)
{
	unsigned int adcRead;

	adcRead = analogRead(analogInPin);
	memset(&cmd[4], '\0', 5); //proper termination of any 0 - 1024 value string
	itoa(adcRead, &cmd[4], 10);
}

void cmd2upper(char * cmd)
{
	int i = 0;

	while(cmd[i] != '\n')
	{
		cmd[i] = toupper(cmd[i]);
		i++;
	}
}

unsigned char ascii2digit(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else
        return 0;
}

uint8_t ascii2hexDigit(char c)
{
	if (c >= '0' && c <= '9')
		return ascii2digit(c);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 0xA);
	else if (c >= 'A' && c <= 'F')
		return c - 'A' + 0xA;
	else
		return 0;
}

uint8_t getPinNumber(uint8_t * cmdPin)
{
	return (ascii2digit(cmdPin[0]) * 10) + ascii2digit(cmdPin[1]);
}
