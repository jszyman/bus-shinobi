
#include <ctype.h>
#include "arduino.h"
#include "commands.h"

void cmd2upper(char * cmd);
unsigned char ascii2digit(char c);


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
        else
        { /* do nothing */ }
    }
    else if (direction == 'R')
    {
        if (kind == 'D')
        {
            CMD_readDigital(cmd, len);
        }
        else
        { /* do nothing */ }
    }
    else
    { /* do nothning */ }
}

void CMD_writeDigitalParse(char * cmd, unsigned char len)
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

void CMD_readDigital(char * cmd, unsigned char len)
{
    int state;

    state = digitalRead(pushButtonPin);
    cmd[4] = state == HIGH ? 'H' : 'L';
    cmd[5] = '\0';    // terminate response string
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
        return '0';
}
