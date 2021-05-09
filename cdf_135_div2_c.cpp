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
lld diff (string s, string t)
{
	lld c = 0;
	for(lld i = 0; i < s.size(); i += 1){
		if (s[i] != t[i])
			c++;
	}
	return c;
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 2){
    	string t1 = "";
    	string t2 = "";
    	for(lld i = 0; i < n; i += 1){
    		if (i%2 == 0)
    			t1+= 'A';
    		else
    			t1+= 'B';
    	}
    	for(lld i = 0; i < n; i += 1){
    		if (i%2 == 0)
    			t2+= 'B';
    		else
    			t2+= 'A';
    	}
    	if (diff(s,t1) <= diff(s,t2)){
    		cout << diff(s,t1) <<"\n";
    		cout << t1 << "\n";
    	}
    	else{
    		cout << diff(s,t2) <<"\n";
    		cout << t2 << "\n";
    	}
    }
    else{
    	lld cnt = 0;
    	s += '?';
    	for(lld i = 1; i < n; i += 1){
    		if (s[i] == s[i-1]){
    			cnt++;
    			for(lld j = 0; j < k; j += 1){
    				char c = (char)(j+65);
    				if (c != s[i-1] && c != s[i+1]){
    					s[i] = c;
    					break;
    				}
    			}
    		}
    	}
    	cout << cnt << "\n";
    	for(lld i = 0; i < n; i += 1){
    		cout << s[i];
    	}
    }
    return 0;
}