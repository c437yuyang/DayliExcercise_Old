/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
* 只要确定根节点，那么左右子树节点个数就能确定
*
* 解析：First note that dp[k] represents the number of BST trees built from
* 1....k;
*
* Then assume we have the number of the first 4 trees: dp[1] = 1 ,dp[2] =2
* ,dp[3] = 5, dp[4] =14 , how do we get dp[5] based on these four numbers
* is the core problem here.
*
* The essential process is: to build a tree, we need to pick a root node,
* then we need to know how many possible left sub trees and right sub trees
* can be held under that node, finally multiply them.
*
* To build a tree contains {1,2,3,4,5}. First we pick 1 as root, for the
* left sub tree, there are none; for the right sub tree, we need count how
* many possible trees are there constructed from {2,3,4,5}, apparently it's
* the same number as {1,2,3,4}. So the total number of trees under "1"
* picked as root is dp[0] * dp[4] = 14. (assume dp[0] =1). Similarly, root
* 2 has dp[1]*dp[3] = 5 trees. root 3 has dp[2]*dp[2] = 4, root 4 has
* dp[3]*dp[1]= 5 and root 5 has dp[0]*dp[4] = 14. Finally sum the up and
* it's done.
*
* Now, we may have a better understanding of the dp[k], which essentially
* represents the number of BST trees with k consecutive nodes. It is used
* as database when we need to know how many left sub trees are possible for
* k nodes when picking (k+1) as root.
*/

class Solution {
public:
    int numTrees(int n) {
        if(n==1 || n==2)
            return n;
        
        std::vector<int> res;
        res.push_back(1); //假设res[0] = 1 ，左边没有元素的时候不影响计算
        res.push_back(1);
        
        for(int i=2;i<=n;++i){
            int cur = 0;
            for(int j=1;j<=i;++j){ //选择哪一个当root
                cur += res[j-1] * res[i-j]; //左边就是j-1个，右边是i-j个，比如3的时候，分别是0、2,1,1、2、0
            }
            res.push_back(cur);
        }
        
        return res[n];
    }
};