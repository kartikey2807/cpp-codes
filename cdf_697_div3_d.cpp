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
void psort (lld A[], lld B[], lld n)
{
	vector <pair <lld , lld> > v;
	for(lld i = 0; i < n; i += 1)
		v.pb({A[i],B[i]});
	sort(v.begin(),v.end());
	for(lld i = 0; i < n; i += 1)
	{
		A[i] = v[n-i-1].first;
		B[i] = v[n-i-1].second;
	}
}
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
    	lld A[n],B[n];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	for(lld i = 0; i < n; i += 1)
    		cin >> B[i];

    	psort(A,B,n);

    	vector <pair <lld , lld> > v;
    	for(lld i = 0; i < n; i += 1)
    		if (B[i] == 1)
    			v.pb({A[i], B[i]});
    	reverse(v.begin(),v.end());
    	for(lld i = 0; i < n; i += 1)
    		if (B[i] == 2)
    			v.pb({A[i], B[i]});

    	lld sum = 0;
    	for(lld i = 0; i < n; i += 1)
    		sum += A[i];

    	if (sum < m)
    	{
    		cout << "-1\n";
    	}
    	else
    	{
    		lld sum = 0;
    		lld cnt = 0;
    		lld ans = MAX;
    		queue <pair <lld, lld> > q;
    		for(lld i = 0; i < v.size(); i += 1)
    		{
    			q.push(v[i]);
    			sum += v[i].first;
    			cnt += v[i].second;
    			while(1)
    			{
    				pair <lld, lld> p = q.front();
    				lld x = p.first;
    				lld y = p.second;
    				if (sum-x >= m)
    				{
    					sum-= x;
    					cnt-= y;
    					q.pop();
    				}
    				else
    				{
    					break;
    				}
    			}
    			if (sum >= m)
    				ans = min(ans, cnt);
    		}
    		cout << ans << "\n";
    	}
    }
    return 0;
}