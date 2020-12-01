#!/usr/bin/python3
import os
import time
cwd = os.path.dirname(__file__)
with open(os.path.join(cwd,'input.txt'), 'r') as file:
    numbers = [int(num) for num in file.read().splitlines()] 

startTime = time.time()
for number in numbers:
    look_for = 2020-number
    if look_for in numbers:
        print(f'({number}, {look_for})')
        print(number*look_for)
        break
runTime = time.time()-startTime


startTime = time.time()
i = 0
for number in numbers:
    i+=1
    look_for = 2020-number
    if look_for in numbers[i:]:
        print(f'({number}, {look_for})')
        print(number*look_for)
        break
runTime2 = time.time()-startTime

print(f'Run time: {runTime}\nRun time 2: {runTime2}')
