
def is_prime(n):
    count = 0
    if(n < 2): return False
    for i in range(2, n):
        if(n%i==0): count+=1
    return (count == 0)

def main():
    m = int(input())
    a = []
    for i in range(m):
        row = list(map(int, input().split()))
        a.append(row)
    count_prime = 0
    for i in range(m):
        if(is_prime(a[i][i])): count_prime+=1
    print(count_prime)

main()
