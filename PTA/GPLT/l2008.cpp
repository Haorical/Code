//最长公共子序列变式 求原来和逆序的最长公共子序列 不知道为什么测试点246过不了
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1010;
// char a[N],b[N];
// int dp[N][N];
// int main(){
//     cin.getline(a+1,N);
//     int n=strlen(a+1);
//     for(int i=n;i>=1;i--){
//         b[n+1-i]=a[i];
//     }
//     for(int i=0;i<=n;i++) dp[i][0]=dp[0][i]=0;
//     //cout<<n<<endl;
//     int MAX=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1; //打错字母了i j
//             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             MAX=max(dp[i][j],MAX);
//         }
//     }
//     cout<<dp[n][n];
//     system("pause");
//     return 0;
// }
//换成暴力过了
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char a[N];
int main(){
    cin.getline(a,N);
    int l=strlen(a);
    int ans=0;
    for(int i=0;i<l;i++){
        //奇数
        for(int j=0;i-j>=0&&i+j<l;j++){
            if(a[i-j]!=a[i+j]) break;
            ans=max(ans,2*j+1);
        }
        //偶数
        for(int j=0;i-j>=0&&i+j+1<l;j++){
            if(a[i-j]!=a[i+j+1]) break;
            ans=max(ans,2*j+2);
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}