#include <stdio.h>

int weights[5] = {8, 7, 6, 3, 2};
int counts[5];
int match_count = 0;

void find_combinations(int index, int current_sum, int target) {
    if (current_sum == target) {
        printf("%2d TD + 2pt, %2d TD + FG, %2d TD, %2d 3pts FG, %2d Safety\n", 
                counts[0], counts[1], counts[2], counts[3], counts[4]);
        match_count++;
        return;
    }

    if (current_sum > target || index == 5) {
        return;
    }

    int max_count = (target - current_sum) / weights[index];
    
    for (int i = 0; i <= max_count; i++) {
        counts[index] = i; 
        find_combinations(index + 1, current_sum + (i * weights[index]), target);
    }
}

int main() {
    int target;
    int status;
    
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        status = scanf("%d", &target);
        
        if (status != 1) {
            printf("Invalid input! Please enter an integer.\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (target == 1) {
            break;
        }

        if (target < 0) {
            printf("Invalid score! Score cannot be negative.\n\n");
            continue;
        }

        match_count = 0;

        printf("Possible combinations of scoring plays if a team's score is %d:\n", target);
        
        find_combinations(0, 0, target);
        
        printf("Total combinations: %d\n\n", match_count);
    }

    return 0;
}