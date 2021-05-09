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
      lld n, k;
      cin >> n >> k;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	B[i]= 1;
      }
      lld end;
      lld start = 0;
      map <lld, vector <pair<lld, lld> > > x;
      for(lld i = 1; i < n; i += 1){
      	if (A[i] == A[i-1] + k){
      		// do nothing
      	}
      	else{
      		end = i-1;
      		if (A[start]-(k*start) >= 1){
      			x[A[start]-(k*start)].push_back({start,end});
      		}
      		start = i;
      	}
      }
      end = n-1;
      if (A[start]-(k*start) >= 1){
      	x[A[start]-(k*start)].push_back({start, end});
      }
      lld max = MIN;
      lld pos =  -1;
      for(map <lld, vector <pair<lld, lld> > > :: iterator itr = x.begin(); itr != x.end(); itr++){
      	vector <pair<lld, lld> > v = itr->second;
      	pair <lld, lld> p = v[0];
      	lld len = v.size();
      	if ((len*(p.second-p.first+1)) > max){
      		max = len*(p.second-p.first+1);
      		pos = itr->first;
      	}
      }
      lld count = 0;
      lld prev = -1;
      map <pair <lld, lld>, char> index;
      for(lld i = 0; i < x[pos].size(); i += 1){
      	pair <lld, lld> p = x[pos][i];
      	for(lld j = p.first-1; j > prev; j -= 1){
      		if (A[j] != A[j+1]-k){
      			count++;
      			lld q = A[j];
      			A[j] = A[j+1]-k;
      			if (q > A[j]) index[{j,q-A[j]}] = '-';
      			if (q < A[j]) index[{j,A[j]-q}] = '+';
      		}
      	}
      	prev = p.second;
      }
      for(lld i = prev+1; i < n; i += 1){
      	if (A[i] != A[i-1]+k){
      		count++;
      		lld q = A[i];
      		A[i] = A[i-1]+k;
      		if (q > A[i]) index[{i,q-A[i]}] = '-';
      		if (q < A[i]) index[{i,A[i]-q}] = '+';
      	}
      }
      cout << count << "\n";
      for(map <pair<lld, lld>, char> :: iterator itr = index.begin(); itr != index.end(); itr++){
      	pair <lld, lld> p = itr->first;
      	cout << itr->second << " " << p.first+1 << " " << p.second << "\n";
      }
      return 0;
}