class Solution {
   public:
    int findUltimateParent(int u, vector<int>& parent) {
        if (parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u], parent);
    }

    bool doUnion(int u, int v, vector<int>& parent, vector<int>& size) {
        int utlParentU = findUltimateParent(u, parent);
        int utlParentV = findUltimateParent(v, parent);
        if (utlParentU == utlParentV) {
            return false;
        }
        if (size[utlParentU] >= size[utlParentV]) {
            size[utlParentU] += size[utlParentV];
            parent[utlParentV] = utlParentU;
        } else {
            size[utlParentV] += size[utlParentU];
            parent[utlParentU] = utlParentV;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> size(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        vector<int> ans = {};
        for (auto it : edges) {
            if (!doUnion(it[0], it[1], parent, size)) {
                ans = it;
                break;
            }
        }
        return ans;
    }
};
