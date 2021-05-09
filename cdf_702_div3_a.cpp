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
    	lld prev = A[0];
    	lld cnt  = 0;
    	for(lld i = 1; i < n;)
    	{
    		if (max(prev,A[i]) > 2*min(prev,A[i]))
    		{
    			if (A[i] < prev)
    				prev = (prev%2 == 0) ? (prev/2) : ((prev/2)+1);
    			else
    				prev = 2*prev;
    			cnt++;
    		}
    		else
    		{
    			prev = A[i];
    			i+= 1;
    		}
    	}
    	cout << cnt << "\n";
    }
    return 0;
}