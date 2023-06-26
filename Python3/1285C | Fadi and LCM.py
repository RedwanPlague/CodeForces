MX = 1000000
prime = [2] 
 
 
def sieve():
    mark = [True for i in range(MX)]
    for i in range(3,MX,2):
        if (mark[i]):
            prime.append(i)
        if (i < 1000):
            for j in range(i*i,MX,i):
                mark[j] = False
 
 
sieve()
x = int(input())
 
temp = x
fact = []
for i in range(len(prime)):
    if (temp % prime[i] == 0):
        mul = 1
        while (temp % prime[i] == 0):
            temp //= prime[i]
            mul *= prime[i]
        fact.append(mul)
if (temp > 1):
    fact.append(temp)
 
mx = x
mx_a = 1
mx_b = x
lim = 1 << len(fact)
for mask in range(lim):
    a = 1
    for i in range(len(fact)):
        if (mask & (1 << i)):
            a *= fact[i]
    b = x//a
    if(max(a,b) < mx):
        mx = max(a,b)
        mx_a = a
        mx_b = b
 
print("{} {}".format(mx_a,mx_b))