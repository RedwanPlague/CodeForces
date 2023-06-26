T = int(input())
 
for cs in range(T):
 
    n = int(input())
    a = list(map(int,input().split()))
 
    tot = sum(a)
    mx = 0
    
    cur = 0
    for i in range(n-1):
        cur += a[i]
        if(cur < 0):
            cur = 0
        mx = max(mx,cur)
    
    cur = 0
    for i in range(1,n):
        cur += a[i]
        if(cur < 0):
            cur = 0
        mx = max(mx,cur)
    
    if(tot > mx):
        print("YES")
    else:
        print("NO")