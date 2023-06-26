T = int(input())
for cs in range(T):
    n = int(input())
    x = input()
    a = b = ''
    done = False
    for digit in x :
        if digit == '0' :
            a += '0'
            b += '0'
        elif digit == '1' :
            if done :
                a += '0'
                b += '1'
            else :
                a += '1'
                b += '0'
                done = True
        else :
            if done :
                a += '0'
                b += '2'
            else :
                a += '1'
                b += '1'
    print(a)
    print(b)