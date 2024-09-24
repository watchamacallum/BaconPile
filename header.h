#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

#define True 1
#define False 0
#define bool char


typedef struct {
    bool transaction;
    int shares;
    double fprice;
    double ftotal;
} sData;

// new ###
typedef struct {
    bool transaction;
    double price;
    int volume;
} sOrder;

typedef struct {
    bool TRX;
    double PRC;
    int VOL;
} sAskBid;




sData func_enter_order();

#endif // HEADER_H