# Count sl chu so
def main():
    n = int(input())
    count = 0
    while(n > 0):
        if(n/10 > 0):
            count += 1
            n = int(n/10)
    print(count)
            
main()
