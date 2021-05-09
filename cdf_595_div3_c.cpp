// みなさん私はカーティキー・シャルマです。LNMIITで勉強しています。私は2年目で、コロナパンデミックが発
// 生しています。世界は終わりそうだ。だから私はそれを最大限に生きたいと思っています。それはつまり、コー
// ドを最大限に意味しているのです。私の好きなアニメは「キメツノヤイバ」で、私の一番の男の子はゼニツで、
// 私の一番の女の子はネズコです。私の好きな呼吸スタイルは息吹です。私の最高の悪魔の血の芸術は、
// ククシボによって使用される月の息です。ムーザンは亡くなり、今ではタンジローがポップの新しい魔王です。
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
bool check (lld x)
{
	while(x){
		if (x%3 == 2)
			return false;
		x/= 3;
	}
	return true;
}
lld prod (lld x)
{
	lld temp = x, c = 0;
	vector <lld> v;
	while(x){
		v.push_back(x%3);
		c+= 1;
		x/= 3;
	}
	lld p;
	lld n = v.size();
	reverse(v.begin(), v.end());
	for(lld i = 0; i < n; i+=1){
		if (v[i] == 2){
			p = i;
			break;
		}
	}
	lld r = -1;
	for(lld i = 0; i < n; i+=1){
		if (v[i] == 0){
			if (i<p){
				r = i;
			}
		}
	}
	if (r == -1){
		return pow(3, n);
	}
	else{
		lld sum = 0;
		lld c = n-1;
		for(lld i = 0; i < r; i+= 1){
			sum += (v[i]*pow(3,c));
			c--;
		}
		sum += pow(3,c);
		return sum;
	}
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
      	lld n;
      	cin >> n;
      	if (check(n)) cout << n << "\n";
      	else cout << prod(n) << "\n";
      }
      return 0;
}