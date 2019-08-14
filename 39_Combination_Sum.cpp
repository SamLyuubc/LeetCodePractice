class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        vector<vector<int>> ans;
        vector<int> result;
        
        int size = candidates.size();
        
        calculateLine(0, 0, size, result, ans, target, candidates);
        return ans;
    }
    
    void calculateLine(int sum, int index, int size, vector<int>& result, vector<vector<int>>& ans, int target, vector<int>& candidates)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ans.push_back(result);
            return;
        }
        for (int i= index; i < size; i++)
        {
            result.push_back(candidates[i]);
            calculateLine(sum+candidates[i], i, size, result,ans, target, candidates);
            result.pop_back();
        }
    }
};
