#include <stdio.h>

int main() {
    printf("Fractional Knapsack\n");

    // Number of items
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Arrays to store profits, weights, and ratios of items
    int p[n]; // Profits
    int w[n]; // Weights
    double ratio[n]; // Ratios of profit to weight

    // Input profits and weights of items and calculate ratios
    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &p[i], &w[i]);
        ratio[i] = (double)p[i] / w[i];
    }

    // Knapsack capacity
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Initialize total value of items in knapsack and remaining capacity
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Display table header
    printf("\nItem\tProfit\tWeight\tRatio\n");

    // Loop through items, add them to the knapsack, and display the table
    for (int i = 0; i < n; i++) {
        // If the weight of the item is less than or equal to the remaining capacity
        
        if (w[i] <= remainingCapacity) {
            // Add entire item to the knapsack
            totalValue += p[i];
            remainingCapacity -= w[i];
            // Display item in the table
            printf("%d\t%d\t%d\t%.2lf\n", i + 1, p[i], w[i], ratio[i]);
        } else {
            // Add a fraction of the item to the knapsack
            double fraction = (double)remainingCapacity / w[i];
            totalValue += fraction * p[i];
            // Display item in the table
            printf("%d\t%d\t%d\t%.2lf (Fraction)\n", i + 1, p[i], w[i], ratio[i]);
            break; // Knapsack is full, exit the loop
        }
    }

    // Print the total value of items in the knapsack
    printf("Total profit: %.2lf\n", totalValue);

    return 0;
}
