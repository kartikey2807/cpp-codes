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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	cin >> n;
      	lld count = 0;
      	vector <lld> v;
      	set <lld> L1, L2, L3;
      	map <lld, lld> count1, count2;
      	for(lld i = 0; i < n; i += 1){
      		lld r;
      		cin >> r;
      		L2.insert(r);
  			L3.insert(r);
      		count2[r] ++;
      		if (count2[r] > 1){
      			count += 1;
      		}
      		v.push_back(r);
      	}
      	lld flag = 1;
      	lld len1 = L1.size();
      	lld len2 = L2.size();
      	map <lld, lld> index;
      	for(lld i = 0; i < v.size(); i += 1){
      		count1[v[i]]++;
      		if (count1[v[i]]== 1){
      			L1.insert(v[i]);
      			len1++;
      		}
      		if (count1[v[i]] > 1){
      			flag = 0;
      		}
      		count2[v[i]]--;
      		if (count2[v[i]]== 0){
      			L2.erase (v[i]);
      			len2--;
      		}
      		if (count2[v[i]]== 1){
      			count--;
      		}
      		if (count == 0 && flag == 1 && len1 >= 1 && len2 >= 1){
      			set <lld> :: iterator a = L1.end(); a--;
      			set <lld> :: iterator b = L2.end(); b--;
      			if ((*a) == len1 && (*b) == len2){
      				index[len1] = len2;
      			}
      		}
      	}
      	cout << index.size() << "\n";
      	for(map <lld, lld> :: iterator itr = index.begin(); itr!=index.end(); itr++){
      		cout << itr->first << " " << itr->second << "\n";
      	}
      }
      return 0;
}