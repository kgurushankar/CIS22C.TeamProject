#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "BinarySearchTree.h"
#include "Hash.h"
#include "Mail.hpp"

using namespace std;

void searchTrackingNumber(BinarySearchTree<Mail> *addressTree);
/**
This is the best I can think of and I think we need to add setter for the tracking number and the address.
**/
int main()
{
    HashTable<Mail> stateTable = HashTable<Mail>(59); // 59 because that many states
    BinarySearchTree<Mail> trackingTable = BinarySearchTree<Mail>();
    BinarySearchTree<PriorityMail> priorityTable = BinarySearchTree<PriorityMail>();

    //Init data structs
    printMenu();

    string choice = "";

    while (choice[0] != 'E')
    {
        std::cout << "Pick an option" << endl;
        getline(std::cin, choice);
        if (choice[0] == 'T')
    }
}

void searchTrackingNumber(BinarySearchTree<Mail> *tree)
{
    int tracking;
    std::cout << "Please enter the tracking number: ";
    std::cin >> tracking;

    Mail obj = Mail(tracking, Address(), Address(), Date(), Type::normal);
    Mail returnItem;

    if (table->search(obj, returnItem))
    {
        std::cout << returnItem;
    }
}

void searchByState(Hashtable *table)
{
    Mail obj;
    Mail returnItem;
    string stateTemp;

    std::cout << "Please enter the state : ";
    getline(std::cin, stateTemp);
    std::cin.ignore();

    obj.setState(stateTemp);
    if (table->search(obj, returnItem))
    {
        std::cout << returnItem;
    }
}

void pintOrder(BinarySearchTree<Mail> *idTree)
{
    idTree->inorder(visitOrder);
}

void printMail(BinarySearchTree<Mail> *idTree)
{
    idTree->inorder(visitMail);
}

void printState(HasTable *table)
{
    table->printHash(state);
}

void visitOrder(HashTable *table)
{
    table->printHash(trackingnumber);
}

void visitMail(Mail &mail, HashTable *table)
{
    std::cout << mail;
}

/* ************************************************************************
 BuildBSTS: This function builds both trees and hash from input file
 input parameter: BST Tree1, BST Tree2, and array of int hash
 *****************************************************************************/
