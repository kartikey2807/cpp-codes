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
        lld n, m;
        cin >> n >> m;
        lld A[n];
        map <lld, lld> cost;
        for(lld i = 0; i < n; i += 1)
            cin >> A[i];
        for(lld i = 1; i <=m; i += 1)
            cin >> cost[i];
        sort(A, A+n, greater<lld> ());
        set <lld> not_used;
        for(lld i = 1; i <=m; i += 1)
            not_used.insert(i);
        lld sum = 0;
        for(lld i = 0; i < n; i += 1)
        {
            auto itr = not_used.begin();
            if ((*itr) <= A[i])
            {
                sum += cost[(*itr)];
                not_used.erase(*itr);
            }
            else
                sum += cost[A[i]];
        }
        cout << sum << "\n";
    }
    return 0;
}