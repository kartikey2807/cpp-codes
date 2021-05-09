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
#define LEN 6000
lld vis[LEN];
vector <lld> order;
lld calc (lld x, lld y){ return (((x+y)*(x+y+1))/2)+y; }
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	order.pb(pos);
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
    lld t;
    cin >> t;
    while(t--){
    	lld n, m;
    	cin >> n >> m;
    	char dd[n+1][m+1];
    	for(lld i = 1; i <= n; i += 1){
    		for(lld j = 1; j <= m; j += 1){
    			cin >> dd[i][j];
    		}
    	}
    	// 1-indexed
    	vector <lld> v[LEN];
    	for(lld i = 1; i <= n; i += 1){
    		for(lld j = 2; j <= m; j += 1){
    			if (dd[i][j] != '#' && dd[i][j-1] != '#'){
    				v[calc(i,j)].pb(calc(i,j-1));
    				v[calc(i,j-1)].pb(calc(i,j));
    			}
    		}
    	}
    	for(lld j = 1; j <= m; j += 1){
    		for(lld i = 2; i <= n; i += 1){
    			if (dd[i][j] != '#' && dd[i-1][j] != '#'){
    				v[calc(i,j)].pb(calc(i-1,j));
    				v[calc(i-1,j)].pb(calc(i,j));
    			}
    		}
    	}
    	memset(vis, -1, sizeof(vis));
    	order.clear();
    	dfs(v,calc(n,m));
    	for(lld i = 1; i <= n; i += 1){
    		for(lld j = 1; j <= m; j += 1){
    			if (dd[i][j] == 'B' && vis[calc(i,j)]==1){
    				if (i > 1 && vis[calc(i-1,j)] == 1 && dd[i-1][j] == '.')
    					dd[i-1][j] = '#';
    				if (i < n && vis[calc(i+1,j)] == 1 && dd[i+1][j] == '.')
    					dd[i+1][j] = '#';
    				if (j > 1 && vis[calc(i,j-1)] == 1 && dd[i][j-1] == '.')
    					dd[i][j-1] = '#';
    				if (j < m && vis[calc(i,j+1)] == 1 && dd[i][j+1] == '.')
    					dd[i][j+1] = '#';
    			}
    		}
    	}
    	vector <lld> g[LEN];
    	for(lld i = 1; i <= n; i += 1){
    		for(lld j = 2; j <= m; j += 1){
    			if (dd[i][j] != '#' && dd[i][j-1] != '#'){
    				g[calc(i,j)].pb(calc(i,j-1));
    				g[calc(i,j-1)].pb(calc(i,j));
    			}
    		}
    	}
    	for(lld j = 1; j <= m; j += 1){
    		for(lld i = 2; i <= n; i += 1){
    			if (dd[i][j] != '#' && dd[i-1][j] != '#'){
    				g[calc(i,j)].pb(calc(i-1,j));
    				g[calc(i-1,j)].pb(calc(i,j));
    			}
    		}
    	}
    	memset(vis, -1, sizeof(vis));
    	order.clear();
    	dfs(g,calc(n,m));
    	lld flag = 1, glag = 1;
    	for(lld i = 1; i <= n; i += 1){
    		for(lld j = 1; j <= m; j += 1){
    			if (dd[i][j] == 'G' && vis[calc(i,j)] ==-1)
    				flag = 0;
    			if (dd[i][j] == 'B' && vis[calc(i,j)] == 1)
    				glag = 0;
    		}
    	}
    	if (flag == 1 && glag == 1)
    		cout << "Yes\n";
    	else
    		cout <<  "No\n";
    }
    return 0;
}