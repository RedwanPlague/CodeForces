odd = ['1', '3', '5', '7', '9']
T = int(input())
for cs in range(T):
    n = int(input())
    s = input()
    d1 = ''
    d2 = ''
    for c in s:
        if c in odd: 
            if d1 == '':
                d1 = c
            else:
                d2 = c
                break
    if d1 == '' or d2 == '':
        print(-1)
    else:
        print(d1+d2)