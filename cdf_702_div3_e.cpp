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
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1)
		P[i]  = {A[i],B[i]};
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1)
	{
		A[i]  = P[i].first;
		B[i]  = P[i].second;
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
    	lld n;
    	cin >> n;
    	lld A[n], B[n], C[n];
    	for(lld i = 0; i < n; i += 1)
    	{
    		cin >> A[i];
    		B[i] =  i+1;
    	}
    	psort(A,B,n);
    	lld sum  = 0;
    	for(lld i = 0; i < n; i += 1)
    	{
    		sum += A[i];
    		C[i] = sum;
    	}
    	vector <lld> po;
    	po.pb(B[n-1]);
    	for(lld i = n-2; i >= 0; i -= 1)
    	{
    		if (C[i] >= A[i+1])
    			po.pb(B[i]);
    		else
    			break;
    	}
    	sort(po.begin(),po.end());
    	cout << po.size() << "\n";
    	
    	for(lld i = 0; i < po.size(); i += 1)
    		cout << po[i] << " ";
    	cout << "\n";
    }
    return 0;
}