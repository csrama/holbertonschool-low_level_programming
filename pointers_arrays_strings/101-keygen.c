#include <stdio.h>
#include <main.h>

int main() {
     int i;
char password[9];
char letters [] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

        srand(time(null));

for (i = 0; i < 8; i++) {
        password [i] = letters [rand() % 62];
}
 password[8] = '\0';

 printf("Password: %s\n", password);

    return 0;
