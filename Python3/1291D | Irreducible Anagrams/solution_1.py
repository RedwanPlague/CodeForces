ALPHA = 26
 
def unique(cnt, l, r):
    sum = 0
    for a,b in zip(cnt[l-1],cnt[r]):
        sum += a < b
    return sum
 
s = tuple(map(lambda c: ord(c)-ord('a'),tuple(input())))
cnt = [[0 for j in range(ALPHA)]]
for i in range(len(s)):
    cnt.append(list(cnt[i]))
    cnt[i+1][s[i]] += 1
 
n = int(input())
for i in range(n):
    l, r = map(int,input().split())
    if (l == r or s[l-1] != s[r-1] or unique(cnt,l,r) >= 3):
        print("Yes")
    else:
        print("No")