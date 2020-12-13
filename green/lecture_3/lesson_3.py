# Max, min
max = 0
i = int(input())
min = i
while(i != -1):
    if(i == -1): break
    if(max < i): max=i
    if(min > i): min=i
    i = int(input())
print("{0} {1}".format(max, min))
