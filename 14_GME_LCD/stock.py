#!/usr/bin/python3
import serial
from datetime import datetime
from time import sleep
import requests
import config
import json

# Is the market Open?
marketOpen = False
prePost = False
lastCall = False


if __name__ == "__main__":
    ser = serial.Serial("/dev/ttyUSB1", 9600, timeout=1)
    ser.flush()
    print("running")

    while True:
        now = datetime.now()
        day  = now.weekday()
        # now = now.replace(hour=5, minute=8, second=0)
        # now = now.replace(hour=8, minute=8, second=0)
        # now = now.replace(hour=16, minute=8, second=0)
        # now = now.replace(hour=19, minute=8, second=0)
        preMarketOpenTime = now.replace(hour=6, minute=00, second=0, microsecond=0)
        marketOpenTime = now.replace(hour=8, minute=30, second=0, microsecond=0)
        marketCloseTime = now.replace(hour=15, minute=0, second=0, microsecond=0)
        postMarketCloseTime = now.replace(hour=19, minute=0, second=0, microsecond=0)

        tracker = str(now).split(" ")[1]
        preMarketTracker = str(preMarketOpenTime).split(" ")[1]
        openTracker = str(marketOpenTime).split(" ")[1]
        closeTracker = str(marketCloseTime).split(" ")[1]
        postMarketTracker = str(postMarketCloseTime).split(" ")[1]
        # print(tracker)
        # print(openTracker)
        # print(closeTracker)

        if (preMarketTracker <= tracker <= postMarketTracker and (day != 5 or day != 6)):
            marketOpen = True
            if (preMarketTracker <= tracker < openTracker or closeTracker <= tracker < postMarketTracker):
                prePost = True
            else:
                prePost = False

        # print(marketOpen)

        if (marketOpen):
            if (preMarketTracker <= tracker < openTracker):
                # pre market call, iex cloud allows pre and post market data
                r = requests.get('https://cloud.iexapis.com/stable/stock/GME/quote?token=' + config.apiToken1)
                jsonData = r.json()
                dic = dict(jsonData)
                latestPrice = dic["latestPrice"]
                market = "pre"
                ser.write("{},{}\n".format(latestPrice, market).encode('utf-8'))
                print("{},{}\n".format(latestPrice, market))

            elif (closeTracker <= tracker < postMarketTracker):
                # post market call
                r = requests.get('https://cloud.iexapis.com/stable/stock/GME/quote?token=' + config.apiToken1)
                jsonData = r.json()
                dic = dict(jsonData)
                latestPrice = dic["latestPrice"]
                market = "pos"
                ser.write("{},{}\n".format(latestPrice, market).encode('utf-8'))
                print("{},{}\n".format(latestPrice, market))

            else:
                # Had an error with finnhub, going to try iexcloud and see how this works
                # r = requests.get('https://finnhub.io/api/v1/quote?symbol=GME&token=' + config.apiToken0)
                r = requests.get('https://cloud.iexapis.com/stable/stock/GME/quote?token=' + config.apiToken1)
                jsonData = r.json()
                dic = dict(jsonData)
                # prevCloseStock = round(dic['pc'],2)
                # currentStock = round(dic['c'],2)
                
                prevCloseStock = dic['previousClose']
                currentStock = dic["latestPrice"]
                percentChange = round((currentStock - prevCloseStock) / prevCloseStock * 100,2)
                ser.write("{},{}\n".format(currentStock, percentChange).encode('utf-8'))
                print("{},{}\n".format(currentStock, percentChange))
        
        # I dont need to make more than one api call when market is closed
        else:
            if lastCall == False:
                r = requests.get('https://cloud.iexapis.com/stable/stock/GME/quote?token=' + config.apiToken1)
                jsonData = r.json()
                dic = dict(jsonData)
                latestPrice = dic["latestPrice"]
                market = "close"
                ser.write("{},{}\n".format(latestPrice, market).encode('utf-8'))
                lastCall = True
                prePost = False
            else:
                ser.write("{},{}\n".format(latestPrice, market).encode('utf-8'))
            print("{},{}\n".format(latestPrice, market))
            
        # Unique delays
        if (marketOpen):
            if (prePost):
                # print("Im in prePost")
                sleep(300)
            else:
                # print("Marketopen")
                sleep(60)
        else:
            # print("Marketclosed")
            sleep(300)
    
    