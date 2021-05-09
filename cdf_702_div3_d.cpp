#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
unordered_map <lld, lld> mac;
void split (lld A[], lld l, lld r, lld depth)
{
	if (l <= r)
	{
		lld ans = MIN;
		lld pos;
		for(lld i = l; i <= r; i += 1)
		{
			if (A[i] > ans)
			{
				ans = A[i];
				pos = i;
			}
		}

		mac[pos] = depth;

		split(A, l, pos-1, depth+1);
		split(A, pos+1, r, depth+1);
	}
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld t;
    cin >> t;
    while(t--)
    {
    	mac.clear();
    	lld n;
    	cin >> n;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	split(A, 0, n-1, 0);
    	for(lld i = 0; i < n; i += 1)
    		cout << mac[i] << " ";
    	cout << "\n";
    }
    return 0;
}