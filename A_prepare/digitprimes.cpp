/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
bool u[maxn];
int su[maxn],u2[maxn],num=0;
void prepare(){
    int i,j;
    memset(u,1,sizeof(u));
    u[1]=0;
    for(i=2;i<maxn;i++){
        if(u[i]) su[num++]=i;
        for(j=0;j<num;j++){
            if(i*su[j]>maxn) break;
            u[i*su[j]]=0;
            if(i%su[j]==0) break;
        }
    }
}
bool ok(int x){
    int k=0;
    while(x){
        k+=x%10;
        x/=10;
    }
    return u[k];
}
int main(){
    int i,j,k;
    prepare();
    for(i=2;i<maxn;i++) if(u[i]&&ok(i)) u2[i]=1;
    for(i=2;i<maxn;i++) u2[i]+=u2[i-1];
    cin>>k;
    while(k--){
        cin>>i>>j;
        cout<<u2[j]-u2[i-1]<<endl;
    }
    system("pause");
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
bool vi[1000010];int pri[1000010];int s[1000010];void add(int x){while(x<=1000000){s[x]++;x+=x&(-x);}}int sum(int x){int ans=0;while(x>0){ans+=s[x];x-=x&(-x);}return ans;}int get(int x){return sum(x)-sum(x-1);}void getprime(){int num=0;for(int i=2;i<=1000000;i++){if(!vi[i]){pri[num++]=i;for(int j=i+i;j<=1000000;j+=i)vi[j]=true;}}for(int i=0;i<num;i++){int check=0,temp=pri[i];while(temp){check+=temp%10;temp/=10;}if(!vi[check])add(pri[i]);}}int main(){getprime();int n;scanf("%d",&n);while(n--){int a,b; scanf("%d %d",&a,&b);printf("%d\n",sum(b)-sum(a-1));}}

#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int vis[maxn],sign[maxn];
void init()
{
	memset(vis,true,sizeof(vis));
	for(int i=2;i<=maxn;i++)
		if(vis[i])
			for(int j=2;j*i<=maxn;j++)
				vis[i*j]=false;
}
bool ok(int x)
{
	int k=0;
	while(x)
	{
		k+=x%10;
		x/=10;
	}
	return vis[k];
}
int main()
{
	init();
	int t;
	cin>>t;
	for(int i=2;i<=maxn;i++)
		if(vis[i]&&ok(i))
			sign[i]=1;
	for(int i=2;i<=maxn;i++) sign[i]+=sign[i-1];
	while(t--)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		printf("%d\n",sign[j]-sign[i-1]);
	}
	return 0;
} 

#include <bits/stdc++.h>
#define MAXN 2333333
using namespace std;
int per[MAXN] = {1, 1};
void sul_per() {
    for(int i = 2; i <= 1300000; i++)
        if(!per[i]&& i * 2 <= 1300000)
            for(int j = 2; j * i <= 1300000; j++)
                per[j * i] = 1;
} 
int main() {
    int x;
    sul_per();
    while(cin >> x&& x) {
        if(!per[x]) {cout << "0" << "\n"; continue;}
        int l = x;
        int r = x;
        while(per[++l]);
        while(per[--r]);
        cout << l - r << "\n";
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int a[1299750];void pp(){int i,j;for(i=2;i<1299750;i++)if(!a[i])for(j=i+i;j<1299750;j+=i)a[j]=1;}int main(){int n;pp();while(scanf("%d",&n)!=EOF,n){int b,c;b=c=n;while(a[b])b++;while(a[c])c--;printf("%d\n",b-c);}}