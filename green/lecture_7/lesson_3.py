import re
string = input()
string = string.strip()
string = re.sub(r"\s{2,}", " ", string)
print(string)
