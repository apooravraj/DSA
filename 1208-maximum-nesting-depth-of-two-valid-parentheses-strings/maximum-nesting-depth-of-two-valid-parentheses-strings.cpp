class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
      int n=seq.size(), p=0;
      vector<int>ans(n,0);
      for (int i=0;i<n;i++){
        char c=seq[i];
        p= p+(c=='(')-(c==')');
        ans[i]=(p&1)^(c=='(');
      } 
      return ans;
    }
};