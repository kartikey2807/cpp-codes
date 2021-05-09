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
lld arranged (lld A[], lld n)
{
	for(lld i = 1; i < n; i += 1)
		if (A[i] < A[i-1])
			return 0;
	return 1;
}
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
    	lld n, x;
    	cin >> n >> x;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1){
    		cin >> A[i];
    	}
    	lld cnt = 0;
    	while(!arranged(A,n)){
    		lld i;
    		for(i = 1; i < n; i += 1){
    			if (A[i] < A[i-1])
    				break;
    		}
    		if (A[i-1] > x){
    			for(lld j = 0; j < i; j += 1){
    				if (A[j] > x){
    					cnt++;
    					swap(A[j],x);
    				}
    			}
    		}
    		else
    			break;
    	}
    	if (arranged(A,n))
    		cout << cnt << "\n";
    	else
    		cout << "-1"<< "\n";
    }
    return 0;
}