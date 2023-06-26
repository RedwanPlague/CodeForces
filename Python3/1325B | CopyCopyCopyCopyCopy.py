T = int(input())
for cs in range(T):
    n = int(input())
    st = set()
    for x in input().split():
        st.add(x)
    print(len(st))