//
// Created by Robson Tavares Júnior on 01/11/18.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef EXERCICIO6B_39917_EXERCICIO6B_H
#define EXERCICIO6B_39917_EXERCICIO6B_H

int v1(){

    float totalBonus, biggestBonus, lowestBonus, bonus, amount, workedHours, dayOff;
    float counter = 1, counter1, counter2, counter3, counter4, counter5;
    char name[900];

    printf("If you want to stop the program, please input as the employee's name the word end\n\n");

    printf("Name of the employee: ");
    scanf("%s", &name);

    while(strcmp(name, "end") != 0){
        if(counter == 1){
            printf("Please input the extra worked hours: ");
            scanf("%f", &workedHours);

            printf("Please input the day offs: ");
            scanf("%f", &dayOff);

        }else{

            printf("Name of the employee: ");
            scanf("%s", &name);

            if(strcmp(name, "end") == 0){

                break;

            }else{

                printf("Please input the extra worked hours: ");
                scanf("%f", &workedHours);

                printf("Please input the day offs: ");
                scanf("%f", &dayOff);
            }
        }

        amount = workedHours - ((2/3)*dayOff);

        if(amount > 40){

            bonus = 50;
            counter1 += 1;

        }else if (amount >30 && amount <= 40){

            bonus = 25;
            counter2 += 1;

        }else if(amount > 20 && amount <=30){

            bonus = 12;
            counter3 += 1;

        }else if(amount > 10 && amount <=20){

            bonus = 7.5;
            counter4 += 1;

        }else{

            bonus = 5;
            counter5 += 1;
        }

        //Assigning biggest and lowest bonuses
        if(counter == 1){

            biggestBonus= bonus;
            lowestBonus = bonus;

        }else{

            if(bonus > biggestBonus){
                biggestBonus = bonus;
            }else if(bonus < lowestBonus){
                lowestBonus = bonus;
            }

        }

        printf("%s worked %.2f hours and missed %.0f days of work, thus the bonus is %.2f\n", name, workedHours, dayOff, bonus);

        // keeping count of the total bonus
        totalBonus += bonus;
        counter += 1;

    }

    printf("Biggest Bonus is: %.2f\n", biggestBonus);
    printf("Lowest Bonus is: %.2f\n", lowestBonus);
    if(counter > 1){
        printf("Average Bonus is: %.2f\n", totalBonus/(counter-1));
    }else{
        printf("Average Bonus is: %.2f\n", totalBonus/(counter));
    }

    printf("There are %.2f %c people earning 50 euros bonus\n", (counter1/(counter-1))*100, 37);
    printf("There are %.2f %c people earning 25 euros bonus\n", (counter2/(counter-1))*100, 37);
    printf("There are %.2f %c people earning 12 euros bonus\n", (counter3/(counter-1))*100, 37);
    printf("There are %.2f %c people earning 7.5 euros bonus\n", (counter4/(counter-1))*100, 37);
    printf("There are %.2f %c people earning 5 euros bonus\n", (counter5/(counter-1))*100, 37);

    return 0;

}

int v2(){

    float revenue, totalRevenue, numberOfPeople, numberOfChildren;
    float referenceRevenue;
    float tierAmount[] = {2496.20, 4992.40, 7488.6, 12481.0, 24962.01};
    int tierClass[] = {1, 2, 3, 4, 5, 6}, eachTier;
    int eachMember, revenueTier;

    printf("If you want to stop the program, please input a negative number of people\n\n");
    numberOfPeople = 1;

    while(numberOfPeople >= 0){

        //gathering the number of people in the family
        printf("Number of people in the family: ");
        scanf("%f", &numberOfPeople);

        if(numberOfPeople <0){break;}

        //gathering the number of children in the family
        printf("Number of children in the family: ");
        scanf("%f", &numberOfChildren);

        for(eachMember=0; eachMember<(numberOfPeople-numberOfChildren); eachMember++){

            printf("Gross Revenue of the person #%d: ", eachMember+1);
            scanf("%f", &revenue);

            //acumulating the revenue
            totalRevenue += revenue;

        }

        //Calculating the reference revenue
        referenceRevenue = totalRevenue/(numberOfChildren + 1);

        //Classifying by tier
        for(eachTier=0; eachTier<5; eachTier++){

            if(eachTier == 0 || eachTier == 4){

                if(eachTier == 0 && referenceRevenue < tierAmount[eachTier]){

                    revenueTier = tierClass[eachTier];

                }else if(eachTier == 4 && referenceRevenue > tierAmount[eachTier]){

                    revenueTier = tierClass[eachTier + 1];

                }

            }else{

                if(totalRevenue >= tierAmount[eachTier - 1] && totalRevenue < tierAmount[eachTier]){

                    revenueTier = tierClass[eachTier];

                }
            }
        }

        printf("This family has %.0f members and, out of them, %.0f are childrens. Possessing a reference revenue of %.2f belonging to the tier # %d\n", numberOfPeople, numberOfChildren, referenceRevenue, revenueTier);
        totalRevenue = 0;

    }

    return 0;
}

