n = int(input())
s = input()
on = 0
for x in s:
    if x == '1':
        on += 1
if on < n-on : 
    print(n-2*on)
else:
    print(2*on-n)