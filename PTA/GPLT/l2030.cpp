#include<bits/stdc++.h>
using namespace std;
struct people{
    char sex;
    string father;
};
unordered_map<string,people> p;
int judge(string a,string b){
    int i=1,j;
    for(string A=a;!A.empty();A=p[A].father,i++){
        j=1;
        for(string B=b;!B.empty();B=p[B].father,j++){
            if(i>=5&&j>=5) return 1;
            if(A==B&&(i<5||j<5)) return 0;
        }
    }
    return 1;
}
int main(){
    int n,m;
    string str,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        // 先名后姓
        // male 男 female 女
        if(b.back()=='n') p[a]={'m',b.substr(0,b.size()-4)};
        else if(b.back()=='r') p[a]={'f',b.substr(0,b.size()-7)}; // b.size() b.length not sizeof(b)
        else p[a].sex=b.back();
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>str>>b>>str; // 姓没用
        if(p.find(a)==p.end()||p.find(b)==p.end()) cout<<"NA\n"; //find 约等于map自带
        else if(p[a].sex==p[b].sex) cout<<"Whatever\n";
        else cout<<(judge(a,b)?"Yes\n":"No\n");
    }
    system("pause");
    return 0;
}


	// cin >> m;
	// for (int i = 0; i < m; i++) {
	// 	cin >> a >> str >> b >> str;  //姓氏没有用
	// 	if (people.find(a) == people.end() || people.find(b) == people.end())		printf("NA\n");
	// 	else if (people[a].sex == people[b].sex)		printf("Whatever\n");
	// 	else	printf("%s\n", judge(a, b) ? "Yes" : "No");
	// }

