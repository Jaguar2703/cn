#include<stdio.h>
#include<string.h>
#define FLAG "01111110"

void bitStuffing(const char* input, char* output) {
int count = 0;
int j = 0;
strcpy(output, FLAG);
j += strlen(FLAG);

for (int i = 0; input[i] != '\0'; i++) {
output[j++] = input[i];

if (input[i] == '1') {
count++;
} else {
count = 0;
}

if (count == 5) {
output[j++] = '0';
count = 0;
}
}

strcpy(&output[j], FLAG);
}

void bitDestuffing(const char* input, char* output) {
int count = 0;
int j = 0;
int i = strlen(FLAG);

while (input[i] != '\0') {
if (input[i] == '1') {
count++;
output[j++] = '1';
} else {
if (count == 5) {
count = 0;
i++;
continue;
} else {
count = 0;
output[j++] = '0';
}
}
i++;
}
output[j] = '\0';
}

int main() {
char input[256];
char stuffed[512];
char destuffed[256];

printf("Enter a binary string (only 0s and 1s): ");
scanf("%s", input);

bitStuffing(input, stuffed);
printf("Stuffed Data: %s\n", stuffed);

bitDestuffing(stuffed, destuffed);
printf("De-stuffed Data: %s\n", destuffed);

return 0;
}
