#pragma once
#include "Nodes.h"
#include <string>

int startUpscreen() {
    int user_type;
    system("cls");
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(         ___             _   _  _                    __  __                                       _     ___         _             
        / __|_  _ ___ __| |_| || |___ _  _ ___ ___  |  \/  |__ _ _ _  __ _ __ _ ___ _ __  ___ _ _| |_  / __|_  _ __| |_ ___ _ __  
       | (_ | || / -_|_-<  _| __ / _ \ || (_-</ -_) | |\/| / _` | ' \/ _` / _` / -_) '  \/ -_) ' \  _| \__ \ || (_-<  _/ -_) '  \ 
        \___|\_,_\___/__/\__|_||_\___/\_,_/__/\___| |_|  |_\__,_|_||_\__,_\__, \___|_|_|_\___|_||_\__| |___/\_, /__/\__\___|_|_|_|
                                                                          |___/                             |__/                  )";
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;
    short rowPos = 10;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (1) for customers" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (2) for owners" << endl;
    cout << endl;
    rowPos = 15;
    string input;
    while (true) {
        while (true) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Select the user type : ";
            cin >> input;
            try {
                user_type = stoi(input);
                break;
            }
            catch (invalid_argument&) {
                SetConsoleCursorPosition(hConsole, { 60,rowPos++});
                cout << "Enter a valid number" << endl;
            }
        }
        
        switch (user_type) {
        case 1:
            system("CLS");
            return 1;
        case 2:
            system("CLS");
            return 2;
        default:
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Invalid number" << endl;
            continue;
        }
        break;
    }

}

int customerScreen() {
    int customer_option;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(         ___             _   _  _                    __  __                                       _     ___         _             
        / __|_  _ ___ __| |_| || |___ _  _ ___ ___  |  \/  |__ _ _ _  __ _ __ _ ___ _ __  ___ _ _| |_  / __|_  _ __| |_ ___ _ __  
       | (_ | || / -_|_-<  _| __ / _ \ || (_-</ -_) | |\/| / _` | ' \/ _` / _` / -_) '  \/ -_) ' \  _| \__ \ || (_-<  _/ -_) '  \ 
        \___|\_,_\___/__/\__|_||_\___/\_,_/__/\___| |_|  |_\__,_|_||_\__,_\__, \___|_|_|_\___|_||_\__| |___/\_, /__/\__\___|_|_|_|
                                                                          |___/                             |__/                  )";
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;
    short rowPos = 10;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (1) to Log In" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (2) for Sign Up" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (3) to go back" << endl;
    cout << endl;
    rowPos = 15;
    string input;
    while (true) {
        while (true) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Enter your option : ";
            cin >> input;
            try {
                customer_option = stoi(input);
                break;
            }
            catch (invalid_argument&) {
                SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
                cout << "Enter a valid number" << endl;
            }
        }
        switch (customer_option) {
        case 1:
            system("CLS");
            return 1;
        case 2:
            system("CLS");
            return 2;
        case 3:
            system("CLS");
            return 3;
        default:
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Invalid number" << endl;
            continue;
        }
        break;
    }
}

