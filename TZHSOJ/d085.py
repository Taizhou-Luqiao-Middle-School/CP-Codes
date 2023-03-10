n=int(input())
ans=[]; num=0
def check(a):  #已知列表a[]中1是n个:[0010110]
    cnt0=0; cnt1=0
    for c1 in a:
        if c1==0:
            cnt0+=1
        else:
            cnt1+=1
            if cnt1>cnt0:   #中间时刻1的个数也不可以大于0的个数
                return False
    return True


#枚举方案m:[0101...01],由2*n个01构成
for m in range(1<<(2*n)):   #1<<(2*n)-1
    a=[]; cnt1=0
    for i in range(2*n):    #由2*n个01构成,其中1是cnt1个
        if m&1:
            a.append(1); cnt1+=1
        else:
            a.append(0)
        m>>=1
    a.reverse()             #确保枚举时按从小到大次序
    if cnt1==n and check(a):
        ans.append(a)
        num+=1

print(num)
for it in ans:
    for i in range(2*n-1):
        print("%d " %it[i],end='')
    print(it[2*n-1])
