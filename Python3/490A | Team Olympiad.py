n = int(input())
i  = 1
l = [[],[],[]]
countL = [0,0,0]
for x in input().split():
    x = int(x)-1
    l[x].append(i)
    countL[x] += 1
    i += 1
w = min(countL)
print(w)
for i in range(w):
    print(l[0].pop(),l[1].pop(),l[2].pop())