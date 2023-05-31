a = list(input().split())
for i in range(0, len(a)):
    for j in range(0, len(a[i])):
        if a[i][len(a[i])-j-1].isalpha():
            print(a[i][len(a[i])-j-1], end='')
    for j in range(0, len(a[i])):
        if a[i][j].isalpha() != 1:
            print(a[i][j], end='')
    print(end=' ')
