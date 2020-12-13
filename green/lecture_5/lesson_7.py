def count_value(value, array):
    count = 0
    for i in array:
        if(i == value): count+=1
    return count

def main():
    n = int(input())
    array = list(map(int, input().split()))
    male = count_value(0, array)
    female = count_value(1, array)
    if(male == female):
        print('YES')
    else:
        print('NO')

main()
