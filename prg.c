#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char str[]) {
    int strlength = strlen(str) - 1;

    /**
     * jelikoz je mozne ze se kazdy charakter muze opakovat jen jednou,
     * vysledna delka by mohla byt dvojnasobne vetsi + 1
     * takze nas buffer bude mit velikost strlength*2 + 1
     **/
    char buffer[65];

    //do teto promenne si ulozime pozici, na ktere jsme naposledy skoncili s sprintf
    int len = 0;

    for (int i = 0; i < strlength; i++) {
        //pocet kolikrat se charakter v nasem stringu objevil
        int count = 1;

        /**
        * pokud je i mensi nez delka naseho stringu - 1 (nullchar)
        * a dosavadni charakter je stejny, jako ten dalsi,
        * inkrementuj count a i
        **/
        while (i < strlength - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        /**
        * uloz do len pozici na ktere jsme naposledy skoncili at muzeme po
        * inkrementaci i dale pokracovat (sprintf vraci delku zapsaneho
        * textu, pokud nastane chyba, vrati negativni hodnotu)
        **/
        len += sprintf(buffer + len, "%i%c", count, str[i]);
    }

    printf("%s", buffer);
}

int main() {
    //vytvor char str o velikosti 32b
    char str[32];

    //napln str s daty pochazejic ze stdinput
    fgets(str, 32, stdin);

    //zavolej funkci compress s argumentem str
    compress(str);

    system("pause");
    return 0;
}
