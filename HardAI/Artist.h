#pragma once
#include"Neuron.h"
#include"NeuronSaver.h"
#include<vector>
using namespace std;
class Artrist {
private:
	double _smoothing;
	NeuronSaver _file;
	vector<Neuron> _nerons;

	vector<vector<int>> normalizOut(vector<double> output) {
		vector<vector<int>> newOut(5, vector<int>(3));
		int score = 0;
		for (int i = 0; i < newOut.size(); ++i) {
			for (int j = 0; j < newOut[i].size(); ++j) {
				if (output[score] > 0.5) {
					newOut[i][j] = 1;
				}
				else {
					newOut[i][j] = 0;
				}
				++score;
			}
		}
		return newOut;
	}

	vector<double> NormalasingPictures(vector<vector<double>>& input) {
		vector<double> normalInput((input.size() * input[0].size()));
		int i = 0;
		for (auto& obj : input) {
			for (auto& obj2 : obj) {
				normalInput[i] = obj2;
				i++;
			}
		}
		return normalInput;
	}

	vector<double> AIThinks(vector<double> input) {
		auto cell = this->_nerons[0].NeuronAnswer(input);
		cell = this->_nerons[1].NeuronAnswer(cell);
		return this->_nerons[2].NeuronAnswer(cell);
	}
public:
	Artrist() {
		this->_smoothing = 0.01;
		this->_file = NeuronSaver("artistData.bin");

		this->_nerons.push_back(Neuron(1, 15));
		this->_nerons.push_back(Neuron(15, 15));
		this->_nerons.push_back(Neuron(15, 15));

		for (auto& obj : this->_nerons) {
			this->_file.AddNeuron(obj);
		}
		/*for (auto& obj : this->_nerons) {
			obj.Initialize();
		}*/

		this->_file.Read();
	}

	vector<vector<int>> AIAnswer(int number) {
		vector<double> v;
		v.push_back(number);
		auto output = this->AIThinks(v);
		return this->normalizOut(output);
		
	}

	void AITraining(vector<vector<vector<double>>>& pictures, vector<double>& numbers) {
		long long score = 0;
		while (score < 1000000) {
			++score;
			if (score % 100000 == 0) {
				cout << "Artist working: " << score / 100000 << endl;
			}
			for (int g = 0; g < numbers.size(); ++g) {
				vector<double> idealOut = NormalasingPictures(pictures[g]);
				vector<double> number;
				number.push_back(numbers[g]);
				this->AIThinks(number);

				this->_nerons[2].OutputErrorCalc(idealOut);
				this->_nerons[1].OtherErrorCalc(this->_nerons[2]);
				this->_nerons[0].OtherErrorCalc(this->_nerons[1]);

				this->_nerons[2].UpdateNeuron(this->_smoothing);
				this->_nerons[1].UpdateNeuron(this->_smoothing);
				this->_nerons[0].UpdateNeuron(this->_smoothing);
			}
		}
		this->_file.Save();
	}

	~Artrist() {
		this->_file.Save();
	}
};