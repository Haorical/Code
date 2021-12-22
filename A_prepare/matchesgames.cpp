/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    while(scanf("%d",&n)!=EOF){
        int ans = 0;
        for(int i=0;i<n;i++){
            cin>>a;
            ans^=a;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    system("pause");
    return 0;
}
// 经典nim博弈

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,t;
    while(scanf("%d",&m)!=EOF){
        int ans=0;
        for(int i=0;i<m;i++){
            scanf("%d",&t);
            ans^=t;
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}

//字母大小写