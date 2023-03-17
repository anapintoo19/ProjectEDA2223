#pragma once

// Estrutura para representar um meio de mobilidade elétrica

typedef struct mobilidade
{
    // Identificador único do meio de mobilidade
    int idMobilidade; 
    // Tipo do meio de mobilidade (ex: bicicleta elétrica, patinete elétrica)
    char tipo[100]; 
    // Nível atual da bateria (em porcentagem)
    float nivel_bateria;
    // Autonomia
    float autonomia;
    // Apontador para o próximo meio de mobilidade na lista
    struct mobilidade* seguinte;


} Mobilidade;


//Declaração das funções para as mobilidades

void listarMobilidade(Mobilidade* mobilidade);
int existeMobilidade(Mobilidade* mobilidade, int idMobilidade);
Mobilidade* inserirMobilidade(Mobilidade* mobilidade, int idMobilidade, char tipo[], float nível_bateria, float autonomia);
Mobilidade* removerMobilidade(Mobilidade* mobilidade, int idMobilidade);
Mobilidade* alterarMobilidade(Mobilidade* mobilidade, int idMobilidade, char tipo[], float nivel_bateria, float autonomia);
void listarMobilidadesDESC(Mobilidade* mobilidade);