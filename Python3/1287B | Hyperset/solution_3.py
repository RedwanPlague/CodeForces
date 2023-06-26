class Trie:
 
    def __init__(self, N):
        self.N = N
        self.tree = [[-1,-1,-1,False]]
 
    def add(self, s):
        tree = self.tree
        cur = 0
        for i in range(self.N):
            if (tree[cur][s[i]] == -1):
                tree.append([-1,-1,-1,False])
                tree[cur][s[i]] = len(tree)-1
            cur = tree[cur][s[i]]
        tree[cur][3] = True
 
    def count(self, s):
        tree = self.tree
        cur = 0
        for i in range(self.N):
            if (tree[cur][s[i]] == -1):
                return 0
            cur = tree[cur][s[i]]
        return tree[cur][3]
 
 
# returns the string that can be matched with a,b
def match(a, b):
    return [a[i] if a[i] == b[i] else 3-a[i]-b[i] for i in range(len(a))]
 
 
def change(s):
    return [0 if s[i] == 'S' else (1 if s[i] == 'E' else 2) for i in range(len(s))]
 
 
n, k = map(int,input().split())
s = [change(input()) for i in range(n)]
 
trie = Trie(k)
for i in range(n):
    trie.add(s[i])
 
cnt = 0
for i in range(n):
    for j in range(i+1,n):
        m = match(s[i],s[j])
        cnt += trie.count(m)
print(cnt//3)