
# python3 script, requires pyserial package
# python -m pip install pyserial
# assumes RGB led with common anode (CA) is controlled by pins:
# color - pin
# red   - 09
# green - 10
# blue  - 11

import serial
import time
import random

def fade_pwm_pin(cmd_pin = b'WA09'):
    for duty in range(9, -1, -1):
        cmd_send = cmd_pin + bytearray( str(duty), encoding='ascii') + bytearray('\n', encoding='ascii')
        num_written = ser.write(cmd_send)
        print("Tx:\t" + str(num_written) + ":\t" + str(cmd_send) )
        buf = ser.readline()
        print("Rx:\t\t" + str(buf))
        time.sleep(0.05)
    for duty in range(0, 10):
        cmd_send = cmd_pin + bytearray( str(duty), encoding='ascii') + bytearray('\n', encoding='ascii')
        num_written = ser.write(cmd_send)
        print("Tx:\t" + str(num_written) + ":\t" + str(cmd_send) )
        buf = ser.readline()
        print("Rx:\t\t" + str(buf))
        time.sleep(0.05)


ser = serial.Serial('COM16', 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)    # check which port was really used
time.sleep(2)                   # unable to use serial port w/o sleep, maybe check with ser.isOpen()?
loops = 100
cmdPwmRed = b'WA09'
cmdPwmGrn = b'WA10'
cmdPwmBlu = b'WA11'

while loops:
    rnd_duty = random.randrange(10)
    cmd_send = cmdPwmRed + bytearray( str(rnd_duty), encoding='ascii') + bytearray('\n', encoding='ascii')
    num_written = ser.write(cmd_send)
    print("Tx:\t" + str(num_written) + ":\t" + str(cmd_send) )
    buf = ser.readline()
    print("Rx:\t\t" + str(buf))
    rnd_duty = random.randrange(10)
    cmd_send = cmdPwmGrn + bytearray( str(rnd_duty), encoding='ascii') + bytearray('\n', encoding='ascii')
    num_written = ser.write(cmd_send)
    print("Tx:\t" + str(num_written) + ":\t" + str(cmd_send) )
    buf = ser.readline()
    print("Rx:\t\t" + str(buf))
    rnd_duty = random.randrange(10)
    cmd_send = cmdPwmBlu + bytearray( str(rnd_duty), encoding='ascii') + bytearray('\n', encoding='ascii')
    num_written = ser.write(cmd_send)
    print("Tx:\t" + str(num_written) + ":\t" + str(cmd_send) )
    buf = ser.readline()
    print("Rx:\t\t" + str(buf))
    time.sleep(0.1)
    loops -= 1
    
ser.close()             # close port