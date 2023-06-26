# returns the string that can be matched with a,b
def match(a, b, mp):
    c = ''
    for i in range(len(a)):
        if (a[i] == b[i]):
            c += a[i]
        else:
            c += mp[a[i]+b[i]]
    return c
 
 
n, k = map(int,input().split())
s = [input() for i in range(n)]
 
st = set()
for i in range(n):
    st.add(s[i])
 
mp = { 'SE':'T', 'ES':'T', 'ST':'E', 'TS':'E', 'TE':'S', 'ET':'S' }
 
cnt = 0
for i in range(n):
    for j in range(i+1,n):
        m = match(s[i],s[j],mp)
        cnt += (m in st)
print(cnt//3)