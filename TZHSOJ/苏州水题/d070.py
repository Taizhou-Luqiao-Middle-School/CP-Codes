a = input()
l = 0
r = 0
for i in a:
    if i == "(":
        l += 1
    elif i == ")":
        r += 1
if l == r:
    print("Yes")
elif l > r:
    print("Left")
elif r > l:
    print("Right")
