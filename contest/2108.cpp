// #include<bits/stdc++.h>
// using namespace std;
// vector<int> a;
// int main(){
//     int n;
//     cin>>n;
//     a.resize(n);
//     for(int i=0;i<n;i++) cin>>a[i];
//     int sum=0;
//     for(int i=0;i<n-1;i++){
//         int MIN=0x3fffffff,u=-1;
//         for(int j=0;j<a.size()-1;j++){
//             if(a[j]+a[j+1]<MIN){
//                 MIN=a[j]+a[j+1];
//                 u=j;
//             }
//         }
//         sum+=MIN;
//         a[u]=MIN;
//         a.erase(a.begin()+u+1);
//     }
//     cout<<sum;
//     system("pause");
//     return 0;
// }

#include<bits/stdc++.h>
 
using namespace std;
const int maxn=0x3fffffff;
int num[510];
int sum[510][510];
int dp[510][510];
 
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&num[i]);
        sum[i][1]=num[i];
        dp[i][1]=0;
    }
 
    for(j=2;j<=n;++j)
    {
        for(i=1;i<=n-j+1;++i)
            sum[i][j]=num[i]+sum[i+1][j-1];
    }
 
    for(j=2;j<=n;++j)
    {
        for(i=1;i<=n-j+1;++i)
        {
            dp[i][j]=maxn;
            for(int k=1;k<=j-1;++k)
            {
                int next=i+k;
                if(dp[i][j]>sum[i][j]+dp[next][j-k]+dp[i][k])
                    dp[i][j]=sum[i][j]+dp[next][j-k]+dp[i][k];
            }
        }
    }
 
 
    printf("%d\n",dp[1][n]);
    return 0;
}