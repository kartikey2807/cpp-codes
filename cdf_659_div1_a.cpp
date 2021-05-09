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
    	lld n;
    	string a, b;
    	cin >> n >> a >> b;
    	lld f = 1;
    	for(lld i = 0; i < n; i += 1){
    		if (a[i] > b[i]){
    			f = 0;
    			break;
    		}
    	}
    	if (f == 0){
    		cout << "-1\n";
    	}
    	else{
    		vector <lld> v[26];
    		for(lld i = 0; i < n; i += 1){
    			v[(lld)a[i]-97].pb(i);
    		}
    		lld cnt = 0;
    		string prev = a;
    		for(char ch = 'a'; ch <= 't'; ch += 1){
    			char ans= 'z';
    			for(lld i = 0; i < v[(lld)ch-97].size(); i += 1){
    				if (a[v[(lld)ch-97][i]]<b[v[(lld)ch-97][i]]){
    					ans = min(ans,b[v[(lld)ch-97][i]]);
    				}
    			}
    			for(lld i = 0; i < v[(lld)ch-97].size(); i += 1){
    				if (a[v[(lld)ch-97][i]]<b[v[(lld)ch-97][i]]){
    					a[v[(lld)ch-97][i]] = ans;
    					v[(lld)ans-97].pb(v[(lld)ch-97][i]);
    				}
    			}
    			if (a != prev)
    				cnt++;
    			if (a == b)
    				break;
    			prev  = a;
    		}
    		cout << cnt << "\n";
    	}
    }
    return 0;
}