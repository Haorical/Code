#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
struct Rb
{
    int id;
    int rmb;
    int cnt;
}rb[MAXN];
bool cmp(Rb a,Rb b){
    if(a.rmb<b.rmb){
        return false;
    }else if(a.rmb==b.rmb){
        if(a.cnt<b.cnt)
            return false;
        else if(a.cnt==b.cnt){
            if(a.id>b.id)
                return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        rb[i].id=i;
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int t1,t2;
            cin>>t1>>t2;
            rb[i].rmb-=t2;
            rb[t1].rmb+=t2;
            rb[t1].cnt++;
            //cout<<rmb[1]<<endl;
        }
    }
    sort(rb+1,rb+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%d %.2f",rb[i].id,rb[i].rmb*0.01);
        //cout<<rb[i].id<<" "<<rb[i].rmb<<" "<<rb[i].cnt<<endl;
        if(i<n) cout<<"\n";
    }
    
    system("pause");
    return 0;
}