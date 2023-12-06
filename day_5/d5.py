import math

f = open("input", "r")



nums = f.readline().rstrip().split(':')[1].split(' ')

size = 0
nums.pop(0)
for i,seed in enumerate(nums):
    if(i%2 == 0):
        size += int(seed)

seeds = [0]*size
print(f.readline())

max_size = 0
last_count = 0
count = 0
minim = [0]*100
minim = [float('inf') for i in range(0,100)]
for line in list(f):

    nums = line.split()
    if(line[0].isdigit()):
        for i,seed in enumerate(seeds):
            if(int(seed) >= int(nums[1]) and int(seed) <= int(nums[1]) + int(nums[2])):
                num = int(nums[0]) + (int(seed) - int(nums[1]))
                if(num < minim[int(i)]):
                    minim[int(i)] = num
    else:
        for i,seed in enumerate(seeds):
            if(minim[int(i)] == float('inf')):
                continue
            seeds[int(i)] = minim[int(i)]
        minim = [float('inf') for i in range(0,100)]
for i,seed in enumerate(seeds):
    if(minim[int(i)] == float('inf')):
        continue
    seeds[int(i)] = minim[int(i)]
minim = [float('inf') for i in range(0,100)]
print(min(seeds))
