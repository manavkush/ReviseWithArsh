class Solution {
private:
    void dfs(vector<int> curr, vector<vector<int>> &ans, int num_left, int sum_left, int pos) {
        if(num_left==0) {
            if(sum_left == 0)
                ans.push_back(curr);
            return;
        }
        if(sum_left==0 || pos>9) {
            return;
        }

        curr.push_back(pos);
        dfs(curr, ans, num_left-1, sum_left-pos, pos+1);
        curr.pop_back();
        dfs(curr, ans, num_left, sum_left, pos+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<int> hash(10, 1);
        vector<int> curr;
        vector<vector<int>> ans;

        dfs(curr, ans, k, n, 1);

        return ans;
    }
};