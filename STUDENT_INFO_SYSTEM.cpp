/*
Agantal, Abdul Azis M.
Bachelor of Science in Computer Science
University of the Philippines Mindanao

This program is a student information system that takes the data of a student and saves them in a linked list using classes. 
THe main function of the program is to: Add student information, Update student information, delete student information, sort student list, display student information
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<conio.h>
#include<string>
#include<sstream>
#include<time.h>
using namespace std; //not advisable to use 


//This is the NODE class for the student (STUDENT NODE)
class Node {
	private:
		string StudentNumber;
		string LastName;
		string FirstName;
		string MiddleName;
		string Course;
		string Seniority;
		string Standing;
		int BirthYear;
		int BirthMonth;
		int BirthDay;
		int Age;		
		double Gwa;
		
		// This is only used when updating the date of birth
		string Birthdate; 
		char ch; 
		
		
	public:
		Node *next;
		
		//Constructors
		Node();
		Node(string s, string l, string f, string md, string c, int y, int m, int d, double g) {
			set_StudentNumber(s);
			set_LastName(l);
			set_FirstName(f);
			set_MiddleName(md);
			set_Course(c);
			set_Age(y,m,d);
			set_Seniority(s);
			set_Standing(g);
		}
			
		//Start of Mutator Methods
		void set_StudentNumber(string s) {
			StudentNumber = s;	
		}
		
		void set_LastName(string l) {
			LastName = l;
		}
		
		void set_FirstName(string f) {
			FirstName = f;
		}
		
		void set_MiddleName(string md) {
			MiddleName = md;
		}
		
		void set_Course(string c) {
			Course = c;
		}
		
		void set_Age(int y, int m, int d) {
			BirthYear = y;
			BirthMonth = m;
			BirthDay = d;
			//Calculate current time using time.h
			time_t now = time(0);
			tm *ltm = localtime(&now);
			//current year
			int current_year = 1900 + ltm->tm_year;
			//current month
			int current_month = 1 + ltm->tm_mon;
			//current day
			int current_day = ltm->tm_mday;
		    if(BirthMonth > current_month){
			    current_year = current_year - 1;
			}  
		    Age = current_year - BirthYear;
		}
		
		void set_Seniority(string s) {
			//s variable pertains to the student number
			char bin[4]; //This will store the first 4 characters of the student number
			int year; //This is where we'll save the converted 4 characters to 4 ints  
			for (int i=0; i < 4; i++) {
				bin[i] = s[i]; //Silces the string into 4 chars
			}
			//converts the characters to integer using streams
			std::istringstream(bin) >> year;
			
			if (year == 2019) Seniority = "1st Year";
			else if (year == 2018) Seniority = "2nd Year";  
			else if (year == 2017) Seniority = "3rd Year";
			else if (year <= 2016 && year >= 2010) Seniority = "4th Year"; //We assume that all student number with a year from 2010 to 2016 are 4th year students
			else Seniority = "Invalid Student Number";
		}
		
		void set_Standing(double g) {
			Gwa = g;
			if (Gwa > 3) Standing = "Fail";
			else if (Gwa <= 1) Standing = "Invalid Gwa";
			else if (Gwa > 1 && Gwa <= 1.20) Standing = "Summa cum laude";
			else if (Gwa > 1.20 && Gwa <= 1.45) Standing = "Magna cum laude";
			else if (Gwa > 1.45 && Gwa <= 1.75) Standing = "Cum laude";
			else Standing= "Pass";
		}
		//End of Mutator Methods
		
		//Start of Accessor Methods
		string get_StudentNumber() {
			return StudentNumber;
		}
		
		string get_LastName() {
			return LastName;
		}
		
		string get_FirstName() {
			return FirstName;
		}
		
		string get_MiddleName() {
			return MiddleName;
		}
		
		string get_Course() {
			return Course;
		}
		
		string get_Seniority() {
			return Seniority;
		}
		
		string get_Standing() {
			return Standing;
		}
		
		int get_Age() {
			return Age;
		}
		
		double get_Gwa() {
			return Gwa;
		}
		//End of Accessor Methods
		
		//Utility Methods
		//Update Info of Student
		void Update_StudentNumber() {
			cout << "Existing Student Number: " << StudentNumber << endl;
			cout << "New Student Number (Format: 20XX-XXXXX): ";
			fflush(stdin);
			getline(cin, StudentNumber);
			set_Seniority(StudentNumber);
		}
		
		void Update_LastName() {	
			cout << "Existing Last Name: " << LastName << endl;
			cout << "New Last Name: ";
			fflush(stdin);
			getline(cin, LastName);
			cout << endl;
		}
		
		void Update_FirstName() {	
			cout << "Existing First Name: " << FirstName << endl;
			cout << "New First Name: ";
			fflush(stdin);
			getline(cin, FirstName);
			cout << endl;
		}
		
		void Update_MiddleName() {	
			cout << "Existing Middle Name: " << MiddleName << endl;
			cout << "New Middle Name: ";
			fflush(stdin);
			getline(cin, MiddleName);
			cout << endl;
		}
				
		void Update_Course() {	
			cout << "Existing Course: " << Course << endl;
			cout << "New Course: ";
			fflush(stdin);
			getline(cin, Course);
			cout << endl;
		}
	
		void Update_Birthdate() {
			cout << "Age: " << get_Age() << endl;
			cout << "Existing Date of Birth: " << BirthYear << "-" << BirthMonth << "-" << BirthDay << endl;
			cout << "New Date of Birth (Format: YYYY-MM-DD): ";
			fflush(stdin);
			cin >> Birthdate; // input can be 2005-03-09 or 2005/04/02 
			stringstream ss(Birthdate);
			ss >> BirthYear >> ch >> BirthMonth >> ch >> BirthDay;
			set_Age(BirthYear, BirthMonth, BirthDay);
		}
		
		void Update_Gwa() {
			cout << "Existing GWA: " << Gwa << endl;
			cout << "New GWA: ";
			fflush(stdin);
			cin >> Gwa;
			set_Standing(Gwa);
		}
		
		//Print Student Information
		void print_info() {
			cout << get_StudentNumber() << endl;
			cout << "Name: " << get_LastName() << ", ";
			cout << get_FirstName() << " ";
			cout << get_MiddleName() << endl;
			cout << "Course: " << get_Course() << endl;
			cout << "Age: " << get_Age() << " years old" << endl;
			cout << "Seniority: " << get_Seniority() << endl;
			cout << "Standing: " << get_Gwa() << " - " << get_Standing() << endl <<endl; 	
		}		
		
};


class List {
	
	public:
		Node *head;  
		
		//Constructor
		List() {
			head = NULL;
		}	
		List(Node *n) {
			head = n;
		} 
		
		//Destructor
		~List () { 
			//Destroy the list 
		    Node *ptr = head;
		    Node *next;
		    while (ptr != NULL) {
		        next = ptr->next;
		        delete ptr;
		        ptr = next;
		    }
		}
		
		//Accessor method to read number of elements in the list
		int getCount() {
			int count = 0;
			Node *temp;
			temp = head;
			while (temp != NULL) {
				count++;
				temp = temp->next; 
			}
			return count;
		}
		
		//Check if node exists using Student Number
		Node *nodeExists(string k) {
			Node *temp = NULL;
			Node *ptr = head;
			while (ptr != NULL) { 
				if (ptr->get_StudentNumber() == k) {
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		//Start of Mutator Methods
		//Insert node in ascending order by Student Number
		void InsertNode(Node *n) {
			
			Node *ptr = head;
			Node *ptr2 = head;
			
			if(nodeExists(n->get_StudentNumber()) != NULL) { //This condition checks if the node exist in the list 
				cout << "Student Number Already Exist!" << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			} 
			//Insert Node in the head of the List if the list is empty
			if (head == NULL) {
				head = n;
				cout << endl << "Student Number "<< n->get_StudentNumber() << " is added!" <<endl << endl;
				cout << "Press any key to continue...";
				getch();
			} else {
				
				//If there is a node or nodes in the list
				//Insert Node in Ascending Order by Student Number 
				int CurrentStudent, NewStudent; // The two student number that will be compared will be stored here as an integer type
				std::string s1 (ptr->get_StudentNumber()); 
				std::string s2 (n->get_StudentNumber());
				s1.erase(4,1); // removes the hyphen '-' sign in the string 
				s2.erase(4,1); // removes the hyphen '-' sign in the string
				std::istringstream(s1) >> CurrentStudent; // convert s1 to int and saved to CurrentStudent
				std::istringstream(s2) >> NewStudent; // convert s2 to int and saved to NewStudent
				
				//When the new NODE < Current NODE 	- When the new node have less in value compared to the current node e.g newnode = 2018-xxxx, current = 2019-xxxx
				//Put the node in the beginning of the list always 
				if (CurrentStudent > NewStudent) {
					n->next = head; 
					head = n;
					cout << endl << "Student Number "<< n->get_StudentNumber() << " is added!" <<endl << endl;
					cout << "Press any key to continue...";
					getch();
					return;
				} 
				//When the new NODE > Current NODE - When the new node have more in value compared to the current node e.g newnode = 2019-xxxx, current = 2018-xxxx
				Node *ptr2; //This node pointer will get address of the node with the greatest value
				while (ptr != NULL) {
					if (CurrentStudent < NewStudent) {
						ptr2 = ptr;
					}
					ptr = ptr->next;
					if (ptr != NULL) {
						std::string s1 (ptr->get_StudentNumber());
						s1.erase(4,1);
						std::istringstream(s1) >> CurrentStudent;
					}	
				}
				n->next = ptr2->next;
				ptr2->next = n;
				cout << endl << "Student Number "<< n->get_StudentNumber() << " is added!" <<endl << endl;
				cout << "Press any key to continue...";
				getch();			
			}
		}
		
		//Deletes the Student NODE from the list by the given Student Number input
		void DeleteNode(string k) {
			//If there is no node in the list
			if (head == NULL) {
				cout << endl << "There is no list to delete." << endl << endl;
				cout << "Press any key to continue...";
				getch();
			}
			//If the node does not exist
			else if (nodeExists(k) == NULL) { 
				cout << endl << "The student number " << k << " does not exist in the list." << endl << endl;
				cout << "Press any key to continue...";
				getch();
			}
			else {
				Node *temp = head;
				Node *ptr = head;
				//If there is only NODE with the student number specified
				if(temp != NULL && (temp->get_StudentNumber() == k)) {
					head = temp->next;
					free(temp); //Free memory
					cout << endl << "Student number " << k << " is removed from the list" << endl << endl;
					cout << "Press any key to continue...";
					getch();
					return;
				}
				//If there are multiple NODES -- the pointer temp will find the variable to delete
				while (temp != NULL && (temp->get_StudentNumber() != k)) {
					ptr = temp;
					temp = temp->next;
				}
				//unlink the node temp (the node with the given student number) from the list
				ptr->next = temp->next;
				free(temp); //Free memory
				cout << endl << "Student number " << k << " is removed from the list" << endl << endl;
				cout << "Press any key to continue...";
				getch();
			}
		}
		
		//Sorts the list in ascending order by student number (Default)
		void SortStudentNumber() {
			Node *pList = head;
			Node * pNew = NULL;       /* sorted list */
			Node **ppNode;            /* ptr to ptr to Node */
			Node **ppLargest;         /* ptr to ptr to largest Node */
			Node * pLargest;          /* ptr to largest Node */
			
			//If list is empty
			if (pList == NULL) {
				cout << endl << "List is empty" << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			}
			//if there is only one node in the list
			if (pList->next == NULL) {
				cout << endl << "There is only one student in the list" << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			}
			//If there are multiple nodes in the list
			while(pList != NULL){  
				//This node pointer will find the address of the node with the largest value    
				ppLargest = &pList;    
				ppNode = &((*ppLargest)->next);
				while(NULL != *ppNode){
					int CurrentStudent, NewStudent; // The two student number in int that will be compared will be stored here
					std::string s1 ((*ppNode)->get_StudentNumber()); 
					std::string s2 ((*ppLargest)->get_StudentNumber());
					s1.erase(4,1); // removes the hyphen '-' sign in the string
					s2.erase(4,1); // removes the hyphen '-' sign in the string
					std::istringstream(s1) >> CurrentStudent; // convert s1 to int and saved to CurrentStudent
					std::istringstream(s2) >> NewStudent; // convert s2 to int and saved to NewStudent
							
				    if(CurrentStudent > NewStudent)
					ppLargest = ppNode;
				    ppNode = &((*ppNode)->next);
				}
				pLargest = *ppLargest;          
				*ppLargest = pLargest->next;
				pLargest->next = pNew;
				pNew = pLargest;
			}   
			head = pNew; //The new sorted list will be saved to the main pointer node of the list
			cout << endl << "Students are sorted by Student Number!" << endl << endl;
			cout << "Press any key to continue...";
			getch();	
		}
	
		//Sorts the list in ascending order by Last Name 
		void SortLastName() {
			Node *pList = head;
			Node * pNew = NULL;      /* sorted list */
			Node **ppNode;           /* ptr to ptr to Node */
			Node **ppLargest;        /* ptr to ptr to largest Node */
			Node * pLargest;         /* ptr to largest Node */
			
			//If list is empty
			if (pList == NULL) {
				cout << endl << "List is empty" << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			}
			//if there is only one node in the list
			if (pList->next == NULL) {
				cout << endl << "There is only one student in the list" << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			}
			//If there are multiple nodes in the list
			while(pList != NULL){   
				//This node pointer will find the address of the node with the largest value                
				ppLargest = &pList;            
				ppNode = &((*ppLargest)->next);
				while(NULL != *ppNode){
					//The nodes by default will compare the Last Names
					string a = (*ppNode)->get_LastName();
					string b = (*ppLargest)->get_LastName();
					std::transform(a.begin(), a.end(), a.begin(), ::toupper); // This will uppercase all letters in string A
					std::transform(b.begin(), b.end(), b.begin(), ::toupper); // This will uppercase all letters in string A
					if(strcmp(a.c_str(), b.c_str()) == 0) { //if the last names are equal
						string a = (*ppNode)->get_FirstName(); 
						string b = (*ppLargest)->get_FirstName();
						std::transform(a.begin(), a.end(), a.begin(), ::toupper); // This will uppercase all letters in string A
						std::transform(b.begin(), b.end(), b.begin(), ::toupper); // This will uppercase all letters in string A
						if (strcmp(a.c_str(), b.c_str()) > 0) ppLargest = ppNode;
					} else if (strcmp(a.c_str(), b.c_str()) > 0) ppLargest = ppNode;
				    ppNode = &((*ppNode)->next); 
				}
				pLargest = *ppLargest;         
				*ppLargest = pLargest->next;
				pLargest->next = pNew;
				pNew = pLargest;
			}   
			head = pNew; //The new sorted list will be saved to the main pointer node of the list
			cout << endl << "Students are sorted by Last Name!" << endl << endl;
			cout << "Press any key to continue...";
			getch();	
		}
		
		//Sorts the list in ascending order by GWA
		void SortGwa() {
			Node *pList = head;
			Node * pNew = NULL;     /* sorted list */
			Node **ppNode;          /* ptr to ptr to Node */
			Node **ppLargest;       /* ptr to ptr to largest Node */
			Node * pLargest;        /* ptr to largest Node */
			
			//If list is empty
			if (pList == NULL) {
				cout << endl << "List is empty" << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			}
			//if there is only one node in the list
			if (pList->next == NULL) {
				cout << endl << "There is only one student in the list" << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			}
			//If there are multiple nodes in the list
			while(pList != NULL){ 
				//This node pointer will find the address of the node with the largest value                 
				ppLargest = &pList;             
				ppNode = &((*ppLargest)->next);			
				while(NULL != *ppNode) {	
					//If the gwas are equal, get the last name instead 
					if ((*ppNode)->get_Gwa() == (*ppLargest)->get_Gwa()) {
						string a = (*ppNode)->get_LastName();
						string b = (*ppLargest)->get_LastName();
						std::transform(a.begin(), a.end(), a.begin(), ::toupper); // This will uppercase all letters in string A
						std::transform(b.begin(), b.end(), b.begin(), ::toupper); // This will uppercase all letters in string A
						if (strcmp(a.c_str(), b.c_str()) > 0) ppLargest = ppNode;
					} else if ((*ppNode)->get_Gwa() > (*ppLargest)->get_Gwa()) ppLargest = ppNode; //If the gwas are not equal
				    ppNode = &((*ppNode)->next);					
				} 
				pLargest = *ppLargest;         
				*ppLargest = pLargest->next;
				pLargest->next = pNew;
				pNew = pLargest;
			   
			}
			head = pNew; //The new sorted list will be saved to the main pointer node of the list
			cout << endl << "Students are sorted by GWA!" << endl << endl;
			cout << "Press any key to continue...";
			getch();	
		}
		//End of Mutator Methods
		
		//Updates the information of a student node given a student number
		void updateStudent(string k) {
			Node *temp = head;
			char ans; // user input
			int opt; // user input 
			int flag = 0; //This will determine if there is an existing record of the given student number
			
			//If the list is empty
			if (temp == NULL) {
				cout << "List is empty." << endl  << endl;
			} else {
				//If there are multiple nodes
				while (temp != NULL) {
					//If the student number given matches with one of the nodes in the list
					if (temp->get_StudentNumber() == k) {
						flag++;
						do {
							system("CLS");
							temp->print_info(); //prints the student node of the given student number
							cout << "Update Student" <<endl <<endl;
							cout << "[1]Student Number" << endl;
							cout << "[2]Last Name" << endl;
							cout << "[3]First Name" << endl;
							cout << "[4]Middle Name" << endl;
							cout << "[5]Course" << endl;
							cout << "[6]Date of Birth" << endl;
							cout << "[7]Gwa" << endl << endl;
							cout << "Option: ";
							cin >> opt;
							cout << endl;
							
							switch(opt) {
								case 1: {
									temp->Update_StudentNumber();
									cout << endl;
									temp->print_info();
									break;
								}
								case 2: {
									temp->Update_LastName();
									cout << endl;
									temp->print_info();
									break;
								}
								case 3: {
									temp->Update_FirstName();
									cout << endl;
									temp->print_info();
									break;
								}
								case 4: {
									temp->Update_MiddleName();
									cout << endl;
									temp->print_info();
									break;
								}
								case 5: {
									temp->Update_Course();
									cout << endl;
									temp->print_info();
									break;
								}
								case 6: {
									temp->Update_Birthdate();
									cout << endl;
									temp->print_info();
									break;
								}
								case 7: {
									temp->Update_Gwa();
									cout << endl;
									temp->print_info();
									break;
								}
							}
							cout << "Successfully Updated!" << endl;
							cout << endl << "Again [y/n]: ";
							cin >> ans;
						} while (ans == 'Y' || ans == 'y');
					}
					temp = temp->next;
				}
				//If there is no existing record of the given student number
				if(temp == NULL && flag == 0) cout << "No existing record with the given student number." << endl << endl;
			}
			cout << "Press any key to continue...";
			getch();	
		}
		
		//Utility Method
		//Prints the list of students - uses the print info method in the student class to print every student node
		void printlist() {
			//If the list is empty
			if(head == NULL) {
				cout << "List is empty." << endl << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			} 	else {
				if (head->next == NULL) cout << "There is only "<< getCount() << " student in the list." << endl << endl;
				else cout << "There are "<< getCount() << " students in the list." << endl << endl;
				Node *temp = head;
				while (temp != NULL) {
					temp->print_info();
					temp = temp->next;
				}
			}
			cout << "Press any key to continue...";
			getch();	
		}
			
};








