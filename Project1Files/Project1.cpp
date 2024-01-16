#include <string>
#include <iostream>

///// Globals /////
// Login Globals
std::string username;
int answer;

// Action Global
int choice;;

// Choic Global
int changechoice;
int newservice;


// Customer Globals
std::string name1 = "Bob Jones";
int num1 = 1;
std::string name2 = "Sarah Davis";
int num2 = 2;
std::string name3 = "Amy Friendly";
int num3 = 1;
std::string name4 = "Johnny Smith";
int num4 = 1;
std::string name5 = "Carol Spears";
int num5 = 2;

/// Fucntion Prototypes /// 
int ChangeCustomerChoice();
void DisplayInfo();
int CheckUserPermissonAccess();


int main(){

	std::cout << "Created By Matt Bass\n";
	std::cout << "Hello! Welcome to our investment company\n";

	while(1){
		answer = CheckUserPermissonAccess();
		if(answer == 1){
			break;
		}
		std::cout << "Invalid Password. Please try again\n";
	}

	while(1){

		std::cout << "What would you like to do?\n";
		std::cout << "DISPLAY the client list (enter 1)\n";
		std::cout << "CHANGE a client's choice (enter 2)\n";
		std::cout <<  "Exit the program.. (enter 3)\n";

		std::cin >> choice;

		std::cout <<"You chose " << choice << std::endl ;

		if(choice == 1){
			DisplayInfo();
		}
		else if(choice == 2){
			ChangeCustomerChoice();
		}
		else if(choice == 3){
			break;
		}
	}


}


int CheckUserPermissonAccess(){

	std::cout << "Enter your username: \n";
	std::cin >> username;

	std::cout <<  "Enter your password: \n";
	std::string user_passwd;
	std::cin >> user_passwd;

	if(!user_passwd.compare("123")){
		return 1;
	}
	return 2;
}


int ChangeCustomerChoice(){
	std::cout << "Enter the number of the client that you wish to change\n";
	std::cin >> changechoice;
	std::cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
	std::cin >> newservice;

	switch(changechoice){
		case 1:
			num1 = newservice;
			break;
		case 2:
			num2 = newservice;
			break;
		case 3:
			num3 = newservice;
			break;
		case 4:
			num4 = newservice;
			break;
		case 5:
			num5 = newservice;
			break;
		default:
			break;
	}
	
	return changechoice;
}


void DisplayInfo(){
	std::cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << std::endl;
	std::cout << "1. "  << name1 << " selected option " << num1 << std::endl;
	std::cout << "2. "  << name2 << " selected option " << num2 << std::endl;
	std::cout << "3. "  << name3 << " selected option " << num3 << std::endl;
	std::cout << "4. "  << name4 << " selected option " << num4 << std::endl;
	std::cout << "5. "  << name5 << " selected option " << num5 << std::endl;
	return;
}


