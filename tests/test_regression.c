#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "linear_regression.h"

#define EPSILON 0.001f

int quase_igual(float a, float b) {
    return fabsf(a - b) < EPSILON;
}

void test_mean() {
    float data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float m = calculate_mean(data, 5);
    if (quase_igual(m, 3.0)) {
        printf("[PASS] Teste de Média\n");
    } else {
        printf("[FAIL] Teste de Média: esperado 3.0, obtido %.2f\n", m);
    }
}

void test_model_fit() {
    float x[] = {1, 2, 3};
    float y[] = {3, 5, 7};
    
    LinearModel model = fit_model(x, y, 3);
    
    assert(quase_igual(model.slope, 2.0));
    assert(quase_igual(model.intercept, 1.0));
    
    printf("[PASS] Teste de Ajuste de Modelo (y = 2x + 1)\n");
}

void test_covariance() {
    float x[] = {1, 2, 3};
    float y[] = {2, 4, 6};
    float cov = calculate_covariance(x, y, 3);
    
    if (cov > 0) {
        printf("[PASS] Teste de Covariância (Correlação positiva detectada)\n");
    } else {
        printf("[FAIL] Teste de Covariância\n");
    }
}

int main() {
    printf("--- INICIANDO TESTES UNITÁRIOS ---\n");
    test_mean();
    test_covariance();
    test_model_fit();
    printf("--- TODOS OS TESTES CONCLUÍDOS ---\n");
    return 0;
}