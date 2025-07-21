#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc != 2)
    {
        printf("computro: error.\n");
        printf("computor: use: ./computor \"5 + 4 * X + X^2= X^2\"\n");
        exit(1);
    }

    for (int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    return (0);
}