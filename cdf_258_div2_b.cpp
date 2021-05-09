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
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      vector <lld> index, seg;
      for(lld i = 0; i < n; i += 1){
      	lld r;
      	cin >> r;
      	index.push_back(r);
      }
      lld pos =  -1;
      for(lld i = 1; i < n; i += 1){
      	if(index[i]<index[i-1]){
      		pos = i-1;
      		break;
      	}
      }
      if (pos == -1){
      	cout << "yes\n";
      	cout << "1 1";
      }
      else{
      	lld p = n;
      	seg.push_back(index[pos]);
      	for(lld i = pos+1; i < n; i += 1){
      		if (index[i] >  index[i-1]){
      			p = i;
      			break;
      		}
      		seg.push_back(index[i]);
      	}
      	vector <lld> v;
      	for(lld i = 0; i < pos; i ++){
      		v.push_back(index[i]);
      	}
      	for(lld i = seg.size()-1; i >= 0; i -= 1){
      		v.push_back(seg[i]);
      	}
      	for(lld i = p; i < n; i += 1){
      		v.push_back(index[i]);
      	}
      	sort(index.begin(), index.end());
      	lld f = 1;
      	for(lld i = 0; i < n; i += 1){
      		if (v[i] != index[i]){
      			f = 0;
      			break;
      		}
      	}
      	if (f == 1){
      		cout << "yes\n";
      		cout << pos+1 << " " << p << "\n";
      	}
      	else{
      		cout <<  "no\n";
      	}
      }
      return 0;
}