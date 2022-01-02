#include<bits/stdc++.h>
using namespace std;
int a[1000005];int GCD(int x,int y){if(y==0) return x;else return GCD(y,x%y);}int main(){int n,k;while(scanf("%d%d",&n,&k)!=EOF){int j=0;for(int i=1;i<=n;i++)if(GCD(n,i)==1) a[j++]=i;if(k%j) printf("%d\n",k/j*n+a[k%j-1]);else printf("%d\n",(k/j-1)*n+a[j-1]);}}