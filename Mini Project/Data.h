#pragma once
#include "Main_Functions.h"

void addData(Customer_List* l_customer, Owner_List* l_owner, GuestHouse_List* l_guestHouse, Room_List* l_rooms, CustomerTable* customers) {
    Room* r1 = new Room();
    Room* r2 = new Room();
    Room* r3 = new Room();
    Room* r4 = new Room();
    Room* r5 = new Room();
    Room* r6 = new Room();
    Room* r7 = new Room();
    Room* r8 = new Room();
    Room* r9 = new Room();
    Room* r10 = new Room();
    Room* r11 = new Room();
    Room* r12 = new Room();
    Room* r13 = new Room();
    Room* r14 = new Room();
    Room* r15 = new Room();
    Room* r16 = new Room();
    Room* r17 = new Room();
    Room* r18 = new Room();
    Room* r19 = new Room();
    Room* r20 = new Room();
    Room* r21 = new Room();
    Room* r22 = new Room();
    Room* r23 = new Room();
    Room* r24 = new Room();
    Room* r25 = new Room();
    Room* r26 = new Room();
    Room* r27 = new Room();
    Room* r28 = new Room();
    Room* r29 = new Room();
    Room* r30 = new Room();
    Room* r31 = new Room();
    Room* r32 = new Room();
    Room* r33 = new Room();
    Room* r34 = new Room();
    Room* r35 = new Room();
    Room* r36 = new Room();
    Room* r37 = new Room();
    Comment com1("Good condition");
    r1->createExistingRoom("1", 2, true, 3000, &com1);
    r2->createExistingRoom("2", 1, true, 2500, &com1);
    r3->createExistingRoom("3", 4, false, 6000, &com1);
    r4->createExistingRoom("4", 1, false, 2000, &com1);
    r5->createExistingRoom("5", 2, true, 5000, &com1);
    r6->createExistingRoom("6", 3, false, 4500, &com1);
    r7->createExistingRoom("7", 3, true, 8000, & com1);
    r8->createExistingRoom("8", 4, false, 7000, &com1);
    r9->createExistingRoom("9", 2, false, 4000, &com1);
    r10->createExistingRoom("10", 1, true, 450, &com1);
    r11->createExistingRoom("11", 3, true, 650, &com1);
    r12->createExistingRoom("12", 4, false, 60, &com1);
    r13->createExistingRoom("13", 2, true, 400, &com1);
    r14->createExistingRoom("14", 2, false, 35, &com1);
    r15->createExistingRoom("15", 1, false, 15, &com1);
    r16->createExistingRoom("16", 1, true, 300, &com1);
    r17->createExistingRoom("17", 4, true, 900, &com1);
    r18->createExistingRoom("18", 3, false, 40, &com1);
    r19->createExistingRoom("19", 3, true, 6000, &com1);
    r20->createExistingRoom("20", 2, true, 4500, &com1);
    r21->createExistingRoom("21", 2, true, 4500, &com1);
    r22->createExistingRoom("22", 1, false, 150, &com1);
    r23->createExistingRoom("23", 3, false, 550, &com1);
    r24->createExistingRoom("24", 2, true, 5000, &com1);
    r25->createExistingRoom("25", 2, true, 5000, &com1);
    r26->createExistingRoom("26", 2, false, 300, &com1);
    r27->createExistingRoom("27", 1, true, 3500, &com1);
    r28->createExistingRoom("28", 3, true, 7500, &com1);
    r29->createExistingRoom("29", 2, true, 4000, &com1);
    r30->createExistingRoom("30", 3, true, 6000, &com1);
    r31->createExistingRoom("31", 1, true, 2500, &com1);
    r32->createExistingRoom("32", 2, false, 400, &com1);
    r33->createExistingRoom("33", 3, true, 7500, &com1);
    r34->createExistingRoom("34", 2, false, 400, &com1);
    r35->createExistingRoom("35", 4, true, 8000, &com1);
    r36->createExistingRoom("36", 4, true, 8000, &com1);
    r37->createExistingRoom("37", 2, false, 450, &com1);
    r23->createExistingRoom("23", 3, false, 550, &com1);
    r24->createExistingRoom("24", 2, true, 5000, &com1);
    r25->createExistingRoom("25", 2, true, 5000, &com1);
    r26->createExistingRoom("26", 2, false, 300, &com1);
    r27->createExistingRoom("27", 1, true, 3500, &com1);
    r28->createExistingRoom("28", 3, true, 7500, &com1);
    r29->createExistingRoom("29", 2, true, 4000, &com1);
    r30->createExistingRoom("30", 3, true, 6000, &com1);
    r31->createExistingRoom("31", 1, true, 2500, &com1);
    r32->createExistingRoom("32", 2, false, 400, &com1);
    r33->createExistingRoom("33", 3, true, 7500, &com1);
    r34->createExistingRoom("34", 2, false, 400, &com1);
    r35->createExistingRoom("35", 4, true, 8000, &com1);
    r36->createExistingRoom("36", 4, true, 8000, &com1);
    r37->createExistingRoom("37", 2, false, 450, &com1);
    Customer_Node* c1 = new Customer_Node();
    Customer_Node* c2 = new Customer_Node();
    Customer_Node* c3 = new Customer_Node();
    Customer_Node* c4 = new Customer_Node();
    Customer_Node* c5 = new Customer_Node();
    Customer_Node* c6 = new Customer_Node();
    Customer_Node* c7 = new Customer_Node();
    Customer_Node* c8 = new Customer_Node();
    Customer_Node* c9 = new Customer_Node();
    Customer_Node* c10 = new Customer_Node();
    c1->initialize_customer("123", "Tom", "Brown", male, "Kandy", "061", "Tom");
    l_customer->insert_exsisting_customer(c1);
    c2->initialize_customer("6754236490v", "Brad", "Pitt", male, "Gampaha", "0714586395", "@Brad490");
    l_customer->insert_exsisting_customer(c2);
    c3->initialize_customer("9658123585v", "Raza", "Ali", male, "Kaluthara", "0752145693", "Ali@3#1");
    l_customer->insert_exsisting_customer(c3);
    c4->initialize_customer("8545698523v", "Cindly", "Graciella", female, "Negombo", "0812598745", "@CinGrace78");
    l_customer->insert_exsisting_customer(c4);
    c5->initialize_customer("9965846328v", "Sean", "Mario", male, "Hatton", "0786983147", "$SeanMari");
    l_customer->insert_exsisting_customer(c5);
    c6->initialize_customer("9785637911v", "Emma", "Lori", female, "Colombo", "0153698547", "Emma11");
    l_customer->insert_exsisting_customer(c6);
    c7->initialize_customer("9458763254v", "Riley", "Vernon", male, "Galle", "0452369876", "Ver456non");
    l_customer->insert_exsisting_customer(c7);
    c8->initialize_customer("7856932741v", "Tracy", "Sara", female, "Matara", "0214739176", "45*sara");
    l_customer->insert_exsisting_customer(c8);
    c9->initialize_customer("6953179512v", "Ashley", "Margeret", female, "Kegalle", "0745237489", "@Ashl%er");
    l_customer->insert_exsisting_customer(c9);
    c10->initialize_customer("9652361781v", "Julian", "Monica", female, "Matale", "0854397645", "@Julian");
    l_customer->insert_exsisting_customer(c10);

    Owner_Node* o1 = new Owner_Node();
    Owner_Node* o2 = new Owner_Node();
    Owner_Node* o3 = new Owner_Node();
    Owner_Node* o4 = new Owner_Node();
    Owner_Node* o5 = new Owner_Node();
    o1->initialize_owner("8523695741v", "Harry", "Ajard", male, "Russia", "077", "123");
    l_owner->insert_exsisting_owner(o1);
    o2->initialize_owner("8968544732v", "Jeffri", "Andrew", female, "Colombo", "0707853915", "Andr@45");
    l_owner->insert_exsisting_owner(o2);
    o3->initialize_owner("9956823574v", "Adhil", "Santhush", male, "Kurunegala", "0758931289", "aadhi");
    l_owner->insert_exsisting_owner(o3);
    o4->initialize_owner("9653269874v", "Priya", "Awya", female, "kandy", "0762369743", "Priya$awya");
    l_owner->insert_exsisting_owner(o4);
    o5->initialize_owner("8652136973v", "Sai", "Salman", male, "Batticaloe", "0779684361", "Sal**1234");
    l_owner->insert_exsisting_owner(o5);
    Room** rArr1 = new Room * [5];
    rArr1[0] = r1;
    rArr1[1] = r2;
    rArr1[2] = r3;
    rArr1[3] = r4;
    rArr1[4] = r5;
    Room** rArr2 = new Room * [6];
    rArr2[0] = r6;
    rArr2[1] = r7;
    rArr2[2] = r8;
    rArr2[3] = r9;
    rArr2[4] = r10;
    rArr2[5] = r11;
    Room** rArr3 = new Room * [8];
    rArr3[0] = r12;
    rArr3[1] = r13;
    rArr3[2] = r14;
    rArr3[3] = r15;
    rArr3[4] = r16;
    rArr3[5] = r17;
    rArr3[6] = r18;
    rArr3[7] = r19;
    Room** rArr4 = new Room * [8];
    rArr4[0] = r20;
    rArr4[1] = r21;
    rArr4[2] = r22;
    rArr4[3] = r23;
    rArr4[4] = r24;
    rArr4[5] = r25;
    rArr4[6] = r26;
    rArr4[7] = r27;
    Room** rArr5 = new Room * [10];
    rArr5[0] = r28;
    rArr5[1] = r29;
    rArr5[2] = r30;
    rArr5[3] = r31;
    rArr5[4] = r32;
    rArr5[5] = r33;
    rArr5[6] = r34;
    rArr5[7] = r35;
    rArr5[8] = r36;
    rArr5[9] = r37;

    Guest_House g1, g2, g3, g4, g5;
    g1.initialize_guestHouse("GH1", 5, "0812345679", "gh1@abc.com", "Kandy", rArr1, o1, l_owner, "GH1pw");
    g2.initialize_guestHouse("GH2", 6, "0813412381", "gh2@Galle.com", "Galle", rArr2, o2, l_owner,"GH2pw");
    g3.initialize_guestHouse("GH3", 8, "0818569314", "gh2@dfg.com", "Hatton", rArr3, o3, l_owner, "GH3pw");
    g4.initialize_guestHouse("GH4", 8, "0815684051", "gh2@kaluthara.com", "kaluthara", rArr4, o4, l_owner, "GH4pw");
    g5.initialize_guestHouse("GH5", 10, "0652536987", "gh2@guests.com", "Rathnapura", rArr5, o5, l_owner, "GH5pw");
    l_guestHouse->insert_exsisting_guestHouse(g1);
    l_guestHouse->insert_exsisting_guestHouse(g2);
    l_guestHouse->insert_exsisting_guestHouse(g3);
    l_guestHouse->insert_exsisting_guestHouse(g4);
    l_guestHouse->insert_exsisting_guestHouse(g5);

    l_rooms->insert_exsisting_room(r1);
    l_rooms->insert_exsisting_room(r2);
    l_rooms->insert_exsisting_room(r3);
    l_rooms->insert_exsisting_room(r4);
    l_rooms->insert_exsisting_room(r5);
    l_rooms->insert_exsisting_room(r6);
    l_rooms->insert_exsisting_room(r7);
    l_rooms->insert_exsisting_room(r8);
    l_rooms->insert_exsisting_room(r9);
    l_rooms->insert_exsisting_room(r10);
    l_rooms->insert_exsisting_room(r11);
    l_rooms->insert_exsisting_room(r12);
    l_rooms->insert_exsisting_room(r13);
    l_rooms->insert_exsisting_room(r14);
    l_rooms->insert_exsisting_room(r15);
    l_rooms->insert_exsisting_room(r16);
    l_rooms->insert_exsisting_room(r17);
    l_rooms->insert_exsisting_room(r18);
    l_rooms->insert_exsisting_room(r19);
    l_rooms->insert_exsisting_room(r20);
    l_rooms->insert_exsisting_room(r21);
    l_rooms->insert_exsisting_room(r22);
    l_rooms->insert_exsisting_room(r23);
    l_rooms->insert_exsisting_room(r24);
    l_rooms->insert_exsisting_room(r25);
    l_rooms->insert_exsisting_room(r26);
    l_rooms->insert_exsisting_room(r27);
    l_rooms->insert_exsisting_room(r28);
    l_rooms->insert_exsisting_room(r29);
    l_rooms->insert_exsisting_room(r30);
    l_rooms->insert_exsisting_room(r31);
    l_rooms->insert_exsisting_room(r32);
    l_rooms->insert_exsisting_room(r33);
    l_rooms->insert_exsisting_room(r34);
    l_rooms->insert_exsisting_room(r35);
    l_rooms->insert_exsisting_room(r36);
    l_rooms->insert_exsisting_room(r37);

    Date* d11 = new Date(2023, January, 10);
    Date* d12 = new Date(2023, February, 1);
    Customer_Entry* e1 = new Customer_Entry(c1, d11, d12);
    Customer_Entry* e2 = new Customer_Entry(c1, d11, d12);
    bookRoomManually(e1, r5);
    bookRoomManually(e2, r2);
    customers->insert(c1->id_number, c1);
    customers->insert(c2->id_number, c2);
    customers->insert(c3->id_number, c3);
    customers->insert(c4->id_number, c4);
    customers->insert(c5->id_number, c5);
    customers->insert(c6->id_number, c6);
    customers->insert(c7->id_number, c7);
    customers->insert(c8->id_number, c8);
    customers->insert(c9->id_number, c9);
    customers->insert(c10->id_number, c10);

   /* customers->print();
    system("pause");*/
}


