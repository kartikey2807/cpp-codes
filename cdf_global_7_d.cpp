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
bool check (string s)
{
	lld len = s.length();
	for(lld i = 0; i < (len/2); i+= 1){
		if (s[i] != s[len-i-1])
			return false;
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
      lld t, w;
      cin >> t;
      foi(w,t){
      	string s;
      	cin >> s;
      	lld n = s.length();
      	lld l = 0, r = n-1;
      	while(l < r){
      		if (s[l] != s[r])
      			break;
      		l++;
      		r--;
      	}
      	if (l >= r){
      		cout << s << "\n";
      		continue;
      	}
      	string t = "";
      	string p;
      	for(lld i = l; i <= r; i += 1){
      		t += s[i];
      		if (check(t))
      			p = t;
      	}
      	t = "";
      	string q;
      	for(lld i = r; i >= l; i -= 1){
      		t = s[i]+t;
      		if (check(t))
      			q = t;
      	}
      	if (p.length() > q.length()){
      		for(lld i = l-1; i >=0; i -= 1)
      			p = s[i]+p;
      		for(lld i = r+1; i < n; i += 1)
      			p = p+s[i];
      		cout << p << "\n";
      	}
      	else{
      		for(lld i = l-1; i >=0; i -= 1)
      			q = s[i]+q;
      		for(lld i = r+1; i < n; i += 1)
      			q = q+s[i];
      		cout << q <<"\n";
      	}
      }
      return 0;
}