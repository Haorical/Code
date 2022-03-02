#include<bits/stdc++.h>
using namespace std;
stack<string> st;
int main(){
    string s;
    cin>>s;
    int l=s.length(),sum=0;
    for (int i = 0; i < l; i++)
    {
        sum+=s[i]-'0';
    }
    string mp[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(sum==0){
        cout<<"zero";
        return 0;
    }
    while(sum){
        st.push(mp[sum%10]);
        sum/=10;
    }
    cout<<st.top();
    st.pop();
    while(!st.empty()){
        cout<<" "<<st.top();
        st.pop();
    }
    system("pause");
    return 0;
}