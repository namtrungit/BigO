#   Sum square number
def main():
    n = int(input())
    sum = 0
    for i in range(1, n+1):
        sum += square_number(i)
    print(sum)
def square_number(n):
    return n**2
main()
