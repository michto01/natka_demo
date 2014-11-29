#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define m 3;

const double CONVERSION_ERROR = -1.0;

const double EURO  = 25.0;
const double LIBRA = 34.0;

enum {
    _EURO,
    _LIBRA,
    KORUNA,
};

int getType(char* str)
{
    if (strcmp(str,"eur")) {
        return _EURO;
    }
    return -1;
}

double convert ( int amount, char valut )
{
    switch (valut) {
        case 'e':
        case 'E':
            return amount * EURO;
            
        case 'l':
        case 'L':
            return amount * LIBRA * m;
            
        default:
            return CONVERSION_ERROR;
    }
}

int main(int argc, const char * argv[]) {
    double amount;
    unsigned char value;
    
    printf("Give value and valut:\n");
    scanf("%lf %c", &amount, &value);
    getchar();
    
    assert(convert(amount, value) != CONVERSION_ERROR);
    printf("Valut has int value: %d \n", value);
    printf("Converted value is: %lf", convert( amount, value ));
    getchar();
    return EXIT_SUCCESS;
}
