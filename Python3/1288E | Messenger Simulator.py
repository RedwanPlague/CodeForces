class BIT:
 
    def __init__(self, N):
        self.N = N
        self.tree = [0 for i in range(N)]
    
    def read(self, idx):
        sum = 0
        while (idx > 0):
            sum += self.tree[idx]
            idx -= (idx & -idx)
        return sum
    
    def update(self, idx, val):
        while (idx < self.N):
            self.tree[idx] += val
            idx += (idx & -idx)
 
 
n, m = map(int,input().split())
f = list(map(int,input().split()))
 
bit = BIT(n+m+1)
for i in range(1,n+1):
    bit.update(i,1)
 
last = n+1
mn = [i for i in range(n+1)]
mx = [0 for i in range(n+1)]
pos = [n-i+1 for i in range(n+1)]
for i in range(m):
    mn[f[i]] = 1
    mx[f[i]] = max(mx[f[i]], n-bit.read(pos[f[i]])+1)
    bit.update(pos[f[i]],-1)
    bit.update(last,1)
    pos[f[i]] = last
    last += 1
 
for i in range(1,n+1):
    mx[i] = max(mx[i], n-bit.read(pos[i])+1)
    print("{} {}".format(mn[i], mx[i]))