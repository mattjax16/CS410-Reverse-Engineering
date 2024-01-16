#include <string>
#include <iostream>
#include <limits>


void DisplayMenu(){ 
  std::cout << "----------------\n"; 
  std::cout << "- 1)Add -\n"; 
  std::cout << "- 2)Subtract -\n"; 
  std::cout << "- 3)Multiply -\n"; 
  std::cout << "- 4)Exit -\n"; 
  std::cout << "----------------\n";
  return;
}

// Function to get an integer input and validate it
bool GetIntInput(int& value) {
    std::cin >> value;
    // Check if the input is an integer
    if (std::cin.fail()) {
        // Clear the error flag and ignore the rest of the line
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false; // Return false if input is invalid
    }
    return true; // Return true if input is valid
}

int main(){
  int num_1, num_2;
  int choice = 0;

  // looking for correct choice value now so exit command works
  while(choice != 4){
    
    // Properly using function
    DisplayMenu();

    // validating and sanatizing user input with function to make sure an int in input and then checking that 
    // the input is in the proper range
    if (!GetIntInput(choice) || (choice < 1 || choice > 4)) {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue; // Continue the loop if the input is invalid
    }


    // optimizing with switch statement (could also check if choice == 4 then break from function)
    // then pull out the reading in both numbers from the cases because now we are sure it is an operation chosen
    // to operate on 2 numbers however I dont want to change the structure of the original code to much
    switch(choice){ 
      case 1:
        // Validate the numeric inputs
        if (!GetIntInput(num_1) || !GetIntInput(num_2)) {
            std::cout << "Invalid input. Please enter numbers.\n";
            continue; // Continue the loop if the inputs are invalid
        }
        // correct opperation
        std::cout << num_1 << " - "  <<  num_2  << " = "  << num_1 + num_2 << "\n"; // implemented \n optimization
      case 2:
        // Validate the numeric inputs
        if (!GetIntInput(num_1) || !GetIntInput(num_2)) {
            std::cout << "Invalid input. Please enter numbers.\n";
            continue; // Continue the loop if the inputs are invalid
        }
        // correct opperation
        std::cout << num_1 << " - "  <<  num_2  << " = " << num_1 - num_2 << "\n"; // implemented \n optimization
    
      case 3:
        // Validate the numeric inputs
        if (!GetIntInput(num_1) || !GetIntInput(num_2)) {
            std::cout << "Invalid input. Please enter numbers.\n";
            continue; // Continue the loop if the inputs are invalid
        }
        // correct opperation
        std::cout << num_1 << " - "  <<  num_2  << " = "  << num_1 * num_2 << "\n";// implemented \n optimization
    }
  } 
}