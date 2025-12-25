/*# P1016 [NOIP 1999 普及组/提高组] 旅行家的预算
## 题目描述
一个旅行家想驾驶汽车以最小的费用从一个城市到另一个城市（假设出发时油箱是空的）。
给定两个城市之间的距离 $S$、汽车油箱的容量 $C$（以升为单位）、每升汽油能行驶的距离 $L$、
出发点每升汽油价格 $P_0$ 和沿途油站数 $N$，油站 $i$ 离出发点的距离 $D_i$、油站 $i$ 每升汽油价格 $P_i\ (i=1,2,\dots,N)$，你需要求出最小的费用。

## 输入格式

第一行，四个实数 $S,C,L,P_0$ 和一个整数 $N$，含义见题目描述。

接下来 $N$ 行，第 $i+1$ 行两个实数 $D_i$ 和 $P_i$，含义见题目描述。

## 输出格式

仅一行一个实数，代表最小的费用（四舍五入至小数点后两位）。

如果无法到达目的地，输出 `No Solution`。

## 输入输出样例 #1

### 输入 #1

```
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2
```

### 输出 #1

```
26.95
```

## 说明/提示

保证 $0 \leq N \leq 6$，$0 \leq D_i \leq S$，$0 \leq S,C,L,P_0,P_i \leq 500$。

NOIP1999 普及组第三题、提高组第三题。*/


#include<iostream>
#include<vector>

using namespace std;

int main() {
	double S, C, L, P0;//S=city_distan,C=oil_contain,L=every_liter_oil's_distan,P0=start_money
	int N;//N=stations_number
	double money = 0;
	cin >> S >> C >> L >> P0 >> N;

	double Cusing = 0;//the using cantain
	double Cnotusing = 0;

	vector<double>Di(N+1);//the distan of station to start station
	vector<double>stationdistan(N+1);//the distan of two distan
	vector<double>Pi(N+1);//oil money
	Di[0] = 0;
	Pi[0] = P0;

	for (int i = 0; i < N; i++) {
		cin >> Di[i+1] >> Pi[i+1];
	}
	stationdistan[0] = Di[1];
	for (int i = 1; i < N; i++) {
		stationdistan[i] = Di[i+1]-Di[i];
	}
	stationdistan[N] = S-Di[N];
	for (int i = 0; i < N+1; i++) {
		if (stationdistan[i] / L > C) {
			cout << "No Solution";
			return 0;
		}
	}


	int skip_station_num=0;
	bool skipstate = false;

	for (int i = 0; i < N; i++) {
		if (Pi[i] >= Pi[i + 1]&&!skipstate) {
			money += Pi[i] * stationdistan[i]/L;
			skip_station_num = 0;
			skipstate = false;
		}

		else if(!skipstate){
			skip_station_num += 1;
			skipstate = true;
			while (Pi[i] < Pi[i + skip_station_num]&&(i + skip_station_num)<N) {
				skip_station_num += 1;
			}
			if ((Di[i + skip_station_num] - Di[i]) / L <= C) {
				money += Pi[i] * (Di[i + skip_station_num] - Di[i])/L;
				skipstate = false;
				i = i + skip_station_num-1;
				skip_station_num = 0;
				continue;
			}
			else {
				money += Pi[i] * C ;
				Cusing = C - stationdistan[i] / L;
				Cnotusing = stationdistan[i] / L;
				continue;
			}

		}
		else if (skipstate) {
			if (Pi[i] >= Pi[i + 1]) {
				if (Cusing * L >= stationdistan[i]) {
					money += 0;
					Cusing -= stationdistan[i] / L;
					Cnotusing += stationdistan[i] / L;
					skip_station_num -= 1;
				}
				else {
					money += Pi[i] * (stationdistan[i] - Cusing * L) / L;
					Cusing -= stationdistan[i] / L;
					Cnotusing += stationdistan[i] / L;
					skip_station_num -= 1;
				}
				if (skip_station_num == 0) {
					skipstate = false;
				}
				continue;
			}
			else {
				int new_skip_station_num = 1;
				while (Pi[i] < Pi[i + new_skip_station_num]&&(i + new_skip_station_num) < N) {
					new_skip_station_num += 1;
				}
				if ((Di[i + new_skip_station_num] - Di[i]) / L <= C) {
					money += Pi[i] * (((Di[i + new_skip_station_num] - Di[i]) / L)- Cusing);
					Cusing = 0;
					Cnotusing = C;

					i = i + new_skip_station_num - 1;
					skip_station_num -= new_skip_station_num+1;
					if (skip_station_num == 0) {
						skipstate = false;
					}
					continue;
				}
				else {
					money += Pi[i] * Cnotusing ;
					Cusing = C - stationdistan[i] / L;
					Cnotusing = stationdistan[i] / L;
					skip_station_num -= 1;
					continue;
				}





			}

		}




	}
	
	



	

	cout << money;


}