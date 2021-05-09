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
    lld t;
    cin >> t;
    while(t--){
    	lld n, m;
    	cin >> n >> m;
    	map <lld, lld> mark;
    	pair <lld,lld> c[m];
    	map <pair<lld, lld>, lld> mac;
    	for(lld i = 0; i < m; i += 1){
    		cin >> c[i].first>>c[i].second;
    		mark[c[i].second] = c[i].first;
    		mac[c[i]] = i;
    	}
    	lld moves = 0;
    	for(lld i = 0; i < m; i += 1){
    		if (c[i].first != c[i].second){
    			lld x = c[i].first;
    			lld y = c[i].second;
    			set <pair<lld,lld>>vis;
    			set <lld> ypart;
    			lld f = 0;
    			while(true){
    				ypart.insert(y);
    				vis.insert({x, y});
    				if (mark.count(x)){
    					y = x;
    					x = mark[x];
    					if (ypart.count(y)){
    						f = 2;
    						break;
    					}
    				}
    				else{
    					f = 1;
    					break;
    				}
    			}
    			if (f == 1){
    				moves += vis.size();
    			}
    			if (f == 2){
    				moves += vis.size();
    				moves += 1;
    			}
    			for(auto itr : vis){
    				mark.erase(itr.second);
    				mark[itr.first] = itr.first;
    				lld pos = mac[itr];
    				c[pos].first= c[pos].second;
    			}
    		}
    	}
    	cout << moves << "\n";
    }
    return 0;
}