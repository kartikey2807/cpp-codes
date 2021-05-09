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
    lld n;
    cin >> n;
    lld pos = 0;
    stack <lld> stk;
    vector <lld> v (n);
    vector <pair <char, lld> > seq;
    for(lld i = 0; i < (2*n); i += 1){
    	char c;
    	cin >> c;
    	if (c == '+'){
    		seq.pb({c,0});
    		stk.push(pos++);
    	}
    	if (c == '-'){
    		lld x;
    		cin >> x;
    		seq.pb({c,x});
    		if (stk.empty()){
    			cout << "NO";
    			return 0;
    		}
    		else{
    			lld val = stk.top();
    			v[val]= x;
    			stk.pop();
    		}
    	}
    }
    pos = 0;
    set <lld> check;
    for(lld i = 0; i < (2*n); i += 1){
    	if (seq[i].first == '+'){
    		check.insert(v[pos]);
    		pos++;
    	}
    	else{
    		auto itr = check.begin();
    		if (*itr!= seq[i].second){
    			cout << "NO";
    			return 0;
    		}
    		check.erase(*itr);
    	}
    }
    cout << "YES\n";
    for(auto itr : v)
    	cout << itr << " ";
    return 0;
}