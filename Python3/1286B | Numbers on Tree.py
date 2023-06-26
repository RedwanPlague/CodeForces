class ordered_set:
 
    def __init__(self, N):
        self.N = N+1
        self.tree = [0 for i in range(self.N)]
 
    def add(self, idx):
        while (idx < self.N):
            self.tree[idx] += 1
            idx += (idx & -idx)
 
    def remove(self, idx):
        while (idx < self.N):
            self.tree[idx] -= 1
            idx += (idx & -idx)
 
    def find_by_order(self, k):
        k -= 1
        idx = 0
        mask = 1
 
        while ((mask<<1) < self.N):
            mask <<= 1
 
        while (mask):
            ti = idx + mask
            mask >>= 1
            if (ti < self.N):
                if (k >= self.tree[ti]):
                    idx = ti
                    k -= self.tree[ti]
 
        if (k != 0):
            return -1
        return idx+1
 
 
def subtree_size(cur, adj, size):
    size[cur] = 1
    for v in adj[cur]:
        if (size[v] == 0):
            subtree_size(v, adj, size)
            size[cur] += size[v]
 
 
def fill(cur, adj, ost, c, a):
    a[cur] = ost.find_by_order(c[cur]+1)
    ost.remove(a[cur])
    for v in adj[cur]:
        if (a[v] == 0):
            fill(v, adj, ost, c, a)
 
 
n = int(input())
adj = [[] for i in range(n+1)]
c = [0]
for i in range(1,n+1):
    p, ct = map(int,input().split())
    adj[p].append(i)
    c.append(ct)
 
size = [0 for i in range(n+1)]
subtree_size(adj[0][0], adj, size)
 
ok = True
for i in range(1,n+1):
    if (c[i] >= size[i]):
        ok = False
        break
 
if not ok:
    print("NO")
else:
    ost = ordered_set(n)
    for i in range(1,n+1):
        ost.add(i)
 
    a = [0 for i in range(n+1)]
    fill(adj[0][0], adj, ost, c, a)
 
    print("YES")
    for i in range(1,n+1):
        print(a[i], end=' ')
    print()