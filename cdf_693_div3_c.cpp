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
map <lld, lld> dist;
lld path (lld A[], lld x, lld n)
{
    if (x > n-1)
        return 0;
    if (!dist.count(x))
        dist[x] = path(A, x+A[x], n) + A[x];
    return dist[x];
}
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
        dist.clear();
        lld n;
        cin >> n;
        lld A[n];
        for(lld i = 0; i < n; i += 1)
            cin >> A[i];
        for(lld i = 0; i < n; i += 1)
            if (!dist.count(i))
                lld t = path(A, i, n);
        lld ans = MIN;
        for(auto itr = dist.begin(); itr != dist.end(); itr++)
            ans = max(ans, itr->second);
        cout << ans << "\n";
    }
    return 0;
}