Customer_Node* customerLogInScreen(Customer_List* cl) {
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(                                     ___           _                            ___                          
                                    / __|_  _  ___| |_  ___  _ __   ___  _ _   / __| __  _ _  ___  ___  _ _  
                                   | (__| || |(_-<|  _|/ _ \| '  \ / -_)| '_|  \__ \/ _|| '_|/ -_)/ -_)| ' \ 
                                    \___|\_,_|/__/ \__|\___/|_|_|_|\___||_|    |___/\__||_|  \___|\___||_||_|)" << endl;
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;
    short rowPos = 8;
    SetConsoleCursorPosition(hConsole, { 40,rowPos++ });
    cout << "(Please enter your telephone number and the password to log in)" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (0) to go back" << endl;
    string tel, pw;
    cout << endl;
    rowPos = 11;
    while (true) {
        SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
        cout << "Telephone Number : ";
        cin >> tel;
        if (cl->searchCustomer(tel)) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "customer found" << endl;
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            break;
        }
        else if (tel == "0") {
            return NULL;
        }
        else {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "customer not found" << endl;
        } 
    }
    while (true) {
        SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
        cout << "Password : ";
        cin >> pw;
        if (cl->validateCustomer(tel,pw)) {
            rowPos += 2;
            SetConsoleCursorPosition(hConsole, { 65,rowPos++ });
            cout << "Done" << endl;
            rowPos += 2;
            SetConsoleCursorPosition(hConsole, { 52,rowPos++ });
            system("pause");
            return cl->getCustomer(tel);
        }
        else if (pw == "0") {
            return NULL;
        }
        else {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Password is incorrect" << endl;
        }
    }


}

void customerSignInScreen(Customer_List* cl, CustomerTable* t) {
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(                                                          ___  _                 ___           
                                                         / __|(_) __ _  _ _     |_ _| _ _  
                                                         \__ \| |/ _` || ' \     | | | ' \ 
                                                         |___/|_|\__, ||_||_|   |___||_||_|
                                                                 |___/                      )" << endl;
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    short rowPos = 8;
    cl->insert_new_customer(t, &rowPos);
    rowPos += 2;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Customer Added" << endl;
    rowPos += 2;
    SetConsoleCursorPosition(hConsole, { 52,rowPos++ });
    system("pause");

}

void bookRoomsWindow(Customer_Node* c, GuestHouse_List* gl, Room_List* lr, Customer_List* cl);
void showBookedRoomsWindow(Customer_Node* c, GuestHouse_List* gl, Room_List* lr,Customer_List* cl);

void customerWindow(Customer_Node* c, GuestHouse_List* gl, Room_List* lr, Customer_List* cl) {
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                     ___           _                            ___                          
                                    / __|_  _  ___| |_  ___  _ __   ___  _ _   / __| __  _ _  ___  ___  _ _  
                                   | (__| || |(_-<|  _|/ _ \| '  \ / -_)| '_|  \__ \/ _|| '_|/ -_)/ -_)| ' \ 
                                    \___|\_,_|/__/ \__|\___/|_|_|_|\___||_|    |___/\__||_|  \___|\___||_||_|)" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        short colPos = 5;
        short rowPos = 8;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "                CUSTOMER INFORMATION                  " << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        rowPos ++;
        c->print_customer(colPos, rowPos);
        cout << endl;
        SetConsoleCursorPosition(hConsole, { 3,20 });
        cout << "------------------------------------------------------" << endl;
        rowPos = 8;
        for (short i = 0; i < 15; i++) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "|" << endl;
        }
        rowPos = 10;
        colPos = 80;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (1) to see the booked rooms" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (2) to book a room" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (0) to log out" << endl;
        int key;
        string input;
        while (true) {
            rowPos += 2;
            while (true) {
                SetConsoleCursorPosition(hConsole, { 85,rowPos++ });
                cout << "Option : ";
                cin >> input;
                try {
                    key = stoi(input);
                    break;
                }
                catch (invalid_argument&) {
                    SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
                    cout << "Enter a valid number" << endl;
                }
            }
            switch (key) {
            case 1:
                showBookedRoomsWindow(c, gl, lr,cl);
                break;
            case 2:
                bookRoomsWindow(c, gl, lr,cl);
                break;
            case 0:
                return;
            }
            break;
        }
        //system("pause");
    } 
}

void showBookedRoomsWindow(Customer_Node* c, GuestHouse_List* gl, Room_List* lr, Customer_List* cl) {
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                     ___            _    _                 ___         __      
                                    | _ ) ___  ___ | |__(_) _ _   __ _    |_ _| _ _   / _| ___ 
                                    | _ \/ _ \/ _ \| / /| || ' \ / _` |    | | | ' \ |  _|/ _ \
                                    |___/\___/\___/|_\_\|_||_||_|\__, |   |___||_||_||_|  \___/
                                                                 |___/                         )" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||5|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        SetConsoleCursorPosition(hConsole, { 5,7 });
        lr->print_booked_rooms(*c);
        cout << endl;
        short rowPos = 20;
        short tempRowPos = rowPos-1;
        SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
        cout << "Press (1) to unbook rooms" << endl;
        SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
        cout << "Type 'exit' to exit" << endl;
        string c, rN, gH;
        int eN;
        rowPos += 2;
        while (true) {
            SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
            cout << "Choice - > ";
            cin >> c;
            if (c == "exit")
                return;
            else if (c == "1") {
                short j = tempRowPos-1;
                for (int i = 0; i < 10; i++) {
                    SetConsoleCursorPosition(hConsole, { 50,j++ });
                    cout << "|";
                }
                SetConsoleCursorPosition(hConsole, { 60,tempRowPos++ });
                cout << "------------------------------------------------------------------" << endl;
                SetConsoleCursorPosition(hConsole, { 60,tempRowPos++ });
                cout << "                          Unbooking Room" << endl;
                SetConsoleCursorPosition(hConsole, { 60,tempRowPos++ });
                cout << "------------------------------------------------------------------" << endl;
                while (true) {
                    SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                    cout << "Guest House : ";
                    cin >> gH;
                    if (gl->isGuestHouseExist(gH))
                        break;
                    else if (gH == "exit")
                        return;
                    else {
                        SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                        cout << "Guest house does not exist" << endl;
                    }

                }while (true) {
                    SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                    cout << "Room Number : ";
                    cin >> rN;
                    if (lr->isRoomExists(rN,gH))
                        break;
                    else if (rN == "exit")
                        return;
                    else {
                        SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                        cout << "Room does not exist" << endl;
                        SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                        cout << "Type 'exit' if want to exit" << endl;
                    }
                }
                Room* r = lr->getRoom(rN, gH);
                string input;
                while (true) {
                    while (true) {
                        SetConsoleCursorPosition(hConsole, { 69,tempRowPos++ });
                        cout << "Entry Number : ";
                        cin >> input;
                        try {
                            eN = stoi(input);
                            break;
                        }
                        catch (invalid_argument&) {
                            SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                            cout << "Enter a valid entry number" << endl;
                        }
                    }
                    if (r->entries->is_entry_exist(eN)) {
                        break;
                    }
                        
                    else if (eN == 0)
                        return;
                    else {
                        SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                        cout << "Entry does not exist" << endl;
                        SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                        cout << "Type '0' if want to exit" << endl;
                    }
                }
                r->entries->delete_entry(eN);
                SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                cout << "Room unbooked" << endl;
                SetConsoleCursorPosition(hConsole, { 70,tempRowPos++ });
                system("pause");
                return;

            }
        }

    }

    system("pause");

}

