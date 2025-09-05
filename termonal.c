#include <stdio.h>

int main() {
    char l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0;
    char r1, r2, r3, r4, r5;
    int contador = 0, conseguiu = 0;

    printf("Bem vindo ao \033[1;07mTERMONAL\033[m, um jogo que imita o famoso jogo \033[1;04mTermo\033[m, só que, adivinha só! No terminal!\n");
    printf("\033[1;01mCOMO JOGAR\033[m: insira palavras de \033[0;04mcinco\033[m letras, tentando adivinhar a palavra secreta.\n");
    printf("As letras podem aparecer em três cores:\n");
    printf("Você tem 6 tentativas, boa sorte!\n");
    printf("- \033[1;32mVerde\033[m: a letra está contida na palavra e está na posição certa.\n");
    printf("- \033[1;33mAmarelo\033[m: a letra está contida na palavra, mas está na posição errada.\n");
    printf("- \033[1;31mVermelho\033[m: a letra \033[1;01mNÃO\033[m está contida na palavra.\n\n");
    printf("\033[1;04mInsira a primeira palavra:\033[m\n\n");
    
    r1 = 'r';
    r2 = 'u';
    r3 = 'm';
    r4 = 'e';
    r5 = 'n';

    while((l1 != r1 || l2 != r2 || l3 != r3 || l4 != r4 || l5 != r5) && contador <= 5)
    {
        scanf("%c%c%c%c%c%*c", &l1, &l2, &l3, &l4, &l5);
        if(l1 == r1) printf("\033[1;32m%c\033[m", l1);
        else if(l1 == r2 || l1 == r3 || l1 == r4 || l1 == r5) printf("\033[1;33m%c\033[m", l1);
        else printf("\033[1;31m%c\033[m", l1);
        if(l2 == r2) printf("\033[1;32m%c\033[m", l2);
        else if(l2 == r1 || l2 == r3 || l2 == r4 || l2 == r5) printf("\033[1;33m%c\033[m", l2);
        else printf("\033[1;31m%c\033[m", l2);
        if(l3 == r3) printf("\033[1;32m%c\033[m", l3);
        else if(l3 == r1 || l3 == r2 || l3 == r4 || l3 == r5) printf("\033[1;33m%c\033[m", l3);
        else printf("\033[1;31m%c\033[m", l3);
        if(l4 == r4) printf("\033[1;32m%c\033[m", l4);
        else if(l4 == r1 || l4 == r2 || l4 == r3 || l4 == r5) printf("\033[1;33m%c\033[m", l4);
        else printf("\033[1;31m%c\033[m", l4);
        if(l5 == r5) printf("\033[1;32m%c\033[m", l5);
        else if(l5 == r1 || l5 == r2 || l5 == r3 || l5 == r4) printf("\033[1;33m%c\033[m", l5);
        else printf("\033[1;31m%c\033[m", l5);
        contador++;
        printf("\n");
        if(l1 == r1 && l2 == r2 && l3 == r3 && l4 == r4 && l5 == r5)
        {
            printf("\033[1;36mPARABÉNS\033[m\n");
            conseguiu = 1;
        }
    }
    if(conseguiu == 0) printf("\033[1;35mFALHOU\033[m: a palavra era \033[1;36m%c%c%c%c%c\033[m!\n", r1, r2, r3, r4, r5);
    return 0;
}