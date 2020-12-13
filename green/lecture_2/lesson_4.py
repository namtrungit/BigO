a, b = map(int, input().split())
c = int(input())
lucky_a = c % a == 0
lucky_b = c % b == 0
if(lucky_a and lucky_b):
    print("Both")
elif(lucky_a):
    print("Upan")
elif(lucky_b):
    print("Ipan")
else:
    print("No")
