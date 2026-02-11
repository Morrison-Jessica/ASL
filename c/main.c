#include <stdio.h>
#include <time.h>

int main(void) {
    printf("Hello from C\n");

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", t);
    printf("%s\n", buf);

    return 0;
}
