#include<stdio.h>
#include<string.h>

void receiver();
char frames[1024];

int main()
{
    int n, len, i;
    char buffer[256], length[10];
    printf("How many frames you want to send: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the frame: ");
        scanf("%s", buffer);
        len = strlen(buffer);
        sprintf(length, "%d", len);
        strcat(frames, length);
        strcat(frames, buffer);
    }
    printf("Frames sent: %s\n", frames);
    receiver();
    return 0;
}

void receiver()
{
    int i = 0, framelen, lpvar;
    printf("\n\nThis is the receiver\n");
    printf("\nData received is: %s\n", frames);
    while (frames[i] != '\0')
    {
        framelen = frames[i] - '0';
        i++;
        printf("\nLength of this frame is: %d\n", framelen);
        printf("Frame----->");
        lpvar = i + framelen;
        while (i < lpvar)
        {
            printf("%c", frames[i++]);
        }
        printf("\n");
    }
}
