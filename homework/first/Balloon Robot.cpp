#include<bits/stdc++.h>
#define max_v 1000005
#define INF 999999999
using namespace std;
typedef long long LL;
LL a[max_v];
LL b[max_v];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);

        for(LL i=1;i<=n;i++)
            scanf("%lld",&a[i]);

        LL id,time;
        LL sum=0;
        for(LL i=1;i<=k;i++)
        {
            scanf("%lld %lld",&id,&time);
            time=time%m;
            if(time==0)
                time=m;
            b[i]=(a[id]-time+m)%m;
            sum+=b[i];
        }

        sort(b+1,b+k+1);
        long long  ans=0x3f3f3f3f3f3f3f3f;
        b[0]=-1;
        for(LL i=1;i<=k;i++)
        {
            if(b[i]!=b[i-1])
                ans=min(ans,sum-k*b[i]+(i-1)*m);
        }
        printf("%lld\n",ans);
    }
    system("pause");
    return 0;
}
