#include "account.h"
#include<iostream>
//记录一笔账，date为日期，amount为金额
void SavingsAccount::record(int date, double amount) {

	
	lastDate = date;
}
    
	


	//构造函数
SavingsAccount::SavingsAccount(int date, int id, double rate):id(id),balance(0),rate(rate),lastDate(0),accumulation(0) {
	std::cout << date << " #" << id << " is created" << std::endl;
}
double SavingsAccount::total = 0;

void SavingsAccount::deposit(int date, double amount) {

	accumulation = accumulate(date);
	balance += amount;
	std::cout << date << " #" << id << " " << amount<<" "<<balance << std::endl;
	lastDate = date;

}   //存入现金
void SavingsAccount::withdraw(int date, double amount) {
	accumulation = accumulate(date);
	balance -= amount;
	std::cout << date << " #" << id << " -" << amount << " " << balance << std::endl;
	lastDate = date;
}  //取出现金



	//结算利息
void SavingsAccount::settle(int date) {
	double temp = accumulate(date) / 365 * rate;
	balance += temp;
	std::cout << date << " #" << id << " " << temp<< " " << balance << std::endl;
	total += balance;
}


void SavingsAccount::show() const {

	std::cout<< '#' << id << " Balance:" << balance;
}