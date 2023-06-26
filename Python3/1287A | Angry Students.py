T = int(input())
for cs in range(T):
    n = int(input())
    s = input()
    mx = 0
    prev = -1
    for i in range(n):
        if (s[i] == 'A'):
            prev = i
            break
    if (prev != -1):
        for i in range(prev+1,n):
            if (s[i] == 'A'):
                mx = max(mx,i-prev-1)
                prev = i
        mx = max(mx,n-prev-1)
    print(mx)