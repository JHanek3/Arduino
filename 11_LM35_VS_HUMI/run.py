#!/usr/bin/env python3

#!/usr/bin/env python3
import serial
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime

if __name__ == '__main__':
  ser = serial.Serial('COM3', 115200, timeout=1)
  ser.flush()

  dataPoints = 1
  dataDict = {}
  
  while dataPoints <= 10:
    if ser.in_waiting > 0:
      now = datetime.now()
      current_time = now.strftime("%H:%M:%S")
      # print("Current Time =", current_time)
      line = ser.readline().decode('utf-8').rstrip()
      val_array = line.split(" ")
      val_array = list(np.float_(val_array))
      dataDict[current_time] = val_array
      print("Datapoint {} collected".format(dataPoints))
      dataPoints += 1  
  
  times = list(dataDict.keys())
  lm35 = []
  humi = []
  humidity = []
  
  for value in dataDict.values():
    lm35.append(value[0])
    humi.append(value[1])
    humidity.append(value[2])

  
  Data = {
            'Time': times,
            'lm35': lm35,
            'humi': humi,
            'humidity': humidity
        }
  plot1 = plt.figure(1)
  df = pd.DataFrame(Data,columns=['Time', 'lm35', 'humi'])
  plt.plot(df['Time'], df['lm35'], color='red', marker='o', label="LM35")
  plt.plot(df['Time'], df['humi'], color='blue', marker='o', label="HUMI-01")
  plt.title('LM35 vs. HUMI-01 Temperature Readings', fontsize=14)
  plt.xlabel('Time', fontsize=14)
  plt.ylabel('Temperature (Celsius)', fontsize=14)
  plt.xticks(rotation=90)
  plt.grid(True)
  plt.legend()

  plot2 = plt.figure(2)
  df = pd.DataFrame(Data,columns=['Time', 'humidity'])
  plt.plot(df['Time'], df['humidity'], color='red', marker='o')
  plt.title('Humidity Readings by HUMI-01', fontsize=14)
  plt.xlabel('Time', fontsize=14)
  plt.ylabel('Humidity %', fontsize=14)
  plt.xticks(rotation=90)
  plt.grid(True)
  
  plt.show()






    

            