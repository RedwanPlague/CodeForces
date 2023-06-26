MOD = 1000000007
 
n, m = map(int, input().split())
 
cur = [1 for i in range(m+n)] # cur[i] will eventually hold C(i,m)
 
for i in range(1,m):
    prev = cur[i-1]
    cur[i-1] = 0
    for j in range(i,m+n):
        prev, cur[j] = cur[j], prev + cur[j-1]
 
prev = [cur[i] for i in range(m+n)] # prev[i] holds C(i,m-1)
cur[m-1] = 0
for i in range(m,m+n):
    cur[i] = cur[i-1] + prev[i-1]
 
sum = 0
for i in range(1,n+1):
    sum += prev[m+i-2]*cur[m+n-i]
 
print(sum % MOD)