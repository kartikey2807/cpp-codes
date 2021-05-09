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
lld lcm (lld a, lld b)
{
	lld x = max(a,b);
	lld y = min(a,b);
	while(y){
		lld rem = x%y;
		x = y;
		y = rem;
	}
	return ((a*b)/x);
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n;
    cin >> n;
    if (n == 1 || n == 2){
    	cout << n;
    	return  0;
    }
    cout << max(max(lcm(n,lcm(n-1,n-2)), lcm(n,lcm(n-1,n-3))), lcm(n-1,lcm(n-2,n-3)));
    return 0;
}