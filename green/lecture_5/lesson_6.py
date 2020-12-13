def find_min(array):
    min = array[0]
    for i in array:
        if(i < min): min = i
    return min

def main():
    n = int(input())
    array = list(map(int, input().split()))
    min = find_min(array)
    point = 0
    for i in array:
        if(i > min): point += i-min
    print(point)

main()
