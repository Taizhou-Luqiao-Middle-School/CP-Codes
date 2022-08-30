#include <cstdio>

int main(){
    int K;
    while(scanf("%d", &K) != EOF){
        int f[K], L[K];
        int maxn = -1, l = 0, r = 0;
        for(int i = 0; i < K; i++){
            int tmp;
            scanf("%d", &tmp);
            if(i == 0)
                f[i] = tmp, L[i] = i;
            else{
                if(f[i-1] >= 0)
                    f[i] = f[i-1] + tmp, L[i] = L[i-1];
                else
                    f[i] = tmp, L[i] = i;
            }
            if(maxn < f[i]){
                maxn = f[i];
                l = L[i], r = i;
            }
        }
        if(maxn < 0) maxn = 0;
        printf("%d %d %d\n", maxn, l, r);
    }
    return 0;
}
