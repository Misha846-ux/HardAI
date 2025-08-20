#pragma once
#include"MathFunctions.h"
#include<vector>
using namespace std;
class Neuron
{
private:
	vector<double> _bias;
	vector<double> _output;
	vector<double> _input;
	vector<double> _error;
	vector<vector<double>> _weights;
public:
	Neuron() {};

	Neuron(int inputsCount, int neronsCount) {
		this->_bias = vector<double>(neronsCount);
		this->_output = vector<double>(neronsCount);
		this->_error = vector<double>(neronsCount);
		this->_input = vector<double>(inputsCount);
		this->_weights = vector<vector<double>>(neronsCount, vector<double>(inputsCount));
	}

	vector<double> NeuronAnswer(vector<double> input) {
		this->_input = input;
		for (int i = 0; i < this->_weights.size(); i++) {
			double cell;
			for (int j = 0; j < this->_weights[i].size(); j++) {
				cell = input[j] * this->_weights[i][j];
			}
			cell += this->_bias[i];
			this->_output[i] = sigmoid(cell);
		}
		return this->_output;
	}

	void OutputErrorCalc(vector<double> perfectResult) {
		for (int i = 0; i < this->_weights.size(); i++) {
			this->_error[i] = (perfectResult[i] - this->_output[i]) * sigmoid_derivative(this->_output[i]);
		}
	}

	void OtherErrorCalc(Neuron &previosLayer) {
		for (int i = 0; i < this->_weights.size(); i++) {
			double error = 0;
			for (int j = 0; j < previosLayer._weights.size(); j++) {
				error += previosLayer._error[j] * previosLayer._weights[j][i];
			}
			this->_error[i] = error * sigmoid_derivative(this->_output[i]);
		}
	}

	void UpdateNeuron(int learningRate) {
		for (int i = 0; i < this->_weights.size(); i++) {
			for (int j = 0; j < this->_weights[i].size(); j++) {
				this->_weights[i][j] += learningRate * this->_error[i] * this->_input[j];
			}
			this->_bias[i] += learningRate * this->_error[i];
		}
	}

	vector<vector<double>>* GetWeights() {
		return &this->_weights;
	}
	
	vector<double>* GetBias() {
		return &this->_bias;
	}
	
	void Initialize() {
		srand((time(nullptr))); // инициализация генератора случайных чисел

		// Заполнение весов
		for (size_t i = 0; i < _weights.size(); ++i) {
			for (size_t j = 0; j < _weights[i].size(); ++j) {
				_weights[i][j] = static_cast<double>(rand()) / RAND_MAX; // [0,1]
			}
		}

		// Заполнение смещений
		for (size_t i = 0; i < _bias.size(); ++i) {
			_bias[i] = static_cast<double>(rand()) / RAND_MAX; // [0,1]
		}
	}
};

