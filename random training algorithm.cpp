#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Função para calcular a predição do modelo de regressão linear
double predict(double weight, double bias, double x) {
	return weight * x + bias;
}

// Função para calcular o erro quadrático médio (MSE)
double calculate_mse(const std::vector<double>& predictions, const std::vector<double>& targets) {
	double mse = 0.0;
	for (size_t i = 0; i < predictions.size(); ++i) {
    	mse += (predictions[i] - targets[i]) * (predictions[i] - targets[i]);
	}
	return mse / predictions.size();
}

// Função para treinar o modelo de regressão linear usando treinamento aleatório
void train_randomly(std::vector<double>& inputs, std::vector<double>& targets, double& weight, double& bias, double learning_rate, int epochs) {
	std::random_device rd;
	std::mt19937 gen(rd());

	for (int epoch = 0; epoch < epochs; ++epoch) {
    	// Selecionar aleatoriamente um índice dos dados de treinamento
    	std::uniform_int_distribution<> dis(0, inputs.size() - 1);
    	int index = dis(gen);

    	// Pegando uma amostra aleatória
    	double x = inputs[index];
    	double y_true = targets[index];

    	// Calculando a predição
    	double y_pred = predict(weight, bias, x);

    	// Calculando o erro
    	double error = y_pred - y_true;

    	// Atualizando os parâmetros (gradiente descendente)
    	weight -= learning_rate * error * x;
    	bias -= learning_rate * error;

    	// Opcional: Imprimir o erro para cada epoch
    	if (epoch % 100 == 0) {
        	std::cout << "Epoch: " << epoch << " | Error: " << error << " | Weight: " << weight << " | Bias: " << bias << std::endl;
    	}
	}
}

int main() {
	// Dados de entrada (x) e seus respectivos alvos (y)
	std::vector<double> inputs = {1.0, 2.0, 3.0, 4.0, 5.0};
	std::vector<double> targets = {2.0, 4.0, 6.0, 8.0, 10.0};  // Supõe uma relação linear simples (y = 2x)

	// Inicialização dos parâmetros (peso e bias)
	double weight = 0.0;
	double bias = 0.0;
	double learning_rate = 0.01;
	int epochs = 1000;

	// Treinamento do modelo usando o algoritmo de treinamento aleatório
	train_randomly(inputs, targets, weight, bias, learning_rate, epochs);

	// Testando o modelo com novos dados
	std::vector<double> test_inputs = {6.0, 7.0, 8.0};
	std::vector<double> predictions;

	for (double x : test_inputs) {
    	double y_pred = predict(weight, bias, x);
    	predictions.push_back(y_pred);
    	std::cout << "Prediction para " << x << ": " << y_pred << std::endl;
	}

	return 0;
}