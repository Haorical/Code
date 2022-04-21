// 初看栈使用 数据比较弱
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    while(k--){
        stack<int> s; //stack没有clear 直接重新定义
        int flag=0;
        memset(a,0,sizeof(a));
        int t1=1,t2;
        int cnt1=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            t2=a[i];
            if(t2==t1){
                t1++;
                while(!s.empty()&&s.top()==t1){
                    s.pop();
                    t1++;
                }
            }else{
                s.push(t2);
                if(s.size()>m){ // 把=改成>就过了 下面写的都是对的
                    flag=1;
                    break;
                }
            }
            // int t3=-1;
            // if(!s.empty()) t3=s.top();
            // while(t3==t1){
            //     t1++;
            //     s.pop(); // pop之后size要-1
            //     cnt1--;
            //     if(s.empty()) break;
            //     t3=s.top();
            // }
        }
        if(flag){ cout<<"NO"<<endl; continue;}
        if(t1==n+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    system("pause");
    return 0;
}