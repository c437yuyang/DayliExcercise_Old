class Flip {
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
        // write code here
        if(f.empty())
            return A;
        for(int i=0;i<f.size();++i){
            int row = f[i][0]-1;
            int col = f[i][1]-1;
            if(row>0){
                A[row-1][col]^=1;
            }
            if(row < 3){
                A[row+1][col]^=1;
            }
            if(col>0)
                A[row][col-1]^=1;
            if(col<3)
                A[row][col+1]^=1;
        }
        return A;
        
    }
};