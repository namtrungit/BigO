n = int(input())
for i in range(1, n+1):
    if(i == 1): 
        for x in range(0, n):
            print('*', end = '')
        print('')
    elif(i == n): 
        for x in range(0, n):
            print('*', end = '')
    else:
        for y in range(1, n+1):
            if(y == 1 or y == n):
                print('*', end = '')
            else:
                print(' ', end = '')
        print('')
        
