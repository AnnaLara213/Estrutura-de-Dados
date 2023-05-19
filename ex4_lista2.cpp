#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

#define MAX_ALUNOS 10
#define NOTA_MAXIMA 10

struct Aluno {
    char nome[50];
    int notas;
    char turma[3];
};

bool verificarNomeValido(const char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && !isspace(nome[i])) {
            return false;
        }
    }
    return true;
}

void lerDadosAlunos(struct Aluno alunos[]) {
    printf("=== Cadastro de Alunos ===\n");

    for (int i = 0; i < MAX_ALUNOS; i++) {
        struct Aluno aluno;

        printf("Aluno %d:\n", i + 1);

        bool nomeValido = false;
        while (!nomeValido) {
            printf("Nome: ");
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

            if (verificarNomeValido(aluno.nome)) {
                nomeValido = true;
            } else {
                printf("Nome inválido. Insira um nome válido sem números.\n");
            }
        }

        bool notaValida = false;
        while (!notaValida) {
            printf("Notas (entre 1 e 10): ");
            if (scanf("%d", &aluno.notas) == 1 && aluno.notas >= 1 && aluno.notas <= 10) {
                notaValida = true;
            } else {
                printf("Nota inválida. Insira um número entre 1 e 10.\n");
                while (getchar() != '\n'); 
            }
        }

        bool turmaValida = false;
        while (!turmaValida) {
            printf("Turma (A1, B2, C3 ou D4): ");
            scanf("%s", aluno.turma);

            if (strcmp(aluno.turma, "A1") == 0 || strcmp(aluno.turma, "B2") == 0 ||
                strcmp(aluno.turma, "C3") == 0 || strcmp(aluno.turma, "D4") == 0) {
                turmaValida = true;
            } else {
                printf("Turma inválida. Insira uma turma válida (A1, B2, C3 ou D4).\n");
                while (getchar() != '\n'); 
            }
        }

        alunos[i] = aluno;
        getchar();  
    }
}


void encontrarMaiorNota(const struct Aluno alunos[], int* maiorNota) {
    *maiorNota = 0;

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].notas > *maiorNota) {
            *maiorNota = alunos[i].notas;
        }
    }
}

void imprimirAlunosMaiorNota(const struct Aluno alunos[], int maiorNota) {
    printf("Alunos com a maior nota (%d):\n", maiorNota);

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].notas == maiorNota) {
            printf("- %s\n", alunos[i].nome);
        }
    }
}

void imprimirTurmasMaiorNota(const struct Aluno alunos[], int maiorNota) {
    printf("Turmas com alunos de maior nota (%d):\n", maiorNota);

    char turmas[MAX_ALUNOS][3];
    int numTurmas = 0;

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].notas == maiorNota) {
            bool turmaEncontrada = false;

            for (int j = 0; j < numTurmas; j++) {
                if (strcmp(turmas[j], alunos[i].turma) == 0) {
                    turmaEncontrada = true;
                    break;
                }
            }

            if (!turmaEncontrada) {
                strcpy(turmas[numTurmas], alunos[i].turma);
                printf("- %s\n", turmas[numTurmas]);
                numTurmas++;
            }
        }
    }
}

void contarAlunosPorTurma(const struct Aluno alunos[], int maiorNota) {
    printf("Quantidade de alunos por turma com a maior nota (%d):\n", maiorNota);

    char turmas[MAX_ALUNOS][3];
    int numTurmas = 0;

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].notas == maiorNota) {
            bool turmaEncontrada = false;

            for (int j = 0; j < numTurmas; j++) {
                if (strcmp(turmas[j], alunos[i].turma) == 0) {
                    turmaEncontrada = true;
                    break;
                }
            }

            if (!turmaEncontrada) {
                strcpy(turmas[numTurmas], alunos[i].turma);

                int cont = 0;

                for (int k = i; k < MAX_ALUNOS; k++) {
                    if (alunos[k].notas == maiorNota && strcmp(alunos[k].turma, turmas[numTurmas]) == 0) {
                        cont++;
                    }
                }

                printf("- %s: %d aluno(s)\n", turmas[numTurmas], cont);
                numTurmas++;
            }
        }
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    struct Aluno alunos[MAX_ALUNOS];
    int maiorNota;

    lerDadosAlunos(alunos);
    encontrarMaiorNota(alunos, &maiorNota);

    imprimirAlunosMaiorNota(alunos, maiorNota);
    printf("\n");

    imprimirTurmasMaiorNota(alunos, maiorNota);
    printf("\n");

    contarAlunosPorTurma(alunos, maiorNota);

    return 0;
}

