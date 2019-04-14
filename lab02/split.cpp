#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    string paths;
    cin >> paths;
    string split;
    
    for (int i=0; i<paths.size(); i++) {
        
        if (paths[i] != ':') {
            split += paths[i];
        }
        else {
            cout << split << endl;
            split = "";
            i++;
        }
    }
    
	return 0;
}
