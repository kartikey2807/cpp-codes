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
vector <lld> vl, vr;
vector <lld> get_ (lld x)
{
	vector <lld> ans;
	while(x){
		ans.push_back(x%10);
		x/=10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
vector <lld> update (vector <lld> v, lld k)
{
	reverse(v.begin(), v.end());
	vector <lld> ans;
	lld carry = 0;
	for(lld i = 0; i < v.size(); i += 1){
		ans.push_back(((k*v[i])+carry)%10);
		carry = ((k*v[i])+carry)/10;
	}
	while(carry){
		ans.push_back(carry%10);
		carry /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
bool check1 (vector <lld> v)
{
	if (v.size() < vl.size()){
		return false;
	}
	if (v.size()== vl.size()){
		for(lld i = 0; i < v.size(); i += 1){
			if (v[i] != vl[i]){
				if (v[i] < vl[i])
					{return false;}
				break;
			}
		}
	}
	return true;
}
bool check2 (vector <lld> v)
{
	if (v.size() > vr.size()){
		return false;
	}
	if (v.size()== vr.size()){
		for(lld i = 0; i < v.size(); i += 1){
			if (v[i] != vr[i]){
				if (v[i] > vr[i])
					{return false;}
				break;
			}
		}
	}
	return true;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld l, r, k;
      cin >> l >> r >> k;
      vl = get_(l);
      vr = get_(r);
      vector <lld> v;
      v.push_back(1);
      lld f = 0;
      while(true){
      	if (!check2(v))
      		break;
      	if (check1(v) && check2(v)) {f = 1; foi(i,v.size()) cout << v[i]; cout << " ";}
      	v = update(v,k);
      }
      if (f == 0) cout << "-1";
      return 0;
}