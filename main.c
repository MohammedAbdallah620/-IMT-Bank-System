#include <stdio.h>
#include <stdlib.h>

#include "adminWindow.c"
int main()
{
    printf("Welcome to IMT Bank System\n");
    createAdminList();
    //PrintLinkedList()
    createClientList();
    //printClientsList();
    while(1)
    {

        printf("login as admin press 1 or as client press 2 : ");
        int option;
        scanf("%d" , &option);
        if (option == 1) // admin
        {
            loginAdmin();
            openAdminWindow();
        }
        else if(option ==2) // client
        {
            //printClientsList();
            loginClient();
        }
    }
    return 0;
}
