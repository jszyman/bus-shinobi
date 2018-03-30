# bus-shinobi
Alternative to bus ninja running on Arduino Uno R3.
Host communication via HW Serial of Arduino Uno: 9600-8-1-N

### Commands supported:
* WD13?\n - Write Digital pin13 where:
	* ? is 'H' or 'L'
* WA$$?\n - Write PWM (Analog) signal to pin $$ with duty cycle proportional to ? where:
	* $$ is '09', '10' or '11'
	* ? is '0' to '9', '0' - duty 0%, '9' - duty 100%
	* WHxxyz\n - Write Hexadicimal digit to segmented LED display (CA) where:
		* xx - digital pin number connected to segment A, can be from '02' to '06'
				next segments shall be connected to consecutive pins
		* y - is hexadecimal digit 0 - 9, A - F
		* z - when = '.' or ',' then dot is On
* RD08\n - Read state of Digital pin 8, response is RD08? where:
    * ? is 'H' or 'L'
* RAA0\n - Read Analog input of pin A0, response is RAA0xxxx where:
	* xxxx is ADC read in range 0 - 1023

See .\example folder for usage examples

### Build
Project can be built with Sloeber, the Eclipse Arduino IDE - https://eclipse.baeyens.it/

### ToDo:
* Add command support:
	* UART Tx/Rx (WU, RU)
	* SPI Tx/Rx (WS, RS)
	* I2C Tx/Rx (WI, RI)
	* HD44780 display (WL)
	* N3310 display (WG)
* split arduino sketch into multiple source files
* support for RGB LEDs with common anode and cathode
* Check correctness of pin and duty values in CMD_analogParse()

