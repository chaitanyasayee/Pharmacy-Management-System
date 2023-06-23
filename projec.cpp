#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10
using namespace std;

class medicineType //base class
{
public:
    void take_order();    // to take_order
    void delete_order();  // to delete the order
    void modify();        // to modify the order
    void order_list();    // to display the order_list
    void daily_summary(); // to display daily_summary
    void exit_system();   // function to exit system
    void display_all();
    medicineType(); // constructor
};

medicineType::medicineType()
{
}

struct node // construct node
{
    int receipt_number;
    string customerName;
    string date;
    int quantity[10];
    string type = "OTC";
    int x, menu2[10];
    double amount[10];
    string medicineName[10] = {"Probiotics", "Vitamin C(500mg)", "Acid Free C(500mg)", "Women'S Multivate",
                              "Marino Tablet", "Maxi Cal Tablet", "Amino Zinc Tablet", "Burnex", "Fabuloss 5",
                              "Royal Propollen"};
    double Medicine[10] = {2.00, 3.00, 1.00, 4.00, 1.00, 5.00, 7.00, 4.00, 3.00, 5.00};
    double total;
    node* prev;
    node* next;
    node* link;
}*q, *temp; // pointer declaration

node* start_ptr = NULL;
node* head = NULL;
node* last = NULL;

