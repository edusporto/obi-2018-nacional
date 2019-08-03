#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 112345
#define INF 0x3f3f3f3f
#define LEFT_NODE(x) 2*x+1
#define RIGHT_NODE(x) 2*x+2

//int menores[MAXN];
//pair<int,int> segtree_menores[4*MAXN];
//int maiores[MAXN];
//pair<int,int> segtree_maiores[4*MAXN];

vector<int> menores;
vector<pair<int,int>> segtree_menores;
vector<int> maiores;
vector<pair<int,int>> segtree_maiores;

void build_maiores(int no_atual, int arvore_l, int arvore_r) {
    if (arvore_l == arvore_r) {
        segtree_maiores[no_atual] = make_pair(maiores[arvore_l], arvore_l);
        return;
    }

    int metade = (arvore_l + arvore_r) / 2;

    build_maiores(LEFT_NODE(no_atual), arvore_l, metade);
    build_maiores(RIGHT_NODE(no_atual), metade + 1, arvore_r);

    segtree_maiores[no_atual] = max(segtree_maiores[LEFT_NODE(no_atual)],
                                    segtree_maiores[RIGHT_NODE(no_atual)]);
}

pair<int,int> query_maiores(int no_atual, int arvore_l, int arvore_r, int alvo_l, int alvo_r) {
    if (arvore_r < alvo_l || arvore_l > alvo_r) {
        return make_pair(-INF,-1);
    }

    if (arvore_l >= alvo_l && arvore_r <= alvo_r) {
        return segtree_maiores[no_atual];
    }

    int metade = (arvore_l + arvore_r) / 2;

    return max(query_maiores(LEFT_NODE(no_atual), arvore_l, metade, alvo_l, alvo_r),
               query_maiores(RIGHT_NODE(no_atual), metade + 1, arvore_r, alvo_l, alvo_r));
}

void update_maiores(int no_atual, int arvore_l, int arvore_r, int pos, int novo_valor) {
    if (arvore_l == arvore_r) {
        segtree_maiores[no_atual] = make_pair(novo_valor, arvore_l);
        return;
    }

    int metade = (arvore_l + arvore_r) / 2;
    if (pos <= metade) {
        update_maiores(LEFT_NODE(no_atual), arvore_l, metade, pos, novo_valor);
    } else {
        update_maiores(RIGHT_NODE(no_atual), metade + 1, arvore_r, pos, novo_valor);
    }

    segtree_maiores[no_atual] = max(segtree_maiores[LEFT_NODE(no_atual)],
                                    segtree_maiores[RIGHT_NODE(no_atual)]);
}

void build_menores(int no_atual, int arvore_l, int arvore_r) {
    if (arvore_l == arvore_r) {
        segtree_menores[no_atual] = make_pair(menores[arvore_l], arvore_l);
        return;
    }

    int metade = (arvore_l + arvore_r) / 2;

    build_menores(LEFT_NODE(no_atual), arvore_l, metade);
    build_menores(RIGHT_NODE(no_atual), metade + 1, arvore_r);

    segtree_menores[no_atual] = min(segtree_menores[LEFT_NODE(no_atual)],
                                    segtree_menores[RIGHT_NODE(no_atual)]);
}

pair<int,int> query_menores(int no_atual, int arvore_l, int arvore_r, int alvo_l, int alvo_r) {
    if (arvore_r < alvo_l || arvore_l > alvo_r) {
        return make_pair(INF, -1);
    }

    if (arvore_l >= alvo_l && arvore_r <= alvo_r) {
        return segtree_menores[no_atual];
    }

    int metade = (arvore_l + arvore_r) / 2;

    return min(query_menores(LEFT_NODE(no_atual), arvore_l, metade, alvo_l, alvo_r),
               query_menores(RIGHT_NODE(no_atual), metade + 1, arvore_r, alvo_l, alvo_r));
}

void update_menores(int no_atual, int arvore_l, int arvore_r, int pos, int novo_valor) {
    if (arvore_l == arvore_r) {
        segtree_menores[no_atual] = make_pair(novo_valor, arvore_l);
        return;
    }

    int metade = (arvore_l + arvore_r) / 2;
    if (pos <= metade) {
        update_menores(LEFT_NODE(no_atual), arvore_l, metade, pos, novo_valor);
    } else {
        update_menores(RIGHT_NODE(no_atual), metade + 1, arvore_r, pos, novo_valor);
    }

    segtree_menores[no_atual] = min(segtree_menores[LEFT_NODE(no_atual)],
                                    segtree_menores[RIGHT_NODE(no_atual)]);
}

int main() {
    int N, M;
    cin >> N >> M;

    menores = vector<int>(N);
    segtree_menores = vector<pair<int,int>>(4*N);
    maiores = vector<int>(N);
    segtree_maiores = vector<pair<int,int>>(4*N);

    for (int i = 0; i < N; i++)
    {
        int valor_atual;
        cin >> valor_atual;
        menores[i] = valor_atual;
        maiores[i] = valor_atual;
    }
    
    build_maiores(0, 0, N-1);
    build_menores(0, 0, N-1);

    for (int i = 0; i < M; i++)
    {
        int op;
        cin >> op;

        if (op == 1) {
            int P, I;
            cin >> P >> I;
            if (P < menores[I-1]) {
                menores[I-1] = P;
                update_menores(0, 0, N-1, I-1, P);
            }
            if (P > maiores[I-1]) {
                maiores[I-1] = P;
                update_maiores(0, 0, N-1, I-1, P);
            }
        }

        if (op == 2) {
            int A, B;
            cin >> A >> B;
            pair<int,int> maior = query_maiores(0, 0, N-1, A-1, B-1);
            pair<int,int> menor = query_menores(0, 0, N-1, A-1, B-1);

            if (maior.second != menor.second) {
                cout << maior.first - menor.first << endl;
                continue;
            }

            update_menores(0, 0, N-1, menor.second, INF);
            pair<int,int> novo_menor = query_menores(0, 0, N-1, A-1, B-1);

            update_maiores(0, 0, N-1, maior.second, -INF);
            pair<int,int> novo_maior = query_maiores(0, 0, N-1, A-1, B-1);

            update_menores(0, 0, N-1, menor.second, menor.first);
            update_maiores(0, 0, N-1, maior.second, maior.first);

            int valor_final = max(maior.first - novo_menor.first, novo_maior.first - menor.first);

            cout << valor_final << endl;
        }
    }

    return 0;
}