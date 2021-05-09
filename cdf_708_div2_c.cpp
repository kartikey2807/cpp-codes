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
    		if (n%4 == 0)
    			cout << (n/2) << " " << (n/4) << " " << (n/4) << "\n";
    		else
    			cout << "2 " << ((n/2)-1) << " " << ((n/2)-1) << "\n";
    	}
    	else
    	{
    		cout << "1 " << (n/2) << " " << (n/2) << "\n";
    	}
    }
    return 0;
}