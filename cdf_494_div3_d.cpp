// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
vector <lld> get_(lld x)
{
	vector <lld> ans;
	while(x)
		{ans.pb(x%2); x/=2;}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, q;
      cin >> n >> q;
      lld A[n];
      map <lld, lld> cnt;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	cnt[A[i]]++;
      }
      while(q--){
      	lld b;
      	cin >> b;
      	vector <lld> bin = get_(b);
      	lld val = bin.size()-1;
      	lld f = 1;
      	for(lld i = 0; i < bin.size(); i += 1){
      		if (bin[i] != 0){
      			if (bin[i] > cnt[pow(2,val)]){
      				lld x = bin[i]-cnt[pow(2,val)];
      				bin[i]=cnt[pow(2,val)];
      				x *= 2;
      				if (val == 0)
      					{f  = 0; break;}
      				else
      					{bin[i+1] += x;}
      			}
      		}
      		val -= 1;
      	}
      	if (f == 0)
      		cout << "-1\n";
      	else{
      		lld ans = 0;
      		for(lld i = 0; i < bin.size(); i += 1){
      			// cout << bin[i] << " ";
      			ans += bin[i];
      		}
      		cout << ans << "\n";
      	}
      }
      return 0;
}