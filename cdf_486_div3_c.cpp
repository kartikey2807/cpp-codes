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
      lld k;
      cin >> k;
      lld Len[k];
      map <lld, vector<pair<lld, lld> > > sick;
      for(lld i = 0; i < k; i += 1){
      	cin >> Len[i];
      	lld A[Len[i]];
      	lld sum = 0;
      	for(lld j = 0; j < Len[i]; j += 1){
      		cin >> A[j];
      		sum += A[j];
      	}
      	for(lld j = 0; j < Len[i]; j += 1){
      		lld diff = sum-A[j];
      		sick[diff].push_back({i, j});
      	}
      }
      for(map <lld, vector<pair<lld, lld> > > :: iterator itr = sick.begin(); itr!=sick.end(); itr++){
      	vector <pair<lld, lld> > v = itr->second;
      	if (v.size() >= 2){
      		for(lld i = 1; i < v.size(); i += 1){
      			if (v[0].first !=  v[i].first){
      				cout << "YES\n";
      				cout << v[0].first+1 << " " << v[0].second+1 << "\n";
      				cout << v[i].first+1 << " " << v[i].second+1 << "\n";
      				return 0;
      			}
      		}
      	}
      }
      cout << "NO";
      return 0;
}