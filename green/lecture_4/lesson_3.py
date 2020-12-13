# Rut gon phan so
# tim UCLN(GCD - Greatest Common Divisor)
def main():
    a, b = map(int, input().split())
    gcd = find_gcd(a, b)
    print("{0} {1}".format(int(a/gcd), int(b/gcd)))

def find_gcd(a, b):
    while(a != b):
        if(a < b): b -= a
        if(a > b): a -= b
    return a

main()
