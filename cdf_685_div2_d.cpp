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
    	lld d, k;
    	cin >> d >> k;
    	lld c = 0, x = 0, y = 0, p = 0;
    	while(1){
    		if (c%2){
    			if (pow(x,2)+pow(y+k,2) <= pow(d,2))
    				y+= k;
    			else{
    				p = 1;
    				break;
    			}
    		}
    		else{
    			if (pow(x+k,2)+pow(y,2) <= pow(d,2))
    				x+= k;
    			else{
    				p = 2;
    				break;
    			}
    		}
    		c++;
    	}
    	if (p == 1) cout << "Ashish\n";
    	else cout << "Utkarsh\n";
    }
    return 0;
}