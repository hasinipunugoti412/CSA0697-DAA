#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10
int optimalBST(int keys[], int freq[], int n) {
    int cost[n + 1][n + 1];
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
    for (int chainLength = 2; chainLength <= n; chainLength++) {
        for (int i = 0; i <= n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int left = (r > i) ? cost[i][r - 1] : 0;
                int right = (r < j) ? cost[r + 1][j] : 0;
                int sumFreq = 0;
                for (int k = i; k <= j; k++) {
                    sumFreq += freq[k];
                }
                int currentCost = left + right + sumFreq;
                if (currentCost < cost[i][j]) {
                    cost[i][j] = currentCost;
                }
            }
        }
    }
    
    return cost[0][n - 1]; 
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    
    int keys[MAX_KEYS]; 
    int freq[MAX_KEYS]; 
    
    printf("Enter the keys and their corresponding frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &keys[i], &freq[i]);
    }
    
    int result = optimalBST(keys, freq, n);
    printf("Optimal cost of binary search tree: %d\n", result);
    
    return 0;
}


