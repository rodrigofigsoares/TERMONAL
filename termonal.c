#include <stdio.h>

int main() {
    char l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0;
    char r1, r2, r3, r4, r5;
    int contador = 0;
    
    r1 = 'a';
    r2 = 'i';
    r3 = 's';
    r4 = 'l';
    r5 = 'a';

    while((l1 != r1 || l2 != r2 || l3 != r3 || l4 != r4 || l5 != r5) && contador <= 5)
    {
        scanf("%c%c%c%c%c", &l1, &l2, &l3, &l4, &l5);
        if(l1 == r1) printf("C");
        else if(l1 == r2 || l1 == r3 || l1 == r4 || l1 == r5) printf("T");
        else printf("E");
        if(l2 == r2) printf("C");
        else if(l2 == r1 || l2 == r3 || l2 == r4 || l2 == r5) printf("T");
        else printf("E");
        if(l3 == r3) printf("C");
        else if(l3 == r1 || l3 == r2 || l3 == r4 || l3 == r5) printf("T");
        else printf("E");
        if(l4 == r4) printf("C");
        else if(l4 == r1 || l4 == r2 || l4 == r3 || l4 == r5) printf("T");
        else printf("E");
        if(l5 == r5) printf("C");
        else if(l5 == r1 || l5 == r2 || l5 == r3 || l5 == r4) printf("T");
        else printf("E");
        contador++;
        printf("\n");
        scanf("%*c");
    }

    return 0;
}