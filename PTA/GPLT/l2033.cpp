// 栈基础
#include<bits/stdc++.h>
using namespace std;
int n;
stack<int> s1;
stack<char> s2;
int main(){
    cin>>n;
    int t1,d1,d2;
    char t2;
    for(int i=0;i<n;i++){
        cin>>t1;
        s1.push(t1);
    }
    for(int i=0;i<n-1;i++){
        cin>>t2;
        s2.push(t2);
    }
    while (!s2.empty())
    {
        d1=s1.top();
        s1.pop();
        d2=s1.top();
        s1.pop();
        t2=s2.top();
        s2.pop();
        if(t2=='+') s1.push(d1+d2);
        if(t2=='-') s1.push(d2-d1);
        if(t2=='*') s1.push(d1*d2);
        if(t2=='/') {if(d1==0){printf("ERROR: %d/0",d2); return 0;} s1.push(d2/d1); }
    }
    cout<<s1.top();
    system("pause");
    return 0;
}