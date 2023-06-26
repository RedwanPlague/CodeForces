from math import sqrt, ceil, floor
#input = raw_input
INF = 1000000007
 
def get_ceil(a, b):
    if(b <= 0):
        return INF
    return (a-1)//b+1
 
T = int(input())
for cs in range(T):
    n, d = map(int, input().split())
    x1 = ceil(sqrt(d))
    x2 = floor(sqrt(d))
    a1 = x1 + get_ceil(d,x1+1)
    a2 = x1-1 + get_ceil(d,x1)
    a3 = x2 + get_ceil(d,x2+1)
    a4 = x2+1 + get_ceil(d,x2+2)
 
    if(a1 <= n or a2 <= n or a3 <= n or a4 <= n):
        print("YES")
    else:
        print("NO")