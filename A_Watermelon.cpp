#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>      // I/O
#include <vector>        // Dynamic arrays
#include <algorithm>     // Sort, min, max, lower_bound, etc.
#include <cmath>         // Math functions (abs, pow, sqrt, etc.)
#include <map>           // Ordered map
#include <set>           // Ordered set
#include <unordered_map> // Hash map (faster, average case)
#include <unordered_set> // Hash set
#include <queue>         // BFS, heap, priority queue
#include <stack>         // LIFO structure
#include <deque>         // Double-ended queue
#include <string>        // String manipulation
#include <sstream>       // String stream (parsing)
#include <bitset>        // Bit manipulation
#include <limits>        // Numeric limits (INT_MAX, LLONG_MAX, etc.)
#include <cassert>       // Assert for debugging
#include <cstring>       // C-style string, memset()
#include <chrono>        // Timing (benchmark)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const ll MOD = 998244353;
const ll INF = 2e18;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define debug(x) cerr << #x << ": " << x << "\n"

int main() {
    fastio;
    int t = 1;
    // cin >> t; // Uncomment if problem is multi-testcase
    while(t--) {
        solve();
    }
    return 0;
}