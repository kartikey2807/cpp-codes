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
#define len 2000
#define MOD 1000000007
lld fac[len];
lld inv[len];
lld ifac[len];
void init_fac ()
{
	fac[0] = 1;
	fac[1] = 1;
	for(lld i = 2; i < len; i += 1)
		fac[i] = i*fac[i-1]%MOD;
}
void init_ifac ()
{
	ifac[0] = 1;
	ifac[1] = 1;
	inv [1] = 1;
	for(lld i = 2; i < len; i += 1)
	{
		inv[i] = MOD-(MOD/i)*inv[MOD%i]%MOD;
		ifac[i]= inv[i]*ifac[i-1]%MOD;
	}
}
lld nCr (lld n, lld r)
{
	if (n < r)
		return 0;
	return ((((fac[n]%MOD)*(ifac[r]%MOD))%MOD)*(ifac[n-r]%MOD))%MOD;
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    init_fac();
    init_ifac();
    lld t;
    cin >> t;
    while(t--)
    {
    	lld n, k;
    	cin >> n >> k;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	sort(A,A+n);

    	vector <lld> count(len);
    	vector <lld> contr(len);
    	for(lld i = 0; i < n; i += 1)
    		count[A[i]]++;
   		
    	for(lld i = n-1; i >= 0; i -= 1)
    	{
    		if (k == 0)
    			break;
    		contr[A[i]]++;
    		k--;
    	}
    
    	lld prod = 1;
    	for(lld i = 0; i < len;  i += 1)
    		if (contr[i] < count[i] && contr[i] > 0)
    			prod = ((prod%MOD)*(nCr(count[i],contr[i])%MOD))%MOD;

    	cout << prod << "\n";
    }
    return 0;
}