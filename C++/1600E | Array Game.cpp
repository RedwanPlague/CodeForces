#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
 
using ll = long long;
using vi = vector<int>;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n;
    while (cin >> n) {
 
        vi a(n);
        for (auto &x : a) {
            cin >> x;
        }
 
        vector<bool> wf(n), wb(n);
 
        wb[0] = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                wb[i] = !wb[i - 1];
            }
            else {
                wb[i] = true;
            }
        }
 
        wf[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i + 1] > a[i]) {
                wf[i] = !wf[i + 1];
            }
            else {
                wf[i] = true;
            }
        }
 
        int i = 0, j = n - 1, turn = 0, last = -1;
 
        // at the end if it's Alice's turn then Bob wins and vice versa
        while (i <= j) {
            if (a[i] <= last && a[j] <= last) {
                break;
            }
            if (a[i] <= last) {
                if (wb[j]) {
                    turn ^= 1; // opponent loses
                }
                break;
            }
            if (a[j] <= last) {
                if (wf[i]) {
                    turn ^= 1; // opponent loses
                }
                break;
            }
 
            if (a[i] < a[j]) {
                if (wb[j]) {
                    turn ^= 1; // opponent loses
                    break;
                }
                else {
                    last = a[i++];
                }
            }
            else if (a[i] > a[j]) {
                if (wf[i]) {
                    turn ^= 1; // opponent loses
                    break;
                }
                else {
                    last = a[j--];
                }
            }
            else {
                if (wf[i] || wb[j]) {
                    turn ^= 1; // opponent loses
                }
                break;
            }
 
            turn ^= 1; // switching turns
        }
 
        if (turn == 1) {
            cout << "Alice" << br;
        }
        else {
            cout << "Bob" << br;
        }
    }
 
    return 0;
}