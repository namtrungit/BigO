def main():
    m, n = map(int, input().split())
    a, b, p = map(int, input().split()) 
    c = (a+b)%p
    old_val = b
    array = [[a, b, c]]
    while(len(array[0]) < n):
        new_value = (c+old_val)%p
        array[0].append(new_value)
        old_val = c
        c = new_value
    for i in range(1, m):
        temp = []
        for j in range(n):
            new_value = (c+old_val)%p
            temp.append(new_value)
            old_val = c
            c = new_value
        array.append(temp)

    for i in range(m):
        for j in range(n):
            print(array[i][j], end=" ")
        print(  )
        
main()
