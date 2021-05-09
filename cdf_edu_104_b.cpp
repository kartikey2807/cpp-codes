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
    	lld n, k;
    	cin >> n >> k;
    	if (n%2 == 0)
    	{
    		if (k%n == 0)
    			cout << n << "\n";
    		else
    			cout <<k%n<< "\n";
    	}
    	else
    	{
    		lld a = (n+1)/2;
    		lld d = (n-1)/2;
    		if (k < a)
    		{
    			cout << k << "\n";
    		}
    		else
    		{
    			lld c = (k-a)/d;
    			k += c+1;
    			if (k%n == 0)
    				cout << n << "\n";
    			else
    				cout <<k%n<< "\n";
    		}
    	}
    }
    return 0;
}