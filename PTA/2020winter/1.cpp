#include<bits/stdc++.h>
using namespace std;
const int MAXN=47;
int a[MAXN];
void pre(){
    a[0]=0;
    a[1]=1;
    for(int i=2;i<MAXN;i++){
        a[i]=a[i-1]+a[i-2];
        //cout<<a[i]<<endl;
    }
}
int main(){
    pre();
    int n;
    cin>>n;
    for(int i=0;i<MAXN;i++){
        if (a[i]<n&&a[i+1]>n)
        {   cout<<n-a[i]<<" "<<a[i+1]-n<<endl;
            if(n-a[i]<=a[i+1]-n){
                cout<<a[i];
            }else cout<<a[i+1];
        }
        
    }
    system("pause");
    return 0;
}