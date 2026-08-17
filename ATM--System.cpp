#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>
#include "StrLib.h"
using namespace std;

const string filename = "Clients.txt";
enum enATM
{
    eQuickWithDraw = 1,
    eWithDraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eATMMainMenu = 5
};
enum enQuickWithDraw
{
    e50 = 1,
    e100 = 2,
    e250 = 3,
    e400 = 4,
    e500 = 5,
    e750 = 6,
    e1000 = 7,
    e1500 = 8
};
struct stClientInfo
{
    string AccountNumber;
    string PINcode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
};
stClientInfo CurrentClient; // Use it In Any Func
string ClientRecord(stClientInfo Client, string Delim);
void showATMMainMenuScreen();
void HandleATMMainMenu(enATM choice);
void BackToATMMainMenu();
void login();
stClientInfo ConvertRecordToData(string record)
{
    stClientInfo Client;
    std::vector<string> vClientData = StrLib::FillvectorsWithStringWords(record, "#//#");
    Client.AccountNumber = vClientData[0];
    Client.PINcode = vClientData[1];
    Client.FullName = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}
string ClientRecord(stClientInfo Client, string Delim = "#//#"){
    string record = Client.AccountNumber + Delim + Client.PINcode + Delim + Client.FullName;
    record += Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
    return record;
}
std::vector<stClientInfo> LoadDataFileToVector(){
    fstream MyFile;
    std::vector<stClientInfo> vClients;
    string line;
    MyFile.open(filename, std::ios::in);
    if (MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            vClients.push_back(ConvertRecordToData(line));
        }
    }
    return vClients;
}

