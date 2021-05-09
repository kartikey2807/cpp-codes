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
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld t, l;
    cin >> t;
    foi(l,t){
    	lld n, p, k;
    	cin >> n >> p >> k;
    	string s;
    	lld x, y;
    	cin >> s >> x >> y;
    	lld A[n+1];
    	for(lld i = 1; i <= n; i += 1){
    		A[i] = (lld)s[i-1]-48;
    	}
    	lld cnt = 0;
    	lld ans = MAX;
    	map <lld, lld> vis;
    	for(lld i = p; i <= n; i += 1){
    		if (!vis.count(i)){
    			vector <lld> temp;
    			for(lld j = i; j <= n; j += k)
    				temp.push_back(j);
    			reverse(temp.begin(),temp.end());
    			lld gin = 0;
    			for(auto itr : temp){
    				if (A[itr] == 0){
    					gin++;
    				}
    				vis[itr] = gin;
    			}
    		}
    		ans = min(ans,(cnt*y)+(vis[i]*x));
    		cnt++;
    	}
    	cout << ans << "\n";
    }
    return 0;
}