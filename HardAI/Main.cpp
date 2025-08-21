#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Viewer.h"
using namespace std;

int main() {
#include <vector>

    std::vector<std::vector<std::vector<double>>> digits = {
        // 0
        {
            {1,1,1},
            {1,0,1},
            {1,0,1},
            {1,0,1},
            {1,1,1}
        },
        // 1
        {
            {0,1,0},
            {1,1,0},
            {0,1,0},
            {0,1,0},
            {1,1,1}
        },
        // 2
        {
            {1,1,1},
            {0,0,1},
            {1,1,1},
            {1,0,0},
            {1,1,1}
        },
        // 3
        {
            {1,1,1},
            {0,0,1},
            {0,1,1},
            {0,0,1},
            {1,1,1}
        },
        // 4
        {
            {1,0,1},
            {1,0,1},
            {1,1,1},
            {0,0,1},
            {0,0,1}
        },
        // 5
        {
            {1,1,1},
            {1,0,0},
            {1,1,1},
            {0,0,1},
            {1,1,1}
        },
        // 6
        {
            {1,1,1},
            {1,0,0},
            {1,1,1},
            {1,0,1},
            {1,1,1}
        },
        // 7
        {
            {1,1,1},
            {0,0,1},
            {0,1,0},
            {1,0,0},
            {1,0,0}
        },
        // 8
        {
            {1,1,1},
            {1,0,1},
            {1,1,1},
            {1,0,1},
            {1,1,1}
        },
        // 9
        {
            {1,1,1},
            {1,0,1},
            {1,1,1},
            {0,0,1},
            {1,1,1}
        }
    };

    vector<double> numbers = { 0,1,2,3,4,5,6,7,8,9 };

	vector<vector<double>> input = 
	{ 
		vector<double> {1,1,1},
		vector<double> {1,0,1},
		vector<double> {1,1,1},
		vector<double> {1,0,1},
		vector<double> {1,1,1}
	};

	Viewer test;
	//test.AITraining(digits, numbers);
    for (auto& obj : digits) {
        cout << test.AIAnswer(obj) << endl;
    }
	
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