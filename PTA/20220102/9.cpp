#include<bits/stdc++.h>
using namespace std;
int a[100002];
int sum(int p1,int p2){
    int s=0;
    for(int i=p1;i<=p2;i++){
        s+=a[i];
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int maxm=0,maxs=0;
    for(int i=0;i<=1;i++){
        int m=n/2-i;
        int s1=sum(0,m);
        int s2=sum(m+1,n-1);
        int s3=s2-s1;
        if(s3>maxs){
            maxs=s3;
            maxm=m;
        }
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d",n-maxm-1,maxm+1,maxs);
    system("pause");
    return 0;
}