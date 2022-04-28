#include <vector>
#include <set>
#include <fstream>

using namespace std;

ifstream fin("heapuri.in");
ofstream fout("heapuri.out");

vector <long long> poz;
set <long long> heap;

long n;
long long x, k;

int main()
{
    fin >> n;
    int op;
    for(long i = 0; i < n; i++)
    {
        fin >> op;
        if(op == 1) {
            fin >> x;
            heap.insert(x);
            poz.push_back(x);
        }
        if(op == 2)
        {
            fin >> x;
            heap.erase(poz[x-1]);
        }
        if(op == 3)
            {
                int first = *heap.begin();
                fout << first <<'\n';
            }
    }
    return 0;
}

