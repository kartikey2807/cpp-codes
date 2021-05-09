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
    	lld x, y;
    	string s;
    	cin >> x >> y >> s;
    	lld x_pos = 0, x_neg = 0;
    	lld y_pos = 0, y_neg = 0;
    	for(lld i = 0; i < s.size(); i += 1)
    	{
    		if (s[i] == 'R')
    			x_pos++;
    		if (s[i] == 'L')
    			x_neg++;
    		if (s[i] == 'U')
    			y_pos++;
    		if (s[i] == 'D')
    			y_neg++;
    	}
    	lld f = 0;
    	lld g = 0;
    	if (x >= 0)
    	{
    		if (abs(x) <= x_pos)
    			f = 1;
    	}
    	else
    	{
    		if (abs(x) <= x_neg)
    			f = 1;
    	}
    	if (y >= 0)
    	{
    		if (abs(y) <= y_pos)
    			g = 1;
    	}
    	else
    	{
    		if (abs(y) <= y_neg)
    			g = 1;
    	}
    	if (f == 1 && g == 1)
    		cout << "YES\n";
    	else
    		cout <<  "NO\n";
    }
    return 0;
}