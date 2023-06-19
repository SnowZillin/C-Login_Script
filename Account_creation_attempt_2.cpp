#include <iostream>
using namespace std;


int Account_Login(string *username_list, string *password_list, int account_list_length){

    while(true){

        bool correct_credential_status = false;

        cout << "Please enter credentials, to quit enter q." << endl;
        cout << "Username: " << flush;
        string inputted_username;
        cin >> inputted_username;

        if(inputted_username == "q"){
            return 1;
        }

        cout << "Password: " << flush;
        string inputted_password;
        cin >> inputted_password;

        //Asks user to input username and password, or quit and return to main

        for(int i=0; i<account_list_length; i++){

            if(inputted_username == username_list[i] && inputted_password == password_list[i]){
                correct_credential_status = true;
            }
        }

        //Loops through array of known usernames and passwords, if both inputted username and password matches an account, then correct_credential_status set true 

        if(correct_credential_status){
            return 0;
        }

        //If correct_credential_status set true, returns to main and quits program

    }
    
}

//User inputs credentials or chooses to quit, if inputs matches with an account program ends

string Account_Creation(string *username_list, string *password_list, int account_list_length){
    
    while(true){

        creation_start:
    
        cout << "Please enter credentials, to quit enter q." << endl;
        cout << "Username: " << flush;
        string inputted_username;
        cin >> inputted_username;

        //Prompts user for username, or if they want to quit

        if(inputted_username == "q"){
            return "Quit";
        }

        //Quits if a user enters q

        for(int i=0; i<account_list_length; i++){
            if(inputted_username==username_list[i]){
                cout << "Duplicate Username, please try again." << endl;
                goto creation_start;
            }
        }

        //If inputted_username is a duplicate of a username already in username_list, we restart account creation

        cout << "Password: " << flush;
        string inputted_password;
        cin >> inputted_password;

        //Prompts user for password

        string updated_username_list[account_list_length+1];
        string updated_password_list[account_list_length+1];

        for(int i=0; i<(account_list_length+1); i++){
            
            if(i < account_list_length){
                updated_username_list[i] = username_list[i];
                updated_password_list[i] = password_list[i];
            }
            else{
                updated_username_list[i] = inputted_username;
                updated_password_list[i] = inputted_password;
            }
        }

        //Creates 2 new lists with old and new usernames and passwords respectivly

        //Implementation needed of a way to return an array

    }

    //Loops until user quits or creates a new account

    return "OK";
}

//User chooses to create a new account or quit, then returns an updated username_list and password_list

int main(){

    string current_usernames[]={"Admin","Admin2","Admin3"};
    string current_passwords[]={"Test","Test2","Test3"};

    //Creates default passwords

    while(true){

        int account_list_length = sizeof(current_usernames)/sizeof(current_usernames[0]);

        cout << "Login (1) or Create Account (2): " << flush;
        string user_login_or_creation_choice;
        cin >> user_login_or_creation_choice;

        //Prompts user to login to an existing account, or create a new one

        if(user_login_or_creation_choice=="1"){

            if(Account_Login(current_usernames,current_passwords,account_list_length) == 0){
                cout << "Correct credentials, now exiting." << endl;
                break;
            }
            else{
                cout << "You chose to quit" << endl;
            }
            
        }

        //Calls the Account_Login function, if user inputs correct credentials the program ends, if user chooses to quit inputting credentials the loop restarts

        else if(user_login_or_creation_choice=="2"){
            Account_Creation(current_usernames,current_passwords, account_list_length);
        }

        //Creates a new account or quits to restart the loop, implemtation needed

        else{
            cout << "Invalid choice, redirecting..." << endl;
        }

        //If user inputs an invalid option when chosing between logging in (1) or creating an account (2), loop restarts

    }

}

//User choses to login to an existing account, or create a new one, if user logs in successfully, program ends
