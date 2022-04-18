// 热身赛原题，考试时做出来了，结构体排序
#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct node{
	string name;
	int cnt;
	int avg;
}nd[N];
int cmp(node x,node y){
	if(x.cnt==y.cnt) return x.avg<y.avg; 
	else return x.cnt>y.cnt;
}
int main(){
	int n,k,t;
	set<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		s.clear();
		cin>>nd[i].name;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>t;
			s.insert(t);
		}
		nd[i].cnt=s.size();
		nd[i].avg=k-nd[i].cnt;
	}
	sort(nd,nd+n,cmp);
	if(n==1) cout<<nd[0].name<<" - -";//容易少写
	else if(n==2) cout<<nd[0].name<<' '<<nd[1].name<<" -";
	else cout<<nd[0].name<<' '<<nd[1].name<<' '<<nd[2].name;
	return 0;
}