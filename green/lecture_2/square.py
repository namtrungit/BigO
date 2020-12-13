m = int(input())
n = int(input())
a = int(input())
height = (m % a == 0) and m/a or m/a+1
width = (n % a == 0) and n/a or n/a+1
print(int(height)*int(width))
