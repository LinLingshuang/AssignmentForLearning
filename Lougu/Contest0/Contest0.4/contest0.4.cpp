/*Mobiusp 有 n 个树结点，编号分别为 1 到 n 。
Mobiusp 需要构建一颗有 n个结点的根结点编号为 1 的有根树，构建出来的树需要满足以下条件：
1、每个结点的子结点个数不能超过自己的编号
2、每个结点的编号必须大于其父结点的编号
3、每层结点的编号必须是连续的

Mobiusp 希望最大化最后一层（距离根结点最远的一层）的结点个数。*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long nobe = 0;
	long long endnobe = 0;
	long long remind = 0;
	bool addnobe = true;
	while (addnobe) {
		if ((n - (nobe+1) * 2) % 2 == 0) {
			if ((n - (n - (nobe+1) * 2) / 2 - 1) - (nobe + 1) * 2 >= nobe + 1) {

				endnobe += (n - nobe * 2) / 2;
				nobe++;
				n -= n / 2 + 1;
			}
			else {
				addnobe = false;
			}
		}
		else {
			if ((n - ((n - (nobe+1) * 2) - 1) / 2 - 1)-(nobe + 1)*2 >= nobe + 1) {
				endnobe += ((n - nobe * 2) - 1) / 2;
				nobe++;
				n -= (n - 1) / 2 + 1;

			}
			else {
				addnobe = false;
			}
		}
	}
	if (endnobe == 0) {
		endnobe = 1;
	}
	cout << endnobe;
	
}/*@stack overflow 💭💡🎈 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
long long int n;
int Chengzai(long long int i);
int main(void)
{
    long long int shuru;
    scanf("%lld", &shuru);
    long long int max = 0;
    n = shuru;
    long long int limit1 = 1, limit2 = n,xuanze;
    while (limit1 < limit2)
    {
        
        xuanze = (limit1 + limit2+1) / 2;
        n -= xuanze;
        if (Chengzai(xuanze) == 1)limit1 = xuanze;
        else limit2 = xuanze-1;
        n = shuru;
    }
    //for (long long int i = n;i >=1;i--)
    //{
       // n -= i;
        //if (Chengzai(i) == 1)
       // {
       //     max = i;break;
     //   }
   //     n = shuru;
 //   }//
printf("%lld", limit1);
//n = shuru;
//printf("%d", Chengzai(3));
return 0;
}
int Chengzai(long long int i)
{
    //n -= i;
    if (i == 1)return 1;
    else if (n <= 0)return 0;
    long long int j = 0;//j为本轮取的数字个数
    long long int sum = 0;//sum为本轮取的那几个数字的和，即为能承载的下一行数字数量
    while (sum < i)
    {
        sum += n;
        n--;
        j++;
        if (n < 0)return 0;
    }
    return Chengzai(j);
}*/