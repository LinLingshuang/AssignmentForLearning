/*题目描述
一个旅行家想驾驶汽车以最小的费用从一个城市到另一个城市（假设出发时油箱是空的）。
给定两个城市之间的距离 S、汽车油箱的容量 C（以升为单位）、每升汽油能行驶的距离 L、出发点每升汽油价格 P0​
  和沿途油站数 N，油站 i 离出发点的距离 Di​ 、油站 i 每升汽油价格 Pi​  (i=1,2,…,N)，你需要求出最小的费用。
输入格式
第一行，四个实数 S,C,L,P0​
  和一个整数 N，含义见题目描述。
接下来 N 行，第 i+1 行两个实数 Di​
  和 Pi​ ，含义见题目描述。
输出格式
仅一行一个实数，代表最小的费用（四舍五入至小数点后两位）。
如果无法到达目的地，输出 No Solution。*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	double s, c, l, p0;int n;
	cin >> s >> c >> l >> p0 >> n;
	vector<double>pi(n+1), di(n+2);
	pi[0] = p0;
	di[0] = 0;
	di[n + 1] = s;
	for (int i = 0; i < n; i++) {
		cin>>di[i+1] >> pi[i + 1];
	}

	double money = 0;
	double usingc = 0;
	for (int i = 0; i <= n; i++) {

		int alternertive = i + 1;
		int skip = 0;
		while ((di[i + 1 + skip] - di[i]) <= c * l && skip != n - i) {
			if (pi[i] >= pi[i + 1 + skip]) {
				money += ((di[i + 1 + skip] - di[i]) / l) * pi[i] - usingc * pi[i];
				i = i + 1 + skip - 1;
				goto start;
			}
			if (pi[alternertive] >= pi[i + 1 + skip])alternertive = i + 1 + skip;
			skip++;
		}

		if (skip == n - i) {
			if ((di[i + 1 + skip] - di[i]) <= c * l) {
				money += ((di[i + 1 + skip] - di[i]) / l) * pi[i] - usingc * pi[i];
				break;
			}
			else if (i == n) {
				cout << "No Solution";
				return 0;
			}
			else if ((di[i + 1 + skip] - di[i]) > c * l) {
				money += c * pi[i] - usingc * pi[i];
				usingc = c - (di[alternertive] - di[i]) / l;
				i = alternertive - 1;
			}
		}
		else if (pi[i] >= pi[i + 1 + skip])continue;
		
		else if((di[i + 1 + skip] - di[i]) > c * l){
			money += c * pi[i] - usingc * pi[i];
			usingc = c - (di[alternertive] - di[i]) / l;
			i = alternertive - 1;
		}
		else if (skip == 0) {
			cout << "No Solution";
			return 0;
		}
	start:


		int a = 0;

	}
	printf("%.2f",money);
	
}