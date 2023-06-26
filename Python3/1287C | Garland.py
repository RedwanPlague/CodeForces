INF = 1000
 
def mod2(a, n):
    even, odd = 0, 0
    for i in range(n):
        if (a[i] == 0):
            a[i] = -1
        elif (a[i]&1):
            a[i] = 1
            odd += 1
        else:
            a[i] = 0
            even += 1
    even = n//2 - even
    odd = (n-1)//2 + 1 - odd
    return even, odd
 
 
def minc(i, e, o, l):
    if (i >= n):
        return 0
 
    cur = dp[i][e][o][l]
    if (cur != -1):
        return cur
    
    if (a[i] == 0):
        cur = (0^l) + minc(i+1,e,o,0)
    elif (a[i] == 1):
        cur = (1^l) + minc(i+1,e,o,1)
    else:
        cur = INF
        if (e > 0):
            cur = min(cur, (0^l) + minc(i+1,e-1,o,0))
        if (o > 0):
            cur = min(cur, (1^l) + minc(i+1,e,o-1,1))
    
    dp[i][e][o][l] = cur
    return cur
    
 
n = int(input())
a = list(map(int,input().split()))
 
even, odd = mod2(a, n)
dp = [[[[-1 for i0 in range(2)] for i1 in range(odd+1)] for i2 in range(even+1)] for i3 in range(n)]
 
if (a[0] == 0):
    ans = minc(1,even,odd,0)
elif (a[0] == 1):
    ans = minc(1,even,odd,1)
else:
    ans = INF
    if (even > 0):
        ans = min(ans, minc(1,even-1,odd,0))
    if (odd > 0):
        ans = min(ans, minc(1,even,odd-1,1))
print(ans)