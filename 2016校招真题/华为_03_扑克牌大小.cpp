/*
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
示例1
输入

4 4 4 4-joker JOKER
输出

joker JOKER
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

enum Rel {
	Single,
	Double,
	Three,
	Seq,
	Bomb,
	TwoJoker,
	None
};

vector<std::string> cards = {
	"3","4","5","6","7","8","9","10",
	"J","Q","K","A","2","joker","JOKER"
};

Rel getCardsType(const std::vector<std::string>&cards) {
	if (cards.size() == 1)
		return Single;

	if (cards.size() == 2) {
		if (std::find(cards.begin(), cards.end(), "joker") != cards.end() &&
			std::find(cards.begin(), cards.end(), "JOKER") != cards.end()) {
			return TwoJoker;
		} else {
			return Double;
		}
	}

	if (cards.size() == 3) {
		return Three;
	}
	if (cards.size() == 4) {
		return Bomb;
	}
	if (cards.size() == 5)
		return Seq;
	return None;

}

void output(const std::vector<std::string> &cards) {
	for (int i = 0; i < cards.size(); ++i) {
		cout << cards[i];
		if (i != cards.size() - 1)
			cout << " ";
	}
}

int bigger(const std::string&card1, const std::string&card2, unordered_map<string, int> &mp) {
	int pos1 = mp[card1];
	int pos2 = mp[card2];
	return pos1 - pos2;
}

void solve(const std::vector<std::string> &cards1, const std::vector<std::string>&cards2) {

	unordered_map<string, int> mp;
	for (int i = 0; i < cards.size(); ++i) {
		mp[cards[i]] = i;
	}
	Rel rel1 = getCardsType(cards1);
	Rel rel2 = getCardsType(cards2);
	if (rel1 != rel2) {
		if (rel1 != Bomb && rel1 != TwoJoker && rel2 != Bomb && rel2 != TwoJoker) {
			cout << "ERROR" << endl;
		} else {
			if (rel1 == TwoJoker)
				output(cards1);
			else if (rel2 == TwoJoker)
				output(cards2);
			else if (rel1 == Bomb && rel2 != Bomb) {
				output(cards1);
			} else if (rel2 == Bomb && rel1 != Bomb) {
				output(cards2);
			}
		}
	} else {
		//if (rel1 == Single) {
		//	output(bigger(cards1[0], cards2[0], mp) < 0 ? cards2 : cards1);
		//} else if (rel1 == Double) {
		//	output(bigger(cards1[0], cards2[0], mp) < 0 ? cards2 : cards1);
		//} else if (rel1 == Three) {
		//	int idx = 0;
		//	while (bigger(cards1[idx], cards2[idx], mp) == 0) ++idx;
		//	output(bigger(cards1[idx], cards2[idx], mp) < 0 ? cards2 : cards1);
		//} else if (rel1 == Seq) {
		//	output(bigger(cards1[0], cards2[0], mp) < 0 ? cards2 : cards1);
		//} else if (rel1 == Bomb) {
		//	output(bigger(cards1[0], cards2[0], mp) < 0 ? cards2 : cards1);
		//} else if (rel1 == TwoJoker) {
		//	output(cards1);
		//}

		if (rel1 == Three) { //3张的话找到第一张不同的
			int idx = 0;
			while (bigger(cards1[idx], cards2[idx], mp) == 0) ++idx;
			output(bigger(cards1[idx], cards2[idx], mp) < 0 ? cards2 : cards1);
		} else if (rel1 == TwoJoker) {
			output(cards1);
		} else { //其他所有情况都是比较第一张的大小
			output(bigger(cards1[0], cards2[0], mp) < 0 ? cards2 : cards1);
		}
	}

}




int main() {
	std::string str;
	bool first = true;
	vector<string>cards1, cards2;
	while (cin >> str) {
		int pos = str.find('-');
		if (pos != -1) {
			cards1.push_back(str.substr(0, pos));
			cards2.push_back(str.substr(pos + 1));
			first = false;
			continue;
		}

		if (first) {
			cards1.push_back(str);
		} else {
			cards2.push_back(str);
		}

	}
	solve(cards1, cards2);


	return 0;
}