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
#define LEN 100001
lld vis[LEN];
set <lld>  cnt[LEN];
vector <lld> v[LEN];
vector <lld> c(LEN);
void dfs (lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (c[v[pos][i]] != c[pos])
			cnt[c[pos]].insert(c[v[pos][i]]);
	}
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1)
			dfs(v[pos][i]);
	}
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, m;
    cin >> n >> m;
    for(lld i = 1; i<= n; i += 1){
    	cin >> c[i];
    }
    for(lld i = 0; i < m; i += 1){
    	lld x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    memset(vis, -1, sizeof(vis));
    for(lld i = 1; i<= n; i += 1){
    	if (vis[i] == -1)
    		dfs(i);
    }
    lld ans = MIN;
    for(lld i = 1; i<= n; i += 1)
    	ans = max(ans,(lld)cnt[c[i]].size());
    lld pos = MAX;
    for(lld i = 1; i<= n; i += 1)
    	if (ans == (lld)cnt[c[i]].size())
    		pos = min(pos,c[i]);
    cout << pos;
    return 0;
}