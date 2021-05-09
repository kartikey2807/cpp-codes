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
      cin >> n;
      lld A[n],B[n],C[n];
      map <lld, pair <lld, lld> > m;
      for(lld i = 0; i < n; i += 1){
            cin >> A[i];
            C[i] = A[i];
      }
      lld sum = 0;
      for(lld i = 0; i < n; i += 1){
            sum+= max((lld)0, A[i]);
            B[i]= sum;
      }
      for(lld i = 0; i < n; i += 1){
            m[A[i]] = {MAX,MIN};
      }
      for(lld i = 0; i < n; i += 1){
            if (i <  m[A[i]].first){
                  m[A[i]].first = i;
            }
            if (i > m[A[i]].second){
                  m[A[i]].second= i;
            }
      }
      lld ans = MIN;
      lld pos;
      for(map <lld, pair <lld, lld> > :: iterator itr = m.begin(); itr != m.end(); itr++){
            pair <lld, lld> p = itr->second;
            if (p.first != p.second){
                  lld sum;
                  if (p.first == 0)
                        sum = B[p.second];
                  else
                        sum = B[p.second]-B[p.first-1];
                  if (itr->first < 0){
                        sum+= 2*(itr->first);
                  }
                  if (sum > ans){
                        ans = sum;
                        pos = itr->first;
                  }
            }
      }
      vector <lld> v;
      pair <lld, lld> p = m[pos];
      for(lld i = 0; i < p.first; i++){
            v.push_back(i+1);
      }
      for(lld i = p.first+1; i < p.second; i++){
            if (A[i] < 0) v.push_back(i+1);
      }
      for(lld i = p.second+1; i < n; i++){
            v.push_back(i+1);
      }
      cout << ans << " " << v.size()<<"\n";
      foi(i, v.size()) cout << v[i] << " ";
      return 0;
}