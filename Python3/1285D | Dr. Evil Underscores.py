DIG = 29
 
def build_xor_tree(a, n):
    tree = [[-1,-1]] 
    for i in range(n):
        cur = 0
        for pos in range(DIG,-1,-1):
            if (a[i] & (1 << pos)):
                if (tree[cur][1] == -1):
                    tree.append([-1,-1])
                    tree[cur][1] = len(tree)-1
                cur = tree[cur][1]
            else:
                if (tree[cur][0] == -1):
                    tree.append([-1,-1])
                    tree[cur][0] = len(tree)-1
                cur = tree[cur][0]
    return tree
 
 
# returns True if such an X can be found so that max(a[i]^X) <= x 
def possible(tree, cur, x, pos): 
    if (pos < 0):
        return True
    if (cur == -1):
        return False
    if (x & (1 << pos)):
        return possible(tree, tree[cur][0], x, pos-1) or possible(tree, tree[cur][1], x, pos-1)
    if (tree[cur][0] != -1 and tree[cur][1] != -1):
        return False
    if (tree[cur][0] != -1):
        return possible(tree, tree[cur][0], x, pos-1)
    return possible(tree, tree[cur][1], x, pos-1)
 
 
n = int(input())
a = list(map(int,input().split()))
 
tree = build_xor_tree(a,n)
 
lo = 0
hi = (1<<(DIG+1))-1;
while (lo < hi-1):
    mid = (lo+hi)//2
    if(possible(tree,0,mid,DIG)):
        hi = mid
    else:
        lo = mid+1
 
if (possible(tree,0,lo,DIG)):
    print(lo)
else:
    print(hi)