# bus-shinobi
Alternative to bus ninja running on Arduino Uno R3.
Host communication via HW Serial of Arduino Uno: 9600-8-1-N

### Commands supported:
* WD13? - Write Digital pin13 (where ? is 'H' or 'L')
* WA##? - Write PWM (Analog) signal to pin ## with duty cycle proportional to ? where:
	* ## is '09', '10' or '11'
	* ? is '0' to '9', '0' - duty 0%, '9' - duty 100%
See .\example folder for usage examples

### ToDo:
* Add command support:
	* RD12x - Read state of Digital pin 12
* split arduino sketch into multiple source files
* support for RGB LEDs with common anode and cathode
* Check correctness of pin and duty values in CMD_analogParse()

