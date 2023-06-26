T = int(input())
for cs in range(T):
    n, a, b = map(int,input().split())
    cli = []
    c = 'a'
    for i in range(a-b+1):
        cli.append(c)
    for j in range(b-1):
        c = chr(ord(c)+1)
        cli.append(c)
    use = 0
    for i in range(n):
        print(cli[use], end='')
        use = (use+1)%len(cli)
    print()