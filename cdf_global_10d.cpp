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
vector <lld> cnt(25);
void calc(lld x)
{
	vector <lld>ans;
	while(x){
		ans.pb(x%2);
		x/=2;
	}
	for(lld i = 0; i < ans.size(); i += 1)
		if (ans[i] == 1)
			cnt[i] += 1;
}
lld val (vector <lld> ans)
{
	lld sum = 0;
	for(lld i = 0; i < ans.size(); i += 1)
		sum += pow(2,i)*ans[i];
	return sum;
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n;
    cin >> n;
    lld A[n];
    for(lld i = 0; i < n; i += 1){
    	cin >> A[i];
    }
    for(lld i = 0; i < n; i += 1){
    	calc(A[i]);
    }
    lld res = 0;
    for(lld i = 0; i < n; i += 1){
    	vector <lld> ans(25);
    	for(lld j = 0; j < cnt.size(); j += 1){
    		if (cnt[j] >= 1){
    			ans[j] = 1;
    			cnt[j]-= 1;
    		}
    	}
    	lld temp = val(ans);
    	res += temp*temp;
    }
    cout << res;
    return 0;
}