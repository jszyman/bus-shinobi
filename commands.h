#ifndef COMMANDS_H
#define COMMANDS_H

#ifdef __cplusplus
extern "C"{
#endif

int analogInPin;
const int ledSegmA = 0;
const int ledSegmB = 1;
const int ledSegmC = 2;
const int ledSegmD = 3;
const int ledSegmE = 4;
const int ledSegmF = 5;
const int ledSegmG = 6;
const int ledSegmDP = 7;
const int pushButtonPin = 8;
const int ledPwmRedPin = 9;
const int ledPwmGrnPin = 10;
const int ledPwmBluPin = 11;
const int ledDigitalPin =  13;      // the number of the LED pin

void CMD_generalParse(char * cmd, unsigned char len);
void CMD_writeDigitalParse(char * cmd, unsigned char len);
void CMD_writeAnalogParse(char * cmd, unsigned char len);
void CMD_readDigital(char * cmd, unsigned char len);
void CMD_readAnalog(char * cmd, unsigned char len);

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* COMMANDS_H */
