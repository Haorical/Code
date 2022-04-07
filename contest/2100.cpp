#include<bits/stdc++.h>
using namespace std;

int n,ht[27];
string s,p,np,pre;
// map<string,int> mp;
// void ddd(int id){
//     if(id==n+1){
//         for(int i=1;i<=n;i++){
//             np+=p[i];
//         }
//         if(np==pre||mp[np]){
//             np.clear();
//             return;
//         };
//         pre=np;
//         mp[np]=1;
//         cout<<np<<" ";
//         np.clear();
//         return;
//     }
//     for (int i=0;i<n;i++)
//     {
//         if(ht[i]==0){
//             p[id]=s[i];
//             ht[i]++;
//             ddd(id+1);
            
//             ht[i]--;
//         }
//     }
    
// }

int main(){
    cin>>s;

    s.erase(s.end()-1);
    n=s.length();
    sort(s.begin(),s.end());
    do
    {
        cout<<s<<" ";
    } while (next_permutation(s.begin(),s.end()));
    
    // //cout<<s<<endl;
    // memset(ht,0,sizeof(ht));
    // ddd(1);
    system("pause");
    return 0;
}