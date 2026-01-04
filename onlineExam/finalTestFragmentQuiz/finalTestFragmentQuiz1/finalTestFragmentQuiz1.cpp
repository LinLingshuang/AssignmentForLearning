// finalTestFragmentQuiz1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

struct reverses {
    string word;
    int index;

};

bool compare(reverses& a, reverses& b) {
    if (a.word[0] != b.word[0])  return a.word[0] < b.word[0];
    else return a.index < b.index;
}


int main() {
    fstream fin("filezip.in");
    fstream fout("filezip.out");


    int n;
    string str;
    cin >> n >> str;
    fin >> n >> str;

    vector<reverses> words(n);
    for (int i = 0; i < n; i++) {
        words[i].word = str.substr(i) + str.substr(0, i);
        words[i].index = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << words[i].word<<endl;
    }
    cout << endl;
    sort(words.begin(), words.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << words[i].word << endl;
    }
    cout << endl;
    string result = "";
    for (auto& p : words) {
        int count = p.word.size();
        result += p.word[count - 1];
    }

    int p = 1;
    char secondch = str[1];
    for (char c : str) {
        if (c < secondch)  p++;
    }

    if (str[0] == secondch) p++;


    fout << result << endl << p;
    cout << result << endl << p;

    fout.close();
    fin.close();

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
