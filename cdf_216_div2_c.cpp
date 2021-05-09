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
set <lld> ans;
map <pair <lld, lld>, lld> path;
lld w (lld a, lld b)
{
	if (path[{a,b}] == 2)
		return 1;
	else
		return 0;
}
void dfs (vector <lld> v[], lld pos, lld val)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			if (w(pos,v[pos][i])){
				ans.erase(val);
				ans.insert(v[pos][i]);
				dfs(v,v[pos][i],v[pos][i]);
			}
			else{
				dfs(v,v[pos][i], val);
			}
		}
	}
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
    vector <lld> v[n+1];
    for(lld i = 0; i < n-1; i += 1){
    	lld x, y, t;
    	cin >> x >> y >> t;
    	v[x].push_back(y);v[y].push_back(x);
    	path[{x,y}]=path[{y,x}] = t;
    }
    memset(vis,-1, sizeof(vis));
    dfs(v,1,0);
    cout << ans.size() << "\n";
    for(auto itr = ans.begin(); itr != ans.end(); itr++)
    	cout << *itr << " ";
    return 0;
}