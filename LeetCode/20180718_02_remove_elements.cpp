/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


*/

#include <bits/stdc++.h>
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(A==nullptr || n <= 0){
            return n;
        }

        int q = n,i=0;
        while(i < q){
            if(A[i]==elem){
                std::swap(A[i],A[--q]);
            }else{
                ++i;
            }
        }
        return q;
    }
};
int main()
{
    Solution s;
    std::vector<int> arr{1,2,3,2,4,2,4,5};
    int res = s.removeElement(&arr[0],arr.size(),2);
    std::cout << res << std::endl;
    return 0;
}
