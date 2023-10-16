#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/dicionario.h"

#define MAX_INPUT_LENGTH 200

int main() {
    DICIONARIO *dicionario = dicionario_criar();
    if (dicionario == NULL) {
        printf("Erro ao criar o dicionario.\n");
        return 1;
    }

    char input[MAX_INPUT_LENGTH];
    char operacao[MAX_INPUT_LENGTH];
    char str1[MAX_INPUT_LENGTH];
    char str2[MAX_INPUT_LENGTH];

    printf("Bem-vindo ao dicionario!\n");
    printf("Para sair, digite 'sair'.\n");

    while (1) {
        printf("Operacao (insercao, alteracao, remocao, busca, impressao): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove o caractere da nova linha

        if (strcmp(input, "sair") == 0) {
            break;
        }

        char *token = strtok(input, " ");
        if (token != NULL) {
            strcpy(operacao, token);

            if (strcmp(operacao, "insercao") == 0) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(str1, token);
                    token = strtok(NULL, "");
                    if (token != NULL) {
                        strcpy(str2, token);
                        if (dicionario_insercao(dicionario, str1, str2)) {
                            printf("Insercao realizada com sucesso.\n");
                        } else {
                            printf("OPERACAO INVALIDA.\n");
                        }
                    } else {
                        printf("Definicao nao especificada.\n");
                    }
                } else {
                    printf("Palavra nao especificada.\n");
                }
            } else if (strcmp(operacao, "alteracao") == 0) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(str1, token);
                    token = strtok(NULL, "");
                    if (token != NULL) {
                        strcpy(str2, token);
                        if (dicionario_alteracao(dicionario, str1, str2)) {
                            printf("Alteracao realizada com sucesso.\n");
                        } else {
                            printf("OPERACAO INVALIDA.\n");
                        }
                    } else {
                        printf("Definicao nao especificada.\n");
                    }
                } else {
                    printf("Palavra nao especificada.\n");
                }
            } else if (strcmp(operacao, "remocao") == 0) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(str1, token);
                    if (dicionario_remocao(dicionario, str1)) {
                        printf("Remocao realizada com sucesso.\n");
                    } else {
                        printf("OPERACAO INVALIDA.\n");
                    }
                } else {
                    printf("Palavra nao especificada.\n");
                }
            } else if (strcmp(operacao, "busca") == 0) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(str1, token);
                    ITEM *item = dicionario_busca(dicionario, str1);
                    if (item != NULL) {
                        printf("Definicao: %s\n", item_get_str2(item));
                    } else {
                        printf("OPERACAO INVALIDA.\n");
                    }
                } else {
                    printf("Palavra nao especificada.\n");
                }
            } else if (strcmp(operacao, "impressao") == 0) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(str1, token);
                    if (!dicionario_impressao(dicionario, str1)) {
                        printf("NAO HA PALAVRAS INICIADAS POR %s\n", str1);
                    }
                } else {
                    printf("Caractere nao especificado.\n");
                }
            } else {
                printf("Operacao invalida.\n");
            }
        }
    }

    dicionario_apagar(&dicionario);
    return 0;
}
