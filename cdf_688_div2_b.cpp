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
    lld t, l;
    cin >> t;
    foi(l,t){
    	lld n;
    	cin >> n;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1){
    		cin >> A[i];
    	}
    	lld res;
    	lld ans = 0;
    	for(lld i = n-2;i>=0; i -= 1){
    		ans += abs(A[i+1]-A[i]);
    	}
    	res = ans;
    	for(lld i = n-2;i>=0; i -= 1){
    		lld temp = ans;
    		temp -= abs(A[i+1]-A[i]);
    		if (i > 0){
    			temp -= abs(A[i]-A[i-1]);
    			temp += abs(A[i+1]-A[i-1]);
    		}
    		res = min(res,temp);
    	}
    	for(lld i = n-2;i>=0; i -= 1){
    		lld temp = ans;
    		temp -= abs(A[i+1]-A[i]);
    		if (i < n-2){
    			temp -= abs(A[i+1]-A[i+2]);
    			temp += abs(A[i+2]-A[i]);
    		}
    		res = min(res,temp);
    	}
    	cout << res << "\n";
    }
    return 0;
}