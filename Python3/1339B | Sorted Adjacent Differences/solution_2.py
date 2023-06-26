T = int(input())
for cs in range(T):
    n = int(input())
    a = sorted(list(map(int,input().split())))
    pos = n//2
    for i in range(n):
        pos += i if i%2 == 0 else -i
        print(a[pos], end=' ')
    print()