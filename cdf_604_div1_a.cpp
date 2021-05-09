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
      lld t, w;
      cin >> t;
      foi(w,t){
      	lld n;
      	cin >> n;
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	vector <lld> v;
      	v.push_back(A[0]);
      	map <lld, lld> count;
      	for(lld i = 0; i < n; i += 1){
      		count[A[i]]++;
      	}
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] != A[i-1])
      			v.push_back(A[i]);
      	}
      	lld i = 0;
      	lld g = 0, s = 0,b = 0;
      	if (count[v[i]]<= n/2){
      		g = count[v[i]];
      		i++;
      		lld j;
      		for(j = i; j < v.size(); j += 1){
      			s += count[v[j]];
      			if (s > g)
      				break;
      		}
      		if (s > g && (s+g) <= (n/2)){
      			i = j+1;
      			lld k;
      			for(k = i; k < v.size(); k += 1){
      				b += count[v[k]];
      				if (b > g)
      					break;
      			}
      			if (b > g && (s + b + g) <= n/2){
      				i = k+1;
      				lld l;
      				for(l = i; l < v.size(); l += 1){
      					b += count[v[l]];
      					if ((s+b+g) > n/2)
      						break;
      				}
      				b -= count[v[l]];
      				cout << g << " " << s << " " << b << "\n";
      			}
      			else
      				cout << "0 0 0\n";
      		}
      		else
      			cout << "0 0 0\n";
      	}
      	else
      		cout << "0 0 0\n";
      }
      return 0;
}