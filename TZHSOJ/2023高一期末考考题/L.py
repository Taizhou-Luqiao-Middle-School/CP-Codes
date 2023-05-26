n = int(input().strip())

for i in range(1, n+1):
    print(' ' * (n-i) + ''.join(str(j % 10) for j in range(1, i+1))[:-1] + ''.join(str(j % 10) for j in range(i, 0, -1)))
# 这压行我不好评价
# 可以看作是
#   ' ' * (n-i)     每一行前的空格
#   +
#   ''.join(str(j % 10) for j in range(1, i+1))[:-1])       1234...i
#   +
#   ''.join(str(j % 10) for j in range(i, 0, -1))           (i-1)(i-2)...1
#   语法补充： 推导式https://www.runoob.com/python3/python-comprehensions.html
