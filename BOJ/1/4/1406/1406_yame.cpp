#include <iostream>
#define MAXSIZE 600001
using namespace std;
int m, unused = 1, cur = 0;
string str;
char dat[MAXSIZE];
int pre[MAXSIZE];
int nxt[MAXSIZE];

void print() {
    int printcur = nxt[0];
    while (printcur != -1) {
        cout << dat[printcur];
        printcur = nxt[printcur];
    }
    cout << '\n';
}

void L() {
    if (cur != 0) cur = pre[cur];
}

void D() {
    if (nxt[cur] != -1) cur = nxt[cur];
}

void insert(char c, int addr) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    cur = nxt[cur];
    unused++;
}

void erase(int addr) {
    if (addr != 0) {
        nxt[pre[addr]] = nxt[addr];
        if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
        cur = pre[cur];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MAXSIZE, -1);
    fill(nxt, nxt + MAXSIZE, -1);
    cin >> str >> m;
    for (int i = 0; i < str.length(); i++) {
        insert(str[i], cur);
    }
    cin.ignore();
    while (m--) {
        getline(cin, str);
        switch (str[0]) {
            case 'L':
                L(); break;
            case 'D':
                D(); break;
            case 'B':
                erase(cur); break;
            case 'P':
                insert(str[2], cur); break;
        }
    }
    print();
}