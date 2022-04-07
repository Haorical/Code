#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
string s[MAXN];
int n,k;

struct Node{
    string data;
    vector<int> child;
}node[MAXN];

vector<string> tr[MAXN];
int index=0;
int newNode(string s){
    node[index].data=s;
    node[index].child.clear();
    return index++;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int cnt=0;
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]==' '){
                cnt++;
            }else break;
        }
        tr[cnt].push_back(s[i]);
    }
    
    system("pause");
    return 0;
}

//不会树存储