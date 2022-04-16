//类似模拟，维护了一个最小值集合的队列
//lower_bound查找>=目标第一个元素 upper_bound >
//这里用upper_bound
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    int t,cnt=0;
    for(int i=0;i<n;i++){
        cin>>t;
        // 性质决定肯定是有序的，直接upper_bound看有没有更大中的最小值
        vector<int>::iterator it=upper_bound(v.begin(),v.end(),t); 
        if(it==v.end()){
            v.push_back(t);//没有直接插进去
            cnt++;
        }else{
            int j=it-v.begin();//有就替换掉
            v[j]=t;
        }
    }
    cout<<cnt;
    system("pause");
    return 0;
}