
#python3 script, requires pyserial package
#python -m pip install pyserial
import serial
import time

ser = serial.Serial('COM16', 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)         # check which port was really used
time.sleep(1)
loops = 10
cmd = b'WA09'
while loops:
    for duty in range(0, 10):
        cmd_send = cmd + bytearray( str(duty), encoding='ascii')
        num_written = ser.write(cmd_send)
        print("Written " + str(num_written))
        buf = ser.read(num_written);
        print("Read " + str(buf))
        time.sleep(0.05)
    for duty in range(8, 0, -1):
        cmd_send = cmd + bytearray( str(duty), encoding='ascii')
        num_written = ser.write(cmd_send)
        print("Written " + str(num_written))
        buf = ser.read(num_written);
        print("Read " + str(buf))
        time.sleep(0.05)
    loops -= 1

# return to no PWM
num_written = ser.write( b'WA090')
print("Written " + str(num_written))
buf = ser.read(num_written);
print("Read " + str(buf))
    
ser.close()             # close port