/***********
 * Author :   Mohammed Akram
 * Date  :   6 AUg,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              6 Aug, 2023               Mohammed Akram
***************************************************************************/
#include <iostream>
#include <string>
#include "APIS.hh"

using namespace std;



string name [MAX_SPECIALIZATIONS+1][MAX_QUEUE_LENGTH+1]; // array to store the name of patient 
int status [MAX_SPECIALIZATIONS+1][MAX_QUEUE_LENGTH+1]; // array to store the status of every patient
int max_queue_length[MAX_SPECIALIZATIONS+1]; //frequency array to count the number of every patient in every specialization 

/*  using this api as a gui for user th choose the function    */
int Gui()
{   
        int choice = -1 ;
        while(choice==-1)
        {
        cout<<"\t\t\t Enter Your Choice\n";
        cout<<"1) Add a new patient \n";
        cout << "2) Print all patients\n";
		cout << "3) Get next patient\n";
		cout << "4) Exit\n";
        cin>>choice;
        if(!1<=choice&&choice>=4)
        {
            cout << "Invalid choice. Try again\n";
			choice = -1;
        }
        }  
        return choice;      
}
/* this is a help function to delete pataient from the front of queue  */
static void ShiftLeft(int x , string _name[], int _statuse[])
{
    int length=max_queue_length[x];
    for (int i = 1; i < length; i++)
    {
        _name[i-1]=_name[i];
        _statuse[i-1]-_statuse[i];

    }
    max_queue_length[x]--;
    
}
/* another help function to add a urgent patient in the first place in the queue*/
 static void ShiftRight(int specializtion , string _name[], int _status [])
{
    int length=max_queue_length[specializtion];
    for(int i = length-1 ; i >=0 ; i--)
    {
        _name[i+1]=_name[i];
        _status[i+1]=_status[i];
    }
    max_queue_length[specializtion]++;
}
/* help function that take the specialization and print all patient*/
static void printpatient(int x , string _name[], int _status[])
{
    int length=max_queue_length[x];
    if(length==0)
    {
        return;
    }
    cout<<"Number of patient in this specializtion: "<<x<<" = "<<length<<"\n";
    for(int i = 0 ; i < length ;i++ )
    {
        cout<<_name[i]<<" ";
        if(_status[i]==0)
        {
            cout<<"regular\n";
        }
        else
        {
            cout<<"Urgent\n";
        }
    }
    cout<<"\n";
}
bool AddNewPatient()
{
    
    int specializtion =0;
    cout<<"\t Enter the speializtion\n";
    
    while (specializtion==0)
    {
        cin>>specializtion;
    if(!1<=specializtion&&specializtion>=20)
    {
        cout<<"invalid specializtion\n";
        cout<<"********************************************\n";
        cout<<"Enter the speializtion\n";
        specializtion=0;
    
    }
    
    }
    int pos=max_queue_length[specializtion];
    if(pos>=5)
    {
        cout<<"cant add patient to this spspecializtion\n";
        cout<<"*******************************************\n";
        return false;
    }
    else
    {
        int patientstatus=-1; 
        string patientname ;
        while(patientstatus==-1)
        {
            cout<<"\tEnter patient name\n";
            cin>>patientname;
            cout<<"Enter the patient status\n";
            cin>>patientstatus;
            
        }
        if(patientstatus==0)
        {
            name[specializtion][pos]=patientname;
            status[specializtion][pos]=patientstatus;
            max_queue_length[specializtion]++;
        }
        else
        {
            ShiftRight(specializtion,name[specializtion],status[specializtion]);
            name[specializtion][0]=patientname;
            status[specializtion][0]=patientstatus;

        }
        return true;
    }

}

void PrintAllPatient()
{
    cout<<"************************************************\n";
    for(int i =0 ; i <= 20 ; i++)
    {
        printpatient(i , name[i],status[i]);
        cout<<"********************************************\n";
    }
}


void GetNextPatient()
{
    int spec;
    cout << "Enter specialization: ";
	cin >> spec;

	int len = max_queue_length[spec];
    if(len==0)
    {
        cout<<" NO Waiting Patient\n";
    }
    cout<<name[spec][0]<<" please go with the Dr\n";
    cout<<"******************************************************\n";
    ShiftLeft(spec,name[spec],status[spec]);



}

void Hospital_Appliction()
{
    while (true)
    {
        int UserChoice=Gui();
        switch (UserChoice)
        {
        case 1:
            AddNewPatient();
            break;
        case 2:
            PrintAllPatient();
            break;
        case 3:
            GetNextPatient();
            break;
        case 4 :
            break;
        default:
            break;
        }
    }
    
}


