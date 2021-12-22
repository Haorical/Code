/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int l=0,s=0;
    while(t--){
        int len,n;
        cin>>len>>n;
        for(int i=0;i<n;i++){
            int loc;
            cin>>loc;
            if(loc<len/2){
                l = max(l,  len-loc);
                s = max(s, loc);
            }else{
                s = max(s,  len-loc);
                l = max(l, loc);
            }
        }
        cout<<s<<" "<<l<<endl;
    }
    system("pause");
    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int len,cnt,tmp;
        cin>>len>>cnt;
        int ma=0,mi=0;
        for(int i=0;i<cnt;i++){
            cin>>tmp;
            if(tmp<(len/2)){
                ma=max(ma,len-tmp);
                mi=max(mi,tmp);
            }else{
                ma=max(ma,tmp);
                mi=max(mi,len-tmp);
            }
        }
        cout<<mi<<" "<<ma<<endl;
    }
    system("pause");
    return 0;
}