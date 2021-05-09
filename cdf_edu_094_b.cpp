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
lld s, w;
lld cnt_s, cnt_w;
lld calc1(lld p, lld f)
{
	lld ans = MIN;
	for(lld i = 0; i <= cnt_s; i += 1){
		lld temp = p;
		temp  -= i*s;
		if (temp>=0){
			lld axes  = min(temp/w, cnt_w);
			lld rem_s = cnt_s-i;
			lld rem_w = cnt_w-axes;
			if (s <= w){
				lld copy = f;
				lld a = min(copy/s, rem_s);
				copy -= a*s;
				lld b = min(copy/w, rem_w);
				ans = max(ans, i+axes+a+b);
			}
			else{
				lld copy = f;
				lld a = min(copy/w, rem_w);
				copy -= a*w;
				lld b = min(copy/s, rem_s);
				ans = max(ans, i+axes+a+b);
			}
		}
	}
	return ans;
}
lld calc2(lld p, lld f)
{
	lld ans = MIN;
	for(lld i = 0; i <= cnt_w; i += 1){
		lld temp = p;
		temp  -= i*w;
		if (temp>=0){
			lld swrd  = min(temp/s, cnt_s);
			lld rem_w = cnt_w-i;
			lld rem_s = cnt_s-swrd;
			if (s <= w){
				lld copy = f;
				lld a = min(copy/s, rem_s);
				copy -= a*s;
				lld b = min(copy/w, rem_w);
				ans = max(ans, i+swrd+a+b);
			}
			else{
				lld copy = f;
				lld a = min(copy/w, rem_w);
				copy -= a*w;
				lld b = min(copy/s, rem_s);
				ans = max(ans, i+swrd+a+b);
			}
		}
	}
	return ans;
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
    while(t--){
    	lld p, f;
    	cin >> p >> f >> cnt_s >> cnt_w >> s >> w;
    	cout << max(max(calc1(p,f),calc2(p,f)),max(calc1(f,p),calc2(f,p))) << "\n";
    }
    return 0;
}