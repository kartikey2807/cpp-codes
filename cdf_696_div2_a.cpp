#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
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
    	string s;
    	cin >> n >> s;
    	lld B[n],A[n];
    	for(lld i = 0; i < n; i += 1)
    		B[i] = (lld)s[i]-48;
    	A[0] = 1;
    	for(lld i = 1; i < n; i += 1)
    	{
    		lld sum = A[i-1] + B[i-1];
    		if (sum == 2)
    			A[i] = (B[i] == 0) ? 1 : 0;
    		if (sum == 1)
    			A[i] = (B[i] == 0) ? 0 : 1;
    		if (sum == 0)
    			A[i] = (B[i] == 0) ? 1 : 1;
    	}
    	for(lld i = 0; i < n; i += 1)
    		cout << A[i];
    	cout << "\n";
    }
    return 0;
}