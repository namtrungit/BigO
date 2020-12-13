def check_array_valid(array):
    a = len(set(array))
    return a == 9
def check(a):
    test_array = []
    for i in range(0, 3):
        for j in range(0, 3):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    test_array = []
    for i in range(0, 3):
        for j in range(3, 6):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    test_array = []
    for i in range(0, 3):
        for j in range(6, 9):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False

    test_array = []
    for i in range(3, 6):
        for j in range(0, 3):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    test_array = []
    for i in range(3, 6):
        for j in range(3, 6):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    test_array = []
    for i in range(3, 6):
        for j in range(6, 9):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False

    test_array = []
    for i in range(6, 9):
        for j in range(0, 3):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    test_array = []
    for i in range(6, 9):
        for j in range(3, 6):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    test_array = []
    for i in range(6, 9):
        for j in range(6, 9):
            test_array.append(a[i][j])
    if not(check_array_valid(test_array)): return False
    return True
def main():
    a = []
    for i in range(9):
        row = list(map(int, input().split()))
        a.append(row)
    ans = check(a)
    if(ans):
        print('YES')
    else:
        print('NO')

main()