void SaveDataTofile(std::vector<stClientInfo> &vClients){
    fstream MyFile;
    string line;
    MyFile.open(filename, std::ios::out);
    if (MyFile.is_open())
    {
        for (stClientInfo &C : vClients)
        {
            MyFile << ClientRecord(C) << endl;
        }
        
    }
}
void SyncAndSaveClientData(const stClientInfo &UpdatedClient) {
    vector<stClientInfo> vClients = LoadDataFileToVector();
    for (stClientInfo &C : vClients) {
        if (C.AccountNumber == UpdatedClient.AccountNumber) {
            C = UpdatedClient; // Update vector element with new balance
            break;
        }
    }
    SaveDataTofile(vClients);
}
bool IsClientExist(string AccountNumber, string PINcode, stClientInfo &Client)
{
    vector<stClientInfo> vClients = LoadDataFileToVector();
    for (stClientInfo &U : vClients)
    {
        if (AccountNumber == U.AccountNumber && PINcode == U.PINcode)
        {
            Client = U;
            return true;
        }
    }
    return false;
}
short ReadUserChoice(short from, short to)
{
    short choice;
    do
    {
        cout << "Enter Your Choice [" << from << " - " << to << "]: ";
        cin >> choice;
    } while (choice > to || choice < from);
    return choice;
}
void showATMMainMenuScreen()
{
    system("clear");
    cout << "-----------------------------------------------------------\n";
    cout << "                ATM System Main Menu Screen                \n";
    cout << "-----------------------------------------------------------\n";
    cout << "\t[1] Quick WithDraw.\n";
    cout << "\t[2] Normal WithDraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    enATM choice = (enATM)ReadUserChoice(1, 5);
    HandleATMMainMenu(choice);
}
void BackToATMMainMenu(){
    std::cout << "\nPress Enter to return to the main menu...";
    std::cin.ignore();
    std::cin.get(); 
    showATMMainMenuScreen();
}
int HandleQuickWithDraw(enQuickWithDraw choice)
{
    switch (choice)
    {
    case enQuickWithDraw::e50:
        return 50;
    case enQuickWithDraw::e100:
        return 100;
    case enQuickWithDraw::e250:
        return 250;
    case enQuickWithDraw::e400:
        return 400;
    case enQuickWithDraw::e500:
        return 500;
    case enQuickWithDraw::e750:
        return 750;
    case enQuickWithDraw::e1000:
        return 1000;
    case enQuickWithDraw::e1500:
        return 1500;
    default:
        showATMMainMenuScreen();
    }
    return 0;
}
void QuickWithDraw(stClientInfo &Client)
{
    short amount;
    char sure;
    system("clear");
    cout << "-----------------------------------------\n";
    cout << "          Quick WithDraw Screen          \n";
    cout << "-----------------------------------------\n";
    cout << "-----------------------------------------";
    cout << "\n\n";
    cout << "[1] 50\t\t[2] 100\n";
    cout << "[3] 250\t\t[4] 400\n";
    cout << "[5] 500\t\t[6] 750\n";
    cout << "[7] 1000\t[8] 1500\n";
    cout << "\t[9] Exit\n" << endl;
    cout << "-----------------------------------------";
    cout << "\nYour Balance Is " << Client.AccountBalance << endl;
    enQuickWithDraw UserChoice = (enQuickWithDraw)ReadUserChoice(1 , 9);
    vector<stClientInfo> vClients = LoadDataFileToVector();
    amount = HandleQuickWithDraw(UserChoice);
    if (amount > Client.AccountBalance)
        {
            cout << "the amount exceeds Your Balance , Make Another Choice Next Time...\n";
        }
    else {
    cout << "Are You Sure To Perform This Transaction [Y/n]: ";
    cin >> sure;
    if (tolower(sure) == 'y')
    {
            Client.AccountBalance -= amount;
            cout << "Done SuccesFully, New Balance Is: " << Client.AccountBalance << endl;
        
    }
    }
    SyncAndSaveClientData(Client);
}
void NormalWithDraw(stClientInfo &Client){
    vector<stClientInfo> vClients = LoadDataFileToVector();
    short amount;
    char sure;
    system("clear");
    cout << "-----------------------------------------\n";
    cout << "          Normal WithDraw Screen          \n";
    cout << "-----------------------------------------\n";
    do
    {
        cout << "\nEnter An Amount Multiple of 5's : ";
        cin >> amount;
        
        if (amount > Client.AccountBalance)
        {
            cout << "the amount exceeds Your Balance , Make Another Choice Next Time...\n";
            break;
        }
    } while (amount % 5 != 0);
    cout << "Are You Sure To Perform This Transaction [Y/n]: ";
    cin >> sure;
    if (tolower(sure) == 'y')
    {
        Client.AccountBalance -= amount;
        cout << "Done SuccesFully, New Balance Is: " << Client.AccountBalance << endl;
        
    }
    SyncAndSaveClientData(Client);
}
void Deposit(stClientInfo &Client){
    vector<stClientInfo> vClients = LoadDataFileToVector();
    short amount;
    char sure;
    system("clear");
    cout << "-----------------------------------------\n";
    cout << "              Deposit Screen             \n";
    cout << "-----------------------------------------\n";
        cout << "\nEnter Deposit Amount : ";
        cin >> amount;

    Client.AccountBalance += amount;
    cout << "Done SuccesFully, New Balance Is: " << Client.AccountBalance << endl;
    SyncAndSaveClientData(Client);
}
void CheckBalance(stClientInfo &Client){
    system("clear");
    cout << "-----------------------------------------\n";
    cout << "           Check Balance Screen          \n";
    cout << "-----------------------------------------\n";
    cout << "\nYour Balance Is " << Client.AccountBalance << endl;
}
void HandleATMMainMenu(enATM choice)
{
    std::vector<stClientInfo> vClients = LoadDataFileToVector();
    switch (choice)
    {
    case enATM::eQuickWithDraw:
        QuickWithDraw(CurrentClient);
        BackToATMMainMenu();
        break;
    case enATM::eWithDraw:
        NormalWithDraw(CurrentClient);
        BackToATMMainMenu();
        break;
    case enATM::eDeposit:
        Deposit(CurrentClient);
        BackToATMMainMenu();
        break;
    case enATM::eCheckBalance:
        CheckBalance(CurrentClient);
        BackToATMMainMenu();
        break;
    case enATM::eATMMainMenu:
        login();
        break;
    default:
        break;
    }
}
void login()
{
    system("clear");
    vector<stClientInfo> vClients = LoadDataFileToVector();
    string AccountNumber, PINcode;
    bool LoginFailed = false;
    cout << "--------------------------------------------\n";
    cout << "                Login Screen                \n";
    cout << "--------------------------------------------\n";
    do
    {
        if (LoginFailed)
        {
            cout << "Invalid AccountNumber/PIN code" << endl;
        }
        cout << "Account Number: ";
        cin >> AccountNumber;
        cout << "\nPIN Code: ";
        cin >> PINcode;
        LoginFailed = !IsClientExist(AccountNumber, PINcode, CurrentClient);
    } while (LoginFailed);
    showATMMainMenuScreen();
}
int main()
{
    login();
    return 0;
}
