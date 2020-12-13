
def main():
    n = int(input())
    array = []
    for i in range(0, n):
        array.append(list(map(int, input().split())))
    i = 1
    fruit = array[0]
    fruit_index = 0
    while(i < n):
        if(fruit[0] < array[i][0]):
            fruit = array[i]
            fruit_index = i
        elif(fruit[0] == array[i][0] and fruit[1] < array[i][1]):
            fruit = array[i]
            fruit_index = i
        i+=1
    print(fruit_index+1)
main()
