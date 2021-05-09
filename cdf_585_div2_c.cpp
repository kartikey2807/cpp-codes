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
      lld n;
      string a;
      string b;
      cin >> n >> a >> b;
      lld count_a = 0, count_b = 0;
      for(lld i = 0; i < n; i += 1){
      	switch(a[i]){
      		case 'a' : count_a++; break;
      		case 'b' : count_b++; break;
      	}
      	switch(b[i]){
      		case 'a' : count_a++; break;
      		case 'b' : count_b++; break;
      	}
      }
      if (count_b%2 == 0 && count_a%2 == 0){
      	vector <lld> p1;
      	vector <lld> p2;
      	for(lld i = 0; i < n; i += 1){
      		if (a[i] == 'a' && b[i] == 'b')
      			p1.push_back(i);
      		if (a[i] == 'b' && b[i] == 'a')
      			p2.push_back(i);
      	}
      	vector <pair <lld, lld> > p;
      	lld len1 = p1.size();
      	lld len2 = p2.size();
      	for(lld i = 1; i < len1; i += 2)
      		p.push_back({p1[i],p1[i-1]});
      	for(lld i = 1; i < len2; i += 2)
      		p.push_back({p2[i],p2[i-1]});
      	if (len1%2 != 0){
      		p.push_back({p2[len2-1],p2[len2-1]});
      		p.push_back({p1[len1-1],p2[len2-1]});
      	}
      	cout << p.size() << "\n";
      	foi(i, p.size())
      		cout << p[i].first+1 << " " << p[i].second+1 << "\n";
      }
      else cout << "-1";
      return 0;
}