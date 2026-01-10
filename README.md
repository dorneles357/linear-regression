# 📈 Linear Regression C Library

Uma biblioteca simples e modular em C para cálculos de regressão linear simples, variância e covariância.

## 📂 Estrutura do Projeto

A estrutura segue o padrão de separação entre interface e implementação:

* **bin/**: Executáveis gerados.
* **include/**: Arquivos de cabeçalho (`.h`) - Definições das funções.
* **obj/**: Arquivos de objeto intermediários.
* **src/**: Código-fonte (`.c`) da biblioteca e programa principal.
* **tests/**: Testes unitários para validar os cálculos.

---

## 🚀 Como Compilar e Rodar

Este projeto utiliza `make` para automatizar o processo de compilação.

### Pré-requisitos

* Compilador `gcc`
* Ferramenta `make`

### 1. Compilar o programa principal

Para compilar o projeto e gerar o executável na pasta `bin/`:

```bash
make

```

### 2. Executar o programa

Para compilar (se necessário) e rodar o programa imediatamente:

```bash
make run

```

### 3. Limpar arquivos temporários

Para remover as pastas `obj/` e `bin/` e realizar uma compilação limpa:

```bash
make clean

```

---

## 🧪 Testes Automatizados

Para garantir que os cálculos matemáticos estão precisos, o projeto conta com uma suíte de testes unitários que valida a média, covariância e o ajuste do modelo.

Para rodar os testes:

```bash
make test

```

---

## 🛠️ Como usar a Lib no seu código

Basta incluir o header e chamar a estrutura `LinearModel`:

```c
#include "linear_regression.h"

float x[] = {1, 2, 3};
float y[] = {2, 4, 6};
LinearModel model = fit_model(x, y, 3);

printf("Inclinação: %.2f\n", model.slope);

```

---