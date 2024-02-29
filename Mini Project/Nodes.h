#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include "Functions.h"
#include <list>
#include <Windows.h>

using namespace std;
using namespace chrono;


enum Gender
{
	male, female
};

class Room_List;

class Customer_Node {
public:
	string id_number;
	string first_name;
	string last_name;
	Gender gender;
	string address;
	string telephone;
	Date* signed_in_date;
	Customer_Node* next;
	Customer_Node* prev;
	string password;

	Customer_Node(short* rowPos) {
		short row = *rowPos+1;
		SetConsoleCursorPosition(hConsole, { 60,row++ });
		cout << "ID Number : ";
		cin >> id_number;
		SetConsoleCursorPosition(hConsole, { 59,row++ });
		cout << "First Name : ";
		cin >> first_name;
		SetConsoleCursorPosition(hConsole, { 60,row++ });
		cout << "Last Name : ";
		cin >> last_name;
		string G;
		while (true) {
			SetConsoleCursorPosition(hConsole, { 40,row++ });
			cout << "Gender (Male - M, Female - F) : ";
			cin >> G;
			if (G == "M" || G == "m") {
				gender = male;
				break;
			}
			else if (G == "F" || G == "f") {
				gender = female;
				break;
			}
			else {
				SetConsoleCursorPosition(hConsole, { 72,row++ });
				cout << "Invalid" << endl;
			}
		}
		SetConsoleCursorPosition(hConsole, { 62,row++ });
		cout << "Address : ";
		cin >> address;
		SetConsoleCursorPosition(hConsole, { 55,row++ });
		cout << "Contact Number : ";
		cin >> telephone;
		SetConsoleCursorPosition(hConsole, { 53,row++ });
		cout << "Enter a password : ";
		cin >> password;
		signed_in_date = new Date();
		next = NULL;
		prev = NULL;
		*rowPos = row;
	}

	Customer_Node() {
		signed_in_date = new Date();
		next = NULL;
		prev = NULL;
	}

	void initialize_customer(string id, string fn, string ln, Gender g, string addr, string tp, string pw) {
		id_number = id;
		first_name = fn;
		last_name = ln;
		gender = g;
		address = addr;
		telephone = tp;
		password = pw;
	}

	void print_customer(short colPos, short rowPos) {
		colPos += 2;
		short colenPos = colPos + 17;
		short elemPos = colPos + 22;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "ID Number";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << id_number;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "First Name";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << first_name;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Last Name";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << last_name;
		string G;
		if (gender == male)
			G = "Male";
		else
			G = "Female";
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Gender";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << G;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Address";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << address;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Contact Number";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << telephone;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Signed Date";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		signed_in_date->printDate();
		
	}

};

class CustomerTable {
private:
	static const int size = 10;
	list<Customer_Node> table[size]; // an array of doubly linked list
	//list<Data_Item> table; // a single doubly linked list
public:

	int getHash(string key) {
		int sum = 0;
		for (int i = 0; i < key.length(); i++) {
			sum = sum + key[i];                        // key[i] returns the ASCII value of that charactor in i th index
		}
		return sum % size;
	}

	void insert(string key, Customer_Node* c) {
		int index = getHash(key);
		if (!isKeyExist(key))
			table[index].push_back(*c); // pushback is similar to the insertLast in doubly linked lists
		else
			cout << "The key already exists" << endl;
	}

	bool isKeyExist(string key) {
		int index = getHash(key);
		for (Customer_Node d : table[index]) { // for each loop in c++
			if (d.id_number == key)
				return true;
		}
		return false;
	}

	Customer_Node* search(string key) {
		int index = getHash(key);
		Customer_Node* c = new Customer_Node();
		for (Customer_Node d : table[index]) {
			if (d.id_number == key) {
				c->first_name = d.first_name;
				c->last_name = d.last_name;
				c->address = d.address;
				c->telephone = d.telephone;
				c->gender = d.gender;
				c->signed_in_date = d.signed_in_date;
				c->id_number = d.id_number;
				return c;
			}
		}
		cout << "Customer does not exist" << endl;
		return NULL;
	}

	void remove(string key) {
		if (!isKeyExist(key))
			cout << "Key does not exists" << endl;
		else {
			int index = getHash(key);
			list<Customer_Node> this_list = table[index];
			list<Customer_Node>::iterator itr = this_list.begin(); // iterator is used to iterate through each data item in the list
			while (itr != this_list.end()) {
				if (itr->id_number == key) {
					itr = this_list.erase(itr); // erase will delete the corresponding node of the list. Once the item is deleted, the iterator jumps to the next node. So we dont want to increment the iterator after a deletion
				}
				else {
					itr++;
				}
			}
			table[index] = this_list;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << "Index " << i << " : ";
			for (Customer_Node d : table[i]) {
				d.print_customer(1,2);
			}
			cout << endl;
		}
	}
};

class Customer_List {
public:
	int size;
	Customer_Node* head;
	Customer_Node* tail;

	Customer_List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void insert_new_customer(CustomerTable* t, short* rowPos){
		Customer_Node* temp = new Customer_Node(rowPos);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
		t->insert(temp->id_number, temp);
	}

	void insert_exsisting_customer(Customer_Node* c) {
		if (head == NULL) {
			head = c;
			tail = c;
			size++;
		}
		else {
			c->next = head;
			head->prev = c;
			head = c;
			size++;
		}
	}

