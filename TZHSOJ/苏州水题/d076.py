a = []
while True:
    try:
        a = a + list(map(int, input().split()))
    except EOFError:
        break
a.sort()
for i in range(len(a)):
    print("%d" % a[i])

# code by fyl
