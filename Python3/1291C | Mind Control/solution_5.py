T = int(input())
for cs in range(T):
    n, m, k = map(int,input().split())
    a = tuple(map(int,input().split()))
    k = min(k,m-1) # i only need to persuade infront of me
    p = m-k
    mx = 0
    for dummy in range(10):
        for i in range(k+1):
            mn = 1000000007
            for j in range(p):
                mn = min(mn,max(a[i+j],a[n-k+i-p+j]))
            mx = max(mx,mn)
    print(mx)