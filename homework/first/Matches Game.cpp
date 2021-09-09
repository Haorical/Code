/*
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
	int M;
	while(cin>>M)
	{
		int a[20];
		for(int i=0; i<M; ++i){
            scanf("%d",&a[i]);
        }
		int result = 0;
		for(int i=0; i<M; i++){	
            result ^= a[i];
        }
		if(result) cout<<"Yes"<<endl;
		else cout<<"No" <<endl;
	}
 
	return 0;
}
*/
//上边代码超时了
#include<iostream>
using namespace std;
int main()
{ int n,a;
 while(scanf("%d",&n)!=EOF)
 { int ans=0;
 for(int i=1;i<=n;i++)
 {
 scanf("%d",&a);
 ans=ans^a;
 }
 if(ans) printf("Yes\n");
 else printf("No\n");
 }
 return 0;
}
