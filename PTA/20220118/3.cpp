// #include<bits/stdc++.h>
// using namespace std;
// int a[1005];
// int main()
// {
// 	memset(a,-1,sizeof(a));
// 	int i=0,n,sum=0,cnt=0;
// 	cin>>n;
// 	while(i<n)
// 	{
//         int x,hh,m;
//         char c;
// 		cin>>x>>c>>hh;
//         getchar();
//         cin>>m;
// 		if(x==0)
// 		{
//             cout<<cnt;
//             if(cnt==0) cout<<0;
//             else cout<<1.0*sum/cnt;
// 			memset(a,-1,sizeof(a));
// 			sum=cnt=0;
//             i++;
// 			continue;
// 		}
// 		if(c=='S')
// 		{
// 			a[x]=hh*60+m;
// 		}
// 		else if(c=='E'&&a[x]!=-1)
// 		{
// 			sum+=hh*60+m-a[x];
// 			a[x]=-1;
// 			cnt++;
// 		}
// 	}
// 	return 0;
// }
// #include <bits/stdc++.h>

// #define db double

// using namespace std;

// const int N = 1e3 + 10;

// int L[N], tim, cnt, n;

// int main() {
//     scanf("%d", &n);
//     while (n -- ) {
//         tim = 0; cnt = 0;
//         memset(L, -1, sizeof L);
//         while (1) {
//             int id, h, m;
//             char op;
//             scanf("%d %c %d:%d", &id, &op, &h, &m);
//             if (id == 0) break;
//             if (op == 'S') {
//                 L[id] = h * 60 + m;
//             } else if (L[id] != -1) {
//                 tim += h * 60 + m - L[id];
//                 L[id] = -1;
//                 cnt ++ ;
//             }
//         }
//         if (!cnt) puts("0 0");
//         else printf("%d %d\n", cnt, int((db)tim / (db)cnt + 0.5));
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int l[1002];
int main(){
	int n;
	cin>>n;
	int cnt,tim;
	while(n--){
		cnt=0,tim=0;
		memset(l,-1,sizeof l);
		int id,h,m;
		char op;
		while(1){
			scanf("%d %c %d:%d",&id,&op,&h,&m);
			if(id==0) break;
			if(op=='S'){
				l[id]=h*60+m;
			}else if(l[id]!=-1){
				tim+=h*60+m-l[id];
				cnt++;
				l[id]=-1;
			}
		}
		if(cnt==0) cout<<"0 0\n";
		else cout<<cnt<<" "<<int(double(tim)/double(cnt)+0.5)<<endl;
	}
	system("pause");
	return 0;
}