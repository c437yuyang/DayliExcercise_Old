/*
给定一个递增序列，a1 <a2 <...<an 。定义这个序列的最大间隔为d=max{ai+1 - ai }(1≤i<n),现在要从a2 ,a3 ..an-1 中删除一个元素。问剩余序列的最大间隔最小是多少？
输入描述:
第一行，一个正整数n(1<=n<=100),序列长度;接下来n个小于1000的正整数，表示一个递增序列。
输出描述:
输出答案。
示例1
输入
5
1 2 3 7 8
输出
4
*/
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


//我的思路AC:首先最大间隔在删除掉数后一定不会变小
int solve(vector<int>&nums) {
	vector<int> spans(nums.size() - 1, 0);
	int maxIdx;
	int max = std::numeric_limits<int>::min();
	for (int i = 1; i < nums.size(); ++i) {
		int span = nums[i] - nums[i - 1];
		if (span > max) {
			maxIdx = i - 1;
			max = span;
		}
		spans[i - 1] = span;
	}

	if (nums.size() == 3) {
		return spans[0] + spans[1];
	}

	if (maxIdx > 1 || maxIdx < spans.size() - 2) { //当前最大只要左右任一还有数，就一定可以保持当前最大 比如间隔是 1 1 4 2，删掉第一个1这个间隔的数就行了，成为2 4 2
		return max;
	} else { //左右都只有一个以内的数，那么就取左右间隔相加较小者
		int max1, max2;
		if (maxIdx > 0) //有左边
			max1 = std::max(max, max + spans[maxIdx - 1]);
		if (maxIdx < spans.size() - 1) //有右边
			max2 = std::max(max, max + spans[maxIdx + 1]);
		return std::min(max1,max2);
	}
}


//牛客的思路:
/*
O（n）时间复杂度，一趟for循环。
算法思想，删除一个数后，这个数的前后两个间隔就会合为一个间隔，最大间隔d可能变大。
要找最小的d值，只要找到连续两个间隔的和最小的值，把它与删除前的最大间隔比较，
如果没有超过原先的d值，那么最大间隔不变，如果超过了，这个就是新的d值。
*/

/*
#include<iostream>
using namespace std;

int main(){
int arr[100];
intn;
while(cin>>n){
for(inti=0;i<n;i++)
cin>>arr[i];
intnum=1000,max=0; //max是最大间隔， num是两个数的最大间隔
for(inti=1;i<n-1;i++){ //注意这里i的值是1到n-2
if(arr[i]-arr[i-1]>max) //寻找最大间隔
max=arr[i]-arr[i-1];
if(arr[i+1]-arr[i-1]<num) //寻找两个数之间的最小间隔
num=arr[i+1]-arr[i-1];
}
//因为上面n的值只遍历到n-2，最后一个间隔没算
max= arr[n-1]-arr[n-2] > max ? arr[n-1]-arr[n-2]:max;
max=max>num?max:num;  //用max保存较大的值
cout<<max<<endl;
}
return0;
}
*/

int main() {

	int n;
	while (cin >> n) {
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		cout << solve(nums) << endl;
	}
	return 0;
}