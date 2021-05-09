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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      string x = "CODEFORCES";
     	if (s.length() < x.length()){
     		cout << "NO";
     		return 0;
     	}
     	queue <char> a;
     	queue <char> t;
     	vector <lld> v;
     	for(lld i = 0; i < x.length(); i += 1){
     		a.push(x[i]);
     		t.push(s[i]);
     	}
     	if (a == t){
     		v.push_back(0);
     	}
     	lld LEN = s.length();
     	lld len = x.length();
     	for(lld i = 1; i < LEN-len+1; i += 1){
     		t.pop();
     		t.push(s[i+len-1]);
     		if (t == a){
     			v.push_back(i);
     		}
     	}
     	lld l = v.size();
     	if (l > 0 && (v[0] == 0 || v[l-1] == (LEN-len))){
     		cout << "YES";
     		return 0;
     	}
     	for(lld i = 0; i < len-1; i += 1){
     		queue <char> a;
     		queue <char> b;
     		for(lld j = 0; j <= i; j += 1){
     			a.push(x[j]);
     		}
     		for(lld j = i+1; j < len; j += 1){
     			b.push(x[j]);
     		}
     		lld f = -1;
     		lld g = -1;
     		queue <char>temp1;
     		queue <char>temp2;
     		lld l1 = a.size();
     		lld l2 = b.size();
     		for(lld j = 0; j < l1; j += 1){
     			temp1.push(s[j]);
     		}
     		if (a == temp1){
     			f = 0;
     		}
     		for(lld j = 0; j < l2; j += 1){
     			temp2.push(s[j]);
     		}
     		if (b == temp2){
     			g = 0;
     		}
     		for(lld j = 1; j < LEN-l2+1; j += 1){
     			temp2.pop();
     			temp2.push(s[j+l2-1]);
     			if (temp2 == b){
     				g = j;
     			}
     		}
     		if (f == 0 && g == (LEN-l2)){
     			cout << "YES";
     			return 0;
     		}
     	}
     	cout << "NO";
      return 0;
}