T = int(input())
for cs in range(T):
    n = int(input())
    a = sorted(list(map(int,input().split())))
    pos = n//2
    for i in range(n):
        if i%2 == 0:
            pos += i
        else:
            pos -= i
        print(a[pos], end=' ')
    print()