void bookRoomNow(Customer_Node* c, Room* r, Date* bf, Date* bu) {
    Customer_Entry* e = new Customer_Entry(c, bf, bu);
    r->entries->insert_existing_entry(e);
    e->is_booked = true;
}

void bookRoomsWindow(Customer_Node* c, GuestHouse_List* gl, Room_List* lr, Customer_List* cl) {
    system("cls");
    string place;
    Room_List* sorted_rl;
    Room* thisRoom = new Room();
    while (true) {
        while (true) {
            system("cls");
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << R"(                                         ___            _       ___                      
                                        | _ ) ___  ___ | |__   | _ \ ___  ___  _ __   ___
                                        | _ \/ _ \/ _ \| / /   |   // _ \/ _ \| '  \ (_-<
                                        |___/\___/\___/|_\_\   |_|_\\___/\___/|_|_|_|/__/)" << endl;
            cout << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            short rowPos = 7;
            SetConsoleCursorPosition(hConsole, { 55,8 });
            cout << "(Type 'exit' to go back)" << endl;
            SetConsoleCursorPosition(hConsole, { 45,10 });
            cout << "Available Areas :" << endl;
            gl->print_areas();
            rowPos = 17;
            while (true) {
                SetConsoleCursorPosition(hConsole, { 35,rowPos++ });
                cout << "Select Your Area : ";
                cin >> place;
                if (place == "exit")
                    return;
                if (gl->isGuestHouseExistInThisArea(place)) {
                    system("cls");
                    break;
                }
                else {
                    SetConsoleCursorPosition(hConsole, { 35,rowPos++ });
                    cout << "No such Area" << endl;
                }
            }
            break;
        }
        sorted_rl = lr->roomsInThatArea(place);
        while (true) {
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << R"(                                         ___            _       ___                      
                                        | _ ) ___  ___ | |__   | _ \ ___  ___  _ __   ___
                                        | _ \/ _ \/ _ \| / /   |   // _ \/ _ \| '  \ (_-<
                                        |___/\___/\___/|_\_\   |_|_\\___/\___/|_|_|_|/__/)" << endl;
            cout << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            SetConsoleCursorPosition(hConsole, { 55,8 });
            cout << "(Type 'exit' to go back)" << endl;
            SetConsoleCursorPosition(hConsole, { 5,10 });
            cout << "---------------------------------------     Free rooms at present in your area     -----------------------------------------" << endl;
            sorted_rl->print_free_rooms();
            cout << endl;
            cout << "     ----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            string gh;
            while (true) {
                cout << "                                         the name of the guest house : ";
                cin >> gh;
                if (gh == "exit")
                    break;
                else if (gl->isGuestHouseExist(gh)) {
                    break;
                }
                else {
                    cout << "                                     Guest House does not exists" << endl;
                }
                    
            }
            if (gh == "exit")
                break;
            string rN;
            while (true) {
                cout << "                                         Enter the room number : ";
                cin >> rN;
                if (rN == "exit")
                    break;
                else if (lr->isRoomExists(rN, gh)) {
                    thisRoom = lr->getRoom(rN, gh);
                    break;
                }
                else {
                    cout << "                                           Room does not exists" << endl;
                }
            }
            if (gh == "exit")
                break;
            system("cls");
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << R"(                                         ___            _       ___                      
                                        | _ ) ___  ___ | |__   | _ \ ___  ___  _ __   ___
                                        | _ \/ _ \/ _ \| / /   |   // _ \/ _ \| '  \ (_-<
                                        |___/\___/\___/|_\_\   |_|_\\___/\___/|_|_|_|/__/)" << endl;
            cout << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            thisRoom->print_room_2();
            short rowPos = 16;
            SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
            cout << "-----------------------------------------------------" << endl;
            rowPos += 2;
            SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
            cout << "Press (1) to book this room" << endl;
            SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
            cout << "Press (2) to book another room" << endl;
            SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
            cout << "Press (0) to go back" << endl;
            string key;
            while (true) {
                SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
                cout << "Option\t: ";
                cin >> key;
                if (key == "1") {
                    system("cls");
                    thisRoom->just_print_room();
                    rowPos = 9;
                    SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
                    cout << "Book the room from : " << endl;
                    Date* bf = new Date(&rowPos,85);
                    SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
                    cout << "Book the room until " << endl;
                    Date* bu = new Date(&rowPos, 85);
                    Room* selectedRoom = lr->find_room(rN, gh);
                    bookRoomNow(c, selectedRoom, bf, bu);
                    rowPos += 2;
                    SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
                    cout << "Room number " << rN << " in " << gh << " is booked";
                    SetConsoleCursorPosition(hConsole, { 85,rowPos++ });
                    cout << "from ";
                    bf->printDate();
                    SetConsoleCursorPosition(hConsole, { 85,rowPos++ });
                    cout << "until ";
                    bu->printDate();
                    cout << endl;
                    rowPos++;
                    SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
                    system("pause");
                    return;
                }
                else if (key == "2") {
                    break;
                }
                else if (key == "0")
                    return;
                else {
                    cout << "Invalid Option" << endl;
                }
            }
            system("cls");
            continue;
        }
        break;
    }
}

