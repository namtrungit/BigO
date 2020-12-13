# Tim so nguyen to
import math
n = int(input())
count = 0
if(n == 1): print("NO")
elif(n == 2 or n == 3): print("YES")
else:
    for i in range(2, int(math.sqrt(n))+2):
        if(n % i == 0): count+=1
    if(count == 0):
        print("YES")
    else:
        print("NO")
