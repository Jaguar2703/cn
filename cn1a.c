#include<stdio.h>
#include<string.h>

#define FRAME_SIZE 1024
#define MAX_FRAMES 3

void sender(const char *data) {
int length = strlen(data);
printf("Sender: Sending frame with %d bytes: \"%s\"\n", length, data);
}

void receiver(const char *frame) {
printf("Receiver: Received frame: \"%s\"\n", frame);
}

int main() {
char frames[MAX_FRAMES][FRAME_SIZE];
int frameCount = 0;

printf("Enter up to %d frames (type 'exit' to finish):\n", MAX_FRAMES);

while (frameCount < MAX_FRAMES) {
printf("Frame %d: ", frameCount + 1);
fgets(frames[frameCount], FRAME_SIZE, stdin);
frames[frameCount][strcspn(frames[frameCount], "\n")] = 0;

if (strcmp(frames[frameCount], "exit") == 0) {
break;
}

sender(frames[frameCount]);
receiver(frames[frameCount]);

frameCount++;
}

printf("\nTotal frames processed: %d\n", frameCount);
return 0;
}
