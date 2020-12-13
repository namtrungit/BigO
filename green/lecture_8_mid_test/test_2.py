n = int(input())

for i in range(1, n+1):
    total = i+(i-1)           
    space = n-i
    for z in reversed(range(1, space+1)):
        print(" ", end="")
    for j in range(1, total+1):
        print('*', end="")
    print(  )

