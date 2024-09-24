#include "header.h"

sData func_enter_order() {
    
    sData l_dataInfo;

    char l_inpt, *l_mode;

    
    int l_shares;

    double l_price;

    printf("Enter Transaction mode [Y] buy  [n] sell\nTransaction\t:\t ");
    scanf(" %c", &l_inpt);
    printf("Stock Quote\t:\tXYZ Corp.\n");
    printf("# of Shares\t:\t ");
    scanf("%d", &l_shares);
    printf("Price\t\t:\t ");
    scanf("%lf", &l_price);

    l_dataInfo.transaction = True;
    l_dataInfo.shares = l_shares;
    l_dataInfo.fprice = l_price;
    l_dataInfo.ftotal = l_price * l_shares;

    // printf("%.2lf\n", l_price);

    printf("\n\tOrder Preview\t\n");
    printf("Transaction %s\n", l_dataInfo.transaction == True ? "[/] Buy [ ] Sell" : "[ ] Buy [/] Sell");
    printf("Stock Quote\t: XYZ Corp.\n");
    printf("# of Shares\t: %d\n", l_dataInfo.shares);
    printf("Price\t\t: %.2lf\n", l_dataInfo.fprice);
    printf("Total Preview\t: %lf\n", l_dataInfo.ftotal);






    return l_dataInfo;
}