int v3(){

    int number, i;
    double factorial;

    number = 1;
    printf("to break the program, enter a negative number\n");

    while(number>=0){

        printf("Please input your number: ");
        scanf("%d", &number);

        if(number<0){break;}

        factorial = 1;

        for(i=1; i<=number; i++){

            factorial *=i;

        }

        printf("%d factorial is %.0f\n", number, factorial);
    }

}

struct infoTable{

    char  buyerName[900];
    int   product;
    float quantity;
    float volume;
    float discount;
    float paidValue;

};

#define maxItems 900

int v4() {

    struct infoTable salesTable[maxItems];
    char buyerName[900];
    float volume, quantity, discount, paidValue, totalSales, totalDiscount, totalPaidValue;
    float totalCatSales[4] = {0, 0, 0, 0};
    float totalCatPaidValue[4] = {0, 0, 0, 0};
    int product, i, j, k, l;
    int categories[4] = {0, 1, 2, 3};
    int discountVolume[4] = {2500, 5000, 3000, 25000};
    float discountedValue[4] = {0.1, 0.25, 0.10, 0.25};

    printf("To exit the program enter the word end at the buyers name field: \n\n");

    for (i = 0; i <= maxItems; i++) {

        printf("Enter the buyer's name\n");
        scanf("%s", buyerName);

        //if-statement to break the program
        if (strcmp(buyerName, "end") == 0) {
            break;
        }else {

        printf("Enter the number equivalent to for product\n 0. Food \n 1. Apparel\n 2. Books\n 3. Furniture\n");
        scanf("%d", &product);

        printf("Enter the quantity\n");
        scanf("%f", &quantity);

        printf("Enter the volume\n");
        scanf("%f", &volume);

        for(j=0; j<4; j++){

            if(categories[j] == j && discountVolume[j] > quantity){
                paidValue = discountedValue[j] * volume;

                if(quantity > 10) {
                    paidValue *= 0.95;
                }
                if(quantity > 20){
                    paidValue *= 0.9;
                }
            }
        }

        strcpy(salesTable[i].buyerName, buyerName);
        salesTable[i].product = product;
        salesTable[i].quantity = quantity;
        salesTable[i].volume = volume;
        salesTable[i].discount = discount;
        salesTable[i].paidValue = paidValue;

        }
    }

    //Calculating sales and paid value per product
    for(k=0; k<=maxItems; k++){

        if(salesTable[k].quantity > 100 && salesTable[k].quantity <= 200){

            totalCatPaidValue[l] += salesTable[k].paidValue * 0.95;

        }else if(salesTable[k].quantity > 200){

            totalCatPaidValue[l] += salesTable[k].paidValue * 0.9;

        }

        totalCatSales[l] += salesTable[k].volume;
        totalCatPaidValue[l] += salesTable[k].paidValue;
    }


    //printing the requested output
    printf("Gross sales of food is: %2.f \nNet sales is: %.2f \nTotal discount is: %.2f", totalCatSales[0], totalCatPaidValue[0], totalCatSales[0] - totalCatPaidValue[0]);
    printf("Gross sales of apparel is: %2.f \nNet sales is: %.2f \nTotal discount is: %.2f", totalCatSales[1], totalCatPaidValue[1], totalCatSales[1] - totalCatPaidValue[1]);
    printf("Gross sales of books: %2.f \nNet sales is: %.2f \nTotal discount is: %.2f", totalCatSales[2], totalCatPaidValue[2], totalCatSales[2] - totalCatPaidValue[2]);
    printf("Gross sales of furniture: %2.f \nNet sales is: %.2f \nTotal discount is: %.2f\n", totalCatSales[3], totalCatPaidValue[3], totalCatSales[3] - totalCatPaidValue[3]);

    return 0;

}



#endif //EXERCICIO6B_39917_EXERCICIO6B_H
