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
    	cin >> n;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1){
    		cin >> A[i];
    	}
    	if (n == 1){
    		cout << "0\n";
    	}
    	else{
    		lld k = 1;
    		lld m = 0;
    		lld c = 1;
    		for(lld i = 1; i < n; i += 1){
    			if (A[i] < A[i-1]){
    				k--;
    				if (k == 0){
    					k = m;
    					m = 0;
    					c+= 1;
    				}
    			}
    			m+= 1;
    		}
    		cout << c << "\n";
    	}
    }
    return 0;
}