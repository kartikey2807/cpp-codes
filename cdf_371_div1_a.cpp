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
string conv (lld x)
{
	lld temp = x;
	vector <lld> v;
	while (x != 0){
		if ((x%10) % 2 == 0){
			v.push_back(0);
		}
		else{
			v.push_back(1);
		}
		x /= 10;
	}
	reverse(v.begin(),v.end());
	string s = "";
	for(lld i = 0; i < v.size(); i += 1){
		s += (char)(v[i]+48);
	}
	lld len = s.length();
	while (len<18){
		s = '0'+s;
		len++;
	}
	return s;
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
      map <string, lld> count;
      for(lld i = 0; i < n; i += 1){
      	lld x;
      	char c;
      	cin >> c >> x;
      	if (c == '+'){
      		string a = conv(x);
      		count[a]++;
      	}
      	if (c == '-'){
      		string a = conv(x);
      		count[a]--;
      	}
      	if (c == '?'){
      		string a = conv(x);
      		cout << count[a] << "\n";
      	}
      }
      return 0;
}