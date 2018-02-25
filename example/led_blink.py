
#python3 script, requires pyserial package
#python -m pip install pyserial
import serial
import time

ser = serial.Serial('COM16', 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)         # check which port was really used
time.sleep(1)
loops = 10
while loops:
    num_written = ser.write( b'WD13H')     # write a string
    print("Written " + str(num_written))
    buf = ser.read(num_written);
    print("Read " + str(buf))
    time.sleep(0.5)
    num_written = ser.write( b'WD13L')     # write a string
    print("Written " + str(num_written))
    buf = ser.read(num_written);
    print("Read " + str(buf))
    time.sleep(0.5)
    loops -= 1

ser.close()             # close port