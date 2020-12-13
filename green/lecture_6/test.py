a1 = [1]
a2 = [1, 2]
a3 = [1, 2, 3]
a4 = [1, 2, 3, 4]

a = [a1, a2, a3, a4]
# cach duyet array 2 chieu
for i in range(len(a)):
    for j in range(len(a[i])):
        print(a[i][j], end=" ")
    print(  )
