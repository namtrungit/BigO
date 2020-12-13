m, n = map(int, input().split())
a = []
for i in range(m):
    row = list(map(int, input().split()))
    a.append(row)

for j in range(n):
    count = 0
    for i in range(m):
        if(a[i][j] < 0): count+=1
    if(count == m): print(j, end=" ")
