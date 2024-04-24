#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, m;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n];
    int p[n];

    printf("\nEnter size of knapsack: ");
    scanf("%d", &m);

    printf("\nEnter the weight of an item:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &w[i]);
    }

    printf("\nEnter profit of an item:\n");
    for (int i = 0; i < n; i++) {
        printf("Profit of item %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    int v[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i - 1] <= j)
                v[i][j] = max(p[i - 1] + v[i - 1][j - w[i - 1]], v[i - 1][j]);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    printf("\nMaximum profit: %d\n", v[n][m]);

    return 0;
}
