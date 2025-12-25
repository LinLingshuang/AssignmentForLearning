/*6-22 ±àĞ´º¯Êıvoid reverse(string &s)£¬ÓÃµİ¹éËã·¨Ê¹×Ö·û´®sµ¹Ğò*/
#include<iostream>
#include<string>
using namespace std;

void reverse(string& s) {
	int length = s.length();
	char *temp=new char[1000]();
	int i = 0;
	while (i < length) {
		temp[i] = s[length - 1 - i];
		i++;
	}
	temp[i] = '\0';
	s = temp;
	delete[] temp;
}



int main() {
	string input;
	cin >> input;
	reverse(input);
	cout << input;

}

/*#include<iostream>
#include<string>
using namespace std;

void reverse(string& s, int left = 0, int right = -1) {
    // ³õÊ¼»¯ÓÒ±ß½ç
    if (right == -1) {
        right = s.length() - 1;
    }
    
    // µİ¹é»ù£º×óÓÒÖ¸ÕëÏàÓö»ò½»²æ
    if (left >= right) {
        return;
    }
    
    // ½»»»×óÓÒ×Ö·û
    swap(s[left], s[right]);
    
    // µİ¹é´¦ÀíÊ£Óà²¿·Ö
    reverse(s, left + 1, right - 1);
}

int main() {
    string input;
    cin >> input;
    reverse(input);
    cout << input;
    return 0;
}*/