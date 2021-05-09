#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
lld gcd_ (lld a, lld b)
{
	lld max = a > b ? a : b;
	lld min = a < b ? a : b;
	while (min != 0){
		lld rem = max%min;
		max = min;
		min = rem;
	}
	return max;
}
lld common (lld n)
{
	set <lld> s;
	for(lld j = 1; j <= n; j += 1){
		s.insert((j*n)/gcd_(j,n));
	}
	return s.size();
}
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	lld n, i;
	cin >> n;
	for(i = 1; i <= n; i++){
		cout << common(i) << "\n";
	}
	return 0;
}