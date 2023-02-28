#pragma once
// Estrutura para representar um meio de mobilidade elétrica
typedef struct mobilidadeEletrica
{
    int id; // Identificador único do meio de mobilidade
    char tipo[20]; // Tipo do meio de mobilidade (ex: bicicleta elétrica, patinete elétrica)
    float nivel_bateria; // Nível atual da bateria (em porcentagem)
    int alugada; // Indica se o meio de mobilidade está alugado (1) ou não (0)
    struct mobilidadeEletrica* next; // Ponteiro para o próximo meio de mobilidade na lista

} mobilidadeEletrica;