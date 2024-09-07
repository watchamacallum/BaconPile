#include "header.h"
 
int func_calculate_boardL(double l_price, int l_lotC) {

    int l_boardL, l_lotS;

    if (l_price >= 0.0001 || l_price <= 0.0099) {

        l_lotS = 1000000;

    } else if (l_price >= 0.0500 || l_price <= 0.2490) {

        l_lotS = 10000;

    } else if (l_price >= 0.2500 || l_price <= 0.4950) {

        l_lotS = 10000;

    } else if (l_price >= 0.5000 || l_price <= 4.9900) {

        l_lotS = 1000;

    } else if (l_price >= 5.0000 || l_price <= 9.9900) {

        l_lotS = 100;

    } else if (l_price >= 10.0000 || l_price <= 19.9800) {

        l_lotS = 100;

    } else if (l_price >= 20.0000 || l_price <= 49.9500) {

        l_lotS = 100;

    } else if (l_price >= 50.0000 || l_price <= 99.9500) {

        l_lotS = 10;

    } else if (l_price >= 100.0000 || l_price <= 199.9000) {

        l_lotS = 10;

    } else if (l_price >= 200.0000 || l_price <= 499.8000) {

        l_lotS = 10;

    } else if (l_price >= 500.0000 || l_price <= 999.5000) {

        l_lotS = 10;

    } else if (l_price >= 1000.000 || l_price <= 1999.000) {

        l_lotS = 5;

    } else if (l_price >= 2000.000 || l_price <= 4998.000) {

        l_lotS = 5;

    } else {

        // for trades with 5000.00 and UP price
        l_lotS = 5;

    }

    l_boardL = l_lotC / l_lotS;

    return l_boardL;
}