n = int(input())
array_string = []
for i in range(0, n):
    string = list(input())
    for i in range(0, len(string)):
        if(i == 0):
            string[i] = string[i].upper()
        else:
            if(string[i-1] == ' '):
                string[i] = string[i].upper()   
            else:
                string[i] =  string[i].lower() 
    array_string.append("".join(string))
for i in array_string:
    print(i)

