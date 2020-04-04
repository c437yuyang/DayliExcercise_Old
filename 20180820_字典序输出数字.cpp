#include <iostream>
#include <set>
#include <YXPUtility>
using namespace std;


//顺序打印1-n,0->n的话，把while(cnt<n)->while(cnt<=n),cur->0
//思路就是，对于每一个数，打印后乘以10，如果超过上限，则除以10+1，并且之后尽可能的把后面的0去掉
void print1toN(int n) {
	int cnt = 0; //记录输出多少个数
	int cur = 0;
	set<int> s;
	while (cnt <= n) {
		if (cur <= n) {
			cout << cur << endl;
			cnt++;
			if (cur == 0)
				++cur;
			else
				cur *= 10; //1->10->100->1000
		} else {
			cur = cur / 10 + 1; //100->11
			while (cur != 0 && cur % 10 == 0) //比如上一行从190->20了，要先回到2,就是递归退栈的行为
				cur /= 10;
		}
	}

}




//递归版本，比较好懂，其实就是dfs的思想
void dfs(int n, int threshold) {
	if (n > threshold)
		return;
	cout << n << endl;
	for (int i = 0; i <= 9; i++)
		dfs(10 * n + i, threshold);
}

void print1toN_1(int n) {
	for (int i = 1; i <= 9; i++)
		dfs(i, n);
}


//兼容从0到1打印的版本
void dfs1(int cur, int n) {
	if (cur > n)
		return;
	if (cur != 0) //如果从0开始打印就屏蔽这一句
		cout << cur << endl;
	for (int i = 0; i <= 9; ++i) {
		if (cur == 0 && i == 0) //防止0无限递归
			continue;
		dfs1(cur * 10 + i, n);
	}
}

void printN(int n) {
	dfs1(0, n);
}

//字典树实现的版本
void dfsTree(yxp_utility::TrieNode<10>*root, std::string&cur) {

	for (int i = 0; i < 10; ++i) {
		cur += ('0' + i);
		if (root->nexts[i] != nullptr && root->nexts[i]->end > 0) {
			cout << cur << endl;
			dfsTree(root->nexts[i], cur);
		}
		cur.pop_back();
	}
}

void printNTrieTree(int n) {
	yxp_utility::TrieTree<10> tree('0');

	//i=1开始就是从1开始打印
	for (int i = 0; i <= n; ++i) {
		tree.insert(std::to_string(i));
	}

	auto root = tree.root_;
	std::string str = "";
	dfsTree(root, str);
}


int main() {
	print1toN(100);
	print1toN_1(100);
	print1toN_1(101);
	printN(109);

	printNTrieTree(109);
	return 0;
}