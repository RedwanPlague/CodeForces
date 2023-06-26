T = int(input())
for cs in range(T):
    s = [input() for i in range(9)]
    for r in s:
        for c in r:
            if c == '1':
                print('2', end='')
            else:
                print(c, end='')
        print()