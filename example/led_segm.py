
#python3 script, requires pyserial package
#python -m pip install pyserial
import serial
import time

def send_bs_command(cmd):
    num_written = ser.write(cmd)
    print("Tx:\t" + str(num_written) + ":\t" + str(cmd))
    buf = ser.readline()
    print("Rx:\t\t" + str(buf))

ser = serial.Serial('COM16', 9600, timeout=1, parity=serial.PARITY_NONE)  # open serial port
print("Opened: " + ser.name)    # check which port was really used
time.sleep(2)                   # unable to use serial port w/o sleep, maybe check with ser.isOpen()?

hexDigits = [0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46]
led_segm_cmd = bytearray(b'WH020_\n')

digit = 0
loops = 16
while loops:
    led_segm_cmd[4] = hexDigits[digit]
    send_bs_command(led_segm_cmd)
    digit += 1
    time.sleep(0.5)
    loops -= 1

led_segm_cmd[5] = 46 # change '_' to '.'
digit = 0
loops = 16 
while loops:
    led_segm_cmd[4] = hexDigits[digit]
    send_bs_command(led_segm_cmd)
    digit += 1
    time.sleep(0.5)
    loops -= 1

 
ser.close()