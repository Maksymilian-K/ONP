#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	string wyr = "a+b-c*(d-e)";
	stack<char> znaki;
	string odpowiedz;

	for (int i = 0; i < wyr.length(); i++) {
		
		
			if (wyr[i] == '+' || wyr[i] == '-') {
				znaki.push(wyr[i]);
			}
			else if (wyr[i] == '*' || wyr[i] == '/') {
				if (wyr[i + 1] != '(') {
					znaki.push(wyr[i]);
					odpowiedz += wyr[i + 1];
					while (znaki.empty() != true) {
						odpowiedz += znaki.top();
						znaki.pop();
					}
					i++;
				}
				else {
					znaki.push(wyr[i]);
				}
			}
			else if (wyr[i] == '(') 
			{
				znaki.push(wyr[i]);
			}
			else if(wyr[i]==')')
			{
				while (znaki.top() != '(') {
					odpowiedz += znaki.top();
					znaki.pop();
				}
				znaki.pop();
			}
			else {
				odpowiedz += wyr[i];
			}
	}
	
	while(znaki.empty()!=true)
	{
		odpowiedz += znaki.top();
		znaki.pop();
	}
	cout << odpowiedz;
}
