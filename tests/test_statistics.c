#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "statistics.h"

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

void test_startandard_deviation() {
    float data[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    float sd = calculate_standard_deviation(data, 8);
    if (quase_igual(sd, 2.0)) {
        printf("[PASS] Teste de Desvio Padrão\n");
    } else {
        printf("[FAIL] Teste de Desvio Padrão: esperado 2.0, obtido %.2f\n", sd);
    }
}

int main() {
    test_mean();
    test_covariance();
    test_startandard_deviation();
    return 0;
}