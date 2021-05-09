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
    	lld sum = 0;
    	lld ans = MAX;
    	for(lld i = 0; i < n; i += 1){
    		sum += A[i];
    		lld f = 1;
    		lld acc = 0;
    		lld steps = i;
    		lld moves = 0;
    		for(lld j = i+1; j < n; j += 1){
    			acc += A[j];
    			moves++;
    			if (acc == sum){
    				acc = 0;
    				steps += moves-1;
    				moves = 0;
    			}
    			if (acc  > sum){
    				f = 0;
    				break;
    			}
    		}
    		if (acc > 0)
    			f = 0;
    		if (f == 1)
    			ans = min(ans,steps);
    	}
    	cout << ans << "\n";
    }
    return 0;
}