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
    	set <lld>  pres;
    	for(lld i = 1; i <=n; i += 1)
    		pres.insert(i);
    	vector <lld>  v;
    	v.pb(A[0]);
    	pres.erase(A[0]);
    	for(lld i = 1; i < n; i += 1)
    	{
    		if (A[i] == A[i-1])
    		{
    			auto itr = pres.begin();
    			v.pb(*itr);
    			pres.erase(*itr);
    		}
    		else
    		{
    			v.pb(A[i]);
    			pres.erase(A[i]);
    		}
    	}
    	for(lld i = 1; i <=n; i += 1)
    		pres.insert(i);
    	vector <lld>  u;
    	u.pb(A[0]);
    	pres.erase(A[0]);
    	for(lld i = 1; i < n; i += 1)
    	{
    		if (A[i] == A[i-1])
    		{
    			pres.insert(A[i]);
    			auto itr = pres.find(A[i]);
    			itr--;
    			u.pb(*itr);
    			pres.erase(*itr);
    			pres.erase(A[i]);
    		}
    		else
    		{
    			u.pb(A[i]);
    			pres.erase(A[i]);
    		}
    	}
    	for(lld i = 0; i < v.size(); i += 1)
    		cout << v[i] << " ";
    	cout << "\n";
    	for(lld i = 0; i < u.size(); i += 1)
    		cout << u[i] << " ";
    	cout << "\n";
    }
    return 0;
}