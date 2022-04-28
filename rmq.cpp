#include <fstream>

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int main() {

    int n,m;

    fin >> n >> m;

    int log[n+1];

    log[1] = 0;

    for (int i = 2; i <= n; i++)
        log[i] = log[i/2] + 1;

    int logN=log[n];

    int rmq[n+1][logN+1];

    for(int i=1;i<=n;i++)
        fin >> rmq[i][0];

    for(int j=1;j<=logN;j++)
        for(int i=1; i+(1<<j)<=n+1; i++)
            rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);


    int x,y;
    for(int i=0;i<m;i++){

        fin >> x >> y;
        int l=log[y-x+1];
        fout << min(rmq[x][l],rmq[y-(1<<l)+1][l])<<"\n";
    }

    return 0;
}
