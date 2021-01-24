/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


*/

class Solution
{
public:
	int singleNumber(int A[], int n)
	{
		std::unordered_map<int, int> map;

		for (size_t i = 0; i < n; ++i)
		{
			if (map.find(A[i]) == map.end())
			{
				map[A[i]] = 2;
			}
			else
			{
				--map[A[i]];
			}
		}

		for (auto it = map.begin(); it != map.end(); ++it)
		{
			if (it->second == 2)
			{
				return it->first;
			}
		}
		return -65536;

	}
};


/*

链接：https://www.nowcoder.com/questionTerminal/1097ca585245418ea2efd0e8b4d9eb7a
来源：牛客网

Single Number的本质，就是用一个数记录每个bit出现的次数，如果一个bit出现两次就归0，这种运算采用二进制底下的位操作^是很自然的。Single Number II中，
如果能定义三进制底下的某种位操作，也可以达到相同的效果，Single Number II中想要记录每个bit出现的次数，一个数搞不定就加两个数，
用ones来记录只出现过一次的bits，用twos来记录只出现过两次的bits，ones&twos实际上就记录了出现过三次的bits，这时候我们来模拟进行出现3次就抵消为0的操作
，抹去ones和twos中都为1的bits。

*/

int singleNumber(int *A,int n)
{
	int ones = 0;//记录只出现过1次的bits
	int twos = 0;//记录只出现过2次的bits
	int threes;
	for (int i = 0; i < n; i++)
	{
		int t = A[i];
		twos |= ones&t;//要在更新ones前面更新twos，ones里面已经有了，那么ones&t就是出现两次的位，再或到twos上即可
		ones ^= t; //ones就是常规的更新方法
		threes = ones&twos;//ones和twos中都为1即出现了3次
		ones &= ~threes;//抹去出现了3次的bits
		twos &= ~threes;
	}
	return ones;
}


//由于只有一个出现一次的数字，其余都是出现三次，那么有如下思路
// 针对于序列中出现三次的所有数字的每一位来说，相加的结果只有两种
//1+1+1==3 或者0+0+0=0
//那么再加上只出现一次的数字的对应位数字的话，也有两种0或者4
//所以我们可以对上述的每一位求和之后对3取余，结果将会是1或者0
//也就是代表了出现一次的的这个数字对应位置上是1或者0
 class Solution1
{
	 int singleNumber(int *A,int n)
	{
		if (A == nullptr || n == 0)
		{
			return -1;
		}
		//得到出现一次的数字的值
		int result = 0;
		//int为4个字节，那么一共有4*8=32位
		for (int i = 0; i < 32; i++)
		{
			//保存每一位求和值
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				//累加所有数字上第i位上的数字
				sum += (A[j] >> i) & 1;
			}
			//取余得到第i位上的数字，之后更新result
			result |= (sum % 3) << i;
		}
		return result;
	}
};
