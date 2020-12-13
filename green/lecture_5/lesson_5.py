def is_prime(n):
    count = 0
    if(n <= 1): return False
    for i in range(2, n):
        if(n%i==0): count+=1
    return (count==0) and True or False

def main():
    n = int(input())
    count = 0
    array = list(map(int, input().split()))
    for i in array:
        if(is_prime(i)):
            count += 1
    print(count)
main()
