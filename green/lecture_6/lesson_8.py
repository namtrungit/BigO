def check_queen(a, m, vt_dong, vt_cot):
    # check dong, check cot
    for i in range(m):
        if(a[vt_dong][i] > a[vt_dong][vt_cot]): return False
        if(a[i][vt_cot] > a[vt_dong][vt_cot]): return False

    # Cheo chinh, huong len
    k = 1
    i = vt_dong
    j = vt_cot
    while(i-k >= 0 and j-k>=0):
        if(a[i-k][j-k] > a[vt_dong][vt_cot]): return False
        k+=1
    # Cheo chinh, huong xuong
    k = 1
    while(i+k < m and j+k < m):
        if(a[i+k][j+k] > a[vt_dong][vt_cot]): return False
        k+=1
    # Cheo phu, huong len
    k = 1
    while(i-k >= 0 and j+k < m):
        if(a[i-k][j+k] > a[vt_dong][vt_cot]): return False
        k+=1
    # Cheo phu, huong xuong
    k = 1
    while(j-k >= 0 and i+k < m):
        if(a[i+k][j-k] > a[vt_dong][vt_cot]): return False
        k+=1

    return True        

def main():
    m = int(input())
    a = []
    count = 0
    for i in range(m):
        row = list(map(int, input().split()))
        a.append(row)
    for i in range(m):
        for j in range(m):
            if(check_queen(a, m, i, j)):
                #print(a[i][j])
                count+=1
    print(count)
main()

