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
bool check (string x, string y)
{
	if (x.length() <= y.length()){
		lld j = x.length()-1;
		for(lld i = y.length()-1; i >= 0; i -= 1){
			if (j < 0)
				break;
			if (x[j] != y[i]){
				return false;
			}
			j--;
		}
		return  true;
	}
	else
		return false;
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
      set <string> name;
      map <pair<string,string>,lld> ct;
      map <string, vector<string> > id;
      for(lld i = 0; i < n; i += 1){
      	string s;
      	cin >> s;
      	lld l;
      	cin >> l;
      	for(lld j = 0; j < l; j += 1){
      		string r;
      		cin >> r;
      		ct[{s,r}]++;
      		if (ct[{s,r}]==1){
      			id[s].push_back(r);
      		}
      	}
      }
     	for(map <string, vector<string> > :: iterator itr = id.begin(); itr != id.end(); itr++){
     		string x = itr->first;
     		vector <string> v = itr->second;
     		for(lld i = 0; i < v.size(); i++){
     			for(lld j = 0; j < v.size(); j++){
     				if (i == j)
     					continue;
     				if (check(v[i],v[j])){
     					ct[{x,v[i]}]= 0;
     				}
     			}
     		}
     	}
     	cout << id.size() << "\n";
     	for(map <string, vector<string> > :: iterator itr = id.begin(); itr != id.end(); itr++){
     		string x = itr->first;
     		vector <string> v = itr->second;
     		lld cnt = 0;
     		for(lld i = 0; i < v.size(); i++){
     			if (ct[{x,v[i]}] != 0){
     				cnt++;
     			}
     		}
     		cout << x << " " << cnt << " ";
     		for(lld i = 0; i < v.size(); i++){
     			if (ct[{x,v[i]}] != 0){
     				cout << v[i] << " ";
     			}
     		}
     		cout << "\n";
     	}
      return 0;
}