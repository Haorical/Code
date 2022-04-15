// 集合交集
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<set<int>> v(n);
    for(int i=0;i<n;i++){
        set<int> s;
        int t,k;
        cin>>t;
        for(int j=0;j<t;j++){
            cin>>k;
            s.insert(k);
        }
        v[i]=s;
    }
    int m;
    cin>>m;
    set<int> s1,s2;
    for(int j=0;j<m;j++){
        s1.clear(); //一定clear
        s2.clear();
        int t1,t2;
        cin>>t1>>t2;
        t1--,t2--;
        set_intersection(v[t1].begin(),v[t1].end(),v[t2].begin(),v[t2].end(),inserter(s1,s1.begin())); //集合函数用法
        // set_union(v[t1].begin(),v[t1].end(),v[t2].begin(),v[t2].end(),inserter(s2,s2.begin()));       
        int nc=s1.size(),nt=v[t1].size()+v[t2].size()-nc; //不用union就不会超时了
        double ans=1.0*nc/nt*100; //乘1.0
        printf("%.2f%%\n",ans);
    }
    system("pause");
    return 0;
}