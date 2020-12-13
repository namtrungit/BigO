def main():
    n = int(input())
    array = list(map(int, input().split()))
    array.sort()
    first_number = array[0]
    for i in array:
        if(first_number < i): break; 
        first_number+=1
    print(first_number)
main()
