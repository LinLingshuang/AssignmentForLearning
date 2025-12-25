class MyString
{
public:
	MyString() {
		c[0] = '\0';
	}
	void exchangeWith(MyString &);
	int compareTo(MyString &);
	void setString(char[]);
	char *getString() {
		return c;
	}
	static const int CAPACITY = 64;

private:
	char c[CAPACITY];
};
