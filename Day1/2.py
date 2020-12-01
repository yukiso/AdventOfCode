#!/usr/bin/python3
import os
import time
cwd = os.path.dirname(__file__)
with open(os.path.join(cwd,'input.txt'), 'r') as file:
    numbers = [int(num) for num in file.read().splitlines()] 

def solve(numbers) -> None:
    for number in numbers:
        for number2 in numbers:
            look_for = 2020-number-number2
            if look_for in numbers:
                print(f'({number}, {number2}, {look_for})')
                print(number*number2*look_for)
                return

def solve2(numbers):
    i, j = 0, 0
    for number in numbers:
        i+=1
        j=i
        for number2 in numbers[i:]:
            j+=1
            look_for = 2020-number-number2
            if look_for in numbers[j:]:
                print(f'({number}, {number2}, {look_for})')
                print(number*number2*look_for)
                return

startTime = time.time()

solve(numbers)

runTime = time.time()-startTime


startTime = time.time()

solve2(numbers)

runTime2 = time.time()-startTime

print(f'Run time: {runTime}\nRun time 2: {runTime2}\n{(runTime/runTime2-1)*100}% imporvement')
