#include <stdio.h>
#include <stdlib.h>

#define SOUVLAKI_MAX 1000000000000000ULL  // 10^15
#define SOUVLAKI_MAX_SEQUENCE 1000000ULL  // max numbers to track for cycle detection

// Function to compute sum of proper divisors of a number
unsigned long long souvlaki_sum_divisors(unsigned long long souvlaki_n) {
    if (souvlaki_n == 1) return 0; // 1 has no proper divisors

    unsigned long long souvlaki_sum = 1; // 1 is always a proper divisor
    for (unsigned long long souvlaki_i = 2; souvlaki_i * souvlaki_i <= souvlaki_n; souvlaki_i++) {
        if (souvlaki_n % souvlaki_i == 0) {
            souvlaki_sum += souvlaki_i;
            unsigned long long souvlaki_other = souvlaki_n / souvlaki_i;
            if (souvlaki_other != souvlaki_i) {
                souvlaki_sum += souvlaki_other;
            }
        }
    }
    return souvlaki_sum;
}

int main() {
    unsigned long long souvlaki_number;       // starting number
    unsigned long long souvlaki_max_length;   // max length of sequence
    char souvlaki_mode;                       // 'f' or 'l'

    // Read inputs
    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%llu", &souvlaki_number) != 1 || souvlaki_number == 0) {
        fprintf(stderr, "Invalid input for starting number! Did you forget the souvlaki?\n");
        return 1;
    }

    printf("Provide the max aliquot length to look for (0 for unlimited): ");
    if (scanf("%llu", &souvlaki_max_length) != 1) {
        fprintf(stderr, "Invalid input for max length! Not even a souvlaki skewer can fix this.\n");
        return 1;
    }

    printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
    if (scanf(" %c", &souvlaki_mode) != 1 || (souvlaki_mode != 'f' && souvlaki_mode != 'l')) {
        fprintf(stderr, "Invalid input for mode! Only 'f' or 'l' allowed, no souvlaki sauce here.\n");
        return 1;
    }

    // Prepare for cycle detection
    unsigned long long *souvlaki_seen = malloc(SOUVLAKI_MAX_SEQUENCE * sizeof(unsigned long long));
    if (!souvlaki_seen) {
        fprintf(stderr, "Out of memory! Your souvlaki sequence is too big.\n");
        return 1;
    }
    unsigned long long souvlaki_count = 0;
    unsigned long long souvlaki_current = souvlaki_number;
    unsigned long long souvlaki_length = 0;

    while (1) {
        if (souvlaki_current > SOUVLAKI_MAX) {
            printf("Number exceeds maximum supported integer (%llu). Stopping.\n", SOUVLAKI_MAX);
            free(souvlaki_seen);
            return 1;
        }

        // Print current number if in 'f' mode
        if (souvlaki_mode == 'f') printf("%llu\n", souvlaki_current);

        // Check for cycles
        for (unsigned long long i = 0; i < souvlaki_count; i++) {
            if (souvlaki_seen[i] == souvlaki_current) {
                printf("Cycle detected! Your souvlaki sequence entered a loop.\n");
                if (souvlaki_mode == 'l') {
                    printf("Length until cycle: %llu\n", souvlaki_length);
                }
                free(souvlaki_seen);
                return 0;
            }
        }

        // Store the current number in the seen array
        if (souvlaki_count < SOUVLAKI_MAX_SEQUENCE) {
            souvlaki_seen[souvlaki_count++] = souvlaki_current;
        } else {
            printf("Sequence too long for cycle detection. Stopping.\n");
            free(souvlaki_seen);
            return 1;
        }

        souvlaki_current = souvlaki_sum_divisors(souvlaki_current);
        souvlaki_length++;

        // Stop conditions
        if (souvlaki_current == 0) break;
        if (souvlaki_max_length != 0 && souvlaki_length >= souvlaki_max_length) break;
    }

    if (souvlaki_mode == 'l') {
        printf("Length of aliquot sequence: %llu\n", souvlaki_length);
    } else {
        printf("Finished calculating your aliquot souvlaki sequence!\n");
    }

    free(souvlaki_seen);
    return 0;
}
