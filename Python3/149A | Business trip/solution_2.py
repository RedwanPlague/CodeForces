k = int(input())
l = []
for x in input().split():
    l.append(int(x))
l.sort(reverse=True)
#print(l)
i = 0
for x in l:
    if k<=0:
        break
    k -= x
    i += 1
if k>0:
    i = -1
print(i)