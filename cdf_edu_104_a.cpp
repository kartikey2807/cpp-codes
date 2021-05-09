#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
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
    	lld n;
    	cin >> n;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	lld ans = MAX;
    	map <lld, lld> cnt;
    	for(lld i = 0; i < n; i += 1)
    	{
    		cnt[A[i]]++;
    		ans = min(ans, A[i]);
    	}
    	cout << n-cnt[ans] << "\n";
    }
    return 0;
}