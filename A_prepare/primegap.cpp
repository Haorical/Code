#include<bits/stdc++.h>
#define maxn  1299809
using namespace std;
int s[100005];
bool a[maxn];
int main()
{
    int i,j,num=0;
    int k;
    memset(a,1,sizeof(a));
    a[0]=a[1]=0;
    for(i=2;i<maxn;i++)
    {
        if(a[i])
        {
            for(j=2*i;j<maxn;j+=i)
            a[j]=0;
            s[++num]=i;
        }
    }
    while(cin>>k,k)
    {
        if(a[k]==1) { cout<<'0'<<endl; continue;}
 
        int left=1,right=num,mid;
        while(left<num)
        {
            mid=(left+right)/2;
            if(s[mid]<k&&s[mid+1]>k) {cout<<s[mid+1]-s[mid]<<endl; break;}
            if(s[mid]>k) right=mid-1;
            else left=mid+1;
        }
    }
    return 0;
}
