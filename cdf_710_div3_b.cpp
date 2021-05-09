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
    	string s;
    	cin >> n >> k >> s;
    	set <lld> index;
    	for(lld i = 0; i < n; i += 1)
    	{
    		if (s[i] == '*')
    		{
    			index.insert(i);
    			break;
    		}
    	}
    	for(lld i = n-1; i >= 0; i -= 1)
    	{
    		if (s[i] == '*')
    		{
    			index.insert(i);
    			break;
    		}
    	}
    	if (index.size() == 1)
    	{
    		cout << "1\n";
    	}
    	else
    	{
    		set <lld> vis;
    		for(lld i = 0; i < n; i += 1)
    		{
    			if (s[i] == '*')
    			{
    				if (!index.count(i))
    					vis.insert(i);
    			}
    		}
    		while(1)
    		{
    			auto itr = index.end();
    			auto pos = itr;
    			itr--;
    			pos--;
    			pos--;
    			lld a = *pos;
    			lld b = *itr;
    			if (b-a <= k)
    				break;
    			lld temp = a+k;
    			if (vis.count(temp))
    			{
    				vis.erase(temp);
    				index.insert(temp);
    			}
    			else
    			{
    				vis.insert(temp);
    				auto mac = vis.find(temp);
    				mac--;
    				lld x = *mac;
    				vis.erase(x);
    				index.insert(x);
    				vis.erase(temp);
    			}
    		}
    		cout << index.size() << "\n";
    	}
    }
    return 0;
}