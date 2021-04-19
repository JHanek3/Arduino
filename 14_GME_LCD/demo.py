#!/usr/bin/python3
import serial
import config
from time import sleep


if __name__ == "__main__":
    ser = serial.Serial("/dev/ttyUSB1", 9600, timeout=1)
    ser.flush()
    
    print("running")
    
    while True:
        #ser.write("Hello from Raspberry Pi!\n".encode('utf-8'))
        prevStock = 159.76
        currentStock = 160.01
        percentChange = round((currentStock - prevStock) / prevStock * 100,2)
        ser.write("{},{}\n".format(currentStock, percentChange).encode('utf-8'))
        sleep(1)
    
        
