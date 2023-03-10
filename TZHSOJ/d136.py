a = input()
n = len(a) - 1
flag = True
for i in range(0, n + 1):
    if a[i] != a[n - i]:
        print("NO")
        flag = False
        break
if flag:
    print("YES")
    
