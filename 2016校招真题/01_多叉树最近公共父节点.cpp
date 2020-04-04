/*
题目描述
git是一种分布式代码管理工具，git通过树的形式记录文件的更改历史，比如： base'<--base<--A<--A' ^ | --- B<--B' 小米工程师常常需要寻找两个分支最近的分割点，即base.假设git 树是多叉树，请实现一个算法，计算git树上任意两点的最近分割点。 （假设git树节点数为n,用邻接矩阵的形式表示git树：字符串数组matrix包含n个字符串，每个字符串由字符'0'或'1'组成，长度为n。matrix[i][j]=='1'当且仅当git树种第i个和第j个节点有连接。节点0为git树的根节点。）
示例1
输入
复制
[01011,10100,01000,10000,10000],1,2
输出
复制
1
*/

/*
多叉树寻找最近公共父节点问题

解题思路
从矩阵构造出father数组，father数组保存每个节点的父节点。
记录从根节点到带求节点A和B的路径。
比较路径，找到最近的公共节点。
技巧
由于矩阵给的双向关系，构造father数组时，需要从根节点0开始，从上层往下层构造。
用双向队列记录根节点到本节点的路径，双向队列可以往对头加节点，也可以从对头取节点。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	/**
	* 返回git树上两点的最近分割点
	*
	* @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
	* @param indexA 节点A的index
	* @param indexB 节点B的index
	* @return 整型
	*/
	int getSplitNode(vector<string> matrix, int indexA, int indexB) {
		vector<int> parents(matrix.size());
		vector<bool> traversed(matrix.size());

		parents[0] = -1;
		traversed[0] = true;

		std::queue<int> childrenQ;
		childrenQ.push(0);

		while (!childrenQ.empty()) {
			int parent = childrenQ.front();
			childrenQ.pop();
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (matrix[parent][j] == '1' && traversed[j] == false) {
					parents[j] = parent;
					traversed[j] = true;
					childrenQ.push(j);
				}
			}
		}


		//另一种遍历方式,错了，考虑[0001,0001,0001,1110]，除了0是已知的根以外，不一定父亲比孩子编号小
		//for (int i = 0; i < matrix.size(); ++i) {
		//	for (int j = 0; j < matrix[0].size(); ++j) {
		//		if (matrix[i][j] == '1' && traversed[j] == false) {
		//			parents[j] = i;
		//			traversed[j] = true;
		//		}
		//	}
		//} 


		//找从根到指定index的距离
		std::stack<int> sA, sB;
		while (indexA != -1) {
			sA.push(indexA);
			indexA = parents[indexA];
		}

		while (indexB != -1) {
			sB.push(indexB);
			indexB = parents[indexB];
		}

		//找到公共节点
		int commonParent = -1;
		while (!sA.empty() && !sB.empty() && sA.top() == sB.top()) {
			commonParent = sA.top();
			sA.pop();
			sB.pop();
		}
		return commonParent;
	}
};


int main() {

	vector<string> mat = {
		"01011","10100","01000","10000","10000"
	};
	Solution s;
	auto ret = s.getSplitNode(mat, 1, 2);

	return 0;
}