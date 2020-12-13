import sys
sys.setrecursionlimit(10000)
n = int(input())

def uoc_le_lon_nhat(n):
    if(n%2 != 0):
        return n
    return uoc_le_lon_nhat(n//2)

print(uoc_le_lon_nhat(n))
