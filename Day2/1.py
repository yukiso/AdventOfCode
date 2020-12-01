#!/usr/bin/python3
import os
import time

file_name = 'input.txt'
cwd = os.path.dirname(__file__)
file_path = os.path.join(cwd, file_name)

with open(file_path, 'r') as file:
    inputs = file.read().splitlines()



def solve(inputs) -> None:
    return






startTime = time.time()

solve(inputs)

runTime = time.time()-startTime


try:
    print(f'Score: {1//runTime}')
except ZeroDivisionError:
    pass
