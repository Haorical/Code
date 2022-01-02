#include<bits/stdc++.h>
using namespace std;
int main(){long long a[6001];int b[]={1,2,4,10,20,40,100,200,400,1000,2000};for(int i=0;i<=6000;i++){a[i]=1;}for(int i=1;i<11;i++){for(int j=b[i];j<=6000;j++){a[j]+=a[j-b[i]];}}while(1){double d;cin>>d;if(d==0.0)break;int n=int(d*20.0);printf("%6.2lf%17lld\n",d,a[n]);}}