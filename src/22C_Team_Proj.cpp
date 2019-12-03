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
void buildBSTs(BinarySearchTree<PriorityMail> *priority, BinarySearchTree<TrackingMail> *tracking, HashTable<Mail> *hash, string mail, string address);
void inputManager(BinarySearchTree<PriorityMail> *priorityTree, BinarySearchTree<TrackingMail> *trackingTree, HashTable<Mail> *hash);
void printMenu();

/**
This is the best I can think of and I think we need to add setter for the tracking number and the address.
**/
int main()
{
    HashTable<Mail> *hash = new HashTable<Mail>();
    BinarySearchTree<TrackingMail> *trackingTree = new BinarySearchTree<TrackingMail>();
    BinarySearchTree<PriorityMail> *priorityTree = new BinarySearchTree<PriorityMail>();

    //Init data structs
    printMenu();

    string choice = "";
    string options = "";
    while (true)
    {
        std::cout << "Pick an option" << endl;
        std::getline(std::cin, choice);
        int tmp = choice.find(" ");
        if (string::npos != choice.find(" "))
        {
            options = choice.substr(tmp + 1); // + 1 to drop off the space
            choice = choice.substr(0, tmp);
        }
        else
            options = "";
        if (choice == "READ")
        {
            string addressFile, mailFile;
            if (string::npos != options.find(" "))
            {
                mailFile = options.substr(options.find(" ") + 1);
                addressFile = options.substr(0, options.find(" "));
                buildBSTs(priorityTree, trackingTree, hash, mailFile, addressFile);
            }
            else
            {
                cout << "Bad options" << endl;
            }
        }
        else if (choice == "PRINT")
        {
            printMail(trackingTree);
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
            int n = stoi(options);
            Mail m;
            PriorityMail pm;
            TrackingMail tm;
            for (int i = 0; i < n; i++)
            {
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
            delete hash;
            delete trackingTree;
            delete priorityTree;
            hash = new HashTable<Mail>();
            trackingTree = new BinarySearchTree<TrackingMail>();
            priorityTree = new BinarySearchTree<PriorityMail>();
        }
        else if (choice == "QUIT" || choice == "EXIT" || choice == "Q" || choice == "E")
        {
            cout << endl
                 << endl
                 << "Goodbye!" << endl;
            return 0;
        }
        else
        {
            cout << "Bad Directive" << endl;
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

    // Address a[10000];
    // while (std::getline(inFile2, tmp))
    // {
    //     string delimiter = "\t";
    //     size_t v = tmp.find(delimiter);
    //     id = stoi(tmp.substr(0, v));
    //     size_t v2 = tmp.find(delimiter, v + 1);
    //     street = tmp.substr(v + 1, v2 - 1);
    //     v = v2;
    //     v2 = tmp.substr(v + 1).find(delimiter);
    //     city = tmp.substr(v + 1, v2 - 1);
    //     v = v2;
    //     v2 = tmp.find(delimiter, v + 1);
    //     state = tmp.substr(v + 1, v2 - 1);
    //     v = v2;
    //     cout << id << endl
    //          << street << endl
    //          << city << endl
    //          << state << endl
    //          << tmp.substr(v + 1) << endl;
    //     zip = stoi(tmp.substr(v + 1));
    //     // cout << "hi";
    //     cout
    //         << zip << endl;
    //     a[id] = Address(street, city, State(state), zip);
    //     cout << a[id];
    // }
    Address arr[100];
    arr[0] = Address("4136 Minerva Green Nestor Alley", "South Ceciliamouth", State("NE"), 45310);
    arr[1] = Address("29 Kirlin Crest Kunze Spur", "East Brice", State("WY"), 4949);
    arr[2] = Address("114 Renner Wall Weston Square", "East Jess", State("NC"), 46494);
    arr[3] = Address("1027 Schumm Manors Dorthy Camp", "Jenningsmouth", State("UT"), 60458);
    arr[4] = Address("31 Herman Drives Keara Island", "West Jarrettmouth", State("IA"), 64134);
    arr[5] = Address("070 Wehner Neck Marcia Knoll", "East Amirhaven", State("NC"), 62803);
    arr[6] = Address("9524 Javier Villages Maxime Via", "Nellefurt", State("TX"), 84372);
    arr[7] = Address("2739 Wiza Summit Woodrow Stravenue", "Lake Kyleestad", State("AK"), 97196);
    arr[8] = Address("38 Regan Mountains Daugherty Haven", "New Autumnberg", State("NC"), 39356);
    arr[9] = Address("90 Keshawn Fields Macejkovic Ranch", "New Axelview", State("UT"), 52621);
    arr[10] = Address("953 Hilpert Forges Moore Mills", "Nikolasburgh", State("WI"), 73333);
    arr[11] = Address("8786 Jacobson Flat Hintz Extensions", "O'Keefefort", State("IA"), 19934);
    arr[12] = Address("39790 Tabitha Camp Webster Court", "Hiltonton", State("DE"), 27697);
    arr[13] = Address("2858 Macie Lights Goyette Parks", "East Lurahaven", State("KY"), 47668);
    arr[14] = Address("71152 Zelda Club Alessandra Mills", "East Doloresborough", State("NC"), 83807);
    arr[15] = Address("69036 Wilfredo Orchard Welch Ramp", "New Eliseo", State("NY"), 6950);
    arr[16] = Address("006 Gleason Mission Vella Walks", "East Tomas", State("PA"), 59156);
    arr[17] = Address("203 Prosacco Corner Dillan Brooks", "Hayesview", State("AZ"), 59043);
    arr[18] = Address("17258 Batz Loop Lynch Mountains", "Kautzerbury", State("OR"), 87044);
    arr[19] = Address("404 Larue Spur Fleta Pass", "Sanfordhaven", State("ND"), 92387);
    arr[20] = Address("8335 Lindsay Forge Brooke Brooks", "Dulcemouth", State("AR"), 80281);
    arr[21] = Address("6231 Ernie Camp Hilll Trail", "Zboncakmouth", State("DE"), 1379);
    arr[22] = Address("8712 Alyson Underpass O'Hara Pike", "New Brant", State("ME"), 96763);
    arr[23] = Address("8275 Lucio Gateway Jordane Hills", "Mayerview", State("WV"), 16305);
    arr[24] = Address("13646 Hayley Way Rowan Fort", "Leonardborough", State("DE"), 23146);
    arr[25] = Address("976 Sunny Burgs Herzog Stream", "East Vito", State("SC"), 11637);
    arr[26] = Address("17565 Kacey Coves Conroy Parks", "North Maudie", State("RI"), 29963);
    arr[27] = Address("832 Windler Trail Schowalter Cliffs", "Rhettland", State("CA"), 16515);
    arr[28] = Address("285 Rosenbaum Ports Kenyatta Forest", "Port Ivy", State("KY"), 52138);
    arr[29] = Address("227 Brady Walks Jody Manors", "Gleasonfort", State("MN"), 80041);
    arr[30] = Address("27259 Satterfield Mission Demarco Flat", "North Kristina", State("NY"), 13890);
    arr[31] = Address("8512 DuBuque Harbors Delaney Drive", "Margaritachester", State("AK"), 25425);
    arr[32] = Address("780 Herzog Tunnel Abshire Manors", "South Carminefort", State("NM"), 96586);
    arr[33] = Address("59257 Carmela Ferry Runolfsdottir Island", "Kaleview", State("FL"), 3095);
    arr[34] = Address("23215 Elmer Canyon Maxime Passage", "South Deron", State("IA"), 83810);
    arr[35] = Address("697 Schoen Grove Reilly Ridges", "East Constantinland", State("MI"), 27354);
    arr[36] = Address("1259 Bernard Green Dibbert Mill", "Darianshire", State("NV"), 7495);
    arr[37] = Address("3975 Jace Islands Arlie Streets", "North Adolphhaven", State("OR"), 28149);
    arr[38] = Address("121 Cecil Roads Armstrong Island", "Roobfurt", State("TN"), 99589);
    arr[39] = Address("49218 Ben Village Gleason Junctions", "Darianhaven", State("ND"), 18946);
    arr[40] = Address("0267 Lockman Ford Miguel Lights", "South Julian", State("VA"), 64631);
    arr[41] = Address("85515 Aliyah Mills Jeanette Skyway", "Port Breanneborough", State("AR"), 91781);
    arr[42] = Address("86632 Murphy Trail Mitchell Canyon", "Rohanside", State("HI"), 15156);
    arr[43] = Address("81317 Kihn Ridge Carroll Forks", "Naomieburgh", State("OH"), 32742);
    arr[44] = Address("011 Bruce Track Macejkovic Summit", "New Jamil", State("CO"), 58844);
    arr[45] = Address("837 White Mission Ashlee Loaf", "East Felixmouth", State("NC"), 84662);
    arr[46] = Address("9927 Monique Groves McDermott Spurs", "Sibylburgh", State("WI"), 9185);
    arr[47] = Address("5281 Lora Prairie Braun Viaduct", "New Jaimeport", State("TX"), 52150);
    arr[48] = Address("7508 Mariela Harbors Cremin Place", "Lake Nelda", State("KY"), 79422);
    arr[49] = Address("995 Kohler Knolls Johns Common", "South Quinnton", State("CA"), 94393);
    arr[50] = Address("65961 Steuber Islands Carmela Glens", "Cielomouth", State("WI"), 74078);
    arr[51] = Address("1811 Abbott Locks Emmet Burg", "North Jovaniberg", State("CO"), 9212);
    arr[52] = Address("778 Blanda Trail Cormier Well", "Dinoside", State("GA"), 18397);
    arr[53] = Address("39343 Colten Meadows Daniela Neck", "Port Mavismouth", State("CT"), 36320);
    arr[54] = Address("3425 Grant Island Nyasia Fall", "Beckerbury", State("HI"), 50389);
    arr[55] = Address("248 Jacobson Estate Johnson Spur", "Erikberg", State("OR"), 55587);
    arr[56] = Address("86769 Block Island Klein Trail", "Lake Godfrey", State("PA"), 69829);
    arr[57] = Address("69116 Purdy Highway Mayer Centers", "Ninabury", State("MD"), 82981);
    arr[58] = Address("999 Karelle Ranch Ruth Creek", "Lake Carletonhaven", State("CO"), 47540);
    arr[59] = Address("91618 Colleen Islands Durgan Locks", "Boganbury", State("SD"), 84991);
    arr[60] = Address("95035 Torrance Isle Gilbert Fields", "Joyport", State("NY"), 45433);
    arr[61] = Address("29326 Dickinson Stravenue Ken Forge", "East Adolf", State("CT"), 92144);
    arr[62] = Address("4570 Stamm Drives Daisha Fork", "New Keyonville", State("PA"), 69054);
    arr[63] = Address("9215 Conroy Port Marianna Landing", "South Aishamouth", State("WY"), 56138);
    arr[64] = Address("86930 Herman Square Sandra Isle", "Hadleyshire", State("MS"), 01131);
    arr[65] = Address("072 Turcotte Rest Rosenbaum Drive", "Trantowshire", State("DE"), 51512);
    arr[66] = Address("062 Edwardo Avenue Nathan Green", "East Reta", State("KS"), 47621);
    arr[67] = Address("26835 Gleason Pike Braun Divide", "Johnsontown", State("IN"), 16656);
    arr[68] = Address("2270 Libby Lake Reinger Forest", "Haleystad", State("MA"), 83996);
    arr[69] = Address("147 Gleichner Parks Emmerich Crescent", "Adrainton", State("FL"), 25564);
    arr[70] = Address("00969 Carter Ferry Lang Ports", "Bennyburgh", State("VA"), 50388);
    arr[71] = Address("7292 Jaskolski Roads Bins Common", "Lake Melvin", State("OR"), 29291);
    arr[72] = Address("527 Roosevelt Ridge Beahan Knolls", "East Martine", State("UT"), 02232);
    arr[73] = Address("5312 Altenwerth Loop Alan Radial", "Lake Blancheview", State("UT"), 29164);
    arr[74] = Address("5860 Lebsack Plains Helene Ports", "East Cobytown", State("OK"), 83774);
    arr[75] = Address("28241 Rodriguez Spring Dallin Well", "New Barbara", State("UT"), 29893);
    arr[76] = Address("097 Kuvalis Mission Graham Highway", "Lake Carroll", State("NM"), 40274);
    arr[77] = Address("51999 Krajcik Neck Cristal Skyway", "Stuartshire", State("IL"), 02475);
    arr[78] = Address("7222 Conn Manors Breitenberg Common", "North Demarcusmouth", State("MO"), 88281);
    arr[79] = Address("05873 Odell Harbor Yasmine Spurs", "North Jane", State("AR"), 03427);
    arr[80] = Address("455 Wilson Shores Glover Meadow", "Tedbury", State("GA"), 51740);
    arr[81] = Address("30939 Waters Harbor Tiara Turnpike", "East Camryn", State("ID"), 89675);
    arr[82] = Address("64564 Klocko Street Thiel Center", "Hamillbury", State("NM"), 97040);
    arr[83] = Address("49345 Schimmel Inlet Hyatt Greens", "Boganburgh", State("WA"), 20595);
    arr[84] = Address("2227 Paucek Lock Willms Forks", "West Rosannachester", State("GA"), 12326);
    arr[85] = Address("086 Kulas Flats Monahan Route", "East Agustin", State("MA"), 82456);
    arr[86] = Address("554 Rocky Track Wendy Inlet", "Lakinfurt", State("WA"), 27661);
    arr[87] = Address("252 Crist Port Rath Stream", "Larkinfurt", State("FL"), 82175);
    arr[88] = Address("005 Donnelly Fields Shad Ferry", "New Humberto", State("SD"), 56960);
    arr[89] = Address("463 Thompson Wall Ward Street", "Port Lancetown", State("WY"), 18377);
    arr[90] = Address("1593 Katelynn Ferry O'Connell Drives", "Justonmouth", State("MI"), 83839);
    arr[91] = Address("6185 Willis Squares Kaylee Lake", "Port Ansel", State("VA"), 74377);
    arr[92] = Address("28828 Kris Station Daugherty Way", "Reichelton", State("MA"), 96058);
    arr[93] = Address("8601 Brown Brook Towne Lodge", "South Edwinaside", State("AL"), 32243);
    arr[94] = Address("0876 Roberta Stravenue Ova Locks", "Alessandroshire", State("CT"), 40367);
    arr[95] = Address("52278 Lula Manor Woodrow Village", "North Frankton", State("HI"), 13423);
    arr[96] = Address("02161 Eleazar Turnpike Guiseppe Stravenue", "New Braulio", State("WA"), 99247);
    arr[97] = Address("766 Alyce Route Casper Forge", "Kaelynmouth", State("TX"), 23779);
    arr[98] = Address("2255 Hegmann Cliff McLaughlin Ways", "West Lloyd", State("NC"), 22570);
    arr[99] = Address("37105 Gabe Mission Reginald Ramp", "Lake Dayna", State("TN"), 14751);

    Mail m;
    while (inFile >> id >> from >> to >> datestr >> type)
    {
        // cout << datestr;
        m = Mail(id, arr[from], arr[to], Date(datestr), Type(type));
        // cout << m;
        priority->insert(PriorityMail(m));
        tracking->insert(TrackingMail(m));
        hash->insertHash(m);
    }

    inFile.close();
    inFile2.close();
}

/* *********************************************************
input: This function allows you to insert a mail object and also checks for duplicate objects
input parameters: BST mytree, BST mytree2, hash
************************************************************/

void inputManager(BinarySearchTree<PriorityMail> *priorityTree, BinarySearchTree<TrackingMail> *trackingTree, HashTable<Mail> *hash)
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
    std::getline(std::cin, streetname);
    std::cout << "enter a city (sender)\n";
    std::getline(std::cin, city);
    std::cout << "enter a state (sender)\n";
    std::getline(std::cin, state);
    std::cout << "enter a zip or postal code (5 digits) (sender)\n";
    std::cin >> zip;
    std::cout << "enter what type of package it is (priority, economy, normal) \n";
    std::getline(std::cin, type);
    Address sender = Address(streetname, city, State(state), zip);
    std::cout << "enter a street address (recipient)\n";
    std::getline(std::cin, streetname);
    std::cout << "enter a city (recipient)\n";
    std::getline(std::cin, city);
    std::cout << "enter a state (recipient)\n";
    std::getline(std::cin, state);
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
              << "PRINT" << '\t' << "Print out the list of mail in order of which they need to be sent (from top)" << endl
              << "SEARCH tracking_number" << '\t' << "Search for a mail with specific tracking number" << endl
              //   << "MAILBOX address" << '\t' << "List all mail going to given address" << endl
              //   << "STATE state" << '\t' << "List all mail going to state" << endl
              << "SEND n" << '\t' << "Removes first n mails from the list" << endl
              << "REMOVE tracking_number" << '\t' << "Removes mail with id from list" << endl
              << "INSERT" << '\t' << "Guides through inserting a new mail (specify tracking number, but does a duplicate check)" << endl
              //  << "PROCESS address mail output"   << '\t' << "Process database generated by address and mail, and write to output" << endl
              //  << "WRITE filename"                << '\t' << "Write processed database to filename" << endl
              //  << "SNAPSHOT address mail"         << '\t' << "Dumps out a snapshot of the database" << endl
              << "CLEAR" << '\t' << "Clear all data from database (prompt for confirmation!)" << endl
              << "QUIT/EXIT/Q/E" << '\t' << "Exit, and write output to out.txt" << endl;
}