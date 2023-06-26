T = int(input())
for cs in range(T):
    A, B = map(int, input().split())
    # it can be proved that any b = 10^d-1, where d = #digits of b 
    i = 9
    sum = 0
    while i <= B:
        sum += A
        i = 10*i+9
    print(sum)