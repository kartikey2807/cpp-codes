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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
lld bin_ (vector <lld> v, lld x)
{
	for(lld i = 0; i < v.size(); i+= 1){
		if (v[i] > x){
			return v[i];
		}
	}
	return -1;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld l, t;
      cin >> t;
      foi(l,t){
      	string s, t, p;
      	cin >> s >> t >> p;
      	vector <lld> x[26];
      	for(lld i = 0; i < t.length(); i += 1){
      		lld y = (lld)t[i]-97;
      		x[y].push_back(i);
      	}
      	lld flag  = 1;
      	lld idx[26];
      	lld prev;
      	for(lld i = 0; i < 26; i+= 1){
      		idx[i] = 0;
      	}
      	for(lld i = 0; i < s.length(); i += 1){
      		if (i == 0){
      			lld y = (lld)s[i]-97;
      			if (x[y].empty()){
      				flag = 0;
      				break;
      			}
      			else{
      				prev = x[y][idx[y]];
      				idx[y]++;
      			}
      		}
      		else{
      			lld y = (lld)s[i]-97;
      			if (x[y].empty()){
      				flag = 0;
      				break;
      			}
      			else{
      				if (bin_(x[y] , prev) == -1){
      					flag = 0;
      					break;
      				}
      				else{
      					prev = bin_(x[y],prev);
      				}
      			}
      		}
      	}
      	if (flag == 0){
      		cout <<  "NO\n";
      	}
      	else{
      		map <char, lld> count_p;
      		map <char, lld> count_t;
      		map <char, lld> count_s;
      		for(lld i = 0; i < s.length(); i += 1){
      			count_s[s[i]]+= 1;
      		}
      		for(lld i = 0; i < t.length(); i += 1){
      			count_t[t[i]]+= 1;
      		}
      		for(lld i = 0; i < p.length(); i += 1){
      			count_p[p[i]]+= 1;
      		}
      		lld f = 1;
      		for(lld i = 0; i < t.length(); i += 1){
      			if (count_t[t[i]] <= count_s[t[i]] + count_p[t[i]] && count_s[t[i]] <= count_t[t[i]]){

      			}
      			else{
      				f = 0;
      				break;
      			}
      		}
      		if (f == 0)
      			cout <<  "NO\n";
      		else
      			cout << "YES\n";
      	}
      }
      return 0;
}