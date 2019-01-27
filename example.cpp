#include <iostream>
#include <string>

using namespace std;


int main() {

	int pid;
	int ppid;
	string name;
	getline(cin, name);

	while(cin >> pid >> ppid) {
		getline(cin, name);
		cout << pid << " " << ppid << " " << name << endl;
	}
}
