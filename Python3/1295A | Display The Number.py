T = int(input())
for cs in range(T):
    n = int(input())
    N = '7' if n&1 else '1'
    n = n//2 - 1
    for i in range(n):
        N += '1'
    print(N)