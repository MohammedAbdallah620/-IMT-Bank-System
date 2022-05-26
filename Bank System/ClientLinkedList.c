#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Client
{
    char fullName[100];
    char fullAddress[100];
    char NationalID[50];
    int age;
    long long bankAccountID;
    char guardianNationalID[50];
    char accountStatus[50];
    double balance;
    long long password;
}client;

long long id = 2000000000;
long long Pass = 3000000000;

typedef struct clientNode
{
    client data;
    struct clientNode *Next;
}clientNode;

typedef struct clientList
{
    int size;
    clientNode *Head;
}clientList;
clientList clients;

appendToClientsList(clientList *clientsPtr, client  new_client)
{
    clientNode* nodePtr = (clientNode *)malloc(sizeof(clientNode));
    nodePtr->data = new_client;
    int size = clientsPtr->size;
    if (size == 0){
        nodePtr->Next = clientsPtr->Head;
        clientsPtr->Head = nodePtr;
    }
    else{
        clientNode * tail = clientsPtr->Head;
        for(int i = 0; i < size-1; i++ ){
            tail = tail->Next;
        }
        nodePtr->Next = tail->Next;
        tail->Next = nodePtr;

    }
    clientsPtr->size+=1;
}

void fillClientList()
{
    client client1;
    strcpy(client1.fullName, "Mohamed Salah Hamed Mahrous");
    strcpy(client1.fullAddress, "6 Hussien Wassef, From El-Dokki st, Giza");
    strcpy(client1.NationalID, "29805070100179");
    client1.age = 24;
    client1.bankAccountID = id;
    id++;
    strcpy(client1.guardianNationalID, "-1");
    strcpy(client1.accountStatus, "Active");
    client1.balance = 750000;
    client1.password = Pass;
    Pass++;
    appendToClientsList(&clients,client1);


    strcpy(client1.fullName, "adel mostafa mahmoud nady");
    strcpy(client1.fullAddress, "6 Hussien Wassef, From El-Dokki st, Giza");
    strcpy(client1.NationalID, "29804070105174");
    client1.age = 24;
    client1.bankAccountID = id;
    id++;
    strcpy(client1.guardianNationalID, "-1");
    strcpy(client1.accountStatus, "Restricted");
    client1.balance = 800000;
    client1.password= Pass;
    Pass++;
    appendToClientsList(&clients,client1);


}
void createClientList()
{
    clients.size = 0;
    clients.Head = NULL;
    fillClientList();

}
void printClientsList()
{
    clientNode *ptr = clients.Head;
    while (ptr != NULL)
    {
        printf("%s\n",ptr->data.fullName);
        printf("%lld\n",ptr->data.bankAccountID);
        printf("%lld\n",ptr->data.password);
        ptr = ptr->Next;
    }
}


int validateClientAccount(long long accountId , long long pass , int isAdmin)
{
    int validate = 0;
    clientNode *ptr = clients.Head;
    while (ptr != NULL)
    {
        if (!isAdmin)
        {
            if(accountId ==  ptr->data.bankAccountID && pass == ptr->data.password)
            {
                validate = 1;
                break;
            }
        }
        else
        {
            if(accountId ==  ptr->data.bankAccountID)
            {
                validate = 1;
                break;
            }
        }
        ptr = ptr->Next;
    }
    return validate;
}
void loginClient()
{
    long long accountId , password;
    int validate = 0;
    do{
        printf("Enter your Bank Account Id: ");
        fflush(stdin);
        scanf("%lld" , &accountId);
        printf("Enter your password: ");
        scanf("%lld" , &password);
        validate = validateClientAccount(accountId , password , 0);
        if(!validate){
            printf("wrong accountId or password\n");
        }
    }while(!validate);

    printf("login successfully\n");
}




