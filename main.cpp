#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	
	string name = "";

	cout << "Hello, what's your name? ";
	
	getline(cin, name);
	
	cout << "Your name is " << name << endl;
}
