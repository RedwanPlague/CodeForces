n = int(input())
 
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
 
b = sorted(b)
 
if(sum(a) <= b[-1] + b[-2]):
    print("YES")
else:
    print("NO")