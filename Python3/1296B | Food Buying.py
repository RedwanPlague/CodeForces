T = int(input())
for cs in range(T):
    n = int(input())
    a = 0
    while (n >= 10):
        a, n = a + n - n%10, n//10 + n%10
    a += n
    print(a)