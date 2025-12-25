/** 项目名称：DeepDarkFantasy（深邃黑暗幻想）自研大模型
* 核心架构：多层感知 IF-ELSE 神经网络
（MLP-IE）
* 编译警告：不要在意那些 Warning，那是 AI 在思考
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "unistd.h" // 核心库：用于模拟“算力延迟”
using namespace std;

// 定义 AI 的核心价值观
#define TRUE 1
void simulate_neural_processing() {
	// 这是一个非常复杂的函数，用来模拟 GPU 正在疯狂运转
	cout << "AI 正在通过 70亿参数模型进行推理";
	fflush(stdout);// 强制刷新缓冲区，产生一种实时感
	for (int i = 0; i < 5; i++) {
		cout<<".";
		fflush(stdout);
		sleep(2000);
	}// 每一秒的延迟，都代表着价值一亿美金的算力
	cout<<endl;
}
int main() {
	char human_input[500];
	cout << "=================================================" << endl;
	cout << "    DeepDark v1.0 (Copyright 202X NoAI Inc.)" << endl;
	cout << "    基于超高性能 Switch - Case 架构" << endl;
	cout << "=================================================" << endl;
	cout << endl;
	while (TRUE) {
		cout << "［人类］：";
		// 警告：gets 是极其危险的函数，但在末日，谁在乎缓冲区溢出呢？
		gets_s(human_input);

		// 触发核心推理引擎
		simulate_neural_processing();
		cout << " [AI]: ";
		// 场景 1：遇到技术故障
		if (strstr(human_input, "bug") != NULL || strstr(human_input, "报错") != NULL)
		{
			printf("这绝不是 bug，这是一个未被记录的 feature（特性）。建议重启试试。\n");
		}
		// 场景 2：老板或产品经理提需求
		else if (strstr(human_input, "需求") != NULL || strstr(human_input, "want") != NULL) {
			printf("这个需求技术上很难实现，底层架构不支持。我们需要重构整个中台\n");
		}
		// 场景 3：涉及金钱
		else if (strstr(human_input, "money") != NULL || strstr(human_input, "钱") != NULL) {
			printf("亲，这就触及到我的知识盲区了。但我建议你打钱给我们公司。\n");
		}
		// 场景 4：终极糊弄学（Fallback 机制）
		else {
			// 根据首字母进行随机（伪随机）回复
			char first_char = human_input[0];
			if (first_char & 3 == 0) {
				printf("非常有意思的观点，请继续展开讲讲。\n");
			}
			else if (first_char & 3 == 1) {
				printf("这确实是一个复杂的哲学问题，我认为关键在于解构主义\n");
			}
			else {
				printf("俺也一样。\n");
			}
		}
	}
return 0;
}
