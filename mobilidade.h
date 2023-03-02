#pragma once

// Estrutura para representar um meio de mobilidade elétrica

typedef struct mobilidade
{
    // Identificador único do meio de mobilidade
    int idMobilidade; 
    // Tipo do meio de mobilidade (ex: bicicleta elétrica, patinete elétrica)
    char tipo[20]; 
    // Nível atual da bateria (em porcentagem)
    float nivel_bateria;
    // Indica se o meio de mobilidade está alugado (1) ou não (0)
    int mobilidadeAlugada; 
    // Ponteiro para o próximo meio de mobilidade na lista
    struct mobilidade* seguinte; 

} Mobilidade;