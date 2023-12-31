/***********
 * Author :   Mohammed Akram
 * Date  :   28 OCT,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 OCT, 2023               Mohammed Akram
***************************************************************************/
#include "../header/User.hpp"


User::User()
:UserId{-1},AllowAnonymousQestions{-1}
{

}
User::User(const string &line)
{
    vector<string>subdtring=SpilitStringToVector(line);
        assert(subdtring.size()==6);
        UserId=StringToInt(subdtring[0]);
        UserName=subdtring[1];
        Password=subdtring[2];
        Name=subdtring[3];
        UserEmail=subdtring[4];
        AllowAnonymousQestions=StringToInt(subdtring[5]);
}
string User::IntegersUserInfoToString()const
{
    ostringstream oss;
        oss<<UserId<<","<<UserName<<","<<Password<<","<<Name<<","<<UserEmail<<","<<AllowAnonymousQestions;

        return oss.str();
}
void User::PrintUserInfo()const
{
        		cout << "User " << UserId << ", " << UserName << " " << Password << ", " << Name << ", " << UserEmail << "\n";

}
void User:: AddToQuestions(const vector<int> & Toquestions)
{
	QuestionsIdForUser.clear();

		for (const auto & question_id : Toquestions)
			QuestionsIdForUser.push_back(question_id);
}
void User:: AddToThreadMap(const vector<pair<int,int>> & Toquestion)
{
	QuestionThreadToIdKey.clear();

		for (const auto & id_pair : Toquestion)
			QuestionThreadToIdKey[id_pair.first].push_back(id_pair.second);
}
void User:: ReadUserInfo(const string & name , int id)
{
	SetUSerName(name);
		SetUserId(id);

		string str;

		cout << "Enter password: ";
		cin >> str;
		SetPasswrd(str);

		cout << "Enter name: ";
		cin >> str;
		SetName(str);

		cout << "Enter email: ";
		cin >> str;
		SetUserEmail(str);

		cout << "Allow anonymous questions? (0 or 1): ";
		int st;
		cin >> st;
		SetAllowAnonymousQestions(st);
}
void User :: SetAllowAnonymousQestions(int _AllowAnonymousQestions)
{
	AllowAnonymousQestions=_AllowAnonymousQestions;
}

int User::  GetAllowAnonymousQestions()const
{
		return AllowAnonymousQestions;
}
void User:: SetUserEmail(const string & email)
{
	UserEmail=email;
}
const string &   User :: GetUserEmail()const
{
	return UserEmail;
}
void User :: SetName(const string & name)
{
	Name=name;
}
const string & User :: GetName()const
{
	return Name;
}
 void User :: SetPasswrd(const string & _password)
 {
	Password=_password;
 }
const string & User ::GetPassword()const
{
	return Password;
}
void User:: SetUSerName(const string & _username)
{
		UserName = _username;
}
const string & User :: GetUsername()const
{
		return UserName;
}
void User :: SetUserId(int _id)
{
		UserId = _id;
}
int User :: GetUserId()const
{
		return UserId;
}
const map<int , vector<int>>& User :: GetQuestionThreadToIdKey()const
{
	return QuestionThreadToIdKey;
}
const vector<int> & User :: GetQuestionsIdForUser()const
{
		return QuestionsIdForUser;
}
UserManager::UserManager()
{
	LastId=0;
}
void UserManager:: LoadDataBase()
{
		LastId=0;
		UserNameToUserObjectMap.clear();
		vector<string>lines=ReadFileLines("users.txt");
		for(const auto & line :lines)
		{	
			User _user (line);
			UserNameToUserObjectMap[_user.GetUsername()]=_user;
			LastId=max(LastId , _user.GetUserId());
		}
}

void UserManager:: AccessSystem()
{
	int choice= ShowReadMenu({"Login" , "SignUp"});
		if(choice==1)
		{
			Login();
		}
		else
		{
			SignUp();	
		}
}
void UserManager:: Login()
{
	LoadDataBase();
	while(true)
 {	
	string name , pass;
	cout<<"Enter USer Name And Password: ";
	cin>>name>>pass;
	CurrentUser.SetUSerName(name);
	CurrentUser.SetPasswrd(pass);
	if(!UserNameToUserObjectMap.count(CurrentUser.GetUsername()))
	{
		cout << "\nInvalid user name or password. Try again\n\n";
		continue;
	}
	const User & USerexit=UserNameToUserObjectMap[CurrentUser.GetUsername()];
	if(CurrentUser.GetPassword()!= USerexit.GetPassword())
	{
		cout << "\nInvalid user name or password. Try again\n\n";
				continue;
	}
	CurrentUser=USerexit;
	break;
}
}
void UserManager:: SignUp()
{
	string user_name;
	while(true)
	{
		cout << "Enter user name. (No spaces): ";
			cin >> user_name;

			if (UserNameToUserObjectMap.count(user_name))
				cout << "Already used. Try again\n";
			else
				break;
	}
	CurrentUser.ReadUserInfo(user_name, ++LastId);
		UserNameToUserObjectMap[CurrentUser.GetUsername()] = CurrentUser;

		UpDataDataBase(CurrentUser);

}
void UserManager:: AddToQuestionsToCurrentUser(const vector<int> & Toquestions)
{
		CurrentUser.AddToQuestions(Toquestions);
}
void UserManager:: AddToThreadMapToCurrentUser(const vector<pair<int,int>> & Toquestion)
{
	CurrentUser.AddToThreadMap(Toquestion);
}
void UserManager:: DisplayUserNameAndIds()const
{
	for(const auto & pair : UserNameToUserObjectMap)
	{
			cout << "ID: " << pair.second.GetUserId() << "\t\tName: " << pair.second.GetName() << "\n";

	}
}
pair<int , int > UserManager:: ReadUserId()const
{
	int user_id;
		cout << "Enter User id or -1 to cancel: ";
		cin >> user_id;

		if (user_id == -1)
			return make_pair(-1, -1);

		for (const auto &pair : UserNameToUserObjectMap) {
			if (pair.second.GetUserId() == user_id)
				return make_pair(user_id, pair.second.GetAllowAnonymousQestions());
		}

		cout << "Invalid User ID. Try again\n";
		return ReadUserId();

}
void UserManager:: UpDataDataBase(const User & user)
{
	string line = user.IntegersUserInfoToString();
		vector<string> lines(1, line);
		WriteFileLines("users.txt", lines);

}
const User& UserManager:: GetCurrentUser()
{	
	return CurrentUser;

}
   
