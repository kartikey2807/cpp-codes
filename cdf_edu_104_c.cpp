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
    	if (n%2 != 0)
    	{
    		lld los = (n-1)/2;
    		lld win = (n-1)/2;
    		for(lld i = 1; i <= n; i += 1)
    		{
    			lld temp_los = los;
    			lld temp_win = win;
    			for(lld j = i+1; j <= n; j += 1)
    			{
    				if (temp_los != 0)
    				{
    					cout << "-1 ";
    					temp_los -= 1;
    				}
    				else
    				{
    					cout << "1 ";
    					temp_win -= 1;
    				}
    			}
    			win--;
    		}
    	}
    	else
    	{
    		lld los = (n-2)/2;
    		lld win = (n-2)/2;
    		for(lld i = 1; i <= n; i += 1)
    		{
    			if (i%2 != 0)
    			{
    				lld temp_los = los;
    				lld temp_win = win;
    				for(lld j = i+1; j <= n; j += 1)
    				{
    					if (j == i+1)
    					{
    						cout << "0 ";
    					}
    					else
    					{
    						if (temp_los != 0)
    						{
    							cout << "-1 ";
    							temp_los -= 1;
    						}
    						else
    						{
    							cout << "1 ";
    							temp_win -= 1;
    						}
    					}
    				}
    			}
    			else
    			{
    				lld temp_los = los;
    				lld temp_win = win;
    				for(lld j = i+1; j <= n; j += 1)
    				{
    					if (temp_los != 0)
    					{
    						cout << "1 ";
    						temp_los -= 1;
    					}
    					else
    					{
    						cout << "-1 ";
    						temp_win -= 1;
    					}
    				}
    				los-=1;
    				win-=1;
    			}
    		}
    	}
    	cout << "\n";
    }
    return 0;
}