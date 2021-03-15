#!/usr/bin/env python3

import serial
import random

if __name__ == "__main__":
    ser = serial.Serial("/dev/ttyUSB0", 9600, timeout=1)
    ser.flush()
    
    while True:
        number = ser.read()
        if number != b'':
            if int.from_bytes(number, byteorder='big') == 42:
                led_number = random.randint(0,1)
                print("Button has been pressed")
                print("Sending number " + str(led_number) + " to Arduino")
                ser.write(str(led_number).encode('utf-8'))
        
            
        
