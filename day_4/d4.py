import math

f = open("input", "r")

LINE_COUNT = 220 
copy_count = [1] * LINE_COUNT
copy_count = [1 for i in range(LINE_COUNT)]

sum = 0

line_counter = 0
for i in f.readlines():
    count = 0
    nums = i.split('|')
    win_nums = nums[0].split(':')[1].split(' ')
    shots = nums[1]
    print(win_nums)
    print(shots)
    for num in win_nums:
      if(num == ''):
          continue
      if(shots.find( " " +str(num)+ " ") != -1):
          count += 1
  
    for i in range(1, count+1):
        copy_count[line_counter + i] += copy_count[line_counter]
    
    print(count)
    print(copy_count)

    line_counter += 1

for i in range(0, LINE_COUNT):
    sum += copy_count[i]

print(sum)
