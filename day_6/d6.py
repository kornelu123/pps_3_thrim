import math

f = open("input","r")

nums = [0]*2
for i,line in enumerate(f.readlines()):
    nums[i] = ''.join(line.split(":")[1].split())
    print(nums[i])

a = -1
b = int(nums[0])
c = - int(nums[1])

delta_x = pow(b,2) - 4*a*c
x_1 = (-b - math.sqrt(delta_x))/(2*a)
x_2 = (-b + math.sqrt(delta_x))/(2*a)

if(x_1 <= 0):
    x_1 = 1
if(x_2 <= 0):
    x_1 = 1

print(x_1)
print(x_2)

res = math.floor(x_1) - math.floor(x_2)
print(res)
