#include<iostream>;
using namespace std;

string convert(string prefix) {
	char ch = prefix.at(0);
	string post;
	//delete first character of pre
	if (isdigit(ch))
		post = post + ch;
	else {
		/*convert(pre, post)
		convert(pre, post)
		post = post + ch*/
	}
	return post;
}
	
int main() {
	string expression;
	cin >> expression;
	string res = convert(expression);
	cout << res << endl;
}
