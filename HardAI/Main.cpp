#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Viewer.h"
#include"Artist.h"
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

	Artrist test;
    //test.AITraining(digits, numbers);
    auto cell = test.AIAnswer(9);
    for (auto& obj : cell) {
        for (auto& obj2 : obj) {
            if (obj2 == 0) {
                cout << ' ' << ' ';
            }
            else {
                cout << obj2 << ' ';
            }

        }
        cout << endl;
    }
	
	return 0;
}