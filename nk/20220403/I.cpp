#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main(){
    int t;
    cin>>t;
    while(t--){
        b.clear();
        a.clear();
        int n;
        cin>>n;
        a.resize(n);
        b.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        b[0]=a[0];
        for(int i=1;i<n;i++){
            b[i]=a[i]-a[i-1];
        }
        //cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
        sort(b.begin(),b.end());
        int sum=0;
        int ns=0;
        for(int i=0;i<n;i++){
            ns+=b[i];
            sum+=ns;
            //cout<<ns<<endl;
        }
        cout<<sum<<endl;
    }
    system("pause");
    return 0;
}