n = int(input())
price = 0
if(n<1):
    print(0)
if(n == 1):
    print(15000)
if(n > 1 and n <=5):
    price = 15000
    count = n - 1
    price += count*13500
    print(price)
if(n > 6):
    price = 15000
    price += 13500*4
    count = n - 5
    price += count*11000
if(n >= 12):
    price = price-(price*0.1)
    print(int(price))
