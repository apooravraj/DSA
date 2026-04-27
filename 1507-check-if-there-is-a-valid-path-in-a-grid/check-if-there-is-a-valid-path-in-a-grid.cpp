constexpr int NN=300*300;
int Rt[NN], Rk[NN];
class UnionFind { // UnionFind class with rank
    int* root, *rank;
public:
    UnionFind(int n){
        root=Rt;
        rank=Rk;
        memset(rank, 0, n*sizeof(int));//set rank all 0
        iota(root, root+n, 0);// set root=[0, 1,..., n-1]
    }

    int Find(int x) {// compressed path
        return (x==root[x])?x:root[x]=Find(root[x]);
    }

    bool Union(int x, int y) {
        x=Find(x), y=Find(y);
        if (x == y) return 0;// a cycle is detected
        if (rank[x]>rank[y]) swap(x, y);
        root[x]=y;
        if (rank[x]==rank[y]) rank[y]++;
        return 1;// each comp is still a tree
    }
    bool connected(int x, int y){ return Find(x)==Find(y); }
};
class Solution {
public:
    inline static int idx(int i, int j, int c){ return i*c+j; }
    static bool hasValidPath(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size(), N=r*c;
        UnionFind G(N);
        for(int i=0; i<r-1; i++){
            for(int j=0; j<c-1; j++){
                const int C=grid[i][j], R=grid[i][j+1], D=grid[i+1][j];
                const int cc=idx(i, j, c), rr=cc+1, dd=cc+c;
                const bool CR=(C==1)|(C==4)|(C==6), RC=R&1;
                const bool CD=(C==2)|(C==4)|(C==3), DC=(D==2)|(D==5)|(D==6);
                // (C, R) connected only for (1,1), (1,3), (1,5) &
                // (4, 1), (4, 3), (4, 5), (6,1) ,(6, 3), (6, 5)
                if(CR & RC)
                    G.Union(cc, rr);
                // (C, D) connected only for (2, 2), (2, 5), (2, 6),
                // (3, 2), (3, 5), (3, 6), (4, 2), (4, 5), (4, 6)
                if (CD & DC)
                    G.Union(cc, dd);
            }
            const int C=grid[i][c-1], D=grid[i+1][c-1];
            const int cc=idx(i, c-1, c), dd=cc+c;
            const bool CD=(C==2)|(C==4)|(C==3), DC=(D==2)|(D==5)|(D==6);
            if (CD & DC)
                G.Union(cc, dd);
        }
        for(int j=0; j<c-1; j++){
            const int C=grid[r-1][j], R=grid[r-1][j+1];
            const int cc=idx(r-1, j, c), rr=cc+1;
            const bool CR=(C==1)|(C==4)|(C==6), RC=R&1;
            if(CR & RC)
                G.Union(cc, rr);
        }
        return G.connected(0, N-1);
    }
};