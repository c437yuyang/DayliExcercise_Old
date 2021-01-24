/*


Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.

Your algorithm should run in O(n) complexity.


*/

#include <algorithm>
#include <cassert>
#include <set>
#include <unordered_set>
#include <vector>
class Solution {
 public:
  //牛客看到的,用hash表，然后每个数都往前找
  int longestConsecutive3(std::vector<int> &num) const {
    if (num.empty()) return 0;
    std::unordered_set<int> s(num.begin(), num.end());
    int max = 1;
    for (auto cur : num) {
      if (s.find(cur) == s.end()) continue;
      s.erase(cur);
      int prev = cur - 1;
      int next = cur + 1;
      while (s.find(prev) != s.end())
        s.erase(
            prev--);  //因为这里删掉了，所以保证是O(n),最多每个数两次被遍历到
      while (s.find(next) != s.end()) s.erase(next++);
      max = std::max(max, next - prev - 1);
    }
    return max;
  }

  // 自己重新实现了一遍
  int longestConsecutive(std::vector<int> &num) {
    if (num.empty()) {
      return 0;
    }

    int maxLen = 1;
    std::unordered_set<int> set(num.begin(), num.end());
    while (!set.empty()) {
      int cur = *set.begin(), pre = cur - 1,
          next = cur + 1;  // 这里不能每次去从iter拿，因为iter可能被后面erase掉
      set.erase(cur);
      int len = 1;
      while (set.find(pre) != set.end()) {
        ++len;
        set.erase(pre--);
      }

      while (set.find(next) != set.end()) {
        ++len;
        set.erase(next++);
      }

      maxLen = std::max(len, maxLen);
    }

    return maxLen;
  }

  //自己的做法，O(nlogn)
  int longestConsecutive2(std::vector<int> &num) {
    if (num.empty()) return 0;
    std::set<int> s;
    for (size_t i = 0; i < num.size(); ++i) s.insert(num[i]);

    auto it = s.begin();
    int pre = *it;
    ++it;
    int maxLen = 1;
    int curLen = 1;
    for (; it != s.end(); ++it) {
      if (*it - pre == 1)
        ++curLen;
      else
        curLen = 1;
      pre = *it;
      maxLen = std::max(curLen, maxLen);
    }
    return maxLen;
  }
};

int main() {
  std::vector<int> nums{100, 1, 3, 200, 4, 2};
  Solution solution;
  int res = solution.longestConsecutive(nums);
  assert(res == 4);
  return 0;
}