#include <string>
#include <iostream>

// a problem I would say is that this function is never used
void DisplayMenu(){ 
  std::cout << "----------------\n"; 
  std::cout << "- 1)Add -\n"; 
  std::cout << "- 2)Subtract -\n"; 
  std::cout << "- 3)Multiply -\n"; 
  std::cout << "- 4)Exit -\n"; 
  std::cout << "----------------\n";
  return;
}

int main(){
  int num_1, num_2;

  int choice = 0;

  // This is an error should be while choice != 4 so that the exit option actually works
  // Right now there is not even a check if choice == 4 and then breaking from the loop.
  while(choice != 5){
    
    // This entire code is what DisplayMenu() does should just use that function 
    // because as of now that function is never used
    std::cout << "----------------\n"; 
    std::cout << "- 1)Add -\n"; 
    std::cout << "- 2)Subtract -\n"; 
    std::cout << "- 3)Multiply -\n"; 
    std::cout << "- 4)Exit -\n"; 
    std::cout << "----------------\n";

    // No sanatizing and validating of user inputs. This could lead to buffer overflows if
    // to big of a value is passed or unexpected behavior if a non it or number that isnt 1-4 is passed
    std::cin >> choice;

    // while not a bug a switch statement would be better as they are generally quicker
    if(choice == 1){ 
      // same problems with reading in user input as before (except needing to be 1-4 of course)
      std::cin >> num_1; 
      std::cin >> num_2; 
      // bug here it should be adding the numbers
      std::cout << num_1 << " - "  <<  num_2  << " = "  << num_1 - num_2 << std::endl; // While not a security issue, excessive use of 
                                                                                        // std::endl can lead to performance issues as it forces a 
                                                                                        // flush of the output buffer. It's more efficient to use '\n' 
                                                                                        //for new lines unless a buffer flush is specifically required.
    }
    else if(choice == 2){
      // same problems with reading in user input as before (except needing to be 1-4 of course)
      std::cin >> num_1; 
      std::cin >> num_2; 
      // bug here it should be subtraction
      std::cout << num_1 << " - "  <<  num_2  << " = " << num_1 + num_2 << std::endl; // same thing as before with std::endl
    }
    else if(choice == 3){ 
      // same problems with reading in user input as before (except needing to be 1-4 of course)
      std::cin >> num_1; 
      std::cin >> num_2;
      // bug here should be multiplication and also right now possible divide by 0 error
      std::cout << num_1 << " - "  <<  num_2  << " = "  << num_1 / num_2 << std::endl;// same thing as before with std::endl
    }
  } 
}