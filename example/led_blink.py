
#python3 script, requires pyserial package
#python -m pip install pyserial
import sys
import serial
import time

ser = serial.Serial(sys.argv[1], 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)    # check which port was really used
time.sleep(2)                   # unable to use serial port w/o sleep, maybe check with ser.isOpen()?

led_on_cmd = b'WD13H\n'
led_off_cmd = b'WD13L\n'

loops = 10
while loops:
    num_written = ser.write(led_on_cmd)
    print("Tx:\t" + str(num_written) + ":\t" + str(led_on_cmd))
    buf = ser.readline()
    print("Rx:\t\t" + str(buf))
    time.sleep(0.5)
    num_written = ser.write(led_off_cmd)
    print("Tx:\t" + str(num_written) + ":\t" + str(led_off_cmd))
    buf = ser.readline()
    print("Rx:\t\t" + str(buf))
    time.sleep(0.5)
    loops -= 1

ser.close()