void buildBSTs(BinarySearchTree<Mail> *mytree1, BinarySearchTree<Mail> *mytree2, int hash[])
{
    State st;
    Type t;
    char mailInfo[] = "mail.txt";
    char addressInfo[] = "address.txt";
    int day, month, year, zip;
    char slash;
    string street = "";
    string city = "";
    string state = "";
    string type = "";
    ifstream inFile, inFile2;
    inFile.open(mailInfo);
    inFile2.open(addressInfo);
    if (!inFile)
    {
        std::cout << "Error opening the input file: \"" << mailInfo << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    if (!inFile2)
    {
        std::cout << "Error opening the input file: \"" << addressInfo << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    while (inFile && inFile2)
    {
        // In the text file I removed the header from mail.txt
        inFile >> trackingnum;
        inFile.ignore(12);
        inFile >> month >> slash >> day >> slash >> year >> type;
        //std::cout << month;
        //std::cout << slash;
        //std::cout << day;
        //std::cout << slash;
        //std::cout << year << endl;

        Date D(month, day, year);
        //std::cout << type << endl;
        if (type == "normal")
        {
            t = normal;
        }
        else if (type == "economy")
        {
            t = economy;
        }
        else
        {
            t = priority;
        }
        // In text file I removed the header from address.txt
        inFile2.ignore(3);
        getline(inFile2, street, ',');
        getline(inFile2, city, ',');
        getline(inFile2, state, ',');
        inFile2 >> zip;
        inFile2.ignore(3);
        //std::cout << street << endl;
        st = toState(state);
        Address A(street, city, st, zip);
        inFile2.ignore(3);
        getline(inFile2, street, ',');
        getline(inFile2, city, ',');
        getline(inFile2, state, ',');
        inFile2 >> zip;
        inFile2.ignore(3);
        st = toState(state);
        Address B(street, city, st, zip);
        Mail package = new Mail(A, B, D, t);
        //std::cout << street << endl;
        //std::cout << city << endl;
        //std::cout << state << endl;
        //std::cout << zip << endl;
        // insert tracking num into hash
        mytree1->insert(package);
    }
    inFile.close();
    inFile2.close();
}

/* *********************************************************
input: This function allows you to insert a mail object and also checks for duplicate objects
input parameters: BST mytree, BST mytree2, hash
************************************************************/
void input(BinarySearchTree<Mail> *mytree, BinarySearchTree<Mail> *mytree2, hash<int tracking> myhash)
{
    string streetname;
    string city;
    string state;
    string type;
    int zip;
    int month;
    int day;
    int year;
    int tracking;
    Type t;
    State st;
    Date D;
    std::cout << "enter a street address (sender)\n";
    getline(std::cin, streetname);
    std::cout << "enter a city(sender)\n";
    getline(std::cin, city);
    std::cout << "enter a state (sender)\n";
    getline(std::cin, state);
    std::cout << "enter a zip or postal code (5 digits) (sender)\n";
    std::cin >> zip;
    std::cout << "enter a tracking num (sender)\n";
    std::cin >> tracking;
    std::cout << "enter what type of package it is (priority, economy, normal) \n";
    getline(std::cin, type);
    t = toType(type);
    st = toState(state);
    Address sender(streetname, city, st, zip);
    std::cout << "enter a street address (sender)\n";
    getline(std::cin, streetname);
    std::cout << "enter a city(sender)\n";
    getline(std::cin, city);
    std::cout << "enter a state (sender)\n";
    getline(std::cin, state);
    std::cout << "enter a zip or postal code (5 digits) (sender)\n";
    std::cin >> zip;
    std::cout << "enter a month\n";
    std::cin >> month;
    std::cout << "enter a day\n";
    std::cin >> day;
    std::cout << "enter a year ]n";
    std::cin >> year;
    D.setMonth(month);
    D.setDay(day);
    D.setYear(year);
    Address reciever(streetname, city, st, zip);
    Mail pack = new Mail(sender, reciever, D, type);
    if (!mytree->getEntry(pack, pack) && mytree2->getEntry(pack, pack))
    {
        mytree->insert(pack);
        mytree2->insert(pack);
        hash->insertHash(tracking);
    }
    else
    {
        std::cout << "sorry this package is already in our system" << endl;
    }
}

void printMenu()
{
    std::cout << "READ address mail" << '\t' << "Load data from input files" << endl
              << "PRINT n shift" << '\t' << "Print out the list of mail in order of which they need to be sent (starting at shift, at most n entries)" << endl
              << "PRINT n " << '\t' << "Print out the list of mail in order of which they need to be sent (from top, at most n)" << endl
              << "PRINT" << '\t' << "Print out the list of mail in order of which they need to be sent (from top, at most first 100)" << endl
              << "SEARCH tracking_number" << '\t' << "Search for a mail with specific tracking number" << endl
              << "MAILBOX address" << '\t' << "List all mail going to given address" << endl
              << "STATE state" << '\t' << "List all mail going to state" << endl
              << "SEND n" << '\t' << "Removes first n mails from the list" << endl
              << "REMOVE tracking_number" << '\t' << "Removes mail with id from list" << endl
              << "INSERT" << '\t' << "Guides through inserting a new mail (specify tracking number, but does a duplicate check)" << endl
              //  << "PROCESS address mail output"   << '\t' << "Process database generated by address and mail, and write to output" << endl
              //  << "WRITE filename"                << '\t' << "Write processed database to filename" << endl
              //  << "SNAPSHOT address mail"         << '\t' << "Dumps out a snapshot of the database" << endl
              << "CLEAR" << '\t' << "Clear all data from database (prompt for confirmation!)" << endl
              << "QUIT/EXIT/Q/E" << '\t' << "Exit, and write output to out.txt" << endl;
}