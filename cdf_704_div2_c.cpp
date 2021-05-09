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
    lld n, m;
    string s;
    string t;
    cin >> n >> m >> s >> t;
    map <char, set <lld>> p;
    for(lld i = 0; i < n; i += 1)
    	p[s[i]].insert(i);

    map <char, set <lld>> x;
    x = p;
    lld A[m];
    lld pov = m+n;
    for(lld i = m-1;i>=0; i -= 1)
    {
    	pov--;
    	if (x[t[i]].count(pov))
    	{
    		A[i] = pov;
    	}
    	else
    	{
    		x[t[i]].insert(pov);
    		auto itr = x[t[i]].find(pov);
    		itr--;
    		A[i] = *itr;
    		x[t[i]].erase (pov);
    	}
    	pov = A[i];
    }
    lld pos = -1;
    lld dis, ans = MIN;
    for(lld i = 0; i<m-1; i += 1)
    {
    	pos++;
    	if (p[t[i]].count(pos))
    	{
    		dis = pos;
    	}
    	else
    	{
    		p[t[i]].insert(pos);
    		auto itr = p[t[i]].find(pos);
    		itr++;
    		dis = *itr;
    		p[t[i]].erase (pos);
    	}
    	ans = max(ans, A[i+1]-dis);
    	pos = dis;
    }
    cout << ans << "\n";
    return 0;
}