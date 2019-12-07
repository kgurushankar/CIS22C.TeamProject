#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <algorithm>

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
void buildBSTs(BinarySearchTree<PriorityMail> *priority, BinarySearchTree<TrackingMail> *tracking, HashTable<Mail> *hash, string mail, string address);
void inputManager(BinarySearchTree<PriorityMail> *priorityTree, BinarySearchTree<TrackingMail> *trackingTree, HashTable<Mail> *hash);
void printMenu();
void toFile(TrackingMail &pm);
ofstream outFile;
/**
This is the best I can think of and I think we need to add setter for the tracking number and the address.
**/
int main()
{
    HashTable<Mail> *hash = new HashTable<Mail>();
    BinarySearchTree<TrackingMail> *trackingTree = new BinarySearchTree<TrackingMail>();
    BinarySearchTree<PriorityMail> *priorityTree = new BinarySearchTree<PriorityMail>();

    printMenu();

    string choice = "";
    string options = "";
    while (true)
    {
        std::cout << endl
                  << "Pick an option" << endl;
        std::getline(std::cin, choice);
        int tmp = choice.find(" ");
        if (string::npos != choice.find(" "))
        {
            options = choice.substr(tmp + 1); // + 1 to drop off the space
            choice = choice.substr(0, tmp);
        }
        else
            options = "";
        std::for_each(choice.begin(), choice.end(), [](char &c) {
            c = ::toupper(c);
        });
        if (choice == "READ")
        {
            string addressFile, mailFile;
            if (string::npos != options.find(" "))
            {
                mailFile = options.substr(options.find(" ") + 1);
                addressFile = options.substr(0, options.find(" "));
                buildBSTs(priorityTree, trackingTree, hash, mailFile, addressFile);
                cout << "Done!" << endl;
            }
            else
            {
                cout << "Bad options" << endl;
            }
        }
        else if (choice == "LIST")
        {
            printMail(trackingTree);
        }
        else if (choice == "PRINT")
        {
            printOrder(priorityTree);
        }
        else if (choice == "SEARCH")
        {
            int num = stoi(options);
            TrackingMail target = TrackingMail(Mail(num, Address(), Address(), Date(), Type()));
            TrackingMail result;
            if (trackingTree->getEntry(target, result))
                cout << result;
            else
                cout << "Not found";
        }
        else if (choice == "SEND")
        {
            int n;
            try
            {
                n = stoi(options);
            }
            catch (...)
            {
                cout << "invalid number" << endl;
            }
            Mail m;
            PriorityMail pm;
            TrackingMail tm;
            for (int i = 0; i < n; i++)
            {
                if (priorityTree->isEmpty())
                {
                    cout << "no more mail to send" << endl;
                    break;
                }
                priorityTree->getMax(pm);
                m = pm.getMail();
                tm = TrackingMail(m);
                priorityTree->remove(pm);
                trackingTree->remove(tm);
                hash->deleteHash(m);
                cout << m.getTrackingNumber() << endl;
            }
        }
        else if (choice == "REMOVE")
        {
            int num = stoi(options);
            TrackingMail tm = TrackingMail(Mail(num, Address(), Address(), Date(), Type()));
            TrackingMail target;
            trackingTree->getEntry(tm, target);
            Mail m = target.getMail();
            PriorityMail pm = PriorityMail(m);
            priorityTree->remove(pm);
            trackingTree->remove(tm);
            hash->deleteHash(m);
            cout << m;
        }
        else if (choice == "INSERT")
        {
            inputManager(priorityTree, trackingTree, hash);
        }
        else if (choice == "CLEAR")
        {
            cout << "are you sure?(y/n)" << endl;
            getline(cin, options);
            if (options == "y")
            {
                // delete hash;
                // delete trackingTree;
                // delete priorityTree;
                hash = new HashTable<Mail>();
                trackingTree = new BinarySearchTree<TrackingMail>();
                priorityTree = new BinarySearchTree<PriorityMail>();
            }
            else
                cout << "aborted!" << endl;
        }
        else if (choice == "QUIT" || choice == "EXIT" || choice == "Q" || choice == "E")
        {

            outFile.open("out.txt");
            trackingTree->inOrder(toFile);
            outFile.close();
            cout << endl
                 << endl
                 << "Data is in 'out.txt'" << endl
                 << "Goodbye!" << endl;
            return 0;
        }
        else if (choice == "HELP" || choice == "H")
        {
            printMenu();
        }
        else
        {
            cout << "Bad Directive " << choice << endl;
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
    std::cout << mail.getMail().getTrackingNumber() << endl;
}

void visitTrackingMail(TrackingMail &mail)
{
    std::cout << mail.getMail().getTrackingNumber() << endl;
}

void visitMail(Mail &mail)
{
    std::cout << mail.getTrackingNumber() << endl;
}
void toFile(TrackingMail &tm)
{
    outFile << tm << endl;
}

/* ************************************************************************
 BuildBSTS: This function builds both trees and hash from input file
 input parameter: BST Tree1, BST Tree2, and array of int hash
 *****************************************************************************/
void buildBSTs(BinarySearchTree<PriorityMail> *priority, BinarySearchTree<TrackingMail> *tracking, HashTable<Mail> *hash, string mail, string address)
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
    //Burn header lines
    string tmp;
    std::getline(inFile, tmp);
    std::getline(inFile2, tmp);

    Address a[10000];
    while (std::getline(inFile2, tmp))
    {
        char delimiter = '\t';
        size_t v = tmp.find(delimiter);
        id = stoi(tmp.substr(0, v));
        size_t v2 = tmp.find(delimiter, v + 1);
        street = tmp.substr(v + 1, v2 - 2);
        v = v2;
        v2 = tmp.find(delimiter, v + 1);
        city = tmp.substr(v + 1, tmp.substr(v + 1).find(delimiter));
        v = v2;
        v2 = tmp.find(delimiter, v + 1);
        state = tmp.substr(v + 1, tmp.substr(v + 1).find(delimiter));
        v = v2;
        zip = stoi(tmp.substr(v + 1));
        a[id] = Address(street, city, State(state), zip);
    }

    Mail m;
    TrackingMail m2;
    int fails = 0;
    while (inFile >> id >> from >> to >> datestr >> type)
    {
        // cout << datestr;
        m = Mail(id, a[from], a[to], Date(datestr), Type(type));
        if (!tracking->getEntry(TrackingMail(m), m2))
        {
            // cout << m;
            priority->insert(PriorityMail(m));
            tracking->insert(TrackingMail(m));
            hash->insertHash(m);
        }
        else
        {
            fails++;
        }
    }
    if (fails > 0)
    {
        cout << fails << " mails were not able to be inserted due to duplicate tracking numbers" << endl;
    }
    // cout << "there are " << hash->collisions() << " collisions in the hashtable" << endl;
    inFile.close();
    inFile2.close();
    getline(cin, tmp); //need to get the newline off
}

/* *********************************************************
input: This function allows you to insert a mail object and also checks for duplicate objects
input parameters: BST mytree, BST mytree2, hash
************************************************************/

void inputManager(BinarySearchTree<PriorityMail> *priorityTree, BinarySearchTree<TrackingMail> *trackingTree, HashTable<Mail> *hash)
{
    string tmp;
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
    while (true)
    {
        std::cout << "enter a tracking num\n";
        std::getline(std::cin, tmp);
        try
        {
            tracking = stoi(tmp);
            break;
        }
        catch (...)
        {
            std::cout << "Invalid number\n";
        }
    }
    std::cout << "enter a street address (sender)\n";
    std::getline(std::cin, streetname);
    std::cout << "enter a city (sender)\n";
    std::getline(std::cin, city);
    std::cout << "enter a state (sender)\n";
    std::getline(std::cin, state);
    std::for_each(state.begin(), state.end(), [](char &c) {
        c = ::toupper(c);
    });
    while (true)
    {
        std::cout << "enter a zip or postal code (5 digits) (sender)\n";
        std::getline(std::cin, tmp);
        try
        {
            zip = stoi(tmp);
            break;
        }
        catch (...)
        {
            std::cout << "Invalid number\n";
        }
    }
    std::cout << "enter what type of package it is (priority, economy, normal) \n";
    std::getline(std::cin, type);
    Address sender = Address(streetname, city, State(state), zip);
    std::cout << "enter a street address (recipient)\n";
    std::getline(std::cin, streetname);
    std::cout << "enter a city (recipient)\n";
    std::getline(std::cin, city);
    std::cout << "enter a state (recipient)\n";
    std::getline(std::cin, state);
    std::for_each(state.begin(), state.end(), [](char &c) {
        c = ::toupper(c);
    });
    std::cout << "enter a zip or postal code (5 digits) (recipient)\n";
    std::cin >> zip;
    std::cout << "enter the sending month\n";
    std::cin >> month;
    std::cout << "enter the sending day\n";
    std::cin >> day;
    std::cout << "enter the sending year\n";
    std::cin >> year;
    d = Date(day - 1, month - 1, year - 1);
    Address reciever = Address(streetname, city, State(state), zip);
    Mail pack = Mail(tracking, sender, reciever, d, type);
    PriorityMail tmpp;
    TrackingMail tmpt;
    if (!priorityTree->getEntry(pack, tmpp) && !trackingTree->getEntry(pack, tmpt))
    {
        trackingTree->insert(TrackingMail(pack));
        priorityTree->insert(PriorityMail(pack));
        hash->insertHash(pack);
    }
    else
    {
        std::cout << "sorry this package is already in our system" << endl;
    }
}

void printMenu()
{
    std::cout << "READ address mail" << '\t' << "Load data from input files" << endl
              //   << "PRINT n shift" << '\t' << "Print out the list of mail in order of which they need to be sent (starting at shift, at most n entries)" << endl
              //   << "PRINT n " << '\t' << "Print out the list of mail in order of which they need to be sent (from top, at most n)" << endl
              << "LIST" << '\t' << "Print out the list of mail in order of tracking number" << endl
              << "PRINT" << '\t' << "Print out the list of mail in order of which they need to be sent (from top)" << endl
              << "SEARCH tracking_number" << '\t' << "Search for a mail with specific tracking number" << endl
              //   << "MAILBOX address" << '\t' << "List all mail going to given address" << endl
              //   << "STATE state" << '\t' << "List all mail going to state" << endl
              << "SEND n" << '\t' << "Removes first n mails from the list" << endl
              << "REMOVE tracking_number" << '\t' << "Removes mail with id from list" << endl
              << "INSERT" << '\t' << "Guides through inserting a new mail (need a unique tracking number)" << endl
              //  << "PROCESS address mail output"   << '\t' << "Process database generated by address and mail, and write to output" << endl
              //  << "WRITE filename"                << '\t' << "Write processed database to filename" << endl
              //  << "SNAPSHOT address mail"         << '\t' << "Dumps out a snapshot of the database" << endl
              << "CLEAR" << '\t' << "Clear all data from database (destructive!)" << endl
              << "QUIT/EXIT/Q/E" << '\t' << "Exit, and write output to out.txt" << endl;
}
