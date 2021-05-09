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
map <lld, lld> cnt;
vector <lld> get_str (lld x)
{
	vector <lld> res;
	while(x){
		res.push_back(x%2);
		x /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}
lld reduce (vector <lld> x)
{
	lld p = 0;
	lld sum = 0;
	for(lld i = x.size()-1; i >= 0; i -= 1){
		sum += x[i]*(pow(2,p));
		p++;
	}
	return sum;
}
lld check (lld val)
{
	vector <lld> v = get_str(val);
	vector <lld> x;
	lld f = 0;
	for(lld i = v.size()-1; i >= 0; i -= 1){
		if (f == 0){
			if (v[i] == 0){x.push_back(0);}
			else{x.push_back(1);f = 1;}
		}
		else{
			if (v[i] == 0){x.push_back(1);}
			else{x.push_back(0);}
		}
	}
	reverse(x.begin(), x.end());
	lld y = reduce(x);
	lld sum = 0;
	if (val == y)sum = cnt[y]-1;
	else sum = cnt[y];
	lld len = x.size();
	while(len <= 32){
		x.insert(x.begin(),1);
		y = reduce(x);
		sum += cnt[y];
		len++;
	}
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
      for(lld i = 0; i < n; i += 1)
      	cin >> A[i];
      for(lld i = 0; i < n; i += 1)
      	cnt[A[i]]++;
      lld sum = 0;
      for(lld i = 0; i < n; i += 1)
      	sum += check(A[i]);
      cout << sum/2;
      return 0;
}