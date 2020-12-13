def is_prime(n):
    count = 0
    if(n < 2): return False
    for i in range(2, n):
        if(n%i==0): count+=1
    return (count == 0)

def main():
    m, n = map(int, input().split())
    a = []
    for i in range(m):
        row = list(map(int, input().split()))
        a.append(row)
    count = 0
    for i in range(n):
        if(is_prime(a[0][i])): count+=1
        if(is_prime(a[m-1][i])): count+=1
    for i in range(1, m-1):
        if(is_prime(a[i][0])): count+=1
        if(is_prime(a[i][n-1])): count+=1
                
    print(count)
main()

