// 栈、队列
#include<bits/stdc++.h>
using namespace std;
queue<int> q[110];
stack<int> st;
map<char,int> mp;
vector<int> v;
void init(){
    for(int i=0;i<26;i++){
        mp[i+'A']=i;
    }
}
int main(){
    int n,m,s;
    string str;
    init();
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            // cout<<mp[str[j]]<<endl;
            q[i].push(mp[str[j]]);
        }
    }
    int t,t1,t2;
    while(cin>>t){
        if(t==-1) break;
        if(t==0){
            if(!st.empty()) // 记得判空即可
            {
                t2=st.top();
                st.pop();
                v.push_back(t2);
            }
        }
        else{
            if(!q[t].empty()){ // 判空
                t1=q[t].front();
                q[t].pop();
                if(st.size()==s){
                    t2=st.top();
                    st.pop();
                    v.push_back(t2);
                }
                st.push(t1);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<char(v[i]+'A');
    }
    system("pause");
    return 0;
}