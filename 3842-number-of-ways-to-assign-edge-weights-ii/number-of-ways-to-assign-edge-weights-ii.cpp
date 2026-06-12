class Solution {
    vector<int> depth, power;
    vector<vector<int>> up;
    int log;

    void dfs(int node,int par,int d,vector<vector<int>>& adj){
        depth[node] = d;
        up[node][0] = par;

        for(int j=1;j<log;j++){
            if(up[node][j-1] == -1){
                up[node][j] = -1;
            }
            else{
                up[node][j] = up[up[node][j-1]][j-1];
            }
        }

        for(auto &child : adj[node]){
            if(child == par) continue;
            dfs(child,node,d+1,adj);
        }
    }

    int getLCA(int u,int v){
        if(depth[u] < depth[v]) swap(u,v);

        for(int j=log-1;j>=0;j--){
            if(u != -1 && depth[u]-(1<<j) >= depth[v]){
                u = up[u][j];
            }
        }

        if(u == v) return u;

        for(int j=log-1;j>=0;j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        int MOD = 1e9+7;

        log = log2(n)+1;

        depth.resize(n+1);
        up.assign(n+1,vector<int>(log,-1));

        vector<vector<int>> adj(n+1);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1,-1,0,adj);

        power.resize(n+1,1);
        for(int i=1;i<=n;i++){
            power[i] = (1LL*power[i-1]*2)%MOD;
        }

        vector<int> ans;

        for(auto &q : queries){
            int u = q[0];
            int v = q[1];

            if(u == v){
                ans.push_back(0);
                continue;
            }

            int len = depth[u] + depth[v] - 2*depth[getLCA(u,v)];
            ans.push_back(power[len-1]);
        }

        return ans;
    }
};