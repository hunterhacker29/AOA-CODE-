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
//or 
#include <stdio.h>

// Structure to represent an item
struct Item {
    int profit; // Profit of the item
    int weight; // Weight of the item
    double ratio; // Ratio of profit to weight
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on items based on ratio
void sortByRatio(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    printf("Fractional Knapsack\n");

    // Number of items
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Array to store items
    struct Item items[n];

    // Input profits and weights of items and calculate ratios
    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    // Sort items by ratio in descending order
    sortByRatio(items, n);

    // Knapsack capacity
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Initialize total value of items in knapsack and remaining capacity
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Display table header
    printf("\nItem\tProfit\tWeight\tRatio\n");

    // Loop through sorted items, add them to the knapsack, and display the table
    for (int i = 0; i < n; i++) {
        // If the weight of the item is less than or equal to the remaining capacity
        if (items[i].weight <= remainingCapacity) {
            // Add entire item to the knapsack
            totalValue += items[i].profit;
            remainingCapacity -= items[i].weight;
            // Display item in the table
            printf("%d\t%d\t%d\t%.2lf\n", i + 1, items[i].profit, items[i].weight, items[i].ratio);
        } else {
            // Add a fraction of the item to the knapsack
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].profit;
            // Display item in the table
            printf("%d\t%d\t%d\t%.2lf (Fraction)\n", i + 1, items[i].profit, items[i].weight, items[i].ratio);
            break; // Knapsack is full, exit the loop
        }
    }

    // Print the total value of items in the knapsack
    printf("Total profit: %.2lf\n", totalValue);

    return 0;
}