void bookRoomManually(Customer_Entry* e, Room* r) {
    r->entries->insert_existing_entry(e);
    e->entry_number = r->entries->size;
    e->is_booked = true;
}

int ownerScreen() {
    int owner_option;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(         ___             _   _  _                    __  __                                       _     ___         _             
        / __|_  _ ___ __| |_| || |___ _  _ ___ ___  |  \/  |__ _ _ _  __ _ __ _ ___ _ __  ___ _ _| |_  / __|_  _ __| |_ ___ _ __  
       | (_ | || / -_|_-<  _| __ / _ \ || (_-</ -_) | |\/| / _` | ' \/ _` / _` / -_) '  \/ -_) ' \  _| \__ \ || (_-<  _/ -_) '  \ 
        \___|\_,_\___/__/\__|_||_\___/\_,_/__/\___| |_|  |_\__,_|_||_\__,_\__, \___|_|_|_\___|_||_\__| |___/\_, /__/\__\___|_|_|_|
                                                                          |___/                             |__/                  )";
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;
    short rowPos = 10;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (1) to Log In" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (2) for Sign Up" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (3) to go back" << endl;
    cout << endl;
    rowPos = 15;
    string input;
    while (true) {
        while (true) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Enter your option : ";
            cin >> input;
            try {
                owner_option = stoi(input);
                break;
            }
            catch (invalid_argument&) {
                SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
                cout << "Enter a valid number" << endl;
            }
        }
        switch (owner_option) {
        case 1:
            system("CLS");
            return 1;
        case 2:
            system("CLS");
            return 2;
        case 3:
            system("CLS");
            return 3;
        default:
            cout << "Invalid number" << endl;
            continue;
        }
        break;
    }
}

Owner_Node* ownerLogInScreen(Customer_List* l_customer, Owner_List* l_owner, GuestHouse_List* l_guestHouse, Room_List* l_rooms) {
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(                                      ___                              ___                          
                                     / _ \ __ __ __ _ _   ___  _ _    / __| __  _ _  ___  ___  _ _  
                                    | (_) |\ V  V /| ' \ / -_)| '_|   \__ \/ _|| '_|/ -_)/ -_)| ' \ 
                                     \___/  \_/\_/ |_||_|\___||_|     |___/\__||_|  \___|\___||_||_|)" << endl;
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;
    short rowPos = 8;
    SetConsoleCursorPosition(hConsole, { 40,rowPos++ });
    cout << "(Please enter your telephone number and the password to log in)" << endl;
    SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
    cout << "Press (0) to go back" << endl;
    string tel, pw;
    cout << endl;
    rowPos = 11;
    while (true) {
        SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
        cout << "Telephone Number : ";
        cin >> tel;
        if (l_owner->searchOwner(tel)) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Owner found" << endl;
            break;
        }
        else if (tel == "0") {
            return NULL;
        }
        else {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "owner not found" << endl;
        }
    }
    while (true) {
        SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
        cout << "Password : ";
        cin >> pw;
        if (l_owner->validateOwner(tel, pw)) {
            rowPos += 2;
            SetConsoleCursorPosition(hConsole, { 65,rowPos++ });
            cout << "Done" << endl;
            rowPos += 2;
            SetConsoleCursorPosition(hConsole, { 52,rowPos++ });
            system("pause");
            return l_owner->getOwner(tel);
        }
        else if (pw == "0") {
            return NULL;
        }
        else {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "Password is incorrect" << endl;
        }
    }


}

void ownerSignInScreen(Customer_List* l_customer, Owner_List* l_owner, GuestHouse_List* l_guestHouse, Room_List* l_rooms) {
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << R"(                                                          ___  _                 ___           
                                                         / __|(_) __ _  _ _     |_ _| _ _  
                                                         \__ \| |/ _` || ' \     | | | ' \ 
                                                         |___/|_|\__, ||_||_|   |___||_||_|
                                                                 |___/                      )" << endl;
    cout << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;
    short colPos = 5;
    short rowPos = 9;
    SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
    cout << "---------------------------------------------------------" << endl;
    SetConsoleCursorPosition(hConsole, { 25,rowPos++ });
    cout << "PERSONAL INFORMATION" << endl;
    SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
    cout << "---------------------------------------------------------" << endl;
    Owner_Node* owner = new Owner_Node(&colPos, &rowPos);
    SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
    cout << "---------------------------------------------------------" << endl;
    rowPos++;
    SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
    cout << "Press (1) to create a new Guest House." << endl;
    SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
    cout << "Press (2) to add to a guest house as an owner" << endl;
    SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
    cout << "Press (0) to exit" << endl;
    int ghDetails;
    string input;
    short temp = rowPos + 1;
    short newTemp = temp;
    while (true) {
        while(true){
            SetConsoleCursorPosition(hConsole, { 10,temp++ });
            cout << "Your option : ";
            cin >> input;
            try {
                ghDetails = stoi(input);
                break;
            }
            catch (invalid_argument&) {
                SetConsoleCursorPosition(hConsole, { 10,temp++ });
                cout << "Enter a valid number" << endl;
            }
        }
        newTemp = temp+2;
        rowPos = 9;
        short temp = 9;
        for (int i = 0; i < 30; i++) {
            SetConsoleCursorPosition(hConsole, {66,temp++ });
            cout << "|";
        }
        switch (ghDetails) {
        case 1:
            SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
            cout << "--------------------------------------------------------------" << endl;
            SetConsoleCursorPosition(hConsole, { 90,rowPos++ });
            cout << "CREATE A NEW GUEST HOUSE" << endl;
            SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
            cout << "--------------------------------------------------------------" << endl;
            rowPos++;
            l_guestHouse->insert_new_guestHouse(owner, l_rooms, &rowPos);
            break;
        case 2:
            SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
            cout << "--------------------------------------------------------------" << endl;
            SetConsoleCursorPosition(hConsole, { 90,rowPos++ });
            cout << "ADD TO AN EXISTING GUEST HOUSE" << endl;
            SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
            cout << "--------------------------------------------------------------" << endl;
            SetConsoleCursorPosition(hConsole, { 90,rowPos++ });
            cout << "( Type 'exit' to exit )" << endl;
            l_guestHouse->addOwner(owner);
            break;
        case 0:
            return;
        default:
            SetConsoleCursorPosition(hConsole, { 10,temp++ });
            cout << "Not a valid choice " << endl;
        }
        break;
    }
    SetConsoleCursorPosition(hConsole, { 5,newTemp++ });
    cout << "---------------------------------------------------------" << endl;
    SetConsoleCursorPosition(hConsole, { 25,newTemp++ });
    cout << "Owner Added" << endl;
    l_owner->insert_exsisting_owner(owner);
    SetConsoleCursorPosition(hConsole, { 15,newTemp++ });
    system("pause");
    SetConsoleCursorPosition(hConsole, { 5,newTemp++ });
    cout << "---------------------------------------------------------" << endl;
    return;
}

void guestHouseDetails(Owner_Node* o, Owner_List* l_owner, GuestHouse_List* l_guestHouse, Room_List* l_rooms, Customer_List* l_customer);

void validate_purchase(Owner_Node* o, Owner_List* l_owner, GuestHouse_List* gl, Room_List* l_rooms, Customer_List* l_customer);

void see_customer_personal_details(CustomerTable* customers) {
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                        ___           _                              ___         __      
                                       / __|_  _  ___| |_  ___  _ __   ___  _ _     |_ _| _ _   / _| ___ 
                                      | (__| || |(_-<|  _|/ _ \| '  \ / -_)| '_|     | | | ' \ |  _|/ _ \
                                       \___|\_,_|/__/ \__|\___/|_|_|_|\___||_|      |___||_||_||_|  \___/)" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        SetConsoleCursorPosition(hConsole, { 55,8 });
        cout << "(Type 'exit' to go back)" << endl;
        string key;
        Customer_Node* c = new Customer_Node();
        short rowPos = 15;
        while (true) {
            SetConsoleCursorPosition(hConsole, { 50,rowPos++ });
            cout << "Enter Customer ID number : ";
            cin >> key;
            c = customers->search(key);
            if (key == "exit")
                return;
            else if (c == NULL) {
                SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
                cout << "No Customer with that ID" << endl;
                continue;
            }
            else {
                SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
                cout << "Customer Found" << endl;
                SetConsoleCursorPosition(hConsole, { 55,rowPos++ });
                system("pause");
                break;
            }
        }
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                        ___           _                              ___         __      
                                       / __|_  _  ___| |_  ___  _ __   ___  _ _     |_ _| _ _   / _| ___ 
                                      | (__| || |(_-<|  _|/ _ \| '  \ / -_)| '_|     | | | ' \ |  _|/ _ \
                                       \___|\_,_|/__/ \__|\___/|_|_|_|\___||_|      |___||_||_||_|  \___/)" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        SetConsoleCursorPosition(hConsole, { 55,8 });
        cout << "(Type 'exit' to go back)" << endl;
        short colPos = 5;
        rowPos = 10;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "                CUSTOMER INFORMATION                  " << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        rowPos++;
        c->print_customer(colPos, rowPos);
        cout << endl;
        SetConsoleCursorPosition(hConsole, { 3,22 });
        cout << "------------------------------------------------------" << endl;
        rowPos = 10;
        for (short i = 0; i < 15; i++) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "|" << endl;
        }
        rowPos = 16;
        colPos = 80;
        while (true) {
            SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
            cout << "Choice -> ";
            cin >> key;
            if (key == "exit")
                return;
            else {
                SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
                cout << "Invalid option" << endl;
            }
                
        }
    }

}

void ownerWindow(Owner_Node* o, Owner_List* l_owner, GuestHouse_List* l_guestHouse, Room_List* l_rooms, Customer_List* l_customer, CustomerTable* customers) {
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                      ___                              ___                          
                                     / _ \ __ __ __ _ _   ___  _ _    / __| __  _ _  ___  ___  _ _  
                                    | (_) |\ V  V /| ' \ / -_)| '_|   \__ \/ _|| '_|/ -_)/ -_)| ' \ 
                                     \___/  \_/\_/ |_||_|\___||_|     |___/\__||_|  \___|\___||_||_|)" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        short colPos = 5;
        short rowPos = 8;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "                OWNER INFORMATION                  " << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        rowPos++;
        o->print_owner(colPos,rowPos);
        cout << endl;
        SetConsoleCursorPosition(hConsole, { 3,20 });
        cout << "------------------------------------------------------" << endl;
        rowPos = 8;
        for (short i = 0; i < 15; i++) {
            SetConsoleCursorPosition(hConsole, { 60,rowPos++ });
            cout << "|" << endl;
        }
        rowPos = 10;
        colPos = 80;
        rowPos = 10;
        colPos = 80;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (1) to see Guest House details" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (2) to see booking requests" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (3) to see customer personal details" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (0) to log out" << endl;
        int key;
        string input;
        while (true) {
            rowPos += 2;
            while (true) {
                SetConsoleCursorPosition(hConsole, { 85,rowPos++ });
                cout << "Option : ";
                cin >> input;
                try {
                    key = stoi(input);
                    break;
                }
                catch (invalid_argument&) {
                    SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
                    cout << "Enter a valid number" << endl;
                }
            }
            switch (key) {
            case 1:
                guestHouseDetails(o, l_owner, l_guestHouse, l_rooms, l_customer);
                break;
            case 2:
                validate_purchase(o, l_owner, l_guestHouse, l_rooms, l_customer);
                break;
            case 3:
                see_customer_personal_details(customers);
                break;
            case 0:
                return;
            }
            break;
        }
        
    }
}

void validate_purchase(Owner_Node* o, Owner_List* l_owner, GuestHouse_List* gl, Room_List* l_rooms, Customer_List* l_customer) {
    Guest_House* gH = gl->returnGuestHouse(o->first_name);
    string choice;
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                     ___                _  _                 ___                            _       
                                    | _ \ ___  _ _   __| |(_) _ _   __ _    | _ \ ___  __ _  _  _  ___  ___| |_  ___
                                    |  _// -_)| ' \ / _` || || ' \ / _` |   |   // -_)/ _` || || |/ -_)(_-<|  _|(_-<
                                    |_|  \___||_||_|\__,_||_||_||_|\__, |   |_|_\\___|\__, | \_,_|\___|/__/ \__|/__/
                                                                   |___/                 |_|                        )" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        short colPos = 5;
        short rowPos = 10;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "               GUEST HOUSE INFORMATION                  " << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        rowPos++;
        gH->print_guestHouse(colPos, rowPos);
        cout << endl;
        SetConsoleCursorPosition(hConsole, { 3,20 });
        cout << "------------------------------------------------------" << endl;
        rowPos = 8;
        for (short i = 0; i < 15; i++) {
            SetConsoleCursorPosition(hConsole, { 65,rowPos++ });
            cout << "|" << endl;
        }
        rowPos = 10;
        colPos = 80;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (1) to see the list view of booking requests" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (2) to see the detailed view of requests" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Type 'exit' to go back" << endl;
        rowPos += 2;
        while (true) {
            SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
            cout << "Choice --> ";
            cin >> choice;
            if (choice == "1") {
                system("cls");
                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                cout << R"(                                     ___                _  _                 ___                            _       
                                    | _ \ ___  _ _   __| |(_) _ _   __ _    | _ \ ___  __ _  _  _  ___  ___| |_  ___
                                    |  _// -_)| ' \ / _` || || ' \ / _` |   |   // -_)/ _` || || |/ -_)(_-<|  _|(_-<
                                    |_|  \___||_||_|\__,_||_||_||_|\__, |   |_|_\\___|\__, | \_,_|\___|/__/ \__|/__/
                                                                   |___/                 |_|                        )" << endl;
                cout << endl;
                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                SetConsoleCursorPosition(hConsole, { 55,9 });
                cout << "( Type 'exit' to go back )" << endl;
                cout << endl;
                rowPos = 12;
                SetConsoleCursorPosition(hConsole, { 17,rowPos });
                cout << "Room Number";
                SetConsoleCursorPosition(hConsole, { 29,rowPos });
                cout << "|";
                SetConsoleCursorPosition(hConsole, { 40,rowPos });
                cout << "Customer Name";
                SetConsoleCursorPosition(hConsole, { 60,rowPos });
                cout << "|";
                SetConsoleCursorPosition(hConsole, { 67,rowPos });
                cout << "Customer ID";
                SetConsoleCursorPosition(hConsole, { 83,rowPos });
                cout << "|";
                SetConsoleCursorPosition(hConsole, { 89,rowPos });
                cout << "Booked From";
                SetConsoleCursorPosition(hConsole, { 104,rowPos });
                cout << "|";
                SetConsoleCursorPosition(hConsole, { 109,rowPos });
                cout << "Booked Until";
                rowPos++;
                SetConsoleCursorPosition(hConsole, { 10,rowPos++ });
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < gH->number_of_rooms; i++) {
                    if (gH->rooms[i]->entries->head!=nullptr) {
                        string rN = gH->rooms[i]->room_number;
                        gH->rooms[i]->entries->print_unpurchased_entries(rN, &rowPos);
                    }
                    
                }
                rowPos += 3;
                string exit;
                while (true) {
                    SetConsoleCursorPosition(hConsole, { 55,rowPos++ });
                    cout << "Option -> ";
                    cin >> exit;
                    if (exit == "exit") {
                        return;
                    }
                    else {
                        SetConsoleCursorPosition(hConsole, { 38,rowPos++ });
                        cout << "Invalid option" << endl;
                    }

                }
                continue;
            }
            else if (choice == "2") {
                int t=0;
                for (int i = 0; i < gH->number_of_rooms; i++) {
                    if (gH->rooms[i]->entries->size > 0) {
                        int val = gH->rooms[i]->entries->book_entries(gH->rooms[i]->room_number);
                        if (val == 0) {
                            if (i > gH->number_of_rooms - 2) {
                                i = t - 1;
                                continue;
                            }
                            else {
                                t = i;
                            }
                        }
                        else if (val == 3) {
                            return;
                        }
                    }
                }
                return;
            }
            else if (choice == "exit") {
                return;
            }
            else {
                short temp = colPos + 8;
                SetConsoleCursorPosition(hConsole, { temp,rowPos++ });
                cout << "Invalid Option" << endl;
            }
        }
        
    }
   

}

