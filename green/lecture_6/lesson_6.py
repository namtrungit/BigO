
def main():
    m, n = map(int, input().split())
    a = []
    for i in range(m):
        row = list(map(int, input().split()))
        a.append(row)

    row = 0
    total = 0
    for i in range(m):
        count_even = 0
        for j in range(n):
            if(a[i][j]%2 == 0): count_even += 1
        if(count_even > total):
            row = i
            total = count_even
    print(row)
main()
