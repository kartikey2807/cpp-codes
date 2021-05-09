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
void merge(string crr[], lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1]; string L3[n1];
    lld R1[n2],R2[n2]; string R3[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
        L3[i] = crr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
        R3[j] = crr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
            k++;
        }
}
void mergeSort(string crr[], lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(crr, brr, arr,l, m);
        mergeSort(crr, brr,arr,m+1,r);
        merge(crr, brr, arr, l, m, r);
    } 
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      string home, away;
      cin >> home >> away;
      lld n;
      cin >> n;
      map <pair <string, lld>, lld> count_red;
      map <pair <string, lld>, lld> count_yel;
      map <pair <string, lld>, lld> fouls;
      foi(i,n){
            lld t, m;
            char a, c;
            cin >> t >> a >> m >> c;
            if (c == 'y'){
                  if (a == 'h'){
                        count_yel[{home, m}]++;
                        if (count_yel[{home, m}] == 2){
                              if (fouls[{home, m}]==0){
                                    fouls[{home, m}] = t;
                              }
                        }
                  }
                  else{
                        count_yel[{away, m}]++;
                        if (count_yel[{away, m}] == 2){
                              if (fouls[{away, m}]==0){
                                    fouls[{away, m}] = t;
                              }
                        }
                  }
            }
            else{
                  if (a == 'h'){
                        count_red[{home, m}]++;
                        if (count_red[{home, m}] == 1){
                              if (fouls[{home, m}]==0){
                                    fouls[{home, m}] = t;
                              }
                        }
                  }
                  else{
                        count_red[{away, m}]++;
                        if (count_red[{away, m}] == 1){
                              if (fouls[{away, m}]==0){
                                    fouls[{away, m}] = t;
                              }
                        }
                  }
            }
      }
      string s[n];
      lld num[n], time[n];
      lld j = 0;
      for(map <pair<string, lld>, lld> :: iterator itr = fouls.begin(); itr != fouls.end(); itr++){
            pair <string, lld> p = itr->first;
            s[j] = p.first;
            num[j] = p.second;
            time[j] = itr->second;
            j++;
      }
      mergeSort(s, num, time, 0, j-1);
      foi(i,j){
            cout << s[i] << " " << num[i] << " " << time[i] << "\n";
      }
      return 0;
}