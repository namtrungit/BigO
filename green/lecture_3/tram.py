n = int(input())
max = 0
old_sit = 0
for i in range(0, n):
    out, arrive = map(int, input().split())
    current_sit = old_sit - out + arrive
    old_sit = current_sit
    if(max < current_sit): max = current_sit
print(max)
