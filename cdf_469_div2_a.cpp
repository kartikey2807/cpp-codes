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
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	lld l, r, a;
	cin >> l >> r >> a;
	lld max = l > r ? l : r;
	lld min = l < r ? l : r;
	lld gap = max - min;
	if (a >= gap){
		a-=gap;
		min = max;
		a/=2;
		min+= a;
		max+= a;
		cout << (min+max);
	}
	else{
		min += a;
		cout << (2 * min);
	}
	return 0;
}