n = int(input())
if( n < 6 ):
    print(1)
else:
    if(n % 10 == 0 or n % 5 == 0):
        print(int(n/5))
    else:
        print(int(n/5) + 1)
