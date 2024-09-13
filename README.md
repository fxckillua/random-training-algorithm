# Random Training Algorithm - Linear Regression

Este projeto implementa um **algoritmo de treinamento aleatório** para ajuste de um modelo de **regressão linear** simples, utilizando a linguagem C++. O modelo ajusta parâmetros como o peso (slope) e o bias (intercept) de maneira iterativa, utilizando amostras aleatórias dos dados de entrada em cada época.

## Funcionalidades

- **Previsão com Regressão Linear**: O modelo realiza previsões com base em uma relação linear simples entre os dados de entrada e as saídas esperadas.
- **Treinamento Aleatório**: A cada época, uma amostra aleatória dos dados de treino é selecionada para atualizar os parâmetros do modelo.
- **Erro Quadrático Médio (MSE)**: A função de erro utilizada é o erro quadrático médio (Mean Squared Error - MSE), calculado entre as previsões e os valores reais.
- **Atualização dos Parâmetros**: Os parâmetros (peso e bias) são ajustados utilizando o gradiente descendente em cada amostra selecionada aleatoriamente.
- **Predições**: Após o treinamento, o modelo pode ser testado em novos dados para realizar previsões.

## Estrutura do Código

1. **Função `predict`**: Calcula a predição do modelo linear dado os parâmetros peso, bias, e um valor de entrada.
2. **Função `calculate_mse`**: Calcula o erro quadrático médio (MSE) entre as previsões do modelo e os alvos.
3. **Função `train_randomly`**: Implementa o treinamento do modelo de regressão linear, selecionando aleatoriamente amostras dos dados de treino e atualizando os parâmetros com base no erro.
4. **Função `main`**: Define os dados de entrada e saída, inicializa os parâmetros, realiza o treinamento e testa o modelo com novos dados.

## Como Usar

1. **Dados de Entrada**: Os dados de treino consistem em um conjunto de entradas (`inputs`) e alvos (`targets`), que seguem uma relação linear simples.
2. **Treinamento**: O modelo é treinado por um número fixo de épocas (`epochs`) com uma taxa de aprendizado (`learning_rate`).
3. **Teste**: Após o treinamento, o modelo realiza previsões para novos dados.

### Exemplo de Uso

No exemplo, o modelo é treinado com dados que seguem a relação linear `y = 2x`. Depois de 1000 épocas, o modelo pode fazer previsões para novos valores de `x`.

```bash
Epoch: 0 | Error: -0.0 | Weight: 0.0 | Bias: 0.0
...
Epoch: 900 | Error: -0.0007 | Weight: 1.9999 | Bias: 0.0001
Predição para 6.0: 12.0002
Predição para 7.0: 14.0003
Predição para 8.0: 16.0004
