import sys
sys.setrecursionlimit(10000)
n = int(input())
def count_number(n, count):
    if(n <= 0):
        return count
    return count_number(n//10, count+1)
    
print(count_number(n, 0))
