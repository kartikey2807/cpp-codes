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
    	string s;
    	cin >> n >> s;
    	string s1, s2, s3;
    	for(lld i = 0; i < 4; i += 1){
    		s1 += s[i];
    	}
    	lld f = 0;
    	if (s1  == "2020")
    		f = 1;
    	lld srt = 3;
    	lld end = n-1;
    	while (1){
    		s1 = s.substr(0,srt);
    		s2 = s[end]+s2;
    		s3 = s1+s2;
    		if (s3 == "2020")
    			f = 1;
    		srt--;
    		end--;
    		if (srt == -1)
    			break;
    	}
    	if (f == 1)
    		cout << "YES\n";
    	else
    		cout <<  "NO\n";
    }
    return 0;
}