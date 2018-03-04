#ifndef COMMANDS_H
#define COMMANDS_H

#ifdef __cplusplus
extern "C"{
#endif


const int pushButtonPin = 2;
const int ledPwmRedPin = 9;
const int ledPwmGrnPin = 10;
const int ledPwmBluPin = 11;
const int ledDigitalPin =  13;      // the number of the LED pin

void CMD_generalParse(char * cmd, unsigned char len);
void CMD_writeDigitalParse(char * cmd, unsigned char len);
void CMD_writeAnalogParse(char * cmd, unsigned char len);
void CMD_readDigital(char * cmd, unsigned char len);
unsigned char ascii2digit(char c);

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* COMMANDS_H */
