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
    	vector <lld> c(3);
    	for(lld i = 0; i < n; i += 1)
    	{
    		c[A[i]%3]++;
    	}
    	lld cnt = 0;
    	for(lld i = 0; i < 3; i += 1)
    	{
    		if (c[i] > (n/3))
    			cnt++;
    	}
    	if (cnt == 0)
    	{
    		cout << "0\n";
    	}
    	if (cnt == 1)
    	{
    		lld pos;
    		for(lld i = 0; i < 3; i += 1)
    		{
    			if (c[i] > (n/3))
    				pos = i;
    		}
    		cout << ((n/3)-c[(pos+1)%3]) + (2*((n/3)-c[(pos+2)%3])) << "\n";
    	}
    	if (cnt == 2)
    	{
    		lld pos;
    		for(lld i = 0; i < 3; i += 1)
    		{
    			if (c[i] < (n/3))
    				pos = i;
    		}
    		cout << (2*(c[(pos+1)%3]-(n/3))) + (c[(pos+2)%3]-(n/3)) << "\n";
    	}
    }
    return 0;
}