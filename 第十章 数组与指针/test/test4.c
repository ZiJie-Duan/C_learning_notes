#include <stdio.h>

int main(void){
    int grid[30][100];
    printf("\n%x",&(grid[22][56]));
    printf("\n%x",&(grid[22][0]));
    printf("\n%x",*(grid+22));
    printf("\n%x",&(grid[0][0]));
    printf("\n%x",grid);
    printf("\n%x",&grid);
    getchar();
}