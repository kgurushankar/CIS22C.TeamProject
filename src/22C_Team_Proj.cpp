#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "BinarySearchTree.h"
#include "Hash.h"
#include "Mail.hpp"
#include "TrackingMail.hpp"
#include "PriorityMail.hpp"

using namespace std;

int main();
void searchTrackingNumber(BinarySearchTree<TrackingMail> *tree);
void printOrder(BinarySearchTree<PriorityMail> *idTree);
void printMail(BinarySearchTree<TrackingMail> *idTree);
void printHash(HashTable<Mail> *table);
void visitPriorityMail(PriorityMail &mail);
void visitTrackingMail(TrackingMail &mail);
void visitMail(Mail &mail);
void buildBSTs(BinarySearchTree<PriorityMail> *priority, BinarySearchTree<TrackingMail> *tracking, HashTable<Mail> hash, char mail[], char address[]);
void input(BinarySearchTree<PriorityMail> *priorityTree, BinarySearchTree<TrackingMail> *trackingTree, HashTable<Mail> hash);
void printMenu();

/**
This is the best I can think of and I think we need to add setter for the tracking number and the address.
**/
int main()
{
    HashTable<Mail> stateTable = HashTable<Mail>(59); // 59 because that many states
    BinarySearchTree<TrackingMail> trackingTable = BinarySearchTree<TrackingMail>();
    BinarySearchTree<PriorityMail> priorityTable = BinarySearchTree<PriorityMail>();

    //Init data structs
    printMenu();

    string choice = "";
    string options = "";
    while (choice == "QUIT" || choice == "EXIT" || choice == "Q" || choice == "E")
    {
        std::cout << "Pick an option" << endl;
        getline(std::cin, choice);
        options = choice.substr(choice.find(" "));
        choice = choice.substr(0, choice.find(" "));
        if (choice == "READ")
        {
        }
        else if (choice == "PRINT")
        {
        }
        else if (choice == "SEARCH")
        {
        }
        else if (choice == "MAILBOX")
        {
        }
        else if (choice == "STATE")
        {
        }
        else if (choice == "SEND")
        {
        }
        else if (choice == "REMOVE")
        {
        }
        else if (choice == "INSERT")
        {
        }
        else if (choice == "CLEAR")
        {
        }
        else if (choice == "QUIT" || choice == "EXIT" || choice == "Q" || choice == "E")
        {
        }
        else
        {
        }
    }
    return 0;
}

void searchTrackingNumber(BinarySearchTree<TrackingMail> *tree)
{
    int tracking;
    std::cout << "Please enter the tracking number: ";
    std::cin >> tracking;

    Mail obj = Mail(tracking, Address(), Address(), Date(), Type("normal"));
    TrackingMail returnItem;

    if (tree->getEntry(obj, returnItem))
    {
        std::cout << returnItem;
    }
}

void printOrder(BinarySearchTree<PriorityMail> *idTree)
{
    idTree->inOrder(visitPriorityMail);
}

void printMail(BinarySearchTree<TrackingMail> *idTree)
{
    idTree->inOrder(visitTrackingMail);
}

void printHash(HashTable<Mail> *table)
{
    table->printHash(visitMail);
}

void visitPriorityMail(PriorityMail &mail)
{
    std::cout << mail;
}

void visitTrackingMail(TrackingMail &mail)
{
    std::cout << mail;
}

void visitMail(Mail &mail)
{
    std::cout << mail;
}

/* ************************************************************************
 BuildBSTS: This function builds both trees and hash from input file
 input parameter: BST Tree1, BST Tree2, and array of int hash
 *****************************************************************************/
void buildBSTs(BinarySearchTree<PriorityMail> *priority, BinarySearchTree<TrackingMail> *tracking, HashTable<Mail> hash, char mail[], char address[])
{
    int id;
    int zip;
    int from;
    int to;
    string street = "";
    string city = "";
    string state = "";
    string datestr = "";
    string type = "";
    ifstream inFile;
    ifstream inFile2;
    inFile.open(mail);
    inFile2.open(address);

    if (!inFile)
    {
        std::cout << "Error opening the input file: \"" << mail << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!inFile2)
    {
        std::cout << "Error opening the input file: \"" << address << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }

    Address a[10000];
    while (inFile2 >> id >> street >> city >> state >> zip)
    {
        a[id] = Address(street, city, State(state), zip);
    }

    Mail m;
    while (inFile >> id >> from >> to >> datestr >> type)
    {
        m = Mail(id, a[from], a[to], Date(datestr), Type(type));
        priority->insert(PriorityMail(m));
        tracking->insert(TrackingMail(m));
    }

    inFile.close();
    inFile2.close();
}

/* *********************************************************
input: This function allows you to insert a mail object and also checks for duplicate objects
input parameters: BST mytree, BST mytree2, hash
************************************************************/

void input(BinarySearchTree<PriorityMail> *priorityTree, BinarySearchTree<TrackingMail> *trackingTree, HashTable<Mail> hash)
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
    Date d;
    std::cout << "enter a tracking num\n";
    std::cin >> tracking;
    std::cout << "enter a street address (sender)\n";
    getline(std::cin, streetname);
    std::cout << "enter a city (sender)\n";
    getline(std::cin, city);
    std::cout << "enter a state (sender)\n";
    getline(std::cin, state);
    std::cout << "enter a zip or postal code (5 digits) (sender)\n";
    std::cin >> zip;
    std::cout << "enter what type of package it is (priority, economy, normal) \n";
    getline(std::cin, type);
    Address sender = Address(streetname, city, State(state), zip);
    std::cout << "enter a street address (recipient)\n";
    getline(std::cin, streetname);
    std::cout << "enter a city (recipient)\n";
    getline(std::cin, city);
    std::cout << "enter a state (recipient)\n";
    getline(std::cin, state);
    std::cout << "enter a zip or postal code (5 digits) (recipient)\n";
    std::cin >> zip;
    std::cout << "enter the sending month\n";
    std::cin >> month;
    std::cout << "enter the sending day\n";
    std::cin >> day;
    std::cout << "enter the sending year\n";
    std::cin >> year;
    d = Date(day - 1, month - 1, year - 1);
    Address reciever = Address(streetname, city, st, zip);
    Mail pack = Mail(tracking, sender, reciever, d, type);
    PriorityMail tmpp;
    TrackingMail tmpt;
    if (!priorityTree->getEntry(pack, tmpp) && !trackingTree->getEntry(pack, tmpt))
    {
        trackingTree->insert(TrackingMail(pack));
        priorityTree->insert(PriorityMail(pack));
        hash.insertHash(pack);
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