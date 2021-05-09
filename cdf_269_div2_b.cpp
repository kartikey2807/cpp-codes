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
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first ;
		B[i] = P[i].second;
	}
}
void xyz (queue <lld> q, lld A[], lld B[], lld n, lld x)
{
	for(lld i = 0; i < n; i += 1){
		if (A[i] < x){
			cout << B[i]<< " ";
		}
	}
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	for(lld i = 0; i < n; i += 1){
		if (A[i] > x){
			cout << B[i]<< " ";
		}
	}
	cout << "\n";
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld A[n], B[n];
      map <lld, lld> count;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	B[i] =  i+1;
      	count[A[i]]++;
      }
      psort(A,B,n);
      lld c = 0;
      lld pos;
      for(map <lld, lld> :: iterator itr = count.begin(); itr != count.end(); itr++){
      	if (itr->second > 1){
      		c++;
      		pos = itr->first;
      	}
      }
      if (c >= 2 || (c == 1 && count[pos] >= 3)){
      	cout << "YES\n";
      	if (c >= 2){
      		lld p;
      		for(map <lld, lld> :: iterator itr = count.begin(); itr != count.end(); itr++){
      			if (itr->second > 1){
      				p = itr->first;
      				break;
      			}
      		}
      		queue <lld> q;
      		for(lld i = 0; i < n;  i += 1){
      			if (A[i] == p){
      				q.push(B[i]);
      			}
      		}
      		xyz(q, A, B, n,p);
      		lld x = q.front();
      		q.pop();
      		q.push(x);
      		xyz(q, A, B, n,p);
      		lld a;
      		for(map <lld, lld> :: iterator itr = count.begin(); itr != count.end(); itr++){
      			if (itr->second > 1 && itr->first != p){
      				a = itr->first;
      				break;
      			}
      		}
      		queue <lld> g;
      		for(lld i = 0; i < n;  i += 1){
      			if (A[i] == a){
      				g.push(B[i]);
      			}
      		}
      		x = g.front();
      		g.pop();
      		g.push(x);
      		xyz(g, A, B, n,a);
      	}
      	else{
      		queue <lld> q;
      		for(lld i = 0; i < n;  i += 1){
      			if (A[i] == pos){
      				q.push(B[i]);
      			}
      		}
      		xyz(q, A, B, n, pos);
      		lld x = q.front();
      		q.pop();
      		q.push(x);
      		xyz(q, A, B, n, pos);
      		lld y = q.front();
      		q.pop();
      		q.push(y);
      		xyz(q, A, B, n, pos);
      	}
      }
      else{
      	cout <<  "NO\n";
      }
      return 0;
}