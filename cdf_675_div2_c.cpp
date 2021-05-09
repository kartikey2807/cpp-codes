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
lld pow_ (lld a, lld n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n%2==0) return ((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD;
	else return ((((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD)*(a%MOD))%MOD;
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    string s;
 	cin >> s;
 	lld n = s.size();
 	lld A[n];
 	for(lld i = 0; i < n; i += 1){
 		A[i]  = (lld)s[i]-48;
 	}
 	lld sum = 0;
 	lld acc = 0;
 	for(lld i = n-1;i>=0; i -= 1){
 		acc = ((acc%MOD)+((((n-i-1)%MOD)*(pow_(10,n-i-2)%MOD))%MOD))%MOD;
 		sum = ((sum%MOD)+(((((((((i*(i+1))/2)%MOD)*(A[i]%MOD))%MOD)*(pow_(10,n-i-1)%MOD))%MOD)+(((A[i]%MOD)*(acc%MOD))%MOD))%MOD))%MOD;
 	}
 	cout << sum%MOD;
    return 0;
}