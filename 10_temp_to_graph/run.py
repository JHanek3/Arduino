#!/usr/bin/env python3

#!/usr/bin/env python3
import serial
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime

if __name__ == '__main__':
    ser = serial.Serial('COM3', 9600, timeout=1)
    ser.flush()
    
    dataPoints = 0
    dataDict = {}
    while dataPoints <= 10:
        if ser.in_waiting > 0:
            now = datetime.now()
            current_time = now.strftime("%H:%M:%S")
            print("Current Time =", current_time)
            line = ser.readline().decode('utf-8').rstrip()
            dataDict[current_time] = line
            print(line)
            dataPoints += 1

    times = list(dataDict.keys())
    temps = list(np.array(list(dataDict.values())).astype(float))

    Data = {'Time': times,
            'Temperature': temps
           }
    
    df = pd.DataFrame(Data,columns=['Time', 'Temperature'])
    plt.plot(df['Time'], df['Temperature'], color='red', marker='o')
    plt.title('Temperature of my work room', fontsize=14)
    plt.xlabel('Time', fontsize=14)
    plt.ylabel('Temperature (Celsius)', fontsize=14)
    plt.grid(True)
    plt.show()

    

            