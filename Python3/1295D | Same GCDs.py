from math import gcd
 
MX = 100000
 
prime = [2]
def sieve():
    mark = [True for i in range(MX)]
    for i in range(3,MX,2):
        if (mark[i]):
            prime.append(i)
            for j in range(i*i,MX,i):
                mark[j] = False
 
def phi(N):
    ph = N
    for p in prime:
        if (N%p == 0):
            ph //= p
            ph *= p-1
            while (N%p == 0):
                N //= p
    if (N > 1):
        ph //= N
        ph *= N-1
    return ph
        
sieve()
T = int(input())
for cs in range(T):
    a, m = map(int,input().split())
    print(phi(m//gcd(a,m)))