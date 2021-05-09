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
    lld n, q, k;
    cin >> n >> q >> k;
    lld A[n];
    for(lld i = 0; i < n; i += 1)
    	cin >> A[i];
    if (n == 1)
    {
    	for(lld i = 0; i < q; i += 1)
    	{
    		lld l, r;
    		cin >> l >> r;
    		cout << k-1 << "\n";
    	}
    }
    else
    {
    	lld B[n];
    	for(lld i = 0; i < n; i += 1)
    	{
    		if (i == 0)
    		{
    			B[i] = A[i+1]-2;
    		}
    		else
    		{
    			if (i == n-1)
    			{
    				B[i] = k-A[i-1]-1;
    			}
    			else
    			{
    				B[i] = A[i+1]-A[i-1]-2;
    			}
    		}
    	}
    	lld sum = 0;
    	vector <lld>val(n+1);
    	for(lld i = 0; i < n; i += 1)
    	{
    		sum+= B[i];
    		val[i+1] = sum;
    	}
    	for(lld i = 0; i < q; i += 1)
    	{
    		lld l, r;
    		cin >> l >> r;
    		if (l < r)
    		{
    			cout << (val[r-1]-val[l]) + (A[l]-2) + (k-A[r-2]-1) << "\n";
    		}
    		else
    		{
    			cout << k-1 << "\n";
    		}
    	}
    }
    return 0;
}