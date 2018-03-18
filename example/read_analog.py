
#python3 script, requires pyserial package
#python -m pip install pyserial
import serial
import time

ser = serial.Serial('COM16', 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)    # check which port was really used
time.sleep(2)                   # unable to use serial port w/o sleep, maybe check with ser.isOpen()?

loops = 100
while loops:
    num_written = ser.write( b'RAA0\n')
    #print("Tx:\t" + str(num_written) + ":\t" + str( b'RAA0\n') )
    buf = ser.readline()
    print("Rx:\t" + str(buf))
    time.sleep(0.1)
    loops -= 1

ser.close()