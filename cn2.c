#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void xorOperation(char *dividend, char *divisor) {
    for (int i = 0; i < strlen(divisor); i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

void divide(char *data, char *generator, char *remainder) {
    int dataLen = strlen(data);
    int genLen = strlen(generator);
    char temp[MAX_LEN];
    strcpy(temp, data);

    for (int i = 0; i <= dataLen - genLen; i++) {
        if (temp[i] == '1') {
            xorOperation(temp + i, generator);
        }
    }

    strncpy(remainder, temp + dataLen - genLen + 1, genLen - 1);
    remainder[genLen - 1] = '\0';
}

void encode(char *data, char *generator, char *encodedData) {
    int genLen = strlen(generator);
    char paddedData[MAX_LEN];
    sprintf(paddedData, "%s%s", data, "0");

    char remainder[MAX_LEN];
    divide(paddedData, generator, remainder);
    sprintf(encodedData, "%s%s", data, remainder);
}

int decode(char *dataWithCRC, char *generator) {
    char remainder[MAX_LEN];
    divide(dataWithCRC, generator, remainder);
    for (int i = 0; i < strlen(remainder); i++) {
        if (remainder[i] == '1') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char generator[MAX_LEN];
    char data[MAX_LEN];
    char encodedData[MAX_LEN];

    printf("Enter the generator polynomial (binary): ");
    scanf("%s", generator);

    printf("Enter the data (binary): ");
    scanf("%s", data);

    printf("Original Data: %s\n", data);
    encode(data, generator, encodedData);
    printf("Encoded Data: %s\n", encodedData);

    int isValid = decode(encodedData, generator);
    printf("Is received data valid? %s\n", isValid ? "Yes" : "No");

    encodedData[strlen(encodedData) - 1] = (encodedData[strlen(encodedData) - 1] == '0') ? '1' : '0';
    isValid = decode(encodedData, generator);
    printf("Is received data with error valid? %s\n", isValid ? "Yes" : "No");

    return 0;
}
