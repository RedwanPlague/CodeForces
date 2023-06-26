ALPHA = 26
 
def offset(c):
    return ord(c) - ord('a')
 
T = int(input())
for cs in range(T):
    s = list(map(offset,list(input())))
    t = list(map(offset,list(input())))
    ls = len(s)
 
    nxt = [[-1 for j in range(ALPHA)] for i in range(ls)] # nxt[i][c] = first position in [i,len(s)] that has character c
    nxt[ls-1][s[ls-1]] = ls-1
    for i in range(ls-2,-1,-1):
        for j in range(ALPHA):
            nxt[i][j] = nxt[i+1][j]
        nxt[i][s[i]] = i
 
    cnt = 1
    cur = 0
    for c in t:
        if (cur >= ls):
            cur = 0
            cnt += 1
        if (nxt[cur][c] == -1):
            cur = 0
            cnt += 1
        if (nxt[cur][c] == -1):
            cnt = -1
            break
        cur = nxt[cur][c]+1
    
    print(cnt)
    