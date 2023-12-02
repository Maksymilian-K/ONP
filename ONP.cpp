#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	//Wyraz do zmienienia na ONP
	string wyr = "a+b-c*(d-e)";
	//Stos znaków
	stack<char> znaki;
	//Odpowiedz
	string odpowiedz;

	//Dla całego wyrazu trzeba zaimplementować pętle for
	for (int i = 0; i < wyr.length(); i++) {
		
			//Dla + i - nie zmiania nam się kolejność
			if (wyr[i] == '+' || wyr[i] == '-') {
				//dlatego tylko dajemy na wierzchołek stosu
				znaki.push(wyr[i]);
			} 
			//Przy * i / zmienia nam się kolejność
			else if (wyr[i] == '*' || wyr[i] == '/') {
				//Na wypadek występowania nawiasu przejdziemy do if odpowiedzialnego
				//za nawiasy żeby nie wywaliło programu
				if (wyr[i + 1] != '(') {
					//na początek dodajemy do stosu znak
					znaki.push(wyr[i]);
					//do odpowiedzi dodajemy następny znak
					//dlatego gdybyśmy mieli nawias przechodzimy dalej
					odpowiedz += wyr[i + 1];
					//wypisujemy znaki dopóki stos nie będzie pusty
					while (znaki.empty() != true) {
						odpowiedz += znaki.top();
						znaki.pop();
					}
					// dodajemy do i 1 ponieważ już dodaliśmy następny znak
					//przez odpowiedz += wyr[i + 1]
					i++;
				}
				//gdyby był nawias traktujemy to jak + lub -
				else {
					znaki.push(wyr[i]);
				}
			}
		        //Jeśli znajdziemy nawias dodajemy go
		        //przyda się później
			else if (wyr[i] == '(') 
			{
				znaki.push(wyr[i]);
			}
			//jeśli zamkniemy nawias 
			else if(wyr[i]==')')
			{
				//musimy wypisać wszystkie znaki do otwarcia nawiasu
				//Litery z nawiasu dodaliśmy już dzięki else na samym dole
				while (znaki.top() != '(') {
					odpowiedz += znaki.top();
					znaki.pop();
				}
				//usuwamy znak (
				znaki.pop();
			}
			//Jeśli nie będzie to znak po prostu to wypisujemy
			else {
				odpowiedz += wyr[i];
			}
	}

	//Jeśli nie znalazł się żaden nawias lub * lub / wypisujemy wszystko co zostało
	//dopóki stos nie będzie pusty
	//znaki już wypisaliśmy dzięki else na samym końcu for'a
	while(znaki.empty()!=true)
	{
		odpowiedz += znaki.top();
		znaki.pop();
	}

	//Wypisujemy odpowiedź
	cout << odpowiedz;
}
