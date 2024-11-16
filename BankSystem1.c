#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USERNAME "manga"
#define IDOFUSER "12456398715978"
#define PASSWORD "891635"
#define AMOUNT "2000"

void login(int attemps){
    char usernamegiven[50];
    char passwordgiven1[50];

    printf("%s", "\n Username: \t");
    scanf("%s", usernamegiven);
    printf("%s", "\n Password: \t");
    scanf("%s", passwordgiven1);
    if (strcmp(usernamegiven, USERNAME) == 0 && strcmp(passwordgiven1, PASSWORD) == 0){
        if(attemps == 0){
            printf("%s", "You have logged in successfully. Welcome back, \n");
        }
    }else if (strcmp(usernamegiven, USERNAME) != 0 || strcmp(passwordgiven1, PASSWORD) != 0){
        if(attemps > 0){
            attemps--;
            printf("The username or the password you have just entered is not correct. You still have %i attemps, try again. \n", attemps);
            login(attemps--);
        }else{
            printf("%s", "You have reach the maximum of your attempts, this app will shut down automatically.");
            return 0;
        }
    }
    system("cls");
}

void Deposit(){
    int randomNum = rand();
    printf("Take this number to the nearest NongaBank Agency where you can complete this operation: \t %i \n", randomNum);
    FILE *fptr;
    fptr = fopen("BS.txt", "a");
    fprintf(fptr, "Number: \t %i \n", randomNum);
    fclose(fptr);
    main();
}

void withdraw(){
    int amount2;
    int confirmWithdrawing;

    printf("%s", "Please input the amount that you want to take: \t");
    scanf("%i", &amount2);
    if(amount2 <= AMOUNT){
        printf("%s", "Are you sure about that?(Print 0 for yes, 1 for no, 2 for return to the main menu) \n");
        scanf("%i", &confirmWithdrawing);
        if(confirmWithdrawing == 0){
            printf("%s", "Operation done! \n");
            system("cls");
            main();
        }else{
            printf("%s", "Operation cancelled successfully... Returning to main menu");
            system("cls");
            main();
        }
    }else{
        printf("%s", "System error....");
        system("cls");
        main();
    }
}

void payement(){
    int id;
    int amount;
    int confirmSending;
    char passwordgiven2[50];

    printf("%s", "Please write the ID of the account: ");
    scanf("%i", &id);
    printf("%s", " \n Please input the amount that you want to sent it: ");
    scanf("%i", &amount);
    printf("Sending %i to this ID: %i. Is this correct?(Input 0 if yes, otherwise input 1) \n", amount, id);
    scanf("%i", &confirmSending);
    if(confirmSending == 0){
        printf("%s", "Pay attention! Your money perhaps will not be returned once you confirm it, are you sure about that? \n");
        scanf("%i", &confirmSending);
        if(confirmSending == 0){
            printf("%s", "Enter your password: \t");
            scanf("%s", passwordgiven2);
            if(strcmp(passwordgiven2, PASSWORD) == 0){
                printf("%s", "Money sent successfully. Operation done!");
                system("cls");
                main();
            }else{
                printf("%s", "Password not correct! \n Restarting the program... \n");
                system("cls");
                main();
            }
        }else if(confirmSending == 1){
            printf("%s", "Operation cancelled successfully.");
            system("cls");
            main();
        }else if(confirmSending != 0 && confirmSending != 1){
            printf("%s", "Error! Logging out from account...");
            system("cls");
            main();
        }
    }else if (confirmSending == 1){
        printf("%s", "Operation cancelled successfully.");
        system("cls");
        main();
    }else if(confirmSending != 0 && confirmSending != 1){
        printf("Error! Logging out from account...");
        system("cls");
        main();
    }

}

void checkAmount(){
    int returnToMenu;

    printf("%s", " \t NongaBank Company: \n");
    printf("Username: \t %s \n", USERNAME);
    printf("ID: \t %s \n", IDOFUSER);
    printf("Amount: \t %s MAD \n", AMOUNT);
    printf("%s", "If you want to return to the main menu press 0");
    scanf("%i", returnToMenu);
    if(returnToMenu == 0){
            system("cls");
        main();
    }
}

int main(){
    int attemps = 3;
    int index;

    printf("%s", "Welcome! Please enter the information below to access to your account.");
    login(3);
    printf("How can I help you in NongaBank? \n For deposit, choose 0. \n For withdraw, choose 1. \n For payement, choose 2. \n For checking the amount, choose 3. \n");
    scanf("%i", &index);
    switch(index){
    case 0:
        Deposit();
        break;
    case 1:
        withdraw();
        break;
    case 2:
        payement();
        break;
    case 3:
        checkAmount();
        break;
    }
}
