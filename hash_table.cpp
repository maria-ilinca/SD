/*Fie o multime de numere naturale initial vida. Asupra acestei multimi se efectueaza operatii de urmatoarele tipuri:

operatia de tipul 1: se adauga elementul x la multime (unde x este un parametru al operatiei). Daca x este deja in multime, atunci aceasta ramane neschimbata.
operatia de tipul 2: se sterge elementul x, daca acesta este deja in multime. In caz contrar, multimea ramane neschimbata.
operatia de tipul 3: returneaza 1 daca si numai daca x este in multime, iar in caz contrar returneaza 0.*/
#include <fstream>
#include <vector>
using namespace std;
ifstream f("hashuri.in");
ofstream g("hashuri.out");

const int Mod = 666013;
vector <int> H[Mod];

void addIfNotExist(int x) {
    int rest = x % Mod;

    for(int i = 0; i < (int) H[rest].size(); ++i) {
        if(H[rest][i] == x) {
            return ;
        }
    }

    H[rest].push_back(x);
}

void deleteIfExist(int x) {
    int rest = x % Mod;

    for(int i = 0; i < (int) H[rest].size(); ++i) {
        if(H[rest][i] == x) {
            H[rest].erase(H[rest].begin() + i);
            return ;
        }
    }
}

bool findIfExist(int x) {
    int rest = x % Mod;

    for(int i = 0; i < (int) H[rest].size(); ++i) {
        if(H[rest][i] == x) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int N;
    f >> N;

    for(int i = 0; i < N; ++i) {
        int tip, x;
        f >> tip >> x;

        switch(tip) {
            case 1 : addIfNotExist(x); break;
            case 2 : deleteIfExist(x); break;
            case 3 : g << findIfExist(x) << '\n';
        };
    }

    f.close();
    g.close();
    return 0;
}
