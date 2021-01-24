class Solution
{
public:
	bool searchMatrix(std::vector<std::vector<int> > &matrix, int target)
	{
		if (matrix.empty() || matrix[0].empty())
			return false;
		int row = 0, col = matrix[0].size() - 1;

		while (row >= 0 && row < matrix.size() 
			&& col >= 0 && col < matrix[0].size()) 
		{
			if (matrix[row][col] < target)
				++row;
			else if (matrix[row][col] > target) 
				--col;
			else
				return true;
		}

		return false;

	}
};
