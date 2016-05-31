#-*- coding:utf8 -*-
import pandas as pd
import csv
import numpy as np

csvfile = file('input2.csv','rb')
reader = csv.reader(csvfile,delimiter=',')

xh = [0 for i in range(700)]
num = 0
for list in reader:
    for each in list:
        xh[int(each)] = num
        num+=1

data = pd.read_excel('input.xlsx')

data = data.loc[:,['SP_SN','Family_O','Feature_S']]

print('读完了!')

up = 0
num = 0
arr = []
for each in range(1,len(data)):
    eachList = data.iloc[each]
    num = eachList['SP_SN']
    if num != up:
        # print (num,' ',each,' ',xh[num])
        arr.append(each)
    up = num

arr.append(len(data)+1)

for each in range(1,len(arr)):
    pieces = [data[arr[each - 1]:arr[each] -1 ]]
    nowData = pd.concat(pieces)
    num1 = xh[data.iloc[arr[each - 1]]['SP_SN']]
    num2 = data.iloc[arr[each - 1]]['SP_SN']
    if (num1 != 0 or (num1 == 0 and num2 == 414)):
        filename = str(num1) + '.csv'
        nowData.to_csv(filename,sheet_name='Sheet1')