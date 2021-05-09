// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define auth set <lld> :: iterator
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld w, h, n;
      cin >> w >> h >> n;
      set <lld> vert, hort;
      map <lld, lld>len_vert,len_hort;
      vert.insert(0); len_vert[0] = h;
      hort.insert(0); len_hort[0] = w;
      set <lld> vertical;
      map <lld, lld> vertical_cnt;
      set <lld> horizont;
      map <lld, lld> horizont_cnt;
      vertical.insert(h);
      vertical_cnt[h] ++;
      horizont.insert(w);
      horizont_cnt[w] ++;
      for(lld i = 0; i < n; i += 1){
      	char c;
      	cin >> c;
      	if (c == 'H'){
      		lld v;
      		cin >> v;
      		vert.insert(v);
      		auth itr = vert.find(v);
      		itr--;
      		lld temp = len_vert[*itr]; vertical_cnt[temp]--; if (vertical_cnt[temp] == 0) vertical.erase(temp);
      		len_vert[*itr] = v-(*itr); vertical_cnt[v-(*itr)]++; if (vertical_cnt[v-(*itr)] == 1) vertical.insert(v-(*itr));
      		len_vert[v] = temp-len_vert[*itr]; vertical_cnt[temp-len_vert[*itr]]++; if (vertical_cnt[temp-len_vert[*itr]] == 1) vertical.insert(temp-len_vert[*itr]);
      	}
      	else{
      		lld H;
      		cin >> H;
      		hort.insert(H);
      		auth itr = hort.find(H);
      		itr--;
      		lld temp = len_hort[*itr]; horizont_cnt[temp]--; if (horizont_cnt[temp] == 0) horizont.erase(temp);
      		len_hort[*itr] = H-(*itr); horizont_cnt[H-(*itr)]++; if (horizont_cnt[H-(*itr)] == 1) horizont.insert(H-(*itr));
      		len_hort[H] = temp-len_hort[*itr]; horizont_cnt[temp-len_hort[*itr]]++; if (horizont_cnt[temp-len_hort[*itr]] == 1) horizont.insert(temp-len_hort[*itr]);
      	}
      	auth a = vertical.end(); a--; lld lena = *a;
      	auth b = horizont.end(); b--; lld lenb = *b;
      	cout << lenb*lena << "\n";
      }
      return 0;
}