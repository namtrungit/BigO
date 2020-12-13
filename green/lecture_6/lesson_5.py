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
    prime_list = []
    for i in range(m):
        if(is_prime(a[i][m-1-i])):
            prime_list.append(a[i][m-1-i])
    if(len(prime_list) > 0):
        total = 1
        for i in prime_list:
            total = int(total*i)
        print(total)
    else:
        print(1)
main()
