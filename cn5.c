#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) ((x > y) ? y : x)

int main() {
    int orate, drop = 0, cap, x, count = 0, inp[10] = {0}, i = 0, nsec, ch;
    printf("\nEnter bucket size: ");
    scanf("%d", &cap);
    printf("\nEnter output rate: ");
    scanf("%d", &orate);

    do {
        printf("\nEnter number of packets coming at second %d: ", i + 1);
        scanf("%d", &inp[i]);
        if (inp[i] > cap) {
            printf("Bucket overflow\n");
            printf("Packet Discarded\n");
            exit(0);
        }
        i++;
        printf("\nEnter 1 to continue or 0 to quit: ");
        scanf("%d", &ch);
    } while (ch);
    nsec = i;

    printf("\nSecond\tReceived\tSent\tDropped\tRemained\n");
    for (i = 0; count > 0 || i < nsec; i++) {
        printf("%d", i + 1);
        printf("\t%d\t", inp[i]);

        int sent = MIN((inp[i] + count), orate);
        printf("%d\t", sent);

        x = inp[i] + count - orate;  
        if (x > 0) {
            if (x > cap) {
                drop = x - cap;  
                count = cap;     
            } else {
                drop = 0;
                count = x;       
            }
        } else {
            drop = 0;
            count = 0;           
        }

        printf("%d\t%d\n", drop, count);
    }
    return 0;
}
