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
#define LEN 200000
lld vis[LEN];
lld val[LEN];
lld dfs (vector <lld> v[], lld pos, lld n)
{
	vis[pos] = 1;
	lld sum = 0;
	lld ans = MIN;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			lld x = dfs(v,v[pos][i],n);
			sum += x;
			ans = max(ans,x);
		}
	}
	ans = max(ans,n-sum-1);
	val[pos] = ans;
	return (sum+1);
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
    	lld n;
    	cin >> n;
    	vector <lld> v[n+1];
    	for(lld i = 1; i < n; i += 1){
    		lld x, y;
    		cin >> x >> y;
    		v[x].pb(y);
    		v[y].pb(x);
    	}
    	memset(val,  0, sizeof(val));
    	memset(vis, -1, sizeof(vis));
    	dfs(v,1,n);
    	lld ans = MAX;
    	for(lld i = 1; i <=n; i += 1)
    		ans = min(ans,val[i]);
    	vector <lld> points;
    	for(lld i = 1; i <=n; i += 1)
    		if (ans == val[i])
    			points.pb(i);
    	if (points.size() == 1){
    		cout << points[0] << " " << v[points[0]][0] << "\n";
    		cout << points[0] << " " << v[points[0]][0] << "\n";
    	}
    	else{
    		for(lld i = 0; i < v[points[0]].size(); i += 1){
    			if (v[points[0]][i] != points[1]){
    				cout << points[0] << " " << v[points[0]][i] << "\n";
    				cout << points[1] << " " << v[points[0]][i] << "\n";
    				break;
    			}
    		}

    	}
    }
    return 0;
}