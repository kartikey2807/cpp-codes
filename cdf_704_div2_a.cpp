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
    	lld p, a, b, c;
    	cin >> p >> a >> b >> c;

    	// for a
    	lld div = p/a;
    	if (p%a != 0)
    		div++;
	
    	// for b;
    	lld piv = p/b;
    	if (p%b != 0)
    		piv++;

    	// for c
    	lld civ = p/c;
    	if (p%c != 0)
    		civ++;
    	cout << min(div*a, min(civ*c, piv*b)) - p << "\n";
    }
    return 0;
}