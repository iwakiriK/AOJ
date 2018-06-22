#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Card { char suit, value; };

void print(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << C[i].suit << C[i].value;
    }
    cout << endl;
}

bool isStable(Card C1[], Card C2[], int N) {
    for (int i = 0; i < N; i++) {
        if (C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

void BubbleSort(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            if (C[j].value < C[j - 1].value) {
                swap(C[j], C[j - 1]);
            }
        }
    }
}

void SelectionSort(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (C[j].value < C[minj].value) minj = j;
        }
        swap(C[i], C[minj]);
    }
}

int main() {
    // input
    int N;
    cin >> N;
    Card C1[N], C2[N];
    for (int i = 0; i < N; i++) {
        cin >> C1[i].suit >> C1[i].value;
        C2[i] = C1[i];
    }
    // sort
    BubbleSort(C1, N);
    SelectionSort(C2, N);
    // output
    print(C1, N);
    cout << "Stable" << endl;
    print(C2, N);
    if (isStable(C1, C2, N)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    return 0;
}