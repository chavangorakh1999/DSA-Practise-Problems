#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
// Consider using splay_tree instead if constant factor is an issue (e.g., log^2 solutions), especially with duplicates.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
 
void run_case() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    ordered_set<pair<int, int>> L_set, R_set;
 
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        L_set.insert({L[i], i});
        R_set.insert({R[i], i});
    }
 
    int best = N;
 
    for (int i = 0; i < N; i++) {
        int current = int(R_set.order_of_key(make_pair(L[i], -1))) + (N - int(L_set.order_of_key(make_pair(R[i], N + 1))));
        best = min(best, current);
    }
 
    cout << best << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests;
    cin >> tests;
 
    while (tests-- > 0)
        run_case();
}