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
    	lld q, d;
    	cin >> q >> d;
    	lld A[q];
    	for(lld i = 0; i < q; i += 1)
    		cin >> A[i];
    	for(lld i = 0; i < q; i += 1)
    	{
    		if (A[i] >= (d*10))
    		{
    			cout << "YES";
    		}
    		else
    		{
    			lld x = -1;
    			lld r = A[i]%10;
    			for(lld j = 1; j <= 10; j += 1)
    			{
    				if ((d*j)%10 == r)
    				{
    					x = j;
    					break;
    				}
    			}
    			if (x == -1)
    			{
    				cout << "NO";
    			}
    			else
    			{
    				if ((d*x) > A[i])
    					cout <<  "NO";
    				else
    					cout << "YES";
    			}
    		}
    		cout << "\n";
    	}
    }
    return 0;
}