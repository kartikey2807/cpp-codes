#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
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
        lld n;
        cin >> n;
        lld A[n];
        for(lld i = 0; i < n; i += 1)
            cin >> A[i];
        sort(A, A+n, greater<int> ());
        lld bob = 0;
        lld alice = 0;
        for(lld i = 0; i < n; i += 1)
        {
            if (i%2 == 0)
                alice += (A[i]%2 == 0) ? A[i] : (lld)0;
            else
                bob += (A[i]%2 != 0) ? A[i] : (lld)0;
        }
        if (alice > bob)
            cout << "Alice";
        if (bob > alice)
            cout << "Bob";
        if (bob == alice)
            cout << "Tie";
        cout << "\n";
    }
    return 0;
}