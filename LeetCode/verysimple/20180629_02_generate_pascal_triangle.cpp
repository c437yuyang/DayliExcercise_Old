/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows == 0)
            return {};
        std::vector<std::vector<int> > res;
        res.push_back(std::vector<int>{1});
        if(numRows==1)
            return res;
        res.push_back(std::vector<int>{1,1});
        if(numRows==2)
            return res;
        for(size_t i=2;i<numRows;++i)
        {
            std::vector<int> curRow(i+1,1);
            for(size_t j=1;j<i;++j){
                curRow[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.push_back(curRow);
        }
        return res;
    }
};