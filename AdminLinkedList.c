#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Admin
{
    char username[50];
    char password[50]
}admin;

typedef struct adminNode
{
    admin data;
    struct adminNode *Next;
}adminNode;

typedef struct adminList
{
    int size;
    adminNode *Head;
}adminsList;
adminsList admins;

appendToAdminsList(adminsList *adminsPtr, admin  new_admin)
{
    adminNode* nodePtr = (adminNode *)malloc(sizeof(adminNode));
    nodePtr->data = new_admin;
    int size = adminsPtr->size;
    if (size == 0){
        nodePtr->Next = adminsPtr->Head;
        adminsPtr->Head = nodePtr;
    }
    else{
        adminNode * tail = adminsPtr->Head;
        for(int i = 0; i < size-1; i++ ){
            tail = tail->Next;
        }
        nodePtr->Next = tail->Next;
        tail->Next = nodePtr;

    }
    adminsPtr->size+=1;
}
void fillAdminList()
{
    admin admin1;
    strcpy(admin1.username, "mohammed abdallah");
    strcpy(admin1.password, "1000000000");
    appendToAdminsList(&admins,admin1);

    strcpy(admin1.username, "ahmed mohamed");
    strcpy(admin1.password, "1000000001");
    appendToAdminsList(&admins,admin1);

    strcpy(admin1.username, "mohammed mohamed");
    strcpy(admin1.password, "1000000002");
    appendToAdminsList(&admins,admin1);

}
void createAdminList()
{
    admins.size = 0;
    admins.Head = NULL;
    fillAdminList();

}
void PrintLinkedList()
{
    adminNode *ptr = admins.Head;
    while (ptr != NULL)
    {
        printf("%s\n",ptr->data.username);
        ptr = ptr->Next;
    }
}
int validateAdminAccount(char *name , char* pass)
{
    int validate = 0;
    adminNode *ptr = admins.Head;
    while (ptr != NULL)
    {
        name[strlen(name)-1] = '\0';
        int cmpName = strcmp(name, ptr->data.username);
        int cmpPassword = strcmp(pass, ptr->data.password);
        //puts(name);
        //puts(ptr->data.username);
        //printf("%d %d %d" , cmpName , (int)strlen(name) , (int)strlen(ptr->data.username));
        //puts("");
        if(!cmpName && !cmpPassword)
        {
            validate = 1;
            break;
        }
        ptr = ptr->Next;
    }
    return validate;
}
void loginAdmin()
{
    char username[50] , password[50];
    int validate = 0;
    do{
        printf("Enter Username: ");
        //scanf("%s", username);
        fflush(stdin);
        fgets(username, 50, stdin);
        //fgets(username, 50, stdin);
        printf("Enter your password: ");
        gets(password);
        validate = validateAdminAccount(username , password);
        if(!validate){
            printf("wrong username or password\n");
        }
    }while(!validate);

    printf("login successfully\n");
}

