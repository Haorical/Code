/* UVA11150 Cola */
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, ans;
    while(~scanf("%d", &n)) {
        ans = n;
        while(n >= 3) {
            ans += n / 3;
            n = n / 3 + n % 3;
        }
        if(n == 2)
            ans++;
 
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}