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
void psort (lld A[], lld B[], lld n)
{
      pair <lld, lld> P[n];
      for(lld i = 0; i < n; i += 1){
            P[i].first  = A[i];
            P[i].second = B[i];
      }
      sort(P, P+n);
      for(lld i = 0; i < n; i += 1){
            A[i] = P[i].first ;
            B[i] = P[i].second;
      }
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, s;
      cin >> n >> s;
      char C[n]; lld P[n], Q[n];
      for(lld i = 0; i < n; i += 1){
            cin >> C[i]>>P[i]>>Q[i];
      }
      lld A[n], B[n];
      lld X[n], Y[n];
      lld j = 0;
      lld l = 0;
      set <lld> visited, visited2;
      for(lld i = 0; i < n; i += 1){
            if (C[i] == 'S' && !visited.count(P[i])){
                  A[j] = P[i];
                  visited.insert(P[i]);
                  lld sum = 0;
                  for(lld k = 0; k < n; k += 1){
                        if (C[k] == 'S' && P[k] == P[i]){
                              sum+=Q[k];
                        }
                  }
                  B[j] = sum;
                  j++;
            }
            if (C[i] == 'B'&& !visited2.count(P[i])){
                  X[l] = P[i];
                  visited2.insert(P[i]);
                  lld sum = 0;
                  for(lld k = 0; k < n; k += 1){
                        if (C[k] == 'B' && P[k] == P[i]){
                              sum+=Q[k];
                        }
                  }
                  Y[l] = sum;
                  l++;
            }
      }
      psort(X, Y, l);
      psort(A, B, j);
      lld temp = s;
      vector <lld> price, quan;
      for(lld i = 0; i < j; i += 1){
            if (temp == 0){
                  break;
            }
            price.push_back(A[i]);
            quan.push_back (B[i]);
            temp--;
      }
      reverse(price.begin(), price.end());
      reverse(quan.begin() ,  quan.end());
      for(lld i = 0;i < price.size();i++){
            cout << "S " << price[i] << " " << quan[i] << "\n";
      }
      for(lld i = l-1; i >= 0; i -= 1){
            if (s == 0){
                  break;
            }
            cout << "B " << X[i] << " " << Y[i] << "\n";
            s--;
      }
      return 0;
}