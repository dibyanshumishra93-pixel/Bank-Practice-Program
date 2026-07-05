 #include <iostream>
    #include <iomanip>
    
    void showbalance(double balance);
    double deposit(double balance);
    double withdraw(double balance);

   int main() {
    double balance = 53.000;
    int choice;

    do{std::cout<< "Enter 1 to deposit, 2 to withdraw, 3 to check balance and 4 to exit: ";
std::cin >> choice;

if (std::cin.fail()) {                    // did the read fail? (e.g., they typed a letter)
        std::cin.clear();                     // unjam it
        std::cin.ignore(1000, '\n');          // throw away the bad input
        std::cout << "Invalid input. Please enter a number.\n";
        continue;                             // skip switch, go back to top of loop and ask again
    }

switch (choice) {
    case 1:
    balance = deposit(balance);
    std::cout << "Your balance is: $ " << std::fixed << std::setprecision(3) << balance << std::endl;
    break;
    case 2:
    balance = withdraw(balance);
    std::cout << "Your balance is: $ " << std::fixed << std::setprecision(3) << balance << std::endl;
    break;
    case 3:
    showbalance(balance);
    break;
    case 4:
    std::cout << "Thank you for using our banking system." << std::endl;
    break;      
    default:
    std::cout << " Invalid choice. Please try again." << std::endl;
}} while (choice != 4);



    return 0;
   }

   void showbalance(double balance) {
   std::cout<< "Your current balance is: $ " << std::fixed << std::setprecision(3) << balance << '\n';
   }
   double deposit(double balance) {
    double deposit;
    std::cout << "Enter the amount you want to deposit: $ ";
    std::cin >> deposit;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. No deposit made.\n";
        return balance;   // return unchanged balance, not 0!
    }
    if(deposit>0) {
    double finalamount = balance += deposit;
    return finalamount;
}
    else {
        std::cout << "Please enter a positive amount next time.";
        return 0;
    }
}
double withdraw(double balance) {
    double withdraw;
    std::cout<< "Enter withdrawal amount:$ ";
    std::cin >> withdraw;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. No withdrawal made.\n";
        return balance;
    }
    if (withdraw <= balance) {
    double finalamount = balance -= withdraw;
    return finalamount;
    }
    else {
        std::cout << "Insufficient Balance.";
        return 0;
    }
}