#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

//�����Ŀ���Զ���һ���ṹ�����ڴ洢ÿ���ֶε���ʼʱ�䣬��ֹʱ�䣬�۸�Ȼ�����
//�������Ҽ۸�һ�µ��������merge����Ҳ����Ŀ������Ҫ����ġ�������������������
//�Ͽ���ʱ��ʱ�����޵�����£���Ȼ������merge�������ӣ�����ע����Ŀ���ᵽ�˾Ƶ�
//�ļ۸���ܲ�һ�£������һ�£�������ļ۸�Ϊ׼����������¼�ļ۸��ǰ��ļ�¼
//��һ������Ϳ��ܵ���ԭ����һ������θ��¼۸����ѳ�Ϊ�����������������Ը��ӡ�
//���Կ���ֱ����һ������洢ÿ��ļ۸��������ĺô����Ǽ�ʹǰ�����ݲ�һ�£�����
//�Ļ�ֱ�Ӹ���ǰ�����ɼ۸���£�ȱ�������Ҫһ����������¼ÿ��ļ۸񣬿ռ临��
//�Ƚϸߣ��������ʵ��������ԣ���������ر������������Բ��ؿ��Ǵ������⣬��Ȼ
//Ҳ�����ڴ湻�á��ر���Ҫע�������ʽҪ������ĿҪ��
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int i = 0;
	int start, end, price;
	while (cin >> start >> end >> price) {
		vector<int> prices(10000);
		for (i = start; i <= end; i++)
			prices[i] = price;
		int min = start;
		int max = end;
		while (cin >> start >> end >> price) {
			if (start < min)
				min = start;
			if (end > max)
				max = end;
			for (i = start; i <= end; i++)
				prices[i] = price;
		}

		cout << "[" << min << ", ";
		for (i = min + 1; i <= max; i++) {
			if (prices[i] != prices[i - 1]) {
				if (prices[i - 1] != 0)
					cout << i - 1 << ", " << prices[i - 1] << "]";
				if (i < max && prices[i] != 0)
					cout << "," << "[" << i << ", ";
			}
		}
		cout << max << ", " << prices[max] << "]" << endl;
	}
	return 0;
}




//�ҵ�����������������Ŀ��˵�ģ��۸��ͻ��ʱ���Ժ���Ϊ׼��Ҫ��
//struct span {
//	int start;
//	int end;
//	int price;
//	bool operator<(const span&other) const {
//		if (start == other.start)
//			return end < other.end;
//		return start < other.start;
//	}
//};
//void solve(vector<span>&spans) {
//	span pre{ -1,-1,-1 };
//	vector<span> res;
//	std::sort(spans.begin(), spans.end());
//	for (int i = 0; i < spans.size(); ++i) {
//		if (spans[i].start <= pre.end + 1 && spans[i].price == pre.price) {
//			res.back().end = spans[i].end;
//		} else {
//			res.push_back(spans[i]);
//			pre = res.back();
//		}
//	}
//
//	for (int i = 0; i < res.size(); ++i) {
//		printf("[%d, %d, %d]", res[i].start, res[i].end, res[i].price);
//
//		if (i != res.size() - 1)
//			printf(",");
//	}
//	printf("\n");
//
//}
//
//int main() {
//	int s, e, p;
//	vector<span> spans;
//	while (cin >> s >> e >> p) {
//		span sp;
//		sp.start = s;
//		sp.end = e;
//		sp.price = p;
//		spans.push_back(sp);
//	}
//	solve(spans);
//	return 0;
//}
