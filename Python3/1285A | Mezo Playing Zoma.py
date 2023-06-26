n = int(input())
s = input()
l = 0
r = 0
for i in range(n):
    if(s[i] == 'L'):
        l += 1
    else:
        r += 1
print(l+r+1)