# returns the string that can be matched with a,b
def match(a, b):
    c = ''
    for i in range(len(a)):
        if (a[i] == b[i]):
            c += a[i]
        elif (a[i]+b[i] == 'SE' or a[i]+b[i] == 'ES'):
            c += 'T'
        elif (a[i]+b[i] == 'ST' or a[i]+b[i] == 'TS'):
            c += 'E'
        else:
            c += 'S'
    return c
 
 
n, k = map(int,input().split())
s = [input() for i in range(n)]
 
st = set()
for i in range(n):
    st.add(s[i])
 
cnt = 0
for i in range(n):
    for j in range(i+1,n):
        m = match(s[i],s[j])
        cnt += (m in st)
print(cnt//3)