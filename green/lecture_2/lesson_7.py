a, b = map(float, input().split())
c = b - a
if(c <= 50):
    price = c * 1484
    print("{0}".format(int(price + price * 0.1)))
elif(c <= 100 and c > 50):
    el =  c - 50
    price = 50 * 1484 
    price += el * 1533
    print("{0}".format(int(price + price * 0.1)))
elif(c <= 200 and c > 100):
    el =  c - 100
    price = 50 * 1484 
    price += 50 * 1533
    price += el * 1786
    print("{0}".format(int(price + price * 0.1)))
elif(c <= 300 and c > 200):
    el =  c - 200
    price = 50 * 1484 
    price += 50 * 1533
    price += 100 * 1786
    price += el * 2242
    print("{0}".format(int(price + price * 0.1)))
elif(c <= 400 and c > 300):
    el =  c - 300
    price = 50 * 1484 
    price += 50 * 1533
    price += 100 * 1786
    price += 100 * 2242
    price += el * 2503
    print("{0}".format(int(price + price * 0.1)))
else:
    el =  c - 400
    price = 50 * 1484 
    price += 50 * 1533
    price += 100 * 1786
    price += 100 * 2242
    price += 100 * 2503
    price += el * 2587
    print("{0}".format(int(price + price * 0.1)))

