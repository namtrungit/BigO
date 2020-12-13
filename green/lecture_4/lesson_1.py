# Sum prime number
import math

def main():
    n = int(input())
    sum_prime = 0
    for i in range(1, n):
        if(is_prime(i)): sum_prime += i
    print(sum_prime)

def is_prime(n):
    count = 0
    if(n < 2): return False
    for i in range(2, n):
        if(n%i == 0):
            count+=1
    return count == 0

main()
