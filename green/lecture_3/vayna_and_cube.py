
cubes = int(input())
sum = 0
n = 1
while(1 < 2):
    if(sum >= cubes): break
    sum = 0
    for x in range(1, n+1):
        sum_y = 0
        for y in range(1, x+1):
            sum_y += y
        sum += sum_y
    n+=1
result = sum <= cubes and n-1 or n-2
print(result)
