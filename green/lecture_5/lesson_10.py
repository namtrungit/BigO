def main():
    n = int(input())
    array = list(map(int, input().split()))
    count = 0
    for i in range(1, len(array)):
        print(count)
        if(count > 3):
            print('NO')
            break
        if(array[i] == 1):
            count = 0
        else:
            count += 1
        
main()
