/*
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
��������:
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)
�������:
���һ�������Էŵĵ�����
ʾ��1
����
3 2
���
4
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;


#include<iostream>
#include<vector>
using namespace std;
/*
import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(), n = sc.nextInt();
        int evenICount = (n / 4) * 2 + (n % 4 < 2 ? n % 4 : 2);
        int oddICount = ((n - 2) / 4) * 2 + ((n - 2) % 4 < 2 ? (n - 2) % 4 : 2);
        int ans = m / 4 * (evenICount + oddICount) * 2;
        if(m % 4 > 0) ans += evenICount;
        if(m % 4 > 1) ans += evenICount;
        if(m % 4 > 2) ans += oddICount;
        System.out.println(ans);
    }
}


//����ÿ��������Ϊһ������pattern��ͬ���µ�ͼ����
����    ����   ����
����    ����   ����
    ����   ����   ����
    ����   ����   ����
����    ����   ����
����    ����   ����
 
ֻҪ�������ÿ��4���У�
i��i��1�еĵ�����Ϊ (n / 4) * 2 + (n % 4 < 2 ? n % 4 : 2)
i��2��i+3�еĵ�����Ϊ ((n - 2) / 4) * 2 + ((n - 2) % 4 < 2 ? (n - 2) % 4 : 2)
Ȼ�������һ���ж��ٸ�������4�о��У� ��Ȼ�ǹ���m / 4 ����
ΨһҪע��ľ��Ǵ���������4���������������������ʣ���1��3 �мӽ�ȥ��

*/

//�����������û����
int main()
{

	int W, H, i, j, counts = 0;

	cin >> W >> H;
	//W*H ���ܵ�
	if (W % 4 == 0 || H % 4 == 0) //W||H��һ����4�ı�����һ�����ܵĵ�һ��
	{
		counts = W*H / 2;
	}
	else if (W % 2 == 0 && H % 2 == 0) //������4�ı������Ҷ���2�ı���
	{
		counts = (W*H / 4 + 1) * 2;
	}
	else //������������ֻ��һ����2�ı���
	{
		counts = W*H / 2 + 1;
	}
	cout << counts << endl;
	return 0;
}