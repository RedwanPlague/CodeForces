T = int(input())
for cs in range(T):
    n, m = map(int, input().split())
    if n % 2 == 0 or m % 2 == 0:
        print(n * m // 2)
    else:
        print( (n-1)//2 * m + (m-1)//2 + 1 )