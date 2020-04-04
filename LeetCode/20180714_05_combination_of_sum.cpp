/*
Given a collection of candidate numbers ( C ) and a target number ( T ), find all unique combinations in C where the candidate numbers sums to T .

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set10,1,2,7,6,1,5and target8, 
A solution set is: 
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

每种硬币只用一次，组成aim
不过输出不是方案的数目，而是怎么拿的方案,因此不能改成动态规划
*/

class Solution
{
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int sum = 0;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int index = 0;
        DFS(candidates, path, sum, target, index);
        vector<vector<int>> ret;
        return res;
    }
    void DFS(vector<int> &arr, vector<int> &path, int sum, int target, int index)
    {
        if (sum > target)return;
        if (sum == target)
        {
            if(std::find(res.begin(),res.end(),path)==res.end())
                res.push_back(path);
            return;
        }
        if(index > arr.size()-1)
            return;
        path.push_back(arr[index]);
        DFS(arr,path,sum+arr[index],target,index+1);
        path.pop_back();
        DFS(arr,path,sum,target,index+1);
    }
};