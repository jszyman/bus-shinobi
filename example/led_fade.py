
# python3 script, requires pyserial package
# python -m pip install pyserial
# assumes LED cathode is connected to pin 09
import sys
import serial
import time

ser = serial.Serial(sys.argv[1], 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)    # check which port was really used
time.sleep(2)                   # unable to use serial port w/o sleep, maybe check with ser.isOpen()?
loops = 10
cmd = b'WA09'
while loops:
    for duty in range(0, 10):
        cmd_send = cmd + bytearray( str(duty), encoding='ascii') + bytearray('\n', encoding='ascii')
        num_written = ser.write(cmd_send)
        print("Tx:\t" + str(num_written)  + ":\t" + str(cmd_send))
        buf = ser.readline()
        print("Rx:\t\t" + str(buf))
        time.sleep(0.05)
    for duty in range(8, 0, -1):
        cmd_send = cmd + bytearray( str(duty), encoding='ascii') + bytearray('\n', encoding='ascii')
        num_written = ser.write(cmd_send)
        print("Tx:\t" + str(num_written)  + ":\t" + str(cmd_send))
        buf = ser.readline()
        print("Rx:\t\t" + str(buf))
        time.sleep(0.05)
    loops -= 1

# return to no PWM
cmd_send = b'WA090\n'
num_written = ser.write(cmd_send)
print("Tx:\t" + str(num_written)  + ":\t" + str(cmd_send))
buf = ser.readline()
print("Rx:\t\t" + str(buf))
    
ser.close()