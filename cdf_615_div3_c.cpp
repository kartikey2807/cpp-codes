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
set <lld> prime;
vector <lld> pFac (lld x)
{
      vector <lld> V;
      while (x%2==0){
            x/=2;
            V.push_back (2);
            prime.insert(2);
      }
      for(lld i = 3; i <= sqrt(x); i += 2){
            while (x%i==0){
                  x/=i;
                  V.push_back (i);
                  prime.insert(i);
            }
      }
      if (x > 2){
            V.push_back (x);
            prime.insert(x);
      }
      return V;
}
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
            prime.clear();
            lld n, i, prod=1;
            cin >> n;
            vector <lld> fac;
            fac = pFac(n);
            if (prime.size() >= 3){
                  for(i = 1; i < fac.size()-1; i++){
                        prod *= fac[i];
                  }
                        cout << "YES" << "\n" << fac[0] << " " << prod << " " << fac[fac.size()-1] << "\n";
            }
            if (prime.size() == 2){
                  if (fac.size() > 3){
                        for(i = 1; i < fac.size()-1; i++){
                              prod *= fac[i];
                        }
                        cout << "YES" << "\n" << fac[0] << " " << prod << " " << fac[fac.size()-1] << "\n";
                  }
                  else{
                        cout <<"NO\n";
                  }
            }
            if (prime.size() == 1){
                  if (fac.size() > 5){
                        for(i = 3; i < fac.size(); i++){
                              prod *= fac[i];
                        }
                        cout << "YES" << "\n" << fac[0] << " " << (fac[1]*fac[2]) << " " << prod  <<  "\n";
                  }
                  else{
                        cout <<"NO\n";
                  }
            }
      }
      return 0;
}