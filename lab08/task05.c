#include <stdio.h>
void printGrid(int (*grid)[5]) {
    int r, c;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            printf("%d", grid[r][c]);
            if (c < 4)
                printf(" ");
        }
        printf("\n");
    }
}
int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    int dr, dc, nr, nc;
    for (dr = -1; dr <= 1; dr++) {
        for (dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0)
                continue;               
            nr = row + dr;
            nc = col + dc;
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
                continue;
            count += (grid[nr][nc] & 1); 
        }
    }
    return count;
}
void nextGeneration(int (*grid)[5]) {
    int r, c, n, alive;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            n = countNeighbours(grid, r, c);
            alive = grid[r][c] & 1;

            if (alive && (n == 2 || n == 3))
                grid[r][c] |= 2;        
            else if (!alive && n == 3)
                grid[r][c] |= 2;        
        }
    }
    for (r = 0; r < 5; r++)
        for (c = 0; c < 5; c++)
            grid[r][c] >>= 1;
}
int main() {
    int grid[5][5] = {0};
    int gens, g;
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    while (1) {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gens);
        if (gens < 0 || gens > 50)
            printf("Invalid number\n");
        else
            break;
    }
    for (g = 0; g <= gens; g++) {
        printf("Generation %d:\n", g);
        printGrid(grid);
        if (g < gens)
            nextGeneration(grid);
    }
    return 0;
}
