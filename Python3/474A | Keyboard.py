ch = input()
key = "qwertyuiopasdfghjkl;zxcvbnm,./"
s = input()
if ch=="R":
    di = -1
else:
    di = 1
for i in s:
    print(key[key.index(i)+di], end="")
print("")
    