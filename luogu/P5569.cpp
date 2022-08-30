// Date: 2021-10-18 08:21:13
// Problem: P5569 [SDOI2008] 石子合并
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5569
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcpet 475ms
// Author: Guan Yongjie
/*
Garsia-Wachs算法
设一个序列是A[0..n-1]
每次寻找最小的一个满足A[k-1]<=A[k+1]的k
那么我们就把A[k]与A[k-1]合并
之后从k向前寻找第一个满足A[j]>A[k]+A[k-1]的j
把合并后的值A[k]+A[k-1]插入A[j]的后面
https://www.luogu.com.cn/problem/solution/P5569
*/
#define DEBUG 1  //调试开关
#include<bits/stdc++.h>
using namespace std;
long long ans,n;
vector<int> l;
inline int read()
{
    int i=0; char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')i=i*10+c-'0',c=getchar();
    return i;
}
int merge()
{
    int k=l.size()-1-1;//如果我们在A[0]到A[n-3]找不到A[k]<=A[k+2]，那么k的值应该为n-2
    for(int i=0;i<l.size()-2;++i)
    {
        if(l[i]<=l[i+2])
        {
            k=i;
            break;
        }
    }
    int tmp=l[k]+l[k+1];
    l.erase(l.begin()+k);
    l.erase(l.begin()+k);//删除
    int in=-1;
    for(int i=k-1;i>=0;--i) //从右往左找第一个 
    {
        if(l[i]>tmp)
        {
            in=i;
            break;
        }
    }
    l.insert(l.begin()+in+1,tmp);//因为是在后面插入，所以要+1
  return tmp; 
}
int main()
{
    cin>>n;
    for(int i=1; i<=n;++i)
        l.push_back(read());
    for(int i=0;i<n-1;i++)
        ans+=merge();
    cout<<ans;
    return 0;
}
/*
不用STD的快了400ms，41ms通过
#include<stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
void wr(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int stone[50010];
int n, t, ans;
void combine(int k) {
    int tem = stone[k] + stone[k - 1];//合并k和k-1堆
    ans += tem;
    for (int i = k; i < t - 1; i++) stone[i] = stone[i + 1]; //k以后的往前移位
    t--;
    int j;
    for (j = k - 1; j > 0 && stone[j - 1] < tem; j--) stone[j] = stone[j - 1]; //k-1以后的往后移位，找大于tem的位置
    stone[j] = tem;//在j处插入tem
    while (j >= 2 && stone[j - 2] <= stone[j]) { //在新得到的序列里递归处理
        int d = t - j;//为了回溯。。。
        combine(j - 1);
        j = t - d;//回溯
    }
}
int main() {
    while (~scanf("%d", &n)) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) stone[i] = rd();
        t = 1;
        ans = 0;
        for (int i = 1; i < n; i++) {
            stone[t++] = stone[i];
            while (t >= 3 && stone[t - 3] <= stone[t - 1]) combine(t - 2);//从1开始遍历到结尾
        }
        while (t > 1) combine(t - 1);//合并完后如果不为一堆再合并一次
        wr(ans), putchar('\n');
    }
    return 0;
}
*/