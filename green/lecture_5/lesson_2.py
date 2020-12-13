n = int(input())
max = 0
array = list(map(int, input().split()))
for i in array:
    if(max < i): max = i

print(max)
