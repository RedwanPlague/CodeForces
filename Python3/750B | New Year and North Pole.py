n = int(input())
dn = 0
valid = "YES"
for i in range(n):
    d,s = input().split()
    d = int(d)
    if (s=="North"):
        if(d>dn):
            valid = "NO"
        else:
            dn = dn-d
    elif (s=="South"):
        if(d+dn>20000):
            valid = "NO"
        else:
            dn = dn+d
    elif(dn==0 or dn==20000):
            valid = "NO"
if (dn!=0):
    valid = "NO"
print(valid)