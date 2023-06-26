n, a, b, k = map(int,input().split())
hli = map(int,input().split())
 
use = []
for h in hli:
    m = h%(a+b)
    if (m == 0):
        m = a+b
    if (m <= a):
        use.append(0)
    else:
        use.append((m-a-1)//a+1)
use.sort()
 
kills = 0
for u in use:
    if (u <= k):
        kills += 1
        k -= u
    else:
        break
 
print(kills)