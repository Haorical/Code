/*
#include<bits/stdc++.h> 
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
    int num;
    while(cin>>num&&num){
        int temp;
        for(int i=0;i<num;i++){
            cin>>temp;
            q.push(temp);
        }
        int a,b,c;
        int sum=0;
        while(1){
            a=q.top();
            q.pop();
            if(q.empty()) break;
            b=q.top();
            q.pop();
            c=a+b;
            q.push(c);
            sum+=c;
        }
        cout<<sum<<endl;
    }
    system("pause");
    return 0;
}
*/
#include<bits/stdc++.h> 
using namespace std;
int main(){priority_queue<int,vector<int>,greater<int>> q;int num;while(cin>>num&&num){int temp;for(int i=0;i<num;i++){cin>>temp;q.push(temp);}int a,b,c;int sum=0;while(1){a=q.top();q.pop();if(q.empty())break;b=q.top();q.pop();c=a+b;q.push(c);sum+=c;}cout<<sum<<endl;}}
