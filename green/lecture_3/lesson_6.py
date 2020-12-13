# Chia keo
n = int(input())
is_devide_for_2 = True
for i in range(1, n+1):
   candies = int(input()) 
   if(candies % 2 != 0): 
       is_devide_for_2 = False
if(is_devide_for_2):
    print("YES")
else:
    print("NO")