	bool searchCustomer(string tel) {
		Customer_Node* current = head;
		if (current == NULL) {
			return false;
		}
		while (current != NULL) {
			if (current->telephone == tel) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool validateCustomer(string tel, string pw) {
		Customer_Node* current = head;
		while (current != NULL) {
			if (current->telephone == tel && current->password == pw) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	Customer_Node* getCustomer(string tel) {
		Customer_Node* current = head;
		while (current != NULL) {
			if (current->telephone == tel) {
				return current;
			}
			current = current->next;
		}
	}

	void print() {
		Customer_Node* current = head;
		while (current != NULL) {
			system("cls");
			current->print_customer(1,2);
			cout << endl;
			int i;
			cout << "Press (1) for next customer" << endl;
			cout << "Press (2) for previous customer" << endl;
			cout << "press (0) to exit" << endl;
			cout << "choice -> ";
			cin >> i;
			if (i == 1 && current->next == NULL) {
				cout << "No other customers" << endl;
				//current = current->next;
			}
			else if (i == 1) {
				current = current->next;
			}
			else if (i == 2 && current->prev == NULL) {
				cout << "No previous Customers" << endl;
			}
			else if (i == 2) {
				current = current->prev;
			}
			else if (i == 0) {
				return;
			}
			else {
				cout << "Invalid choice" << endl;
			}
			system("pause");
		}
		cout << endl;
	}

	Customer_Node* find_customer(Customer_Node cl) {
		Customer_Node* current = head;
		if (head == NULL)
			return NULL;
		else {
			while (current != NULL) {
				if (current->telephone == cl.telephone)
					return current;
				current = current->next;
			}
		}
	}

};

class Customer_Entry {
public:
	Customer_Entry* next;
	Customer_Entry* prev;
	Customer_Node* customer;
	Date* booked_from;
	Date* booked_until;
	bool is_purchased;
	bool is_booked;
	int entry_number;

	Customer_Entry() {
		next = NULL;
		prev = NULL;
		//booked_from = new Date();
		//booked_until = new Date();
	}

	Customer_Entry(Customer_Node* c, Date* bf, Date* bu) {
		customer = c;
		booked_from = bf;
		booked_until = bu;
	}
};

class Entry_Queue {
public:
	int size;
	Customer_Entry* head;
	Customer_Entry* tail;

	Entry_Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void print_entries() {
		Customer_Entry* current = head;
		string name;
		if (head == NULL) {
			cout << "No bookings..............." << endl;
		}
		else {
			cout << "----------------------------------------------------------------" << endl;
			cout << "Customer\t|\t" << "Booked From\t|\t" << "Booked Until" << endl;
			cout << "----------------------------------------------------------------" << endl;
			while (current != NULL) {
				if (current->is_booked == true) {
					name = current->customer->first_name + " " + current->customer->last_name;
					cout << name << "\t|\t";
					current->booked_from->printDate();
					cout << "\t|\t";
					current->booked_until->printDate();
					cout << endl;
				}
				current = current->next;
			}
		}
	}

	void print_unpurchased_entries(string rN, short* rowPos) {
		short row = *rowPos;
		Customer_Entry* current = head;
		string name;
		if (head == NULL) {
			return;
		}
		else {
			while (current != NULL) {
				if (current->is_booked == true && current->is_purchased==false) {
					name = current->customer->first_name + " " + current->customer->last_name;
					SetConsoleCursorPosition(hConsole, { 22,row });
					cout << rN;
					SetConsoleCursorPosition(hConsole, { 29,row });
					cout << "|";
					SetConsoleCursorPosition(hConsole, { 41,row });
					cout << name;
					SetConsoleCursorPosition(hConsole, { 60,row });
					cout << "|";
					SetConsoleCursorPosition(hConsole, { 67,row });
					cout << current->customer->id_number;
					SetConsoleCursorPosition(hConsole, { 83,row });
					cout << "|";
					SetConsoleCursorPosition(hConsole, { 87,row });
					current->booked_from->printDate();
					SetConsoleCursorPosition(hConsole, { 104,row });
					cout << "|";
					SetConsoleCursorPosition(hConsole, { 109,row });
					current->booked_until->printDate();
					row++;
				}
				current = current->next;
			}
			SetConsoleCursorPosition(hConsole, { 10,row++ });
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		}
		*rowPos = row;
	}

	int book_entries(string rN) {
		Customer_Entry* e = head;
		string c;
		short rowPos = 0;
		if (head == NULL) {
			cout << "No Bookings" << endl;
			system("pause");
			return 0;
		}
		else {
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
				SetConsoleCursorPosition(hConsole, { 60,9});
				cout << "( Type 'exit' to go back )" << endl;
				rowPos = 11;
				short temp = rowPos;
				SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
				cout << "----------------------------------------------------------" << endl;
				SetConsoleCursorPosition(hConsole, { 20,rowPos++ });
				cout << "BOOKING INFORMATION" << endl;
				SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
				cout << "----------------------------------------------------------" << endl;
				rowPos++;
				for (int j = 0; j < 10; j++) {
					SetConsoleCursorPosition(hConsole, { 70,temp++ });
					cout << "|";
				}
				temp = 13;
				SetConsoleCursorPosition(hConsole, { 80,temp++ });
				cout << "Press (1) for next entry" << endl;
				SetConsoleCursorPosition(hConsole, { 80,temp++ });
				cout << "press (2) for previous entry" << endl;
				SetConsoleCursorPosition(hConsole, { 80,temp++ });
				cout << "Press (3) to accept this request" << endl;
				SetConsoleCursorPosition(hConsole, { 80,temp++ });
				cout << "Press (4) to change room" << endl;
				if (e != nullptr) {
					if (e->is_booked == true && e->is_purchased == false) {
						SetConsoleCursorPosition(hConsole, { 10,rowPos });
						cout << "Room Number";
						SetConsoleCursorPosition(hConsole, { 25,rowPos });
						cout << ":";
						SetConsoleCursorPosition(hConsole, { 30,rowPos++ });
						cout << rN;
						SetConsoleCursorPosition(hConsole, { 10,rowPos });
						string name = e->customer->first_name + " " + e->customer->last_name;
						cout << "Customer Name";
						SetConsoleCursorPosition(hConsole, { 25,rowPos });
						cout << ":";
						SetConsoleCursorPosition(hConsole, { 30,rowPos++ });
						cout << name;
						SetConsoleCursorPosition(hConsole, { 10,rowPos });
						cout << "Booked from";
						SetConsoleCursorPosition(hConsole, { 25,rowPos });
						cout << ":";
						SetConsoleCursorPosition(hConsole, { 30,rowPos++ });
						e->booked_from->printDate();
						SetConsoleCursorPosition(hConsole, { 10,rowPos });
						cout << "Booked Until";
						SetConsoleCursorPosition(hConsole, { 25,rowPos });
						cout << ":";
						SetConsoleCursorPosition(hConsole, { 30,rowPos++ });
						e->booked_until->printDate();
						SetConsoleCursorPosition(hConsole, { 5,++rowPos});
						cout << "--------------------------------------------------------------" << endl;
						rowPos += 2;
						temp += 2;
						SetConsoleCursorPosition(hConsole, { 80,temp++ });
						cout << "Choice -- >";
						cin >> c;
						if (c == "1") {
							if (e->next != NULL)
								e = e->next;
							else {
								SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
								cout << "No other bookings for this room" << endl;
								SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
								system("pause");
							}
						}
						else if (c == "2") {
							if (e->prev != NULL)
								e = e->prev;
							else {
								SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
								cout << "No other booking for this room" << endl;
								SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
								system("pause");
							}
								
						}
						else if (c == "3") {
							e->is_purchased = true;
							SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
							cout << "Request accepted !!!" << endl;
							SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
							system("pause");
							e = e->next;
						}
						else if (c == "4") {
							return 0;
						}
						else if (c == "exit") {
							return 3;
						}
						else {
							SetConsoleCursorPosition(hConsole, { 80,temp++ });
							cout << "Invalid Option" << endl;
						}
					}
					else if(e->is_booked==true && e->is_purchased==true){
						e = e->next;
					}
				}
				else {
					SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
					cout << "No other entries" << endl;
					SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
					system("pause");
					break;
				}
				
			}
		}
	}

	void print_entries_for_customers() {
		Customer_Entry* current = head;
		if (head == NULL) {
			cout << "No bookings..............." << endl;
		}
		else {
			cout << "   Booked From\t\t|   " << "Booked Until" << endl;
			cout << "-------------------------------------------------------" << endl;
			while (current != NULL) {
				if (current->is_booked == true) {
					cout << "  ";
					current->booked_from->printDate();
					if(current->booked_from->month == March || current->booked_from->month == April || current->booked_from->month == May || current->booked_from->month == June || current->booked_from->month == July)
						cout << "\t\t|   ";
					else
						cout << "\t|   ";
					current->booked_until->printDate();
					cout << endl;
					cout << "-------------------------------------------------------" << endl;
				}
				current = current->next;
			}
		}
	}

	bool is_room_booked() {
		if (head == NULL)
			return false;
		else
			return true;
	}

	void insert_existing_entry(Customer_Entry* e) {
		e->entry_number = size + 1;
		if (head == NULL) {
			head = e;
			tail = e;
			size++;
		}
		else {
			tail->next = e;
			e->prev = tail;
			tail = e;
			size++;
		}
	}

	bool is_entry_exist(int n) {
		Customer_Entry* e = head;
		bool b = false;
		if (head == NULL) {
			return false;
		}
		else {
			while (e != NULL) {
				if (e->entry_number == n)
					b = true;
				e = e->next;
			}
		}
		return b;
	}

	void delete_entry(int n) {
		Customer_Entry* e = head;
		while (e != NULL) {
			if (e->entry_number == n) {
				if (e == head && head->next==nullptr) {
					Customer_Entry* temp = e;
					head = NULL;
					delete temp;
					return;
				}
				else if (e == head && head->next != nullptr) {
					Customer_Entry* temp = e;
					head = head->next;
					head->prev = nullptr;
					delete temp;
					return;
				}
				else if (e == tail && tail->prev!=NULL) {
					Customer_Entry* temp = e;
					tail = tail->prev;
					tail->next = nullptr;
					delete temp;
					return;
				}
				else {
					Customer_Entry* temp = e;
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
					delete temp;
					return;
				}
			}
			e = e->next;
		}
	}
};

class Comment {
public:
	string comment;
	Comment* next;
	Comment* prev;

	Comment() {
		comment = "";
		next = NULL;
		prev = NULL;
	}

	Comment(string txt) {
		comment = txt;
		next = NULL;
		prev = NULL;
	}
};

class Comment_List {
public:
	int size;
	Comment* head;
	Comment* tail;

	Comment_List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void insert_comment() {
		Comment* temp = new Comment();
		cout << "Enter your comments ;" << endl;
		cin >> temp->comment;
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void insert_existing_comment(Comment c) {
		Comment* temp = new Comment();
		temp->comment = c.comment;
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void print_comments() {
		cout << endl;
		Comment* current = head;
		if (head == NULL) {
			cout << "No reviews available" << endl;
		}
		else {
			while (current != NULL) {
				cout << "-> " << current->comment << endl;
				current = current->next;
			}
		}
		cout << endl;
	}
};

class Room:Customer_List{
public:
	string room_number;
	int number_of_beds;
	bool AC_condition;
	int price;
	Entry_Queue* entries;
	Room* next;
	Room* prev;
	string guestHouse;
	string address;
	Comment_List* comments;

	void createExistingRoom(string r_n, int n_beds, bool ac, int pr, Comment* com) {
		room_number = r_n;
		number_of_beds = n_beds;
		AC_condition = ac;
		entries = new Entry_Queue();
		price = pr;
		comments->head = com;
	}

	Room() {
		entries = new Entry_Queue();
		next = NULL;
		prev = NULL;
		price = 0;
		comments = new Comment_List();
	}

	Room(int i) {
		cout << "Room Number : ";
		cin >> room_number;
		cout << "Number of Beds : ";
		cin >> number_of_beds;
		string temp;
		while (true) {
			cout << "Type (A) for A/C and (N) for Non-A/C " << endl;
			cout << "AC or Non-AC :";
			cin >> temp;
			if (temp == "A" || temp == "a") {
				AC_condition = true;
				break;
			}
			else if (temp == "N" || temp == "n") {
				AC_condition = false;
				break;
			}
			else {
				cout << "Invalid option" << endl;
			}
		}
		cout << "Price of the room : ";
		cin >> price;
		entries = new Entry_Queue();
		comments = new Comment_List();
	}

	Room(string gh, string addr, short* rowPos) {
		short row = *rowPos;
		SetConsoleCursorPosition(hConsole, { 90,row++ });
		cout << "Room Number : ";
		cin >> room_number;
		string input;
		while (true) {
			SetConsoleCursorPosition(hConsole, { 87,row++ });
			cout << "Number of Beds : ";
			cin >> input;
			try {
				number_of_beds = stoi(input);
				break;
			}
			catch (invalid_argument&) {
				SetConsoleCursorPosition(hConsole, { 100,row++ });
				cout << "Enter a valid number" << endl;
			}
		}
		string temp;
		while (true) {
			SetConsoleCursorPosition(hConsole, { 81,row++ });
			cout << "AC (A) or Non-AC (N) : ";
			cin >> temp;
			if (temp == "A" || temp == "a") {
				AC_condition = true;
				break;
			}
			else if (temp == "N" || temp == "n") {
				AC_condition = false;
				break;
			}
			else {
				SetConsoleCursorPosition(hConsole, { 100,row++ });
				cout << "Invalid option" << endl;
			}
		}
		while (true) {
			SetConsoleCursorPosition(hConsole, { 84,row++ });
			cout << "Price of the room : ";
			cin >> input;
			try {
				price = stoi(input);
				break;
			}
			catch (invalid_argument&) {
				SetConsoleCursorPosition(hConsole, { 100,row++ });
				cout << "Enter a valid number" << endl;
			}
		}
		guestHouse = gh;
		address = addr;
		entries = new Entry_Queue();
		comments = new Comment_List();
		*rowPos = row;
	}

	Room* createNewRoom(string gh) {
		Room* tr = new Room();
		cout << "Room Number : ";
		cin >> tr->room_number;
		cout << "Number of Beds : ";
		cin >> tr->number_of_beds;
		string temp;
		while (true) {
			cout << "Type (A) for A/C and (N) for Non-A/C " << endl;
			cout << "AC or Non-AC :";
			cin >> temp;
			if (temp == "A" || temp == "a") {
				tr->AC_condition = true;
				break;
			}
			else if (temp == "N" || temp == "n") {
				tr->AC_condition = false;
				break;
			}
			else {
				cout << "Invalid option" << endl;
			}
		}
		cout << "Price of the room : ";
		cin >> tr->price;
		tr->guestHouse = gh;
		tr->entries = new Entry_Queue();
		tr->comments = new Comment_List();
		return tr;
	}

	void print_room_2() {
		string ac;
		if (AC_condition == true)
			ac = "A/C";
		else
			ac = "Non-A/C";
		short rowPos = 9;
		SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
		rowPos++;
		cout << "----------------- Room Details ---------------------" << endl;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Guest House\t: " << guestHouse;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Room Number\t: " << room_number;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Address\t\t: " << address;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "A/C Condition\t: " << ac;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Price\t\t: " << "Rs." << price;
		
		rowPos = 9;
		for (int i = 0; i < 10; i++) {
			SetConsoleCursorPosition(hConsole, { 65,rowPos++ });
			cout << "|";
		}
		rowPos = 9;
		SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
		cout << "-------------------- Customer Comments ------------------------" << endl;
		if (comments->head == nullptr) {
			SetConsoleCursorPosition(hConsole, { 75,rowPos++ });
			cout << "No comments" << endl;
		}
		else {
			Comment* temp = comments->head;
			while (temp != nullptr) {
				SetConsoleCursorPosition(hConsole, { 70,rowPos });
				cout << "-> ";
				SetConsoleCursorPosition(hConsole, { 73,rowPos++ });
				cout << temp->comment;
				temp = temp->next;
			}
		}
	}
	void print_room() {
		string ac;
		if (AC_condition == true)
			ac = "A/C";
		else
			ac = "Non-A/C";
		string key;
		while (true) {
			cout << "----------------- Room Details ---------------------" << endl;
			cout << endl;
			cout << "Guest House\t: " << guestHouse << endl;
			cout << "Room Number\t: " << room_number << endl;
			cout << "Address\t\t: " << address << endl;
			cout << "A/C Condition\t: " << ac << endl;
			cout << "Price\t\t: " << "Rs." << price << endl;
			cout << endl;
			cout << "Type 'rev' to see the customer reviews." << endl;
			cout << "Press (1) to continue" << endl;
			while (true) {
				cout << "Option\t: ";
				cin >> key;
				if (key == "rev") {
					system("cls");
					cout << "----------------------------- Customer Comments ----------------------------------" << endl;
					comments->print_comments();
					string key1;
					cout << endl;
					cout << "Press (0) to go back" << endl;
					while (true) {
						cout << "--> ";
						cin >> key1;
						if (key1 == "0") {
							system("cls");
							break;
						}
						else
							cout << "Invalid Option" << endl;
					}
					print_room();
					break;
				}
				else if (key == "1") {
					system("cls");
					cout << "-------------------------------------------------------" << endl;
					cout << "                       BOOKING                         " << endl;
					cout << "-------------------------------------------------------" << endl;
					cout << "------------------- Room Details ----------------------" << endl;
					cout << endl;
					cout << "Guest House\t: " << guestHouse << endl;
					cout << "Room Number\t: " << room_number << endl;
					cout << "Address\t\t: " << address << endl;
					cout << "A/C Condition\t: " << ac << endl;
					cout << "Price\t\t: " << "Rs." << price << endl;
					cout << endl;
					break;
				}
				else {
					cout << "Invalid Option" << endl;
				}
			}
			break;
		}
		
	}

	void print_room_in_guestHouse() {
		string ac;
		if (AC_condition == true)
			ac = "A/C";
		else
			ac = "Non-A/C";
		string key;
		while (true) {
			cout << "----------------------- Room Details ------------------------" << endl;
			cout << endl;
			cout << "Guest House\t: " << guestHouse << endl;
			cout << "Room Number\t: " << room_number << endl;
			cout << "Address\t\t: " << address << endl;
			cout << "A/C Condition\t: " << ac << endl;
			cout << "Price\t\t: " << "Rs." << price << endl;

			if (entries->is_room_booked()) {
				cout << "----------------------- Booking Details ------------------------" << endl;
				entries->print_entries();
			}
			cout << endl;
			cout << "Type 'rev' to see the customer reviews." << endl;
			cout << "Press (1) to continue browsing" << endl;
			cout << endl;
			while (true) {
				cout << "Option\t: ";
				cin >> key;
				if (key == "rev") {
					cout << "--------------------- Customer Comments ---------------------" << endl;
					comments->print_comments();
					cout << "-------------------------------------------------------------" << endl;
					cout << endl;
					break;
				}
				else if (key == "1") {
					cout << "-------------------------------------------------------------" << endl;
					cout << endl;
					break;
				}
				else {
					cout << "Invalid Option" << endl;
				}
			}
			break;
		}

	}

	void just_print_room() {
		string ac;
		if (AC_condition == true)
			ac = "A/C";
		else
			ac = "Non-A/C";
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << R"(                                         ___            _       ___                      
                                        | _ ) ___  ___ | |__   | _ \ ___  ___  _ __   ___
                                        | _ \/ _ \/ _ \| / /   |   // _ \/ _ \| '  \ (_-<
                                        |___/\___/\___/|_\_\   |_|_\\___/\___/|_|_|_|/__/)" << endl;
		cout << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		short rowPos = 9;
		SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
		rowPos++;
		cout << "----------------- Room Details ---------------------" << endl;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Guest House\t: " << guestHouse;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Room Number\t: " << room_number;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Address\t\t: " << address;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "A/C Condition\t: " << ac;
		SetConsoleCursorPosition(hConsole, { 15,rowPos++ });
		cout << "Price\t\t: " << "Rs." << price;
		SetConsoleCursorPosition(hConsole, { 5,rowPos++ });
		cout << "----------------------------------------------------" << endl;
		rowPos = 9;
		for (int i = 0; i < 15; i++) {
			SetConsoleCursorPosition(hConsole, { 65,rowPos++ });
			cout << "|";
		}
	}

};

class Customer_Node;

class Room_List:Room {
public:
	int size;
	Room* head;
	Room* tail;

	Room_List() {
		int size = 0;
		head = NULL;
		tail = NULL;
	}

	void insert_new_room() {
		Room* temp = new Room(1);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void insert_exsisting_room(Room* r) {
		Room* temp = new Room();
		temp->room_number = r->room_number;
		temp->number_of_beds = r->number_of_beds;
		temp->AC_condition = r->AC_condition;
		temp->price = r->price;
		temp->guestHouse = r->guestHouse;
		temp->address = r->address;
		temp->entries = r->entries;
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void print_free_rooms() {
		Room* current = head;
		int i = 0;
		if (head == NULL) {
			cout << "No Rooms in the list" << endl;
		}
		else {
			short rowPos = 12;
			SetConsoleCursorPosition(hConsole, { 14,rowPos });
			cout << "Guest House";
			SetConsoleCursorPosition(hConsole, { 29,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 32,rowPos });
			cout << "Room Number";
			SetConsoleCursorPosition(hConsole, { 47,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 50,rowPos });
			cout << "No.of Beds";
			SetConsoleCursorPosition(hConsole, { 63,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 67,rowPos });
			cout << "AC Condition";
			SetConsoleCursorPosition(hConsole, { 85,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 88,rowPos });
			cout << "Booked From";
			SetConsoleCursorPosition(hConsole, { 105,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 110,rowPos });
			cout << "Booked Until";
			rowPos++;
			while (current != NULL) {
				Customer_Entry* ec = current->entries->head;
				SetConsoleCursorPosition(hConsole, { 17,rowPos });
				cout << current->guestHouse;
				SetConsoleCursorPosition(hConsole, { 29,rowPos });
				cout << "|";
				SetConsoleCursorPosition(hConsole, { 37,rowPos });
				cout << current->room_number;
				SetConsoleCursorPosition(hConsole, { 47,rowPos });
				cout << "|";
				SetConsoleCursorPosition(hConsole, { 54,rowPos });
				cout << current->number_of_beds;
				SetConsoleCursorPosition(hConsole, { 63,rowPos });
				cout << "|";
				string AC = "";
				if (current->AC_condition == true)
					AC = "AC";
				else
					AC = "No";
				SetConsoleCursorPosition(hConsole, { 71,rowPos });
				cout << AC;
				SetConsoleCursorPosition(hConsole, { 85,rowPos });
				cout << "|";
				if (ec == nullptr) {
					SetConsoleCursorPosition(hConsole, { 93,rowPos });
					cout << "-";
					SetConsoleCursorPosition(hConsole, { 105,rowPos });
					cout << "|";
					SetConsoleCursorPosition(hConsole, { 115,rowPos });
					cout << "-";
				}
				else {
					while (ec != nullptr) {
						SetConsoleCursorPosition(hConsole, { 88,rowPos });
						ec->booked_from->printDate();
						SetConsoleCursorPosition(hConsole, { 105,rowPos });
						cout << "|";
						SetConsoleCursorPosition(hConsole, { 110,rowPos });
						ec->booked_until->printDate();
						rowPos++;
						ec = ec->next;
					}
				}
				rowPos++;
				current = current->next;
			}
		}
	}

	void print_booked_rooms(Customer_Node c) {
		Room* current = head;
		int i = 0;

		if (head == NULL) {
			cout << "No Rooms in the list" << endl;
		}
		else {
			short rowPos = 8;
			SetConsoleCursorPosition(hConsole, { 10,rowPos });
			cout << "Entry No.";
			SetConsoleCursorPosition(hConsole, { 22,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 30,rowPos });
			cout << "Guest House";
			SetConsoleCursorPosition(hConsole, { 47,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 50,rowPos });
			cout << "Room Number";
			SetConsoleCursorPosition(hConsole, { 62,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 68,rowPos });
			cout << "Booked from";
			SetConsoleCursorPosition(hConsole, { 85,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 92,rowPos });
			cout << "Booked Until";
			SetConsoleCursorPosition(hConsole, { 107,rowPos });
			cout << "|";
			SetConsoleCursorPosition(hConsole, { 110,rowPos });
			cout << "Purchased" << endl;
			SetConsoleCursorPosition(hConsole, { 5,9 });
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
			rowPos = 11;
			while (i<size) {
				Customer_Entry* e = current->entries->head;
				if (e == NULL) {
					current = current->next;
					i++;
					continue;
				}
				else {
					while (e != NULL) {
						if (e->is_booked == true && e->customer->telephone==c.telephone) {
							string purchase;
							if (e->is_purchased == true)
								purchase = "Purchased";
							else
								purchase = "No";
							SetConsoleCursorPosition(hConsole, { 13,rowPos });
							cout << e->entry_number;
							SetConsoleCursorPosition(hConsole, { 22,rowPos });
							cout << "|";
							SetConsoleCursorPosition(hConsole, { 33,rowPos });
							cout << current->guestHouse;
							SetConsoleCursorPosition(hConsole, { 47,rowPos });
							cout << "|";
							SetConsoleCursorPosition(hConsole, { 54,rowPos });
							cout << current->room_number;
							SetConsoleCursorPosition(hConsole, { 62,rowPos });
							cout << "|";
							SetConsoleCursorPosition(hConsole, { 66,rowPos });
							e->booked_from->printDate();
							SetConsoleCursorPosition(hConsole, { 85,rowPos });
							cout << "|";
							SetConsoleCursorPosition(hConsole, { 89,rowPos });
							e->booked_until->printDate();
							SetConsoleCursorPosition(hConsole, { 107,rowPos });
							cout << "|";
							SetConsoleCursorPosition(hConsole, { 114,rowPos });
							cout << purchase;
							rowPos++;
						}
						e = e->next;
					}
				}
				current = current->next;
				i++;
			}
			cout << endl;
		}
		SetConsoleCursorPosition(hConsole, { 5,17 });
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}

	Room* find_room(Room r) {
		Room* current = head;
		if (head == NULL)
			return NULL;
		else {
			while (current != NULL) {
				if (current->guestHouse == r.guestHouse && current->room_number == r.room_number)
					return current;
				current = current->next;
			}
			cout << "Room does not exist" << endl;
			return NULL;
		}
	}

	Room* find_room(string rN, string gH) {
		Room* current = head;
		if (head == NULL)
			return NULL;
		else {
			while (current != NULL) {
				if (current->room_number == rN && current->guestHouse == gH)
					return current;
				current = current->next;
			}
		}
	}

	bool isRoomExists(string rN, string gH) {
		Room* current = head;
		if (head == NULL)
			return NULL;
		else {
			while (current != NULL) {
				if (current->room_number==rN && current->guestHouse==gH)
					return true;
				current = current->next;
			}
			return false;
		}
	}

	Room* getRoom(string rN, string gH) {
		Room* current = head;
		if (head == NULL)
			return NULL;
		else {
			while (current != NULL) {
				if (current->room_number == rN && current->guestHouse == gH)
					return current;
				current = current->next;
			}
		}
	}

	Room_List* returnAllRoomsWithThatCustomer(Customer_Node* c) {
		Room_List* lst = new Room_List();
		Room* current = head;
		if (head == NULL) {
			return NULL;
		}
		else {
			while (current != NULL) {
				Customer_Entry* e = current->entries->head;
				if (e == NULL) {
					current = current->next;
					continue;
				}
				else {
					while (e != nullptr) {
						if (e->customer->telephone == c->telephone) {
							lst->insert_exsisting_room(current);
						}
						e = e->next;
					}
				}
				current = current->next;	
			}
		}
		return lst;
	}

	Room_List* roomsInThatArea(string place) {
		Room_List* sorted_rl = new Room_List();
		Room* current = head;
		int i = 0;
		if (head == NULL) {
			cout << "Empty" << endl;
		}
		else {
			while (i<size) {
				if (current->address==place)
					sorted_rl->insert_exsisting_room(current);
				current = current->next;
				i++;
			}
		}
		return sorted_rl;
	}
};

class Owner_Node {
public:
	string id_number;
	string first_name;
	string last_name;
	Gender gender;
	string address;
	string telephone;
	Date* signed_in_date;
	string guest_house;
	string password;
	Owner_Node* next;
	Owner_Node* prev;
	
	

	Owner_Node(short* colPos, short* rowPos) {
		short row = *rowPos + 1;
		short col = *colPos;
		SetConsoleCursorPosition(hConsole, { 25,row++ });
		cout << "ID Number : ";
		cin >> id_number;
		SetConsoleCursorPosition(hConsole, { 24,row++ });
		cout << "First Name : ";
		cin >> first_name;
		SetConsoleCursorPosition(hConsole, { 25,row++ });
		cout << "Last Name : ";
		cin >> last_name;
		string G;
		while (true) {
			SetConsoleCursorPosition(hConsole, { 5,row++ });
			cout << "Gender (Male - M, Female - F) : ";
			cin >> G;
			if (G == "M" || G == "m") {
				gender = male;
				break;
			}
			else if (G == "F" || G == "f") {
				gender = female;
				break;
			}
			else {
				SetConsoleCursorPosition(hConsole, { 37,row++ });
				cout << "Invalid" << endl;
			}
		}
		SetConsoleCursorPosition(hConsole, { 27,row++ });
		cout << "Address : ";
		cin >> address;
		SetConsoleCursorPosition(hConsole, { 20,row++ });
		cout << "Contact Number : ";
		cin >> telephone;
		SetConsoleCursorPosition(hConsole, { 18,row++ });
		cout << "Enter a password : ";
		cin >> password;
		signed_in_date = new Date();
		next = NULL;
		prev = NULL;
		*rowPos = row;
	}

	Owner_Node() {
		signed_in_date = new Date();
	}

	void initialize_owner(string id, string fn, string ln, Gender g, string addr, string tp, string pw) {
		id_number = id;
		first_name = fn;
		last_name = ln;
		gender = g;
		address = addr;
		telephone = tp;
		password = pw;
	}

	void print_owner(short colPos, short rowPos) {
		colPos += 2;
		short colenPos = colPos + 17;
		short elemPos = colPos + 22;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "ID Number";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << id_number;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "First Name";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << first_name;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Last Name";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << last_name;
		string G;
		if (gender == male)
			G = "Male";
		else
			G = "Female";
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Gender";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << G;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Address";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << address;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Contact Number";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << telephone;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Guest House";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << guest_house;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Signed Date";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		signed_in_date->printDate();


	}
};

class Owner_List {
public:
	int size;
	Owner_Node* head;
	Owner_Node* tail;

	Owner_List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void insert_new_owner() {
		Owner_Node* temp = new Owner_Node();
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void insert_exsisting_owner(Owner_Node c) {
		Owner_Node* temp = new Owner_Node();
		temp->id_number = c.id_number;
		temp->first_name = c.first_name;
		temp->last_name = c.last_name;
		temp->address = c.address;
		temp->gender = c.gender;
		temp->telephone = c.telephone;
		temp->password = c.password;
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void insert_exsisting_owner(Owner_Node* o) {
		if (head == NULL) {
			head = o;
			tail = o;
			size++;
		}
		else {
			o->next = head;
			head->prev = o;
			head = o;
			size++;
		}
	}

	bool searchOwner(string tel) {
		Owner_Node* current = head;
		if (head == NULL) {
			return false;
		}
		while (current != NULL) {
			if (current->telephone == tel) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool validateOwner(string tel, string pw) {
		Owner_Node* current = head;
		while (current != NULL) {
			if (current->telephone == tel && current->password == pw) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	Owner_Node* getOwner(string tel) {
		Owner_Node* current = head;
		while (current != NULL) {
			if (current->telephone == tel) {
				return current;
			}
			current = current->next;
		}
	}

	void print() {
		Owner_Node* current = head;
		while (current != NULL) {
			system("cls");
			current->print_owner(1,2);
			cout << endl;
			int i;
			cout << "Press (1) for next owner" << endl;
			cout << "Press (2) for previous owner" << endl;
			cout << "press (0) to exit" << endl;
			cin >> i;
			if (i == 1 && current->next == NULL) {
				cout << "No other owners" << endl;
			}
			else if (i == 1) {
				current = current->next;
			}	
			else if (i == 2 && current->prev == NULL) {
				cout << "No previous owners" << endl;
			}
			else if (i == 2) {
				current = current->prev;
			}
			else if (i == 0) {
				return;
			}
			else {
				cout << "Invalid choice" << endl;
			}
			//system("pause");
		}
		cout << endl;
	}
};

class Guest_House {
public:
	string name;
	int number_of_rooms;
	string contact_number;
	string email;
	string address;
	Room** rooms;
	Owner_List* owners;
	Guest_House* next;
	Guest_House* prev;
	string password;

	Guest_House(Owner_Node* o, Room_List* lr, short* rowPos) {
		short row = *rowPos;
		SetConsoleCursorPosition(hConsole, { 80,row++ });
		cout << "Guest House Name : ";
		cin >> name;
		string input;
		while (true) {
			SetConsoleCursorPosition(hConsole, { 81,row++ });
			cout << "Number of Rooms : ";
			cin >> input;
			try {
				number_of_rooms = stoi(input);
				break;
			}
			catch (invalid_argument&) {
				SetConsoleCursorPosition(hConsole, { 96,row++ });
				cout << "Enter a valid number" << endl;
			}
		}
		SetConsoleCursorPosition(hConsole, { 82,row++ });
		cout << "Contact number : ";
		cin >> contact_number;
		SetConsoleCursorPosition(hConsole, { 90,row++ });
		cout << "E-mail : ";
		cin >> email;
		SetConsoleCursorPosition(hConsole, { 89,row++ });
		cout << "Address : ";
		cin >> address;
		SetConsoleCursorPosition(hConsole, { 89,row++ });
		cout << "Password : ";
		cin >> password;
		rooms = new Room * [number_of_rooms];
		row++;
		SetConsoleCursorPosition(hConsole, { 90,row++ });
		cout << "Enter the rooms details ;" << endl;
		SetConsoleCursorPosition(hConsole, { 75,row++ });
		cout << "------------------------------------------------------" << endl;
		for (int i = 0; i < number_of_rooms; i++) {
			rooms[i] = new Room(name, address, &row);
			lr->insert_exsisting_room(rooms[i]);
			SetConsoleCursorPosition(hConsole, { 75,row++ });
			cout << "------------------------------------------------------" << endl;
		}
		owners = new Owner_List();
		owners->head = o;
		o->guest_house = name;
	}

	Guest_House() {
		owners = new Owner_List();
		next = NULL;
		prev = NULL;
	}

	void initialize_guestHouse(string nm, int nRooms, string tp, string mail, string addr, Room** rms, Owner_Node* o, Owner_List* ol, string pw) {
		name = nm;
		number_of_rooms = nRooms;
		password = pw;
		contact_number = tp;
		email = mail;
		address = addr;
		rooms = rms;
		for (int i = 0; i < nRooms; i++) {
			rooms[i]->guestHouse = name;
			rooms[i]->address = addr;
		}
		o->guest_house = nm;
		Owner_Node* own = new Owner_Node();
		own->first_name = o->first_name;
		own->last_name = o->last_name;
		own->address = o->address;
		own->gender = o->gender;
		own->id_number = o->id_number;
		own->guest_house = o->guest_house;
		owners->insert_exsisting_owner(own);
	}

	void print_guestHouse(short colPos, short rowPos) {
		colPos += 2;
		short colenPos = colPos + 22;
		short elemPos = colPos + 27;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Guest House name";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << name;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Address";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << address;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "Contact number";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << contact_number;
		SetConsoleCursorPosition(hConsole, { colPos,rowPos });
		cout << "E-mail";
		SetConsoleCursorPosition(hConsole, { colenPos,rowPos });
		cout << ":";
		SetConsoleCursorPosition(hConsole, { elemPos,rowPos++ });
		cout << email;
	}

};

class GuestHouse_List {
public:
	int size;
	Guest_House* head;
	Guest_House* tail;

	GuestHouse_List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void insert_new_guestHouse(Owner_Node* o, Room_List* lr, short* rowPos) {
		Guest_House* temp = new Guest_House(o,lr, rowPos);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void insert_exsisting_guestHouse(Guest_House g) {
		Guest_House* temp = new Guest_House();
		temp->name = g.name;
		temp->number_of_rooms = g.number_of_rooms;
		temp->contact_number = g.contact_number;
		temp->address = g.address;
		temp->email = g.email;
		temp->rooms = g.rooms;
		temp->owners = g.owners;
		temp->password = g.password;
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void addOwner(Owner_Node* o) {
		short rowPos = 14;
		SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
		cout << "Available Guest Houses " << endl;
		print(&rowPos);
		string gh, code;
		while (true) {
			SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
			cout << "Enter the Guest House Name : ";
			cin >> gh;
			if (isGuestHouseExist(gh)) {
				break;
			}
			else if (gh == "exit")
				return;
			else {
				SetConsoleCursorPosition(hConsole, { 80,rowPos++ });
				cout << "Invalid Name" << endl;
			}
		}
		while (true) {
			SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
			cout << "Enter the Guest House Password : ";
			cin >> code;
			Guest_House* current = head;
			while (current != NULL) {
				if (current->name == gh && current->password == code) {
					break;
				}
				current = current->next;
			}
			if (gh == "exit")
				return;
			else if (current == nullptr) {
				SetConsoleCursorPosition(hConsole, { 70,rowPos++ });
				cout << "Invalid Password : ";
			}
			break;
		}
		Guest_House* current = head;
		while (current != NULL) {
			if (current->name == gh) {
				current->owners->insert_exsisting_owner(*o);
				o->guest_house = current->name;
			}
			current = current->next;
		}
		cout << endl;
	}

	void print(short* rowPos) {
		short row = *rowPos;
		Guest_House* current = head;
		while (current != NULL) {
			SetConsoleCursorPosition(hConsole, { 80,row++ });
			cout << "--> " <<  current->name << endl;
			current = current->next;
		}
		*rowPos = row+1;
	}

	Guest_House* findGuestHouse(GuestHouse_List* gh, string gName) {
		Guest_House* current = head;
		if (head == NULL)
			return NULL;
		else {
			while (current != NULL) {
				if (current->name == gName)
					return current;
				else {
					cout << "Room does not exist" << endl;
					return NULL;
				}
				current = current->next;
			}
		}
	}

	bool isGuestHouseExist(string gName) {
		Guest_House* current = head;
		if (head == NULL) {
			cout << "No Guest Houses" << endl;
			return NULL;
		}
		else {
			while (current != NULL) {
				if (current->name == gName)
					return true;
				current = current->next;
			}
			return false;
				
		}
	}

	Guest_House* returnGuestHouse(string oName) {
		Guest_House* currentgH = head;
		while (currentgH != NULL) {
			Owner_Node* o = currentgH->owners->head;
			if (currentgH->owners->head == NULL) {
				currentgH = currentgH->next;
				continue;
			}
			while (o != NULL) {
				if (o->first_name == oName)
					return currentgH;
				o = o->next;
			}
			currentgH = currentgH->next;
		}
	}

	bool isGuestHouseExistInThisArea(string place) {
		Guest_House* current = head;
		if (head == NULL) {
			cout << "No Guest Houses" << endl;
			return NULL;
		}
		else {
			while (current != NULL) {
				if (current->address==place)
					return true;
				current = current->next;
			}
			return false;

		}
	}

	void print_areas() {
		short rowPos = 11;
		Guest_House* current = head;
		while (current != nullptr) {
			SetConsoleCursorPosition(hConsole, { 40,rowPos++ });
			cout << "\t\t\t-> " << current->address << endl;
			current = current->next;
		}
	}

};



