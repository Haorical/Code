#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<char> s2;
int main(){
    int n=0,tn=0;
    char tc;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tn;
        s1.push(tn);
    }
    for(int i=0;i<n-1;i++){
        cin>>tc;
        //cout<<tc<<endl;
        s2.push(tc);
    }
    while(!s2.empty()){
        int n1=s1.top();
        //cout<<s1.top()<<endl;
        s1.pop();
        int n2=s1.top();
        s1.pop();
        char s=s2.top();
        //cout<<s<<endl;
        s2.pop();
        if(s=='+') s1.push(n1+n2);
        else if(s=='-') s1.push(n2-n1);
        else if(s=='*') s1.push(n2*n1);
        else{
            if(n1==0){
                printf("ERROR: %d/0",n2);
                system("pause");
                return 0;
            }else s1.push(n2/n1);
        }
    }
    cout<<s1.top();
    system("pause");
    return 0;
}