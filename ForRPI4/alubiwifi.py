'''import requests
import base64
import json 
import time


def put_wireless(ssid, passwd):
    headers={'Content-Type' : 'application/json; charset=UTF-8'}
    d = { 
        "ssid": ssid, 
        "passwd": passwd 
        }
    
    url ='http://192.168.12.1:8080/wireless' 

    res=requests.put(url, data=json.dumps(d), headers=headers) 
    
    print (res)

#put_wireless ("raspberryPi4", "raspberrypi") 

put_wireless("IsraIMUs", "isra")

'''
import requests
import base64
import json
import time


def put_wireless(ssid, passwd):


    headers = {'Content-Type': 'application/json;charset=UTF-8'}
    d = {
        "ssid": ssid,
        "passwd": passwd
    }
    url = 'http://192.168.12.1:8080/wireless'
    res = requests.put(url, data=json.dumps(d), headers=headers)
    print(res)

put_wireless("IsraIMUs","isra" )
