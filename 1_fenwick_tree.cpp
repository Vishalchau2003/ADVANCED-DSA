#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& fen, int ind, int add, int n) {

    while(ind <= n){
        fen[ind] += add;
        ind = ind + (ind & (-ind));
    }
}

int sum(int ind, vector<int>& fen, int n) {
    int s = 0;

    while(ind > 0){
        s += fen[ind];
        ind = ind - (ind & (-ind));
    }

    return s;
}

int sumrange(int l, int r, vector<int>& fen, int n) {
    return sum(r, fen, n) - sum(l - 1, fen, n);
}

int main(){

    int n;
    cout << "enter size of array ";
    cin >> n;

    vector<int> fen(n + 1, 0);   
    //we creating 1 based fenwick tree
    

    int ind, add;
    cout << "enter the index and value to add ";
    cin >> ind >> add;

    update(fen, ind, add, n);

    cout << "enter the range for sum ";
    int l, r;
    cin >> l >> r;

    cout << sumrange(l, r, fen, n);

    return 0;
}
