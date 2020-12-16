#include<bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
 
    for (auto &a : A) {
        cin >> a;
        sum += a;
    }
 
    for (int count = N; count > 0; count--) {
        if (sum % count != 0)
            continue;
 
        int goal = sum / count;
        bool fail = false;
 
        for (int i = 0, j = 0; i < N; i = j) {
            int current = 0;
 
            while (j < N && current + A[j] <= goal) {
                current += A[j];
                j++;
            }
 
            if (current != goal) {
                fail = true;
                break;
            }
        }
 
        if (!fail) {
            cout << N - count << '\n';
            return;
        }
    }
}
 
int main() {

    int tests;
    cin >> tests;
 
    while (tests-- > 0)
        run_case();
}