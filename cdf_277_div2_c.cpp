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
void get_min (lld m, lld s)
{
	vector <lld> v (m);
	lld pos = m-1;
	while (s > 1){
		if (s > 9){
			v[pos] = 9;
			pos--;
			s-= 9;
		}
		else{
			v[pos] = s-1;
			pos--;
			s = 1;
		}
	}
	while(pos >= 0){
		v[pos]=0;
		pos--;
	}
	v[0] += 1;
	for(lld i = 0; i < m; i += 1){
		cout << v[i];
	}
	cout << " ";
}
void get_max (lld m, lld s)
{
	vector <lld> v;
	lld count =  0;
	while(s){
		if (s > 9){
			v.push_back(9);
			s-= 9;
		}
		else{
			v.push_back(s);
			s = 0;
		}
	}
	lld L = v.size();
	while(L < m){v.push_back(0); L++;}
	for(lld i = 0; i < m; i += 1){
		cout << v[i];
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld m, s;
      cin >> m >> s;
      if (s == 0 && m == 1){
      	cout << "0 0";
      }
      else{
      	if (s > (9*m) || (s == 0 && m != 1)){
      		cout << "-1 -1";
      	}
      	else{
      		get_min(m, s);
      		get_max(m, s);
      	}
      }
      return 0;
}