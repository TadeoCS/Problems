#include <stdio.h>

int prime(int p);

int main() {
    
    int n, is_prime;
    int count = 2;
    int num_prime = 0;
    
    printf("Enter an integer\t");
    scanf("%d", &n);
    
    while (num_prime<n) {
        is_prime = prime(count);
        
        if (is_prime)
            num_prime += 1;
        
        count++;
    }
    
    printf("\nThe %d-th prime is: %d",n , count-1);
       
    return 0;
}

int prime(int p) {
    
    if (p==2)
        return 1;
    
    for (int i=2; i<p/2 + 1; i++) {
        if (p%i == 0)
            return 0;
        else
            continue;
    }
}
