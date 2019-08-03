#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 12345

long long int visitados[MAXN];

long long int procurado = 0;

long long int solve(long long int valor_atual) {
    if (visitados[valor_atual] != 0) {
        return visitados[valor_atual];
    }

    if (procurado == valor_atual) {
        return 1;
    }

    long long int respostas = 0;

    if (procurado - valor_atual >= 1) {
        respostas += solve(valor_atual + 1);
    }

    if (procurado - valor_atual >= 2) {
        respostas += 4 * solve(valor_atual + 2);
    }
    
    if (procurado - valor_atual >= 3) {
        respostas += 2 * solve(valor_atual + 3);
    }

    visitados[valor_atual] = respostas % 1000000007;
    return respostas;
}

int main() {
    long long int N;
    cin >> N;

    memset(visitados, 0, sizeof(visitados));

    procurado = N;
    cout << solve(0) % 1000000007 << endl;

    return 0;
}