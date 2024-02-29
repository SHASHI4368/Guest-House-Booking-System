#include "Nodes.h"
#include <stdlib.h>
#include "Data.h"


int main() {
    Customer_List l_customer;
    Owner_List l_owner;
    GuestHouse_List l_guestHouse;
    Room_List l_rooms;
    CustomerTable customers;
    addData(&l_customer, &l_owner, &l_guestHouse, &l_rooms, &customers);
    system("CLS");
    Customer_Node* tempC;
    Owner_Node* tempO;
    while (true) {
        switch (startUpscreen()) {
        case 1:
            system("cls");
            switch (customerScreen()) {
            case 1:
                tempC = customerLogInScreen(&l_customer);
                if (tempC==NULL)
                    break;
                else {
                    customerWindow(tempC, &l_guestHouse, &l_rooms,&l_customer);
                    break;
                }
            case 2:
                customerSignInScreen(&l_customer, &customers);
                break;
            case 3:
                continue;
            }
            break;
        case 2:
            system("cls");
            switch (ownerScreen()) {
            case 1:
                tempO = ownerLogInScreen(&l_customer, &l_owner, &l_guestHouse, &l_rooms);
                if (tempO == NULL)
                    break;
                else {
                    ownerWindow(tempO, &l_owner, &l_guestHouse, &l_rooms, &l_customer, &customers);
                    break;
                }
                ;
                break;
            case 2:
                ownerSignInScreen(&l_customer, &l_owner, &l_guestHouse, &l_rooms);
                break;
            case 3:
                continue;
            }
        }
    }
}

