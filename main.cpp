#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <vector>
using namespace std;

// program global variables
int i;
string newFirstName, newLastName, newRole;
double newPayRate;

struct Employee {
    int employeeID;
    string employeeFirstName;
    string employeeLastName;
    string employeeRole;
    double employeeHourlySalary;
};

vector<Employee> employees = {
        {1549, "John", "Davis", "Accountant", 25.67},
        {1640, "Katy", "Rogers", "CEO", 100.87}
    };

void displayMenu(); // function for menu of the program
void searchEmployee(int id);
void searchEmployee(string firstName, string lastName);
void searchEmployee(string role);
void displayEmployees(void);
void updateFirstName(string newFirstName);
void updateLastName(string newLastName);
void updatePayRate(double newPayRate);
void updateRole(string newRole);

updateFirstName(string newFirstName) {
    employees[i].employeeFirstName = newFirstName;
    cout << "Employee first name updated..." << endl;
    cout << "Returning to main menu..." << endl;
}

updateLastName(string newLastName) {
    // logic for updating last name
}

updatePayRate(double newPayRate) {
    // logic for updating pay rate
}

updateRole(string newRole) {
    // logic for updating position
}

void searchEmployee(int id) {
    bool found = false; // Flag to check if employee is found
    int optionsChoice;
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].employeeID == id) {
            cout << "Employee(s) found: " << endl;
            cout << "ID: " << employees[i].employeeID << ", Name: " << employees[i].employeeFirstName << " " << employees[i].employeeLastName << endl;
            found = true; // Set flag to true if found
            cout << "Options:" << endl;
            cout << "0. Return to main menu" << endl;
            cout << "1. Update first name" << endl;
            cout << "2. Update last name" << endl;
            cout << "3. Update postiion" << endl;
            cout << "4. Update pay rate (promotion)" << endl;
            cout << "Enter your choice: ";
            cin >> optionsChoice;
            switch (optionsChoice) {
                case 0:
                    cout << "Returning to main menu..." << endl;
                    displayMenu();
                case 1:
                    cout << "Enter new name:";
                    cin >> newFirstName;
                    updateFirstName(string newFirstName);
            }
            break;
        }
    }
    if (!found) {
        cout << "No employee found with ID: " << id << endl; // Message if not found
        cout << "Returning to main menu..." << endl;
        displayMenu();
    }
}

void searchEmployee(string firstName, string lastName) {
    bool found = false; // Flag to check if employee is found
    for (const auto& employee : employees) {
        if (employee.employeeFirstName == firstName && employee.employeeLastName == lastName) {
            cout << "Employee(s) found: " << endl;
            cout << "ID: " << employee.employeeID << ", Name: " << employee.employeeFirstName << " " << employee.employeeLastName << endl;
            found = true; // Set flag to true if found
            break;
        }
    }
    if (!found) {
        cout << "No employee found with name: " << firstName << " " << lastName << endl; // Message if not found
    }
}

void searchEmployee(string role) {
    bool found = false; // Flag to check if employee is found
    for (const auto& employee : employees) {
        if (employee.employeeRole == role) {
            cout << "Employee(s) found: " << endl;
            cout << "ID: " << employee.employeeID << ", Name: " << employee.employeeFirstName << " " << employee.employeeLastName << endl;
            found = true; // Set flag to true if found
        }
    }
    if (!found) {
        cout << "No employee found with role: " << role << endl; // Message if not found
    }
}

void displayMenu() {
    int choice;
    string searchedFirstName, searchedLastName;
    cout << "MAIN MENU" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Search an Employee" << endl;
    cout << "2. Display all Employees" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 0: 
            break;
        case 1:
            int searchChoice;
            cout << "0. Search an Employee by name" << endl;
            cout << "1. Search an Employee by ID" << endl;
            cout << "2. Search an Employee by position" << endl;
            cout << "Enter your choice: ";
            cin >> searchChoice;
            switch (searchChoice) {
                case 0:
                    cout << "Enter the first name of the Employee: ";
                    cin >> searchedFirstName;
                    cout << "Enter the last name of the Employee: ";
                    cin >> searchedLastName;
                    searchEmployee(searchedFirstName, searchedLastName);
                    break;
                case 1:
                    int id;
                    cout << "Enter the ID of the Employee: ";
                    cin >> id;
                    searchEmployee(id);
                    break;
                case 2:
                    string role;
                    cout << "Enter the role of the Employee: ";
                    cin >> role;
                    searchEmployee(role);
                    break;
            }
            break;
        case 2: 
            displayEmployees();
            break;
    }
}

void displayEmployees(void) {
    for (const auto& employee : employees) {
        cout << employee.employeeFirstName << " " << employee.employeeLastName << " | " << employee.employeeRole << " |" << endl;
    }
}

int main(void) {
    displayMenu();
    return 0;
}
