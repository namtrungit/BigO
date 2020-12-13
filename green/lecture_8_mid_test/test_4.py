n = int(input())
count = 0
array = []
for i in range(0, n):
    array.append(input())

for i in range(0, n-1):
    if(array[i] == array[i+1]): count+=1
print(count)

