# bus-shinobi
Alternative to bus ninja running on Arduino Uno R3.
Host communication via HW Serial of Arduino Uno: 9600-8-1-N

### Commands supported:
* WD13? - Write Digital pin13 (where ? is 'H' or 'L')
* WA09? - Write PWM (Analog) signal to pin 9 with duty cycle proportional to ? (where ? is '0' to '9', '0' - duty 0%, '9' - duty 100%)

### ToDo:
* Add command support:
	* RD13x - Read state of Digital pin 13

