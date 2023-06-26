n = int(input())
mwin = cwin = 0
for i in range(n):
    m, c = input().split()
    m, c = int(m), int(c)
    if m>c:
        mwin += 1
    elif c>m:
        cwin += 1
if mwin>cwin:
    print("Mishka")
elif cwin>mwin:
    print("Chris")
else:
    print("Friendship is magic!^^")