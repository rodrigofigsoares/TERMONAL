#include <stdio.h>
#include <string.h>

#define ACERTOU 1
#define ERROU 0
#define PERDEU -1


// Coloque aqui a quantidade de tentativas
#define QUANTIDADE_TENTATIVAS_TERMO 6
#define QUANTIDADE_TENTATIVAS_DUETO 7
#define QUANTIDADE_TENTATIVAS_QUARTETO 8

int termo(char * palavra);
int dueto(char * palavra1, char * palavra2);
int quarteto(char * palavra1, char * palavra2, char * palavra3, char * palavra4);
int verifica_palavra(char * tentativa, char * palavra);
void intro();
int escolha_modo();

int main() {

    intro();
    
    // COLOQUE AQUI A PALAVRA SECRETA (ENTRE AS ASPAS)
    char palavra[6] = "mesto";

    // SE FOR JOGAR COM MAIS DE UMA PALAVRA, COLOQUE AS OUTRAS PALAVRAS AQUI AQUI (ENTRE ASPAS)
    // PARA DUETO (PREENCHA A PALAVRA ANTERIOR TAMBÉM)
    char palavra2[6] = "limbo";
    // PARA QUARTETO (PREENCHA AS PALAVRAS ANTERIORES TAMBÉM)
    char palavra3[6] = "fazer";
    char palavra4[6] = "tchau";

    int modo = escolha_modo();
    if(modo == 1)
    {
        int resultado = termo(palavra);
        if(resultado == PERDEU)
        {
            printf("\033[1;35mFALHOU\033[m: a palavra era \033[1;36m%s\033[m!\n", palavra);
        }
        else
        {
            printf("\033[1;36mPARABÉNS\033[m, você acertou a palavra em \033[1;33m%d\033[m ", resultado+1);
            if(resultado == 0) printf("tentativa!\n");
            else printf("tentativas!\n");
        }
    }
    else if(modo == 2)
    {
        int resultado = dueto(palavra, palavra2);
        if(resultado == PERDEU)
        {
            printf("\033[1;35mFALHOU\033[m: as palavras eram \033[1;36m%s\033[m e \033[1;36m%s\033[m!\n", palavra, palavra2);
        }
        else
        {
            printf("\033[1;36mPARABÉNS\033[m, você acertou as palavras em \033[1;33m%d\033[m tentativas!\n", resultado+1);
        }
    }
    else if(modo == 3)
    {
        int resultado = quarteto(palavra, palavra2, palavra3, palavra4);
        if(resultado == PERDEU)
        {
            printf("\033[1;35mFALHOU\033[m: as palavras eram \033[1;36m%s\033[m, \033[1;36m%s\033[m, \033[1;36m%s\033[m e \033[1;36m%s\033[m!\n", palavra, palavra2, palavra3, palavra4);
        }
        else
        {
            printf("\033[1;36mPARABÉNS\033[m, você acertou as palavras em \033[1;33m%d\033[m tentativas!\n", resultado+1);
        }
    }
    return 0;
}

void intro() {
    printf("Bem vindo ao \033[1;07mTERMONAL\033[m, um jogo que imita o famoso jogo \033[1;04mTermo\033[m, só que, adivinha só! No terminal!\n");
    printf("\033[1;01mCOMO JOGAR\033[m: insira palavras de \033[0;04mcinco\033[m letras, tentando adivinhar a palavra secreta.\n");
    printf("As letras podem aparecer em três cores:\n");
    printf("Você tem 6 tentativas, boa sorte!\n");
    printf("- \033[1;32mVerde\033[m: a letra está contida na palavra e está na posição certa.\n");
    printf("- \033[1;33mAmarelo\033[m: a letra está contida na palavra, mas está na posição errada.\n");
    printf("- \033[1;31mVermelho\033[m: a letra \033[1;01mNÃO\033[m está contida na palavra.\n\n");
    printf("Há dois modos de jogo: termo, dueto e quarteto.\n");
    printf("- \033[1;04m1 - Termo\033[m: você deve adivinhar uma palavra secreta.\n");
    printf("- \033[1;04m2 - Dueto\033[m: você deve adivinhar duas palavras secretas.\n");
    printf("- \033[1;04m3 - Quarteto\033[m: você deve adivinhar quatro palavras secretas.\n\n");
}

int escolha_modo() {
    int modo;
    printf("Escolha seu modo de jogo (1, 2 ou 3): ");
    while(1)
    {
        scanf("%d%*c", &modo);
        if(modo == 1 || modo == 2 || modo == 3) break;
        printf("Modo inválido! Escolha um modo entre 1 e 3: ");
    }

    return modo; 
}

