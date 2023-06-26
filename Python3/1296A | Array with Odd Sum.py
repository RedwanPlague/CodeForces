T = int(input())
for cs in range(T):
    n = int(input())
    a = map(int,input().split())
 
    foundo = False
    founde = False
    for x in a:
        if (x&1):
            foundo = True
        else:
            founde = True
    if (n&1):
        if foundo:
            print("YES")
        else:
            print("NO")
    else:
        if founde and foundo:
            print("YES")
        else:
            print("NO")