//void addData(Customer_List* l_customer, Owner_List* l_owner, GuestHouse_List* l_guestHouse, Room_List* l_rooms, CustomerTable* customers) {
//    Room* r1 = new Room();
//    Room* r2 = new Room();
//    Room* r3 = new Room();
//    Room* r4 = new Room();
//    Room* r5 = new Room();
//    Comment com1("Good condition");
//    r1->createExistingRoom("10", 2, true, 3000, &com1);
//    r2->createExistingRoom("11", 2, true, 4000, &com1);
//    r3->createExistingRoom("12", 3, false, 3500, &com1);
//    r4->createExistingRoom("13", 2, false, 3000, &com1);
//    r5->createExistingRoom("14", 2, true, 5000, &com1);
//    Customer_Node* c1 = new Customer_Node();
//    Customer_Node* c2 = new Customer_Node();
//    c1->initialize_customer("123", "Tom", "Brown", male, "Kandy", "07123", "Tom");
//    l_customer->insert_exsisting_customer(c1);
//    c2->initialize_customer("789", "Brad", "Pitt", male, "Gampaha", "078123", "Brad");
//    l_customer->insert_exsisting_customer(c2);
//    Owner_Node o1, o2;
//    o1.initialize_owner("345", "Tim", "Smith", male, "Kandy", "077123", "Tim");
//    l_owner->insert_exsisting_owner(o1);
//    o2.initialize_owner("567", "Jeff", "Blue", male, "Colombo", "070123", "Jeff");
//    l_owner->insert_exsisting_owner(o2);
//    Room** rArr1 = new Room * [2];
//    rArr1[0] = r1;
//    rArr1[1] = r2;
//    Room** rArr2 = new Room * [3];
//    rArr2[0] = r3;
//    rArr2[1] = r4;
//    rArr2[2] = r5;
//    Guest_House g1, g2;
//    g1.initialize_guestHouse("GH1", 2, "081234567", "gh1@abc.com", "Kandy", rArr1, l_owner->head);
//    g2.initialize_guestHouse("GH2", 3, "081341238", "gh2@abc.com", "Galle", rArr2, l_owner->head->next);
//    l_guestHouse->insert_exsisting_guestHouse(g1);
//    l_guestHouse->insert_exsisting_guestHouse(g2);
//    l_rooms->insert_exsisting_room(r1);
//    l_rooms->insert_exsisting_room(r2);
//    l_rooms->insert_exsisting_room(r3);
//    l_rooms->insert_exsisting_room(r4);
//    l_rooms->insert_exsisting_room(r5);
//    Date* d11 = new Date(2023, January, 10);
//    Date* d12 = new Date(2023, February, 1);
//    Customer_Entry* e1 = new Customer_Entry(c1, d11, d12);
//    Customer_Entry* e2 = new Customer_Entry(c1, d11, d12);
//    bookRoomManually(e1, r5);
//    bookRoomManually(e2, r2);
//    customers->insert(c1->id_number, c1);
//    customers->insert(c2->id_number, c2);
//    /* customers->print();
//     system("pause");*/
//}