int main() {
	
	//User-defined Variables
	string num, Lname, Fname, Mname, Course, Birthdate; double Gwa; 	
	char ch; //This is used for the birthday '-' separator 
 	int Year, Month, Day; // Date of Birth YYYY-MM-DD
	
	int option;
	List mylist; //This is the list object called mylist

	do {
	
		cout << "STUDENT INFORMATION SYSTEM" << endl << endl;
		cout << "[1]Add a Student" << endl;
		cout << "[2]Update Student Information" << endl;
		cout << "[3]Remove a Student" << endl;
		cout << "[4]Sort List" << endl;
		cout << "[5]Display Students" << endl;
		cout << "[6]Exit" << endl << endl;
		cout << "Option: ";
		cin >> option;
		cout << endl;
		switch(option) {
			case 1:  {
				//User input (getline function is used here to read the space character of the input e.g Juan Cruz)
				fflush(stdin);
				cout << "Student Number (Format: 20XX-XXXXX): ";
				getline(cin, num);
				cout << "Last Name: ";
				getline(cin, Lname); 
				cout << "First Name: ";
				getline(cin, Fname);
				cout << "Middle Name: ";
				getline(cin, Mname);
				cout << "Course: ";
				getline(cin, Course);
				cout << "Date of Birth (Format: YYYY-MM-DD): ";
				cin >> Birthdate; // input can be 2005-03-09 or 2005/04/02 
				stringstream ss(Birthdate);
				ss >> Year >> ch >> Month >> ch >> Day;
				cout << "GWA: ";
				cin >> Gwa;
				//End of User input
				
				//Create new Node to be added in the List
				Node *n1 = new Node(num, Lname, Fname, Mname, Course, Year, Month, Day, Gwa);
				mylist.InsertNode(n1); //The given information will be inserted to the list object 
				system("cls");
				break;
			}
			case 2 : {
				cout << "Update Information of a Student" << endl <<endl;
				cout << "Enter Student Number: ";
				cin >> num;
				cout << endl;
				mylist.updateStudent(num);
				system("cls");
				break;
			}
			case 3 : {
				cout << "Enter student number to delete: ";
				cin >> num;
				mylist.DeleteNode(num);
				system("cls");
				break;
			}
			case 4: {
				int choice;
				cout << "Sort Student Information" << endl;
				cout << "[1]Sort by Student Number" << endl;
				cout << "[2]Sort by Last Name" << endl;
				cout << "[3]Sort by GWA" << endl<<endl;
				cout << "Enter choice: ";
				cin >> choice;
				
				switch(choice) {
					case 1: {
						mylist.SortStudentNumber();
						break;
					}
					case 2: {
						mylist.SortLastName();
						break;
					}
					case 3: {
						mylist.SortGwa();
						break;
					}
				}	
				system("cls");
				break;
			}	
			case 5 : {
				mylist.printlist();
				system("cls");
				break;
			}
			case 6: {
				mylist.~List();
				exit(0);
				break;
			}		
				
		}
	} while (1);
	
}

//END OF PROGRAM
