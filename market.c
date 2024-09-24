#include "header.h"

void funcMarketEngine() {

    double cur_price, bidPrice;

    sBoardLot Boardlot[15];

    Boardlot[0].minRngPrc = 0.0001f;
    Boardlot[0].maxRngPrc = 0.0099f;
    Boardlot[0].lotSz = 1000000;
    Boardlot[0].fluctuation = 0.0001f;

    Boardlot[1].minRngPrc = 0.0100f;
    Boardlot[1].maxRngPrc = 0.0490f;
    Boardlot[1].lotSz = 100000;
    Boardlot[1].fluctuation = 0.001f;

    Boardlot[2].minRngPrc = 0.0500f;
    Boardlot[2].maxRngPrc = 0.2490f;
    Boardlot[2].lotSz = 10000;
    Boardlot[2].fluctuation = 0.001f;

    Boardlot[3].minRngPrc = 0.2500f;
    Boardlot[3].maxRngPrc = 0.4950f;
    Boardlot[3].lotSz = 10000;
    Boardlot[3].fluctuation = 0.005f;
    
    Boardlot[4].minRngPrc = 0.5000f;
    Boardlot[4].maxRngPrc = 4.9900f;
    Boardlot[4].lotSz = 1000;
    Boardlot[4].fluctuation = 0.01f;

    Boardlot[5].minRngPrc = 5.0000f;
    Boardlot[5].maxRngPrc = 9.9900f;
    Boardlot[5].lotSz = 100;
    Boardlot[5].fluctuation = 0.01f;

    Boardlot[6].minRngPrc = 10.0000f;
    Boardlot[6].maxRngPrc = 19.9800f;
    Boardlot[6].lotSz = 100;
    Boardlot[6].fluctuation = 0.02f;

    Boardlot[7].minRngPrc = 20.0000f;
    Boardlot[7].maxRngPrc = 49.9500f;
    Boardlot[7].lotSz = 100;
    Boardlot[7].fluctuation = 0.05f;

    Boardlot[8].minRngPrc = 50.0000f;
    Boardlot[8].maxRngPrc = 99.9500f;
    Boardlot[8].lotSz = 10;
    Boardlot[8].fluctuation = 0.05f;

    Boardlot[9].minRngPrc = 100.0000f;
    Boardlot[9].maxRngPrc = 199.9000f;
    Boardlot[9].lotSz = 10;
    Boardlot[9].fluctuation = 0.1f;

    Boardlot[10].minRngPrc = 200.0000f;
    Boardlot[10].maxRngPrc = 499.8000f;
    Boardlot[10].lotSz = 10;
    Boardlot[10].fluctuation = 0.2f;
    
    Boardlot[11].minRngPrc = 500.0000f;
    Boardlot[11].maxRngPrc = 999.5000f;
    Boardlot[11].lotSz = 10;
    Boardlot[11].fluctuation = 0.5f;

    Boardlot[12].minRngPrc = 1000.000f;
    Boardlot[12].maxRngPrc = 1999.000f;
    Boardlot[12].lotSz = 5;
    Boardlot[12].fluctuation = 1.00f;

    Boardlot[13].minRngPrc = 2000.000f;
    Boardlot[13].maxRngPrc = 4998.000f;
    Boardlot[13].lotSz = 5;
    Boardlot[13].fluctuation = 2.00f;

    Boardlot[14].minRngPrc = 5000.000f;
    Boardlot[14].maxRngPrc = 999999999.00f;
    Boardlot[14].lotSz = 5;
    Boardlot[14].fluctuation = 5.00f;

    int k;

    for (int i = 0; i != 20; i++) {
        printf("Enter price: ");
        scanf("%lf", &bidPrice);

        if (bidPrice < 1.3 * cur_price || bidPrice > 0.5 * cur_price) {

            cur_price = bidPrice;
            printf("Current Price: %.2lf \n", cur_price);
        } 

        // boardlot tester
        for (k = 0; k <= 14; k++) {


            if (bidPrice >= Boardlot[k].minRngPrc && bidPrice <= Boardlot[k].maxRngPrc) {
                
                break;

            } 
        }

        printf("Boardlot: %d\n", Boardlot[k].lotSz);
    }
    
}

void funcAskBidEngine() {

    int szr = 0, sza = 0,  szb = 0, trx;
    double bid;

    sAskBid rawAskBids[1000];
    sAskBid askOrders[100];
    sAskBid bidOrders[100];

    for (int w = 0; w < 3; w++) {
        printf("Enter order price: ");
        scanf("%lf", &rawAskBids[w].PRC);
        printf("Enter volume: ");
        scanf("%d", &rawAskBids[w].VOL);
        rawAskBids[szr].TRX = True;
        // rawAskBids[szr].VOL = 10000;
        szr++;
    }

    for (int u = 0; u < szr; u++) {
        
        if (rawAskBids[u].TRX) {
            askOrders[sza].PRC = rawAskBids[u].PRC;
            askOrders[sza].VOL = rawAskBids[u].VOL;
            sza++;
        } else {
            bidOrders[szb] = rawAskBids[u];
            szb++;
        }
    }

    printf("Ask\t\t\tBids\n");
    
    for (int q = 0; q < sza || q < szb; q++) {

        printf("Price: %.4lf  Volume: %d\n", askOrders[q].PRC, askOrders[q].VOL);
    }
    
}