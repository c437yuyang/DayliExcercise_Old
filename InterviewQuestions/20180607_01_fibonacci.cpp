class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        int arr[3] = {1,1,2};
        if(n==1 || n==2 || n==3){
            return arr[n-1];
        }
        for(int i=4;i<=n;++i)
        {
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = arr[0] + arr[1];
        }
        return arr[2];
    }
};