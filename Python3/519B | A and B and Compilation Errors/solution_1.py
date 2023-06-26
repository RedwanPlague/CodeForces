n = int(input())
li1 = [int(x) for x in input().split()]
li2 = [int(x) for x in input().split()]
 
li1.sort()
li2.sort()
 
for i in range(n-1):
    if li1[i] != li2[i]:
        break
else:
    i += 1
print(li1[i])
del(li1)
 
li3 = [int(x) for x in input().split()]
li3.sort()
 
for i in range(n-2):
    if li2[i] != li3[i]:
        break
else:
    i += 1
print(li2[i])