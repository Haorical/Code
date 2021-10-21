#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int aTbl[20], aAns[20], aMax[20], nLen, nVar, i = 0;
    for (cin >> nLen; i < nLen && cin >> nVar; aTbl[i++] = nVar);
    while (true) {
        for (i = 0; i < nLen && cin >> nVar; aAns[nVar - 1] = aTbl[i++]);
        if (i != nLen) {
            break;
        }
        memset(aMax, 0, sizeof(aMax));
        for (nVar = 0, i = nLen - 1; i >= 0; --i) {
            for (int j = i + 1; j < nLen; ++j) {
                if (aAns[j] > aAns[i] && aMax[j] > aMax[i]) {
                    aMax[i] = aMax[j];
                }
            }
            nVar = ++aMax[i] > nVar ? aMax[i] : nVar;
        }
        cout << nVar << endl;
    }
    return 0;
}