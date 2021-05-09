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
lld steps (lld x, lld y)
{
	lld c = 0;
	while(x)
	{
		x/=y;
		c+=1;
	}
	return c;
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
    	lld a, b;
    	cin >> a >> b;
    	lld ops = MAX;
    	for(lld i = b; i <= (b+100); i++)
    	{
    		if (i == 1)
    			continue;
    		ops = min(ops, (i-b) + steps(a,i));
    	}
    	cout << ops << '\n';
    }
    return 0;
}