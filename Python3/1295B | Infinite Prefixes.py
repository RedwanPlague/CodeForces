T = int(input())
for cs in range(T):
    n, x = map(int,input().split())
    s = input()
 
    p = [0]
    for i in range(n):
        p.append( p[i] + (1 if s[i] == '0' else -1) )
 
    if (p[n] == 0):
        cnt = 0
        for i in range(n):
            if (p[i] == x):
                cnt = -1
                break
        print(cnt)
    else:      
        cnt = 0
        for i in range(n):
            if ((x-p[i])%p[n] == 0 and (x-p[i])/p[n] >= 0):
                cnt += 1
        print(cnt)