int verifica_palavra(char * tentativa, char * palavra) {
    // Verifica se acertou a palavra
    if(strcmp(tentativa, palavra) == 0)
    {
        return ACERTOU;
    }

    // Primeira letra
    if(tentativa[0] == palavra[0]) printf("\033[1;32m%c\033[m", tentativa[0]);
    else if(tentativa[0] == palavra[1] || tentativa[0] == palavra[2] || tentativa[0] == palavra[3] || tentativa[0] == palavra[4]) printf("\033[1;33m%c\033[m", tentativa[0]);
    else printf("\033[1;31m%c\033[m", tentativa[0]);

    // Segunda letra
    if(tentativa[1] == palavra[1]) printf("\033[1;32m%c\033[m", tentativa[1]);
    else if(tentativa[1] == palavra[0] || tentativa[1] == palavra[2] || tentativa[1] == palavra[3] || tentativa[1] == palavra[4]) printf("\033[1;33m%c\033[m", tentativa[1]);
    else printf("\033[1;31m%c\033[m", tentativa[1]);

    // Terceira letra
    if(tentativa[2] == palavra[2]) printf("\033[1;32m%c\033[m", tentativa[2]);
    else if(tentativa[2] == palavra[0] || tentativa[2] == palavra[1] || tentativa[2] == palavra[3] || tentativa[2] == palavra[4]) printf("\033[1;33m%c\033[m", tentativa[2]);
    else printf("\033[1;31m%c\033[m", tentativa[2]);

    // Quarta letra
    if(tentativa[3] == palavra[3]) printf("\033[1;32m%c\033[m", tentativa[3]);
    else if(tentativa[3] == palavra[0] || tentativa[3] == palavra[1] || tentativa[3] == palavra[2] || tentativa[3] == palavra[4]) printf("\033[1;33m%c\033[m", tentativa[3]);
    else printf("\033[1;31m%c\033[m", tentativa[3]);

    // Quinta letra
    if(tentativa[4] == palavra[4]) printf("\033[1;32m%c\033[m", tentativa[4]);
    else if(tentativa[4] == palavra[0] || tentativa[4] == palavra[1] || tentativa[4] == palavra[2] || tentativa[4] == palavra[3]) printf("\033[1;33m%c\033[m", tentativa[4]);
    else printf("\033[1;31m%c\033[m", tentativa[4]);

    return ERROU;
}

// Uma palavra
int termo(char * palavra) {
    printf("\nNo termo, você tem 6 tentativas para acertar uma palavra. Boa sorte!\n\n");
    printf("Escreva sua primeira palavra:\n");
    char tentativa[6][6];
    int i;
    for(i=0;i<QUANTIDADE_TENTATIVAS_TERMO;i++)
    {
        scanf("%s", tentativa[i]);
        if(verifica_palavra(tentativa[i], palavra) == ACERTOU)
        {
            printf("\033[1;32m%s\033[m", palavra);
            printf("\n");
            return i;
        }
        printf(" %d tentativas restantes!\n", 5-i);
    }
    return PERDEU;
}

// Duas palavras
int dueto(char * palavra1, char * palavra2) {
    printf("\nNo dueto, você tem 7 tentativas para acertar duas palavras. Boa sorte!\n\n");
    printf("Escreva sua primeira palavra:\n");
    int resultado1, resultado2;
    int first, second;
    first = second = 0;

    char tentativa[6];
    int i;
    for(i=0;i<QUANTIDADE_TENTATIVAS_DUETO;i++)
    {
        scanf("%s", tentativa);

        if(first == 0)
        {
            resultado1 = verifica_palavra(tentativa, palavra1);
            if(resultado1 == ACERTOU)
            {
                printf("\033[1;32m%s\033[m", palavra1);
                first = 1;
            }
        }
        else printf("     ");
        printf(" ");
        if(second == 0)
        {
            resultado2 = verifica_palavra(tentativa, palavra2);
            if(resultado2 == ACERTOU)
            {
                printf("\033[1;32m%s\033[m", palavra2);
                second = 1;
            }
        }
        else printf("     ");
        printf("\n");
        if(first == 1 && second == 1) return i;
    }
    return PERDEU;
}

// Quatro palavras
int quarteto(char * palavra1, char * palavra2, char * palavra3, char * palavra4) {
    char tentativa[6];
    int first, second, third, fourth;
    first = second = third = fourth = 0;
    printf("\nNo quarteto, você tem 8 tentativas para acertar quatro palavras. Boa sorte!\n\n");
    printf("Escreva sua primeira palavra:\n");

    int resultado1, resultado2, resultado3, resultado4;
    int i;
    for(i=0;i<QUANTIDADE_TENTATIVAS_QUARTETO;i++)
    {
        scanf("%s", tentativa);

        if(first == 0)
        {
            resultado1 = verifica_palavra(tentativa, palavra1);
            if(resultado1 == ACERTOU)
            {
                printf("\033[1;32m%s\033[m", palavra1);
                first = 1;
            }
        }
        else printf("     ");
        printf(" ");
        if(second == 0)
        {
            resultado2 = verifica_palavra(tentativa, palavra2);
            if(resultado2 == ACERTOU)
            {
                printf("\033[1;32m%s\033[m", palavra2);
                second = 1;
            }
        }
        else printf("     ");
        printf(" ");
        if(third == 0)
        {
            resultado3 = verifica_palavra(tentativa, palavra3);
            if(resultado3 == ACERTOU)
            {
                printf("\033[1;32m%s\033[m", palavra3);
                third = 1;
            }
        }
        else printf("     ");
        printf(" ");
        if(fourth == 0)
        {
            resultado4 = verifica_palavra(tentativa, palavra4);
            if(resultado4 == ACERTOU)
            {
                printf("\033[1;32m%s\033[m", palavra4);
                fourth = 1;
            }
        }
        else printf("     ");
        printf("\n");
        if(first == 1 && second == 1 && third == 1 && fourth == 1) return i;
    }
    return PERDEU;
}