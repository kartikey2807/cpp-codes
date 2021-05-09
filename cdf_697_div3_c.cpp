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
    	lld a, b, k;
    	cin >> a >> b >> k;
    	pair <lld, lld> P[k];
    	for(lld i = 0; i < k; i += 1)
    		cin >> P[i].first;
    	for(lld i = 0; i < k; i += 1)
    		cin >> P[i].second;

    	unordered_map <lld, lld> A,B;
    	for(lld i = 0; i < k; i += 1)
    	{
    		A[P[i].first]++;
    		B[P[i].second]++;
    	}
    	lld cnt = 0;
    	for(lld i = 0; i < k; i += 1)
    		cnt += k-(A[P[i].first]-1)-(B[P[i].second]-1)-1;

    	cout << cnt/2 << "\n";
    }
    return 0;
}