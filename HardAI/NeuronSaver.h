#pragma once
#include"Neuron.h"
#include<fstream>
#include<string>
#include<memory>
using namespace std;
class NeuronSaver
{
private:
	string _path;
	vector<Neuron*> _neurons;
public:
	NeuronSaver(){}
	NeuronSaver(string path) {
		this->_path = path;
	}

	void AddNeuron(Neuron& neuron) {
		this->_neurons.push_back(&neuron);
	}

	void Save() {
		ofstream in(this->_path, ios::binary);
		for (auto& obj : this->_neurons) {
			for (auto& obj2 : *obj->GetWeights()) {
				in.write(reinterpret_cast<char*>(obj2.data()), (obj2.size() * sizeof(obj2[0])));
			}
			auto& obj2 = *obj->GetBias();
			in.write(reinterpret_cast<char*>(obj2.data()), (obj2.size() * sizeof(obj2[0])));
		}
		in.close();
	}

	void Read() {
		ifstream out(this->_path, ios::binary);
		for (auto& obj : this->_neurons) {
			for (auto& obj2 : *obj->GetWeights()) {
				out.read(reinterpret_cast<char*>(obj2.data()), (obj2.size() * sizeof(obj2[0])));
			}
			auto& obj2 = *obj->GetBias();
			out.read(reinterpret_cast<char*>(obj2.data()), (obj2.size() * sizeof(obj2[0])));
		}
		out.close();
	}
};

