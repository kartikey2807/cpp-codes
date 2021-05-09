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
    	lld n, m;
    	cin >> n >> m;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	for(lld i = 0; i < n; i += 1)
    		A[i] = A[i]%m;
    	
    	vector <lld> cnt(m);
    	for(lld i = 0; i < n; i += 1)
    		cnt[A[i]]++;
    	lld sum = 0;
    	for(lld i = 0; i <= (m/2); i += 1)
    	{
    		if (i == 0)
    		{
    			if (cnt[i] > 0)
    				sum++;
    		}
    		else
    		{
    			lld x = i;
    			lld y = m-i;
    			if (cnt[x] > 0 || cnt[y] > 0)
    			{
    				if (x != y)
    				{
    					lld min_count = min(cnt[x], cnt[y]);
    					if (cnt[x] > min_count)
    					{
    						cnt[x] -= (min_count+1);
    						cnt[y] -= (min_count+0);
    					}
    					else
    					{
    						if (cnt[y] > min_count)
    						{
    							cnt[x] -= (min_count+0);
    							cnt[y] -= (min_count+1);
    						}
    						else
    						{
    							cnt[x] -= (min_count+0);
    							cnt[y] -= (min_count+0);
    						}
    					}
    					sum += (cnt[x]+cnt[y]+1);
    				}
    				else
    				{
    					sum++;
    				}
    			}
    		}
    	}
    	cout << sum << "\n";
    }
    return 0;
}