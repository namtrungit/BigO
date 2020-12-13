def find_length(n):
    count = 0
    i = 1
    while(n > 0):
        count+=1
        n = n//10
    return count

def build_index(length):
    index = length//2
    if(length%2 == 0):
        return index, index
    else:
        return index+1, index
    
def main():
    n = int(input())
    length = find_length(n)
    if(length < 2):
        print('YES')
    else:
        index_a, index_b = build_index(length)
        a = n
        clone_n = n
        b = ""
        for i in range(0, index_a):
            a = a//10
        for i in range(0, index_b):
            b += str(clone_n%10)
            clone_n = clone_n//10
        if(str(a) == b):
            print('YES')
        else:
            print('NO')

main()
