/*1. 个人银行账户管理程序
【问题描述】设计一个以面向个人的银行账户管理程序，说明类及成员函数的设计。
注意：此题提供main.cpp工程文件作为示范，和account.h声明文件作为约束和提示，请独自完成account.cpp函数实现文件的编写。
类的说明：设计一个活期储蓄账户类，该类包含以下属性：账户（id)、余额（balance)、年利率（rate)等信息，还包括显示账户信息（show)、存款（deposit)、取款（withdraw)、
结算利息（settle)等操作。其中：
1. 将账户（id)、余额（balance)、年利率（rate)作为其私有成员数据；
2. 利息的计算方式：将一年当中每天的余额累积起来再除以一年的总天数365天，得到一个日均余额，再乘以年利率；
3. 为计算余额的累积值，引入私有数据成员lastDate、accumulation和私有成员函数accumulate。
   lastDate：存储上一次余额变动的日期
   accumulation：存储上次计算利息以后直到最近一次余额变动时余额按日累加的值
   accumulate：计算截止指定日期的账户余额按日累积的值
4. 存款、取款和结算利息，都需要修改当前的余额并且将余额的变动输出，这些公共操作由私有成员函数record实现。
5. 为简便起见，该类中的所有日期均用一个整数来表示，该整数是一个以日为单位的相对日期。
【输入形式】
用户从键盘输入三组数据，分别是：
1. 年利率、利息结算日
2. 第一个账户的创建日期、账户号（id）、存款日期、存入的金额、取款日期、取出的金额
3. 第二个账户的创建日期、账户号（id）、存款日期、存入的金额、取款日期、取出的金额
【输出形式】
（提示：每行显示的各项目之间用一个空格隔开显示）
显示出两个账户的创建日期、账户号
显示出两个账户的存款日期、账户号、存款金额、账户余额
显示出两个账户的取款日期、账户号、取款金额、账户余额
显示出两个账户的计息日期、账户号、利息金额、账户余额
显示出两个账户的账户号、账户余额
显示出两个账户的总余额金额
【样例输入】
0.017 362
3 555555 3 7000 60 600
3 666666 3 9000 70 2000
【样例输出】
3 #555555 is created
3 #666666 is created
3 #555555 7000 7000
3 #666666 9000 9000
60 #555555 -600 6400
70 #666666 -2000 7000
362 #555555 108.6 6508.6
362 #666666 123.28 7123.28
#555555 Balance:6508.6
#666666 Balance:7123.28
Total:13631.9
【样例说明】*/

// main.cpp : 个人银行账户管理程序。此处提供main.cpp工程文件作为示范，和account.h声明文件作为约束和提示，请独自完成account.cpp函数实现文件的编写。
//

#include "account.h"
#include <iostream>
using namespace std;

int main()
{
    //const double bank_rate = 0.015;
    double bank_rate;
    int i_date;
    int use_date1, use_date2, use_id1, use_id2;
    int s_date1, s_date2, w_date1, w_date2;
    double SaveAmout1, SaveAmout2, DeceAmout1, DeceAmout2;

    //cout << "请输入年利率、利息结算日:" << endl;
    cin >> bank_rate >> i_date;
    //cout << "请输入第一个账户的创建日期、账户号（id）、存款日期、存入的金额、取款日期、取出的金额：" << endl;
    cin >> use_date1 >> use_id1 >> s_date1 >> SaveAmout1 >> w_date1 >> DeceAmout1;
    //cout << "请输入第二个账户的创建日期、账户号（id）、存款日期、存入的金额、取款日期、取出的金额：" << endl;
    cin >> use_date2 >> use_id2 >> s_date2 >> SaveAmout2 >> w_date2 >> DeceAmout2;

    //建立几个账户
    SavingsAccount sa0(use_date1, use_id1, bank_rate);
    SavingsAccount sa1(use_date2, use_id2, bank_rate);


    //几笔账目   
    sa0.deposit(s_date1, SaveAmout1);
    sa1.deposit(s_date2, SaveAmout2);


    sa0.withdraw(w_date1, DeceAmout1);
    sa1.withdraw(w_date2, DeceAmout2);


    //开户后第i_date天到了银行的计息日，结算所有账户的年息
    sa0.settle(i_date);
    sa1.settle(i_date);

    //输出各个账户信息
    sa0.show(); cout << endl;
    sa1.show(); cout << endl;


    cout << "Total:" << SavingsAccount::getTotal() << endl;
    //cout << "Total:" << SavingsAccount::getTotal();
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
