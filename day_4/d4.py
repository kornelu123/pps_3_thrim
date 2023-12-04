import math

f = open("input", "r")

sum = 0

for i in f.readlines():
    temp_sum = 1
    nums = i.split('|')
    win_nums = nums[0].split(':')[1]
    shots = nums[1]
    for num in win_nums:


