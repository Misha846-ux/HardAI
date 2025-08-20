#pragma once
#include<cmath>

double sigmoid(double value) {
	return 1.0 / (1.0 + std::exp(-value));
}

double sigmoid_derivative(double sigmoidOutput) {
	return sigmoidOutput* (1.0 - sigmoidOutput);
}