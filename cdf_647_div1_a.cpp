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
#define LEN 600000
lld vis[LEN];
lld val[LEN];
lld f;
set <lld>fix;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1)
		fix.erase(val[v[pos][i]]);
	auto itr = fix.begin();
	if (val[pos] !=(*itr))
		f = 0;
	for(lld i = 0; i < v[pos].size(); i += 1)
		fix.insert(val[v[pos][i]]);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
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
    vector <lld> v[n+1];
    for(lld i = 0; i < m; i += 1){
    	lld x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    for(lld i = 1; i <=n; i += 1){
    	cin >> val[i];
    }
    for(lld i = 1; i <=n; i += 1){
    	fix.insert(i);
    }
    memset(vis, -1, sizeof(vis));
    lld flag  = 1;
    for(lld i = 1; i <=n; i += 1){
    	if (vis[i] == -1){
    		f = 1;
    		dfs(v,i);
    		if (f == 0)
    			flag=0;
    	}
    }
    if (flag == 0){
    	cout<<"-1";
    }
    else{
    	vector <lld> topic[n+1];
    	for(lld i = 1; i <= n; i += 1){
    		topic[val[i]].pb(i);
    	}
    	for(lld i = 1; i <= n; i += 1){
    		for(auto itr : topic[i])
    			cout << itr << " ";
    	}
    }
    return 0;
}