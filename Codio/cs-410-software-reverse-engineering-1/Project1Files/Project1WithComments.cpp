#include <string>
#include <iostream>

///// Globals /////
// Login Globals
std::string username; // Global variable can be accessed and potentially modified from anywhere in the program.
                      // Recommendation: Limit the scope of the username variable, and ensure it is properly sanitized before use.

int answer; // Global variable can be accessed and potentially modified from anywhere in the program.
            // Recommendation: Limit the scope of the answer variable.

// Action Global
int choice; // Global variable can be accessed and potentially modified from anywhere in the program.
            // Recommendation: Limit the scope of the choice variable.

// Choice Global
int changechoice; // Global variable can be accessed and potentially modified from anywhere in the program.
                  // Recommendation: Limit the scope of the changechoice variable.

int newservice; // Global variable can be accessed and potentially modified from anywhere in the program.
                // Recommendation: Limit the scope of the newservice variable.

// Customer Globals
// Storing customer data in plain text could be a security risk if the data is sensitive.
// Recommendation: Use a struct or class to group related data together, and limit the scope of the customer data.
// If the data is sensitive, ensure it is properly protected.
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

/// Function Prototypes /// 
int ChangeCustomerChoice();
void DisplayInfo();
int CheckUserPermissonAccess();


int main(){

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

        // Security vulnerability: The choice variable is not validated before use.
        // this can lead to a stack overflow or other security vulnerabilities such as a buffer overflow or format string vulnerability.
        // Recommendation: Validate the choice variable before use.
        // one way to do this is to make sure the user enters an integer, and that the integer is within the expected range.
        // example code: 
        // std::string input;
        // std::cin >> input;
        // int choice = std::stoi(input);
        // if(choice < 1 || choice > 3){
        //     std::cout << "Invalid choice. Please try again.\n";
        //     continue;
        // }
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
    
    // No input validation. If the user enters a string longer than 255 characters, the program will crash.
    // can cause a stack overflow or other security vulnerabilities such as a buffer overflow or format string vulnerability.
    // Also the username variable is a global variable, which can be accessed and potentially modified from anywhere in the program.
    // Also maybe hash the username before storing it in the database, to prevent the username from being exposed if the database is compromised.
    // Recommendation: Limit the scope of the username variable, and ensure it is properly sanitized before use.
    // Recommendation: Add input validation to ensure the user enters a valid username.
    // example code:
    // std::string input;
    // std::cin >> input;
    // std::string username = hash(input);
    // if(username.length() > 255){
    //     std::cout << "Invalid username. Please try again.\n";
    //     return;
    // }
    std::cin >> username;

    std::cout <<  "Enter your password: \n";
    std::string user_passwd;
    
    // No input validation. If the user enters a string longer than 255 characters, the program will crash.
    // can cause a stack overflow or other security vulnerabilities such as a buffer overflow or format string vulnerability.
    // Also the user_passwd variable is a global variable, which can be accessed and potentially modified from anywhere in the program.
    // Also maybe hash the password before storing it in the database, to prevent the password from being exposed if the database is compromised.
    // Recommendation: Limit the scope of the user_passwd variable, and ensure it is properly sanitized before use.
    // Recommendation: Add input validation to ensure the user enters a valid password.
    // example code:
    // std::string input;
    // std::cin >> input;
    // std::string user_passwd = hash(input);
    // if(user_passwd.length() > 255){
    //     std::cout << "Invalid password. Please try again.\n";
    //     return;
    // }
    std::cin >> user_passwd;


    // Security vulnerability: username is not validated before use.
    // There is no point in having a username if it is not validated before use.
    // Recommendation: Validate the username before use.
    // example code:
    // std::string stored_hash = "admin";
    // std::string input_hash = hash(username);
    // if(!input_hash.compare(stored_hash)){
    //     return 1;
    // }
    // Usernames should also not be hardcoded and in plain text.
  

    // Password is hardcoded and in plain text, which is a security risk.
    // Recommendation: Store hashed passwords and compare the hash of the input password against the stored hash.
    // This will prevent the password from being exposed if the database is compromised.
    // example code:
    // std::string stored_hash = "123";
    // std::string input_hash = hash(user_passwd);
    // if(!input_hash.compare(stored_hash)){
    //     return 1;
    // }
    // return 2;
    // Passwords should also not be hardcoded and in plain text.
    if(!user_passwd.compare("123")){ 
        return 1;                    
    }
    return 2;
}

int ChangeCustomerChoice(){
    // No input validation. If the user enters a non-integer, the program will crash.
    // can cause a stack overflow or other security vulnerabilities such as a buffer overflow or format string vulnerability.
    // Recommendation: Add input validation to ensure the user enters a valid integer.
    // example code:
    // std::string input;
    // std::cin >> input;
    // int changechoice = std::stoi(input);
    // if(changechoice < 1 || changechoice > 5){
    //     std::cout << "Invalid choice. Please try again.\n";
    //     return;
    // }
    std::cin >> changechoice;

    // No input validation. If the user enters a non-integer, the program will crash.
    // can cause a stack overflow or other security vulnerabilities such as a buffer overflow or format string vulnerability.
    // Recommendation: Add input validation to ensure the user enters a valid integer.
    // example code:
    // std::string input;
    // std::cin >> input;
    // int newservice = std::stoi(input);
    // if(newservice < 1 || newservice > 2){
    //     std::cout << "Invalid choice. Please try again.\n";
    //     return;
    // }
    std::cin >> newservice;

    // No validation of the changechoice or newservice variables. If the user enters an invalid value,
    // the program behavior may be unpredictable.
    // Recommendation: Add validation to ensure the changechoice and newservice variables are within expected ranges.
    // This should have been taken care of in the input validation step above.
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
    // Security vulnerability: The customer data is hardcoded and in plain text, which is a security risk.
    // Recommendation: Store customer data in a database, and retrieve it from the database when needed.
    // Example code:
    // void get_customer_data(int customer_id){
    //     // connect to database
    //     // query database for customer data
    //     // return customer data
    // }

    std::cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << std::endl;
    std::cout << "1. "  << name1 << " selected option " << num1 << std::endl;
    std::cout << "2. "  << name2 << " selected option " << num2 << std::endl;
    std::cout << "3. "  << name3 << " selected option " << num3 << std::endl;
    std::cout << "4. "  << name4 << " selected option " << num4 << std::endl;
    std::cout << "5. "  << name5 << " selected option " << num5 << std::endl;
    return;
}