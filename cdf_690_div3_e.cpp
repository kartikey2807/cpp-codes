// Always prefer arrays over data structures
// Code style can go to hell
// Make strong test cases if doubtful
// Read the code atleast once before submitting.
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define MOD 1000000007
#define LEN 300000
lld fac[LEN];
lld inv[LEN];
lld ifac[LEN];
void init_fac ()
{
	fac[0] = 1;
	fac[1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		fac[i] = fac[i-1]*i%MOD;
	}
}
void init_ifac()
{
	ifac[0] = 1;
	ifac[1] = 1;
	inv [1] = 1;
	for(lld i = 2; i < LEN; i += 1){
		inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
		ifac[i]= ifac[i-1]*inv[i]%MOD;
	}
}
lld nCr (lld n, lld r)
{
	if (n < r || n < 0 || r < 0)
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
    init_fac ();
    init_ifac();
    lld t;
    cin >> t;
    while(t--){
    	lld n, m, k;
    	cin >> n >> m >> k;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1){
    		cin >> A[i];
    	}
    	sort(A,A+n);
    	if (m >= 2){
    		vector <lld> val (n);
    		for(lld i = 0; i < n; i += 1){
    			lld pos = upper_bound(A+0,A+n,A[i]+k)-(A+0);
    			pos--;
    			if (pos-i-1 >= m-2)
    				val[pos-i-1]++;
    		}
    		lld acc = 0;
    		lld sum = 0;
    		for(lld i = n-1;i>=0; i -= 1){
    			sum = ((sum%MOD)+(val[i]%MOD))%MOD;
    			acc = ((acc%MOD)+(((sum%MOD)*(nCr(i,m-2)%MOD))%MOD))%MOD;
    		}
    		cout <<acc<< "\n";
    	}
    	else
    		cout << n << "\n";
    }
    return 0;
}