def is_max_in_row(row, n):
    is_max = True
    for i in row:
        if(n < i): is_max = False
    return is_max

def main():
    m, n = map(int, input().split())
    a = []
    count = 0
    for i in range(m):
        row = list(map(int, input().split()))
        a.append(row)
    for i in range(m):
        for j in range(n):
            if(is_max_in_row(a[i], a[i][j])):
                min = a[i][j]
                for k in range(m):
                    if(min > a[k][j]): min = a[k][j]
                if(min == a[i][j]): count+=1
    print(count)
                    
main()
