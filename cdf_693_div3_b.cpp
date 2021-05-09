#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld t;
    cin >> t;
    while(t--)
    {
        lld n, a;
        cin >> n;
        lld cnt_1 = 0;
        lld cnt_2 = 0;
        for (lld i = 0; i < n; i += 1)
        {
            cin >> a;
            if (a == 1) cnt_1 += 1;
            if (a == 2) cnt_2 += 1;
        }
        if (cnt_1%2 == 0)
        {
            if (cnt_1 == 0 && cnt_2%2 != 0)
                cout <<  "NO";
            else
                cout << "YES";
        }
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}