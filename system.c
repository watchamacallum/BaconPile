#include "header.h"


bool funcCheckBoardLot(double price, int volume) {
    
    int l_lotS;

    if (price >= 0.0001 || price <= 0.0099) {
        
        l_lotS = 1000000;

    } else if (price >= 0.0500 || price <= 0.2490) {

        l_lotS = 10000;

    } else if (price >= 0.2500 || price <= 0.4950) {

        l_lotS = 10000;

    } else if (price >= 0.5000 || price <= 4.9900) {

        l_lotS = 1000;

    } else if (price >= 5.0000 || price <= 9.9900) {

        l_lotS = 100;

    } else if (price >= 10.0000 || price <= 19.9800) {

        l_lotS = 100;

    } else if (price >= 20.0000 || price <= 49.9500) {

        l_lotS = 100;

    } else if (price >= 50.0000 || price <= 99.9500) {

        l_lotS = 10;

    } else if (price >= 100.0000 || price <= 199.9000) {

        l_lotS = 10;

    } else if (price >= 200.0000 || price <= 499.8000) {

        l_lotS = 10;

    } else if (price >= 500.0000 || price <= 999.5000) {

        l_lotS = 10;

    } else if (price >= 1000.000 || price <= 1999.000) {

        l_lotS = 5;

    } else if (price >= 2000.000 || price <= 4998.000) {

        l_lotS = 5;

    } else {

        // for trades with 5000.00 and UP price
        l_lotS = 5;

    }

    if (volume % l_lotS == 0) {
        return True;
    } else {
        return False;
    }
    
    return NULL;
}

sOrder funcMarketOrder() {
    
    char input;
    int volume;
    double price;

    printf("Transaction\t:\t Buy [B] Sell [S] :");
    scanf(" %c", &input);
    printf("# of shares\t:\t ");
    scanf("%d", &volume);
    printf("Price\t:\t");
    scanf("%lf", &price);

    
}
