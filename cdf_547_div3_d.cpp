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
      string s;
      string t;
      cin >> n >> s >>  t;
      map <char, queue<lld> > idx;
      for(lld i = 0; i < n; i += 1){
      	idx[t[i]].push(i);
      }
      vector <pair <lld, lld> > v;
      lld count = 0;
      lld vis[n];
      memset(vis, -1, sizeof(vis));
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != '?'){
      		if (!idx[s[i]].empty()){
      			count++;
      			lld x = idx[s[i]].front();
      			idx[s[i]].pop();
      			vis[i] = 1;
      			v.push_back({i+1,x+1});
      		}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (s[i] == '?'){
      		for(char a = 'a'; a <= 'z'; a++){
      			if (!idx[a].empty()){
      				count++;
      				lld x = idx[a].front();
      				idx[a].pop();
      				vis[i] = 1;
      				v.push_back({i+1,x+1});
      				break;
      			}
      		}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (vis[i] == -1 && s[i] != '?'){
      		if (!idx['?'].empty()){
      			count++;
      			lld x = idx['?'].front();
      			idx['?'].pop();
      			vis[i] = 1;
      			v.push_back({i+1,x+1});
      		}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (vis[i] == -1 && s[i] == '?'){
      		if (!idx['?'].empty()){
      			count++;
      			lld x = idx['?'].front();
      			idx['?'].pop();
      			vis[i] = 1;
      			v.push_back({i+1,x+1});
      		}
      	}
      }
      cout << count << "\n";
      for(lld i = 0; i < v.size(); i += 1)
      	cout << v[i].first << " " << v[i].second << "\n";
      return 0;
}