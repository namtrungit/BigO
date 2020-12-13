# Chau hoa
i = int(input())
old_i = 0
valid = True
while(i != 0):
    if(i == 0): break
    if(old_i > i): valid = False
    old_i = i
    i = int(input())
    
if(valid): print("YES") 
else: print("NO")
