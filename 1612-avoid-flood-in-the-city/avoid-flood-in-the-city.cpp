class UnionFind{
public:
    vector<int> root;
    UnionFind(int n): root(n+1){
        iota(root.begin(), root.end(), 0);
    }
    int Find(int x){
        return (x==root[x])?x:root[x]=Find(root[x]);
    }
    void UnionNext(int x){
        root[x]=Find(x+1);// union x & x+1
    }

};
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n=rains.size();

        // root is the 1st day dry after a successive rainy days
        UnionFind G(n+1); 
        unordered_map<int, int> rainDay;//lake->last rainy day
        rainDay.reserve(n);
        vector<int> ans(n, 1);// dry lake 1 by default
        for(int i=0; i<n; i++){
            const int lake=rains[i];
            if (lake>0){
                ans[i]=-1;
                G.UnionNext(i);// connect to i+1
                auto it=rainDay.find(lake);
                if (it!=rainDay.end()){
                    int prev=it->second;
                    int dry=G.Find(prev+1); //find next dry day after prev
                    if (dry>=i) return {};  //no dry day before i
                    ans[dry]=lake;      // dry that lake
                    G.UnionNext(dry);   // dry day as used
                    it->second=i;       // update last rain
                }
                else rainDay[lake]=i;
            } 
        }
        return ans;
    }
};