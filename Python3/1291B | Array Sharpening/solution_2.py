T = int(input())
for cs in range(T):
    n = int(input())
    a = tuple(map(int,input().split()))
 
    left = [True for i in range(n)]
    right = [True for i in range(n)]
    for i in range(1,n):
        left[i] = left[i-1] and (i <= a[i])
        right[n-i-1] = right[n-i] and (i <= a[n-i-1])
    
    found = False
    for i in range(n):
        if left[i] and right[i]:
            found = True
            break
    if found:
        print("YES")
    else:
        print("NO")
 