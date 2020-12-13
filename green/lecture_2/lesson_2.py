a, b = map(float, input().split())
c = ( a > 0 ) and 1 or 2
d = ( b > 0 ) and 1 or 2
print(c == d and "YES" or "NO")
