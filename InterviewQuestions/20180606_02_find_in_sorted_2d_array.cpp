class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int cur_row = 0;
        int cur_col = array[0].size()-1;
        while(cur_row < array.size() && cur_col>=0)
        {
            if(array[cur_row][cur_col] < target)
                ++cur_row;
            else if(array[cur_row][cur_col] > target)
                --cur_col;
            else
                return true;
        }
        return false;
        
    }
};