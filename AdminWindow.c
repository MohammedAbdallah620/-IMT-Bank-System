#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdminLinkedList.c"
#include "ClientLinkedList.c"

void createNewAccount()
{
    char fullName[100], fullAddress[100], NationalID[50], guardianNationalID[50], accountStatus[50];
    int age;
    long long bankAccountID , password;
    double balance;

    fflush(stdin);

    printf("Enter your full name (at least 4 names): ");
    fgets(fullName, 100, stdin);
    fullName[strlen(fullName)-1] = '\0';

    printf("Enter your Full address : ");
    fgets(fullAddress, 100, stdin);
    fullAddress[strlen(fullAddress)-1] = '\0';

    printf("Enter your National ID : ");
    fgets(NationalID, 100, stdin);
    NationalID[strlen(NationalID)-1] = '\0';

    printf("Enter your age : ");
    scanf("%f" , &age);

    bankAccountID = id ;
    id++;
    if(age < 21)
    {
        printf("Enter your guardian National ID : ");
        fgets(guardianNationalID, 100, stdin);
        guardianNationalID[strlen(guardianNationalID)-1] = '\0';
    }
    else
    {
        strcpy(guardianNationalID, "-1");
    }
    strcpy(accountStatus, "Active");

    printf("Enter your Balance : ");
    scanf("%lf" , &balance);

    password = Pass;
    Pass++;



    client client1;

    strcpy(client1.fullName, fullName);
    strcpy(client1.fullAddress, fullAddress);
    strcpy(client1.NationalID, NationalID);
    client1.age = age;
    client1.bankAccountID = bankAccountID;
    strcpy(client1.guardianNationalID, guardianNationalID);
    strcpy(client1.accountStatus, accountStatus);
    client1.balance = balance;
    client1.password=password;

    appendToClientsList(&clients,client1);
}
int validAccount(long long accountID , double transactionMoney , int transfer)
{
    int valid = 0;
    clientNode *ptr = clients.Head;
    while (ptr != NULL)
    {
        if(!transfer)
        {
            int status = strcmp(ptr->data.accountStatus, "Active");
            if(accountId == ptr->data.bankAccountID && transactionMoney <= ptr->data.balance && !status)
            {
                validate = 1;
                break;
            }
        }
        else
        {
            int status = strcmp(ptr->data.accountStatus, "Active");
            if(accountId == ptr->data.bankAccountID && !status)
            {
                validate = 1;
                break;
            }
        }
        ptr = ptr->Next;
    }
    return valid;
}
int getCash(long long accountID , double transactionMoney)
{
    int valid =0
    clientNode *ptr = clients.Head;
    while (ptr != NULL)
    {
        int status = strcmp(ptr->data.accountStatus, "Active");
        if(accountId == ptr->data.bankAccountID && transactionMoney <= ptr->data.balance && !status)
        {
            ptr->data.balance -= transactionMoney;
            validate = 1;
            break;
        }
        ptr = ptr->Next;
    }
    return valid;
}
int deposit(long long accountID , double transactionMoney)
{
    int valid =0
    clientNode *ptr = clients.Head;
    while (ptr != NULL)
    {
        int status = strcmp(ptr->data.accountStatus, "Active");
        if(accountId == ptr->data.bankAccountID && !status)
        {
            ptr->data.balance += transactionMoney;
            validate = 1;
            break;
        }
        ptr = ptr->Next;
    }
    return valid;
}
int makeTransaction(long long accountID)
{
    puts("Enter Account ID: ");
    long long accountID_Transaction;
    scanf("%lld" , accountID_Transaction);

    puts("Enter amount of money to transfer :");
    double transactionMoney;
    scanf("%lf" , transactionMoney);
    int accountOneValidation = validAccount(accountID , transactionMoney , 0);
    int accountTwoValidation = validAccount(accountID_Transaction , transactionMoney , 1);
    if(accountOneValidation&&accountTwoValidation)
    {
        getCash(accountID , transactionMoney);
        deposit(accountID_Transaction , transactionMoney);
        puts("succeeded to transfer money \n");
    }
    else
    {
        puts("Failed to Make Transaction \n");
    }

}
void changeStatus(long long accountID)
{
    puts("for Active state press 1 \n");
    puts("for Restricted state press 2 \n");
    puts("for Closed state press 2 \n");
    puts("Enter your option : \n");

    int option;
    scanf("%d" , option);

    char op[20];
    if(option==1)strcpy(op , "Active");
    else if (option==2)strcpy(op , "Restricted");
    else strcpy(op , "Closed");

    clientNode *ptr = clients.Head;
    while (ptr != NULL)
    {
        if(accountId == ptr->data.bankAccountID)
        {
            strcpy(ptr->data.accountStatus, op);
            break;
        }
        ptr = ptr->Next;
    }
    puts("Status Has been changed successfully\n");
}
void openExistingAccount()
{
    while(1)
    {
        puts("Enter Account ID: ");
        long long accountID;
        scanf("%lld" , accountID);
        int validateAccount = validateClientAccount(accountID , -1 , 1);
        if(validateAccount == 0 )
            puts("Wrong account Id");
        else
        {
            printf("Make Transaction press 1 \n");
            printf("change account ststus press 2 \n");
            printf("get cash press 3 \n");
            printf("Deposite in account press 4 \n");
            printf("return to main menu press 5 \n");
            int option;
            printf("Enter your option : ");
            scanf("%d" , &option);
            if (option ==1)
            {
                makeTransaction(accountID);
            }
            else if (option ==2)
            {
                changeStatus(accountID);
            }
            else if (option ==3)
            {
                puts("Enter amount of money :");
                double money;
                scanf("%lf" , money);
                int success = getCash(accountID ,money);
                if (success)
                {
                    puts("get cash completed successfully\n");
                }
                else
                {
                     puts("failed to get cash\n");
                }
            }
            else if (option ==4)
            {
                puts("Enter amount of money to deposit :");
                double money;
                scanf("%lf" , money)
                int success = deposit(accountID , transactionMoney);
                if (success)
                {
                    puts("deposit completed successfully\n");
                }
                else
                {
                     puts("failed to deposit\n");
                }
            }
            else{

            }
            break;
        }
    }

}
void openAdminWindow()
{
    while(1)
    {
        fflush(stdin);
        puts("to create new account press 1");
        puts("to open existing account press 2");
        puts("to exit system press 3");
        char option[5];
        scanf("%s" , option);
        if(!strcmp(option, "1"))
        {
            createNewAccount();
            //validate
            //printClientsList();
        }
        else if (!strcmp(option, "2"))
        {
            openExistingAccount();
        }
        else if (!strcmp(option, "3"))
        {
            break;
        }
        else{
            puts("invalid option please press 1, 2 or 3");
        }
    }
}
