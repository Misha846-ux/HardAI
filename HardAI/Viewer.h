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
		this->_smoothing = 0.01;
		this->_file = NeuronSaver("viewerData.bin");

		this->_nerons.push_back(Neuron(15, 12));
		this->_nerons.push_back(Neuron(12, 12));
		this->_nerons.push_back(Neuron(12, 10));

		for (auto& obj : this->_nerons) {
			this->_file.AddNeuron(obj);
		}

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
		return max;
	}

	void AITraining(vector<vector<vector<double>>>& pictures, vector<double>& numbers) {
		vector<vector<double>> input(pictures.size());
		for (int i = 0; i < input.size(); i++) {
			input[i] = this->NormalasingInput(pictures[i]);
		}
	}
	
};