void print_guestHouse_rooms(Guest_House* gH) {
    int i = 0;
    int n = gH->number_of_rooms;
    string choice;
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                                              ___                      ___        _          _  _     
                                             | _ \ ___  ___  _ __     |   \  ___ | |_  __ _ (_)| | ___
                                             |   // _ \/ _ \| '  \    | |) |/ -_)|  _|/ _` || || |(_-<
                                             |_|_\\___/\___/|_|_|_|   |___/ \___| \__|\__,_||_||_|/__/)" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        gH->rooms[i]->print_room_2();
        short rowPos = 16;
        short temp = rowPos;
        SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
        cout << "-----------------------------------------------------" << endl;
        rowPos += 2;
        SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
        cout << "Press (1) to go to next room" << endl;
        SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
        cout << "Press (2) to go to previous room" << endl;
        SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
        cout << "Press (0) to go back" << endl;
        string key;
        cout << endl;
        SetConsoleCursorPosition(hConsole, { 7,rowPos++ });
        cout << "Choice --> ";
        cin >> choice;
        if (choice == "1") {
            if ((i+1) < n) {
                i++;
                continue;
            }
            else {
                short temp = rowPos + 1;
                SetConsoleCursorPosition(hConsole, { 9,temp++ });
                cout << "No other rooms" << endl;
                SetConsoleCursorPosition(hConsole, { 9,temp++ });
                system("pause");
                continue;
            }
        }
        else if (choice == "2") {
            if ((i - 1) >= 0) {
                i--;
                continue;
            }
            else {
                short temp = rowPos + 1;
                SetConsoleCursorPosition(hConsole, { 9,temp++ });
                cout << "No other rooms" << endl;
                SetConsoleCursorPosition(hConsole, { 9,temp++ });
                system("pause");
            }
        }
        else if (choice == "0") {
            return;
        }
        else {
            short temp = rowPos + 1;
            SetConsoleCursorPosition(hConsole, { 9,temp++ });
            cout << "Invalid choice" << endl;
            continue;
        }
    }
}

