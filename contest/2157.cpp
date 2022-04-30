// dfs 排列树
// #include<bits/stdc++.h>
// using namespace std;
// bool isp[40]={true};
// bool vis[40]={false};
// int n;
// int a[20];
// void init(){
//     isp[1]=false;
//     for(int i=2;i<=40;i++){
//         for(int j=2;j<=sqrt(i);j++){
//             if(i%j==0) {isp[i]=false; break;}
//         }
//     }
// }
// int cnt;
// void dfs(int s){
//     if(s==n&&isp[a[0]+a[n-1]]) cnt++;
//     else{
//         for(int i=2;i<=n;i++){
//             if(!vis[i]&&isp[i+a[s-1]]){
//                 a[s]=i;
//                 vis[i]=true;
//                 dfs(s+1);
//                 vis[i]=0;
//             }
//         }
//     }
// }

// int main(){
//     init();

//     while(cin>>n){
//         memset(vis, 0, sizeof(vis));
//         a[0]=1;
//         dfs(1);
//         cout<<cnt<<endl;
//     }
//     system("pause");
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int is_prime(int x) {
  for(int i = 2; i*i <= x; i++)
    if(x % i == 0) return 0;
  return 1;
}

int n, A[50], isp[50], vis[50],cnt;
void dfs(int cur) {
  if(cur == n && isp[A[0]+A[n-1]]) {
      cnt++;
  }
  else for(int i = 2; i <= n; i++)
    if(!vis[i] && isp[i+A[cur-1]]) {
      A[cur] = i;
      vis[i] = 1;
      dfs(cur+1);
      vis[i] = 0;
    }
}

int main() {
  while(cin>>n) {
    cnt=0;
    for(int i = 2; i <= n*2; i++) isp[i] = is_prime(i);
    memset(vis, 0, sizeof(vis));
    memset(A, 0, sizeof(A));
    A[0] = 1;
    dfs(1);
    cout<<cnt<<endl;
  }
  return 0;
}