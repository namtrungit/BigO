n = int(input())
post_no_like = 0
array = list(map(int, input().split()))
for i in array:
    if(i==0): post_no_like+=1

if(post_no_like == 0):
    print('YES')
else:
    print('NO')
