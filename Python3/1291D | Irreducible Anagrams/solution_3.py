ALPHA = 26
 
def unique(cnt, l, r):
    sum = 0
    for a,b in zip(cnt[l-1],cnt[r]):
        sum += a < b
    return sum
 
s = list(map(lambda c: ord(c)-ord('a'),list(input())))
cnt = [[] for i in range(len(s)+1)]
cnt[0] = [0 for j in range(ALPHA)]
for i in range(len(s)):
    cnt[i+1] = cnt[i].copy()
    cnt[i+1][s[i]] += 1
 
n = int(input())
for i in range(n):
    l, r = map(int,input().split())
    if (l == r or s[l-1] != s[r-1] or unique(cnt,l,r) >= 3):
        print("Yes")
    else:
        print("No")