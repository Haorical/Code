#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int a[MAXN],b[MAXN];
bool vis[MAXN]={false};
int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int win=n/2,cnt=0;
        int ptr = 0;//指向a
        for (int i = 0; i < n;i++){//循环b,找最小战胜
            for (; ptr < n;ptr++){
                if(a[ptr]>b[i])
                    {
                        cnt++;
                        ptr++;
                        break;
                    }
            }
            if(ptr>=n)
                break;
        }
        cout<<(cnt>win?"YES":"NO")<<endl;
    }
    system("pause");
    return 0;
}