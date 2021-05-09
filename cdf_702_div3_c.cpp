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
    	lld x;
    	cin >> x;
    	lld f = 0;
    	for(lld b = 1; pow(b,3) < x; b += 1)
    	{
    		lld a = cbrt(x-pow(b,3));
    		if ((pow(a,3)+ pow(b,3)) == x)
    		{
    			f = 1;
    			break;
    		}
    	}
    	if (f == 1)
    		cout << "YES\n";
    	else
    		cout <<  "NO\n";
    }
    return 0;
}