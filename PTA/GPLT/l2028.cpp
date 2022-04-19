// 模拟 太恶心了，挂了几个测试点，考试的时候我绝对不会改的
// 得用字符串存，正确的我放后面了
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2010;
// double a[N][N];
// int tp[N];
// int main(){
//     int n,m,k;
//     cin>>n>>m;
//     while(m--){
//         cin>>k;
//         memset(tp,0,sizeof(tp));
//         for(int i=0;i<k;i++){
//             cin>>tp[i];
//         }
//         double tt=1.0/k;
//         for(int i=0;i<k;i++){
//             for(int j=i+1;j<k;j++){
//                 if(tp[i]*tp[j]<0 || (tp[i]==0&&tp[j]<0) || (tp[i]<0&&tp[j]==0)) {
//                     a[tp[i]+1000][tp[j]+1000]+=tt;
//                     a[tp[j]+1000][tp[i]+1000]+=tt;
//                 }
//             }
//         }
//     }
//     int t1,t2;
//     cin>>t1>>t2;
//     vector<int> v1,v2;
//     double MAX,MAX1,MAX2;
//     MAX=MAX1=MAX2=a[t1+1000][t2+1000];
//     for(int i=0;i<N;i++){
//         if(a[t1+1000][i]>MAX1){
//             MAX1=a[t1+1000][i];
//             v1.clear();
//             v1.push_back(i-1000);
//         }else if(a[t1+1000][i]==MAX1){
//             v1.push_back(i-1000);
//         }
//     }
    
//     for(int i=0;i<N;i++){
//         if(a[t2+1000][i]>MAX2){
//             MAX2=a[t2+1000][i];
//             v2.clear();
//             v2.push_back(i-1000);
//         }else if(a[t2+1000][i]==MAX2){
//             v2.push_back(i-1000);
//         }
//     }
//     if(MAX1==MAX2&&MAX==MAX1) cout<<t1<<' '<<t2;
//     else{
//         if(t1>0) sort(v1.begin(),v1.end(),greater<int>());
//         else sort(v1.begin(),v1.end());
//         if(t2>0) sort(v2.begin(),v2.end(),greater<int>());
//         else sort(v2.begin(),v2.end());
//         for(auto i:v1) cout<<t1<<' '<<i<<endl;
//         for(auto i:v2) cout<<t2<<' '<<i<<endl;
//     } 
//     system("pause");
//     return 0;
// }

//AC
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	if(abs(a)==1000)return true;
	if(abs(b)==1000)return false;
	return abs(a)<abs(b);
}
int main(){
	//input
	int n, m, sex[1010]={0};
	cin>>n>>m;
	vector<vector<int>>photo(m);
	for(int i = 0; i < m; i++){
		int k;  cin>>k;
		for(int j = 0; j < k; j++){
			string s;  cin>>s;
			if(s=="0")s="1000";
			if(s=="-0")s="-1000";
			int tmp = stoi(s);
			photo[i].push_back(tmp);
			sex[abs(tmp)] = tmp;
		}
	}
	int cp[3];
	for(int i = 1; i <= 2; i++){
		string s;  cin>>s;
		if(s=="0")s="1000";
		if(s=="-0")s="-1000";
		cp[i] = stoi(s);
	}
	//Search Photo
	double love[1010] = {0};
	for(int c = 1; c <= 2; c++){
		for(int i = 0; i < m; i++){
			//Find CP
			int ok = 0;
			for(int j = 0; j < photo[i].size(); j++){
				if(photo[i][j]==cp[c]){
					ok = 1;
					break;
				}
			}
			//Add Love
			if(ok){
				for(int j = 0; j < photo[i].size(); j++){
					if(cp[c]*photo[i][j]<0){
						love[abs(photo[i][j])] += 1.0/photo[i].size();
					}
				}
			}
		}
	}
	//Count maxlove
	double maxx[3] = {0};
	vector<vector<int> >ans(3);
	for(int c = 1; c <= 2; c++){
		for(int i = 1; i <= 1000; i++){
			if(cp[c]*sex[i]<0){
				if(love[i]>maxx[c]){
					maxx[c] = love[i];
					ans[c].clear();
					ans[c].push_back(sex[i]);
				}else if(love[i]==maxx[c]){
					ans[c].push_back(sex[i]);
				}
			}
		}
	}
	//cout<<ans[1].size()<<" "<<ans[2].size()<<endl;
	//output
	if(maxx[1]==love[abs(cp[2])] && maxx[2]==love[abs(cp[1])]){
		string s1 = to_string(cp[1]), s2 = to_string(cp[2]);
		if(cp[1]==1000)s1="0";
		if(cp[1]==-1000)s1="-0";
		if(cp[2]==1000)s2="0";
		if(cp[2]==-1000)s2="-0";
		cout<<s1<<" "<<s2<<endl;
		return 0;
	}
	for(int c = 1; c <= 2; c++){
		sort(ans[c].begin(), ans[c].end(),cmp);
		for(int i = 0; i < ans[c].size(); i++){
			string s1 = to_string(cp[c]), s2 = to_string(ans[c][i]);
			if(cp[c]==1000)s1 = "0";
			if(cp[c]==-1000)s1 = "-0";
			if(ans[c][i]==1000)s2 = "0";
			if(ans[c][i]==-1000)s2 = "-0";
			cout<<s1<<" "<<s2<<endl;
		}
	}
	return 0;
}
