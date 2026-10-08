#include <iostream>
#include <vector>

using namespace std;

int diasDeDescanzo(vector<int>& v) {
    int res = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i > 0) {
            
            if (v[i - 1] == 1) {
                if (v[i] == 1) v[i] = 0;      
                else if (v[i] == 3) v[i] = 2; 
            }
            
            else if (v[i - 1] == 2) {
                if (v[i] == 2) v[i] = 0;      
                else if (v[i] == 3) v[i] = 1; 
            }
        }

        if (v[i] == 0) {
            res++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> vacaciones(n);
    for (int i = 0; i < n; i++) {
        cin >> vacaciones[i];
    }

    cout << diasDeDescanzo(vacaciones);
}