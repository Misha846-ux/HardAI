#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Viewer.h"
using namespace std;

int main() {
	vector<vector<double>> input = 
	{ 
		vector<double> {1,1,1},
		vector<double> {1,0,1},
		vector<double> {1,1,1},
		vector<double> {1,0,1},
		vector<double> {1,1,1}
	};

	Viewer test;
	cout << test.AIAnswer(input);
	/*int a = 30;
	int b = 40;

	ofstream in("test.bin", ios::binary);
	in.write(reinterpret_cast<char*>(&a), sizeof(a));
	in.write(reinterpret_cast<char*>(&b), sizeof(b));
	in.close();
	
	int c;
	int d;
	
	ifstream on("test.bin", ios::binary);
	on.read(reinterpret_cast<char*>(&c), sizeof(c));
	on.read(reinterpret_cast<char*>(&d), sizeof(d));
	on.close();
	cout << c << ' ' << d;*/
	return 0;
}