void guestHouseDetails(Owner_Node* o, Owner_List* l_owner, GuestHouse_List* gl, Room_List* l_rooms, Customer_List* l_customer) {
    Guest_House* gH = new Guest_House();
    gH = gl->returnGuestHouse(o->first_name);
    system("cls");
    while (true) {
        system("cls");
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << R"(                               ___                 _    _  _                         ___        _          _  _     
                              / __| _  _  ___  ___| |_ | || | ___  _  _  ___ ___    |   \  ___ | |_  __ _ (_)| | ___
                             | (_ || || |/ -_)(_-<|  _|| __ |/ _ \| || |(_-</ -_)   | |) |/ -_)|  _|/ _` || || |(_-<
                              \___| \_,_|\___|/__/ \__||_||_|\___/ \_,_|/__/\___|   |___/ \___| \__|\__,_||_||_|/__/)" << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        short colPos = 5;
        short rowPos = 9;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "               GUEST HOUSE INFORMATION                  " << endl;
        SetConsoleCursorPosition(hConsole, { 3,rowPos++ });
        cout << "------------------------------------------------------" << endl;
        rowPos++;
        gH->print_guestHouse(colPos, rowPos);
        cout << endl;
        SetConsoleCursorPosition(hConsole, { 3,16 });
        cout << "------------------------------------------------------" << endl;
        rowPos = 8;
        for (short i = 0; i < 15; i++) {
            SetConsoleCursorPosition(hConsole, { 65,rowPos++ });
            cout << "|" << endl;
        }
        rowPos = 10;
        colPos = 80;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (1) for room details" << endl;
        SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
        cout << "Press (0) to exit" << endl;
        string choice;
        rowPos += 2;
        while (true) {
            SetConsoleCursorPosition(hConsole, { colPos,rowPos++ });
            cout << "Choice --> ";
            cin >> choice;
            if (choice == "0")
                return;
            else if (choice == "1") {
                print_guestHouse_rooms(gH);
                break;
            }
            else {
                short temp = colPos + 10;
                SetConsoleCursorPosition(hConsole, { temp,rowPos++ });
                cout << "Invalid choice" << endl;
            }
        }
    }
    
    
    system("pause");
}



