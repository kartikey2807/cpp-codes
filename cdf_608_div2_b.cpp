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
lld n;
vector <lld> cnt_ (string s, char c,char d)
{
	vector <lld>x;
	for(lld i = 0; i < n; i+= 1){
		if (s[i] == c){
			stack <lld> index;
			lld j;
			for(j = i+1; j < n; j += 1){
				if (s[j] == c){
					break;
				}
				index.push(j+1);
			}
			while (!index.empty()){
				x.push_back(index.top());
				index.pop();
			}
			x.push_back(i+1);
			s[i] = d;
			s[j] = d;
			s[i+1]=d;
			i+=1;
		}
	}
	return x;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      cin >> n;
      string s;
      cin >> s;
      map <char,lld> count;
      for(lld i = 0; i < n; i += 1){
      	if (s[i] == 'B')
      		count['B']++;
      	if (s[i] == 'W')
      		count['W']++;
      }
      if (count['B']%2 == 0 || count['W']%2 == 0){
      	vector <lld> a;
      	vector <lld> b;
      	if (count['B']%2 == 0 && count['W']%2 != 0){
      		a = cnt_(s, 'B', 'W');
      		cout << a.size() << "\n";
      		for(lld i = 0; i <a.size();i++){
      			cout << a[i] <<  " ";
      		}
      	}
      	if (count['B']%2 != 0 && count['W']%2 == 0){
      		a = cnt_(s, 'W', 'B');
      		cout << a.size() << "\n";
      		for(lld i = 0; i <a.size();i++){
      			cout << a[i] <<  " ";
      		}
      	}
      	if (count['B']%2 == 0 && count['W']%2 == 0){
      		a = cnt_(s, 'B', 'W');
      		b = cnt_(s, 'W', 'B');
      		if (a.size() < b.size()){
      			cout << a.size() << "\n";
      			for(lld i = 0; i <a.size();i++){
      				cout << a[i] <<  " ";
      			}
      		}
      		else{
      			cout << b.size() << "\n";
      			for(lld i = 0; i <b.size();i++){
      				cout << b[i] <<  " ";
      			}
      		}
      	}
      }
      else{
      	cout << "-1\n";
      }
      return 0;
}