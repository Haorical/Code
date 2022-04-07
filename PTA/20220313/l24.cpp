#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000+10;
double a[MAXN][MAXN];
int tmp[MAXN];
int main(){
    int n,m;
    cin>>n>>m;
    fill(a[0],a[0]+MAXN*MAXN,0.0);
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        memset(tmp,0,sizeof(tmp));
        for(int j=0;j<k;j++){
            cin>>tmp[j];
        }
        for(int p=0;p<k;p++){
            for(int q=p+1;q<k;q++){
                if(tmp[p]*tmp[q]<0){
                    a[tmp[p]+1000][tmp[q]+1000]+=1.0/k;
                }else if(tmp[p]==0){
                    if(tmp[q]<0) a[tmp[p]+1000][tmp[q]+1000]+=1.0/k;
                }else if(tmp[q]==0){
                    if(tmp[p]<0) a[tmp[p]+1000][tmp[q]+1000]+=1.0/k;
                }
            }
        }
    }
    int h1,h2;
    cin>>h1>>h2;
    vector<int> v;
    double MAX=-0x3fffffff;
    for(int i=0;i<n;i++){
        if(a[i+1000][h1+1000]>MAX){
            MAX=a[i+1000][h1+1000];
        }
    }
    for(int i=0;i<n;i++){
        if(a[h1+1000][i+1000]>MAX){
            MAX=a[h1+1000][i+1000];
        };
    }
    for(int i=0;i<n;i++){
        if(a[i+1000][h1+1000]==MAX){
            v.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        if(a[h1+1000][i+1000]==MAX){
            v.push_back(i);
        };
    }
    if(h1<0)
        sort(v.begin(),v.end(),greater<int>());
    else
        sort(v.begin(),v.end());
    for(auto i=v.begin();i<v.end();i++){
        cout<<h1<<" "<<*i<<endl;
    }
    v.clear();
    MAX=-0x3fffffff;
    for(int i=0;i<n;i++){
        if(a[i+1000][h2+1000]>MAX){
            MAX=a[i+1000][h2+1000];
        }
    }
    for(int i=0;i<n;i++){
        if(a[h2+1000][i+1000]>MAX){
            MAX=a[h2+1000][i+1000];
        };
    }
    for(int i=0;i<n;i++){
        if(a[i+1000][h2+1000]==MAX){
            v.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        if(a[h2+1000][i+1000]==MAX){
            v.push_back(i);
        };
    }
    cout<<a[1002][997]<<endl;
    if(h2<0)
        sort(v.begin(),v.end(),greater<int>());
    else
        sort(v.begin(),v.end());
    for(auto i=v.begin();i<v.end();i++){
        cout<<h2<<" "<<*i<<endl;
    }
    system("pause");
    return 0;
}