#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100

char grid[MAX_N][MAX_M + 1];
int N, M;
int memo[MAX_N][MAX_M][3]; // 0: D, 1: L, 2: R
int split_count = 0;

int dir_index(char dir) {
    if (dir == 'D') return 0;
    if (dir == 'L') return 1;
    return 2; // 'R'
}

void dfs(int x, int y, char dir) {
    if (x < 0 || y < 0 || x >= N || y >= M) return;
    int dindex = dir_index(dir);
    if (memo[x][y][dindex]) return;
    memo[x][y][dindex] = 1;

    if (grid[x][y] == '^') {
        if (dir == 'D') {
            split_count++;
            dfs(x, y - 1, 'L');
            dfs(x, y + 1, 'R');
            return;
        } else {
            // si llega horizontal a un splitter, se detiene
            return;
        }
    }

    // avanzar en la dirección actual
    if (dir == 'D') dfs(x + 1, y, 'D');
    else if (dir == 'L') dfs(x, y - 1, 'L');
    else if (dir == 'R') dfs(x, y + 1, 'R');
}

int main() {
    // leer grid
    N = 0;
    while (scanf("%s", grid[N]) != EOF) N++;
    M = strlen(grid[0]);

    // encontrar S
    int start_x = -1, start_y = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
                break;
            }
        }
    }

    // inicializar memo
    memset(memo, 0, sizeof(memo));
    split_count = 0;

    // empezar desde S hacia abajo
    dfs(start_x + 1, start_y, 'D');

    printf("Total splits: %d\n", split_count);
    return 0;
}
