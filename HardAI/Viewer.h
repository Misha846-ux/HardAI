#pragma once
#include"Neuron.h"
#include"NeuronSaver.h"
#include<vector>
using namespace std;
class Viewer
{
private:
	double _smoothing;
	NeuronSaver _file;
	vector<Neuron> _nerons;

	vector<double> NormalasingInput(vector<vector<double>>& input) {
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
public:
	Viewer() {
		this->_smoothing = 0.1;
		this->_file = NeuronSaver("viewerData.bin");

		this->_nerons.push_back(Neuron(15, 12));
		this->_nerons.push_back(Neuron(12, 12));
		this->_nerons.push_back(Neuron(12, 10));

		for (auto& obj : this->_nerons) {
			this->_file.AddNeuron(obj);
		}
		/*for (auto& obj : this->_nerons) {
			obj.Initialize();
		}*/

		this->_file.Read();
		
	}

	int AIAnswer(vector<vector<double>>& input) {
		vector<double> normalInput = this->NormalasingInput(input);
		
		auto cell = this->_nerons[0].NeuronAnswer(normalInput);
		cell = this->_nerons[1].NeuronAnswer(cell);
		cell = this->_nerons[2].NeuronAnswer(cell);
		
		int number = -1;
		double max = 0;
		for (int i = 0; i < cell.size(); i++) {
			if (max < cell[i] || number < 0) {
				max = cell[i];
				number = i;
			}
		}
		return number;
	}

	void AITraining(vector<vector<vector<double>>>& pictures, vector<double>& numbers) {
		long long score = 0;
		while (score < 1000000) {
			score++;
			if (score % 100000 == 0) {
				cout << "I'm working: " << score / 100000 << endl;
			}
			for (int i = 0; i < numbers.size(); i++) {
				vector<double> idealOut(numbers.size());
				for (int j = 0; j < idealOut.size(); j++) {
					if (j == i) {
						idealOut[j] = 1;
					}
					else {
						idealOut[j] = 0;
					}
				}

				this->AIAnswer(pictures[i]);

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

	~Viewer() {
		this->_file.Save();
	}
	
};

