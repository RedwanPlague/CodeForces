T = int(input())
for cs in range(T):
    n = int(input())
    a = sorted(map(int,input().split()))
    print(a[n]-a[n-1])