void medicineType::take_order() // function to take_order
{
    system("cls");
    int i;
    int choice, quantity, price, None;
    cout << "\nAdd Order Details\n";
    cout << "_____________ \n\n";
    node* temp;
    temp = new node;
    cout << "**************************\n";
    cout << "DRUGS ID"
         << "\tDRUGS TYPE"
         << "\t\tDRUGS NAME"
         << " DRUGS PRICE(Rs)" << endl;
    cout << "**************************\n";
    cout << "0001"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Probiotics"
         << " Rs 60" << endl;
    cout << "0002"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Vitamin C(500mg)"
         << " Rs 80" << endl;
    cout << "0003"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Acid Free C(500mg)"
         << " Rs 100" << endl;
    cout << "0004"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Women'S Multivate"
         << " Rs 150" << endl;
    cout << "0005"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Marino Tablet"
         << " Rs 75" << endl;
    cout << "0006"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Maxi Cal Tablet"
         << " Rs 200" << endl;
    cout << "0007"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Amino Zinc Tablet"
         << " Rs 120" << endl;
    cout << "0008"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Burnex"
         << " Rs 90" << endl;
    cout << "0009"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Fabuloss 5"
         << " Rs 110" << endl;
    cout << "0010"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << " Royal Propollen"
         << " Rs 130" << endl;
    cout << "**************************\n";
    cout << "Enter the customer name : ";
    cin >> temp->customerName;
    cout << "Enter the receipt number : ";
    cin >> temp->receipt_number;
    cout << "Enter the date : ";
    cin >> temp->date;
    cout << "How many types of medicine do you want to purchase : ";
    cin >> temp->x;
    for (i = 0; i < temp->x; i++)
    {
        cout << "Enter the drugs ID : ";
        cin >> temp->menu2[i];
        cout << "Enter the quantity : ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
    }
    cout << "Enter 1 to confirm your order : ";
    cin >> choice;
    if (choice == 1)
    {
        temp->total = 0;
        for (i = 0; i < temp->x; i++)
        {
            temp->total = temp->total + temp->amount[i];
        }
        temp->next = NULL;
        temp->prev = NULL;
        if (start_ptr == NULL)
        {
            start_ptr = temp;
            last = start_ptr;
        }
        else
        {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
    }
    else
    {
        cout << "Order not confirmed!\n";
        delete temp;
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void medicineType::delete_order() // function to delete the order
{
    system("cls");
    int r, f = 0;
    cout << "Delete Order\n";
    cout << "____________ \n\n";
    cout << "Enter the receipt number : ";
    cin >> r;
    temp = start_ptr;
    if (start_ptr == NULL)
    {
        cout << "No orders found!\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    while (temp != NULL)
    {
        if (temp->receipt_number == r)
        {
            f = 1;
            if (temp == start_ptr)
            {
                start_ptr = start_ptr->next;
                if (start_ptr != NULL)
                    start_ptr->prev = NULL;
                delete temp;
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                delete temp;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            cout << "Order deleted successfully!\n";
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (f == 0)
    {
        cout << "Order not found!\n";
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void medicineType::modify() // function to modify the order
{
    system("cls");
    int r, f = 0;
    cout << "Modify Order\n";
    cout << "____________ \n\n";
    cout << "Enter the receipt number : ";
    cin >> r;
    temp = start_ptr;
    if (start_ptr == NULL)
    {
        cout << "No orders found!\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    while (temp != NULL)
    {
        if (temp->receipt_number == r)
        {
            f = 1;
            cout << "Enter the new customer name : ";
            cin >> temp->customerName;
            cout << "Enter the new date : ";
            cin >> temp->date;
            cout << "How many types of medicine do you want to modify : ";
            cin >> temp->x;
            for (int i = 0; i < temp->x; i++)
            {
                cout << "Enter the drugs ID : ";
                cin >> temp->menu2[i];
                cout << "Enter the new quantity : ";
                cin >> temp->quantity[i];
                temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
            }
            cout << "Order modified successfully!\n";
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (f == 0)
    {
        cout << "Order not found!\n";
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void medicineType::order_list() // function to display the order_list
{
    system("cls");
    int i;
    cout << "Order List\n";
    cout << "__________ \n\n";
    temp = start_ptr;
    if (start_ptr == NULL)
    {
        cout << "No orders found!\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    while (temp != NULL)
    {
        cout << "*******************************\n";
        cout << "Receipt Number: " << temp->receipt_number << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Date: " << temp->date << endl;
        cout << "*******************************\n";
        cout << "DRUGS ID"
             << "\tDRUGS TYPE"
             << "\t\tDRUGS NAME"
             << " QUANTITY"
             << " AMOUNT(Rs)" << endl;
        cout << "*******************************\n";
        for (i = 0; i < temp->x; i++)
        {
            cout << temp->menu2[i] << "\t\t" << temp->type << "\t\t" << temp->medicineName[temp->menu2[i] - 1] << "\t"
                 << temp->quantity[i] << "\t" << temp->amount[i] << endl;
        }
        cout << "*******************************\n";
        cout << "Total: " << temp->total << endl;
        temp = temp->next;
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void medicineType::daily_summary() // function to display the daily_summary
{
    system("cls");
    int d, m, y, f = 0;
    double sum = 0;
    cout << "Daily Summary\n";
    cout << "_____________ \n\n";
    cout << "Enter the date (dd mm yyyy) : ";
    cin >> d >> m >> y;
    temp = start_ptr;
    if (start_ptr == NULL)
    {
        cout << "No orders found!\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    while (temp != NULL)
    {
        string date = temp->date;
        int day, month, year;
        sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
        if (day == d && month == m && year == y)
        {
            f = 1;
            cout << "*******************************\n";
            cout << "Receipt Number: " << temp->receipt_number << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Date: " << temp->date << endl;
            cout << "*******************************\n";
            cout << "DRUGS ID"
                 << "\tDRUGS TYPE"
                 << "\t\tDRUGS NAME"
                 << " QUANTITY"
                 << " AMOUNT(Rs)" << endl;
            cout << "*******************************\n";
            for (int i = 0; i < temp->x; i++)
            {
                cout << temp->menu2[i] << "\t\t" << temp->type << "\t\t" << temp->medicineName[temp->menu2[i] - 1] << "\t"
                     << temp->quantity[i] << "\t" << temp->amount[i] << endl;
            }
            cout << "*******************************\n";
            cout << "Total: " << temp->total << endl;
            sum += temp->total;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "No orders found for the specified date!\n";
    }
    else
    {
        cout << "*******************************\n";
        cout << "Total sales for the day: " << sum << endl;
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void medicineType::exit_system() // function to exit system
{
    system("cls");
    cout << "Exiting the system...\n";
    exit(0);
}

void medicineType::display_all()
{
    system("cls");
    int i;
    cout << "Display All\n";
    cout << "__________ \n\n";
    temp = start_ptr;
    if (start_ptr == NULL)
    {
        cout << "No orders found!\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    while (temp != NULL)
    {
        cout << "*******************************\n";
        cout << "Receipt Number: " << temp->receipt_number << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Date: " << temp->date << endl;
        cout << "*******************************\n";
        cout << "DRUGS ID"
             << "\tDRUGS TYPE"
             << "\t\tDRUGS NAME"
             << " QUANTITY"
             << " AMOUNT(Rs)" << endl;
        cout << "*******************************\n";
        for (i = 0; i < temp->x; i++)
        {
            cout << temp->menu2[i] << "\t\t" << temp->type << "\t\t" << temp->medicineName[temp->menu2[i] - 1] << "\t"
                 << temp->quantity[i] << "\t" << temp->amount[i] << endl;
        }
        cout << "*******************************\n";
        cout << "Total: " << temp->total << endl;
        temp = temp->next;
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

int main()
{
    medicineType M; // object of class
    int choice;
    do
    {
        system("cls");
        cout << "Main Menu\n";
        cout << "_________ \n\n";
        cout << "1. Take Order\n";
        cout << "2. Delete Order\n";
        cout << "3. Modify Order\n";
        cout << "4. Order List\n";
        cout << "5. Daily Summary\n";
        cout << "6. Display All\n";
        cout << "7. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            M.take_order();
            break;
        case 2:
            M.delete_order();
            break;
        case 3:
            M.modify();
            break;
        case 4:
            M.order_list();
            break;
        case 5:
            M.daily_summary();
            break;
        case 6:
            M.display_all();
            break;
        case 7:
            M.exit_system();
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 7);
    return 0;
}
