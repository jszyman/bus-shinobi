
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

led_segmC_on_cmd = b'WD02L\n'
led_segmC_off_cmd = b'WD02H\n'
led_segmD_on_cmd = b'WD03L\n'
led_segmD_off_cmd = b'WD03H\n'
led_segmE_on_cmd = b'WD04L\n'
led_segmE_off_cmd = b'WD04H\n'
led_segmF_on_cmd = b'WD05L\n'
led_segmF_off_cmd = b'WD05H\n'
led_segmG_on_cmd = b'WD06L\n'
led_segmG_off_cmd = b'WD06H\n'

loops = 10
while loops:
    send_bs_command(led_segmC_on_cmd)
    send_bs_command(led_segmD_on_cmd)
    send_bs_command(led_segmE_on_cmd)
    send_bs_command(led_segmF_on_cmd)
    send_bs_command(led_segmG_on_cmd)
    time.sleep(1.0)
    send_bs_command(led_segmC_off_cmd)
    send_bs_command(led_segmD_off_cmd)
    send_bs_command(led_segmE_off_cmd)
    send_bs_command(led_segmF_off_cmd)
    send_bs_command(led_segmG_off_cmd)
    time.sleep(1.0)
    loops -= 1

ser.close()