/***********
 * Author :   Mohammed Akram
 * Date  :   17 Aug,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              17 Aug, 2023               Mohammed Akram
***************************************************************************/

/*
    @brief
            This overview ofthe project is  people ask questions and other answers them 
            project consist of 5 structs, maps, vectors and two files  

*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;

/* 
    @brief
        function take the string and dafault argument the split sting to vector of string
        int this function use comma as a delimiter

*/
vector<string> SpilitStringToVector(string _line , string Delimiter=",")
{   
    vector<string>strings;
    int DelimiterPostion=0;
    string SubString;
    while((DelimiterPostion=(int)_line.find(Delimiter)) != -1)
    {
        SubString=_line.substr(0,DelimiterPostion);     //take the string from postion zero to delemiter postion
        strings.push_back(SubString);           //pusth the string to the vector of string
        _line.erase(0,DelimiterPostion+Delimiter.length());     //delete the string from 0 to after of delimiter
    }
    strings.push_back(_line);     //push last string after delimiter to vector

    return strings;   //return the vector of string

}
/*+
        @brief
            function that take strig and cast it to integer by using sstream library

*/
int StringToInt(string s)
{
    istringstream iss(s);  //assin string to iss that is object of fstream
    int num ;

    iss >> num; //assign the string to integer variable
    return num ;
}
/*
    @brief
        function to read a line from file and push it to vector of string

*/
vector<string> ReadLinesFromFile(string FilePath)
{
        vector<string>lines;
        fstream Userfile(FilePath.c_str());     // take object of fstram and assign it to file path 
        if(Userfile.fail())     //check if can't open the file
        {
            cout<<"\n\nCan't Open File\n\n";
        }
        string line;
        while(getline(Userfile,line))
        {
            if(line.size()==0)
            {
                continue;
            }
            lines.push_back(line);
        }
        Userfile.close();
        return lines;
}

/*
    @brief
        function to write string in the file
        with dafault argument to appand not to delete the content and start to write

*/
void WriteFileLines(string path, vector<string> lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// this status to overwrite not to appand 

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (auto line : lines) //iterators for vector 
		file_handler << line << "\n";  // write in the file

	file_handler.close();
}
/*
    @brief  
            function to read the user input that take the range of input 
            from the minmum number of choice and the max number of choice 

*/
int ReadInt(int low, int high) {
	cout << "\nEnter number in range " << low << " - " << high << ": ";
	int value;

	cin >> value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);      // to call the function agian when the input is invalid
}
/*
    @brief
        function to display the exist choice
        take a vector of string and display all choice
*/
int ShowReadMenu(vector<string> choices) {
	cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}


/*    struct for Question 

            questions inforamtions
            some functions to print print rhe question and its answer
*/
struct Question
{   
    /*  struct   Data members*/
    int QuestionId;
    int ParentQestionId;
    int QuestionFromUserId;
    int QuestionToUserId;
    int AnonymousOrNot;
    string QuestionText;
    string AnswerText;
    Question()
    {
        QuestionId=ParentQestionId=QuestionFromUserId=QuestionToUserId=-1;
        AnonymousOrNot=1;
    }
    Question(string line)
    {
            vector<string>substring=SpilitStringToVector(line);
            assert(substring.size()==7);
            QuestionId=StringToInt(substring[0]);
            ParentQestionId=StringToInt(substring[1]);
            QuestionFromUserId=StringToInt(substring[2]);
            QuestionToUserId=StringToInt(substring[3]);
            AnonymousOrNot=StringToInt(substring[4]);
            QuestionText=substring[5];
            AnswerText=substring[6];
    }

            /*
                struct funcions
            */
    string INtegersQuestionInfoToString()
    {
        ostringstream oss;
     
        oss<<QuestionId<<","<<ParentQestionId<<","<<QuestionFromUserId<<","<<QuestionToUserId<<","<<AnonymousOrNot<<","<<QuestionText<<","<<AnswerText;

            return oss.str();
    }
    void PrintToQuestion()
    {
        string prefix ="";
        if(ParentQestionId!=-1)
        {
            prefix="\tThread: ";
        }
        cout<<"Question Id ("<<QuestionId<<")";

        if(!AnonymousOrNot)
        {
            cout<<"From User Id("<<QuestionFromUserId<<")";
        }
        
        cout<<"Question: "<<QuestionText<<"\n";

        if(AnswerText!="")
        {
            cout<<prefix<<"\tAnswer: "<<AnswerText<<"\n";
        }
        cout<<"\n";
    }

    void PrintFromQuestion()
    {
        cout<<"Question Id("<<QuestionId<<")";
        if(!AnonymousOrNot)
        {
            cout<<"!AQ";
        }
        cout<<" To User Id("<<QuestionToUserId<<")";
        cout<<"\tQuestion "<<QuestionText;
        if(AnswerText!="")
        {
            cout<<"\tAnswer: "<<AnswerText<<"\n";
        }
        else
        {
            cout<<"\tNot Answered Yet\n";
        }
    }
    void PrintFeedQuestion()
    {
        if(ParentQestionId!=-1)
        {
            cout<<"Thread Parent Question ID ("<<ParentQestionId<<")";
        }
        cout<<"Question Id ("<<QuestionId<<")";

        if(!AnonymousOrNot)
        {
            cout<<"From User Id("<<QuestionFromUserId<<")";
        }
         cout<<" To User Id("<<QuestionToUserId<<")";
        cout<<"\tQuestion "<<QuestionText;
        if(AnswerText!="")
        {
            cout<<"\tAnswer: "<<AnswerText<<"\n";
        }
    }

};
/*      struct for user
            user info 
            functions to read user info and cointiners for questions

*/

struct User
{
    int UserId;
    string UserName;
    string Password;
    string Name;
    string UserEmail;
    int AllowAnonymousQestions;

    vector<int>QuestionsIdForUser; // vector to store the questions IDs for this user

    map<int,vector<int>>QuestionThreadToIdKey; // this map contain question id and vector for all answers

    User()
    {
        UserId=AllowAnonymousQestions=-1;
    } 

    User(string line)
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

   string IntegersUserInfoToString()
   {
        ostringstream oss;
        oss<<UserId<<","<<UserName<<","<<Password<<","<<Name<<","<<UserEmail<<","<<AllowAnonymousQestions;

        return oss.str();
   }
   void PrintUserInfo()
   {
    		cout << "User " << UserId << ", " << UserName << " " << Password << ", " << Name << ", " << UserEmail << "\n";

   }
};
/* struct to manage questions

*/

struct ManageQuestions
{
    map<int , vector<int>>QuestionIdQestionsThreadMap; // map to store the question id as a key and vector of strings of answers as a value 
    map<int, Question>QuestionsIdQuestionObject;        // map to store the question id as key and vector of string of object of this question
    int LastQuestionId;
    ManageQuestions()
    {
        LastQuestionId=0;
    }
    void LoadDataBase()
    {
        LastQuestionId=0;
        QuestionIdQestionsThreadMap.clear();
        QuestionsIdQuestionObject.clear();
        vector<string>lines=ReadLinesFromFile("questions.txt");
        for(auto &line : lines)
        {
            Question NewQuestion(line);
            LastQuestionId=max(LastQuestionId,NewQuestion.QuestionId);
            QuestionsIdQuestionObject[NewQuestion.QuestionId]=NewQuestion;
            if(NewQuestion.ParentQestionId==-1)
            {
                QuestionIdQestionsThreadMap[NewQuestion.QuestionId].push_back(NewQuestion.QuestionId);
            }
            else
            {
                QuestionIdQestionsThreadMap[NewQuestion.ParentQestionId].push_back(NewQuestion.QuestionId);

            }
        }
    }
    void FillUserQuestion(User & _user)
    {
        _user.QuestionsIdForUser.clear();
        _user.QuestionThreadToIdKey.clear();
        for(auto &pair : QuestionIdQestionsThreadMap)
        {
            for(auto & questionid : pair.second)
            {
                Question & question=QuestionsIdQuestionObject[questionid];
                if(question.QuestionFromUserId==_user.UserId)
                {
                    _user.QuestionsIdForUser.push_back(question.QuestionId);
                }
            }
        }
    }
    void PrintUserToQuestion(User &_User)
    {
        cout<<"\n";
        if(_User.QuestionThreadToIdKey.size()==0)
        {
            cout<<"No Questions";
        }
        for(auto &pair :_User.QuestionThreadToIdKey)
        {
            for(auto & _QuestionId:pair.second)
            {
                Question & question=QuestionsIdQuestionObject[_QuestionId];
                question.PrintToQuestion();
            }
        }
        cout<<"\n";
    }
    void PrintUserFromQuestion(User &_User)
    {
        cout<<"\n";
        if(_User.QuestionsIdForUser.size()==0)
        {
            cout<<"No Questions";
        }
        for(auto &_questionid : _User.QuestionsIdForUser)
        {
            Question & question=QuestionsIdQuestionObject[_questionid];
            question.PrintFromQuestion();
        }
        cout<<"\n";

    }
    int ReadQuestionId(User & _user)
    {
        int question_id;
        cout<<"Enter Question id or -1 to cancel: ";
        cin>>question_id;
        if(!QuestionsIdQuestionObject.count(question_id))
        {
            cout << "\nERROR: No question with such ID. Try again\n\n";
			return ReadQuestionId(_user);
        }
        Question & question=QuestionsIdQuestionObject[question_id];
        if(question.QuestionId != _user.UserId)
        {
            cout << "\nERROR: Invalid question ID. Try again\n\n";
			return ReadQuestionId(_user);
        }
        return question_id;
    }
    int ReadQuestionIdThread(User &user) {
		int question_id;
		cout << "For thread question: Enter Question id or -1 for new question: ";
		cin >> question_id;

		if (question_id == -1)
			return -1;

		if (!QuestionIdQestionsThreadMap.count(question_id)) {
			cout << "No thread question with such ID. Try again\n";
			return ReadQuestionIdThread(user);
		}
		return question_id;
	}

	void AnswerQuestion(User &user) {
		int question_id = ReadQuestionId(user);

		if (question_id == -1)
			return;

		Question &question = QuestionsIdQuestionObject[question_id];

		question.PrintToQuestion();

		if (question.AnswerText != "")
			cout << "\nWarning: Already answered. Answer will be updated\n";

		cout << "Enter answer: ";	// if user entered comma, system fails :)
		getline(cin, question.AnswerText);	// read last enter
		getline(cin, question.AnswerText);
	}

	void DeleteQuestion(User &user) {
		int question_id = ReadQuestionId(user);

		if (question_id == -1)
			return;

		vector<int> ids_to_remove;	// to remove from questionid_questionobject_map

		// Let's see if thread or not. If thread, remove all of it
		if (QuestionIdQestionsThreadMap.count(question_id)) { // thread
			ids_to_remove = QuestionIdQestionsThreadMap[question_id];
			QuestionIdQestionsThreadMap.erase(question_id);
		} else {
			ids_to_remove.push_back(question_id);

			// let's find in which thread to remove. Consistency is important when have multi-view
			for (auto &pair : QuestionIdQestionsThreadMap) {
				vector<int> &vec = pair.second;
				for (int pos = 0; pos < (int) vec.size(); ++pos) {
					if (question_id == vec[pos]) {
						vec.erase(vec.begin() + pos);
						break;
					}
				}
			}

		}

		for (auto id : ids_to_remove) {
			QuestionsIdQuestionObject.erase(id);
		}
	}

	void AskQuestion(User &user, pair<int, int> to_user_pair) {
		Question question;

		if (!to_user_pair.second) {
			cout << "Note: Anonymous questions are not allowed for this user\n";
			question.AnonymousOrNot = 0;
		} else {
			cout << "Is anonymous questions?: (0 or 1): ";
			cin >> question.AnonymousOrNot;
		}

		question.ParentQestionId = ReadQuestionIdThread(user);

		cout << "Enter question text(without comma): ";	
		getline(cin, question.QuestionText);
		getline(cin, question.QuestionText);

		question.QuestionFromUserId = user.UserId;
		question.QuestionToUserId = to_user_pair.first;

		
		question.QuestionId = ++LastQuestionId;

		QuestionsIdQuestionObject[question.QuestionId] = question;

		if (question.ParentQestionId == -1)
			QuestionIdQestionsThreadMap[question.QuestionId].push_back(question.QuestionId);
		else
			QuestionIdQestionsThreadMap[question.ParentQestionId].push_back(question.QuestionId);
	}

	void ListFeed() {
		for (auto &pair : QuestionsIdQuestionObject) {
			Question &question = pair.second;

			if (question.AnswerText == "")
				continue;

			question.PrintFeedQuestion();
		}
	}

	void UpdateDatabase() {
		vector<string> lines;

		for (auto &pair : QuestionsIdQuestionObject)
			lines.push_back(pair.second.INtegersQuestionInfoToString());

		WriteFileLines("questions.txt", lines, false);
	}
};
/*
        struct to manage User functions
*/
struct MangeUser
{
    map<string,User>NameUserObjectMap;  // map using name of user as key and object of user name as value
    User CurrentUser;
    int LastId;
    MangeUser()
    {
        LastId=0;
    }
    void LoadDtataBase()
    {
        LastId=0;
        NameUserObjectMap.clear();
        vector<string>Lines=ReadLinesFromFile("users.txt");
        for(auto &line : Lines)
        {
                User user(line);
                NameUserObjectMap[user.UserName]=user;
                LastId=max(LastId,user.UserId);
        }
    }
    void WaytoAccessSystem()
    {
        int choice = ShowReadMenu({"Login", "Sign Up"});
        if(choice==1)
        {
            Login();
        }
        else
        {
            SignUp();
        }
    }
    void Login()
    {
        LoadDtataBase();
        while(true)
        {
            cout<<"Enter UserName & Password: ";
            cin>>CurrentUser.UserName>>CurrentUser.Password;
            if(!NameUserObjectMap.count(CurrentUser.UserName))
            {
                cout << "\nInvalid user name or password. Try again\n\n";
				continue;
            }
            User ExistUser=NameUserObjectMap[CurrentUser.UserName];
            if(CurrentUser.Password != ExistUser.Password)
            {
                cout << "\nInvalid user name or password. Try again\n\n";
				continue;
            }
            CurrentUser=ExistUser;
            break;
        }
    }
    void SignUp()
    {
        while(true)
        {
            cout<<"Enter UserName: ";
            cin>>CurrentUser.UserName;
            if(NameUserObjectMap.count(CurrentUser.UserName))
            {
                cout<<"This UserName Already Used\n";
            }
            else
            {
                break;
            }
        }
        cout<<"Enter Pasword: ";
        cin>>CurrentUser.Password;
        cout<<"Enter Name: ";
        cin>>CurrentUser.Name;
        cout<<"Enter Email: ";
        cin>>CurrentUser.UserEmail;
        cout << "Allow anonymous questions? (0 or 1): ";
		cin >> CurrentUser.AllowAnonymousQestions;
        CurrentUser.UserId=++LastId;
        NameUserObjectMap[CurrentUser.UserName]=CurrentUser;

                UpdateDatabase(CurrentUser);
    }
    void UpdateDatabase(User &user) {
		string line = user.IntegersUserInfoToString();
		vector<string> lines(1, line);
		WriteFileLines("users.txt", lines);
	}
    void ListUsersNamesAndIds()
    {
        for(auto &elemnt : NameUserObjectMap)
        {
            cout<<"ID: "<<elemnt.second.UserId<<"\t\t Name: "<<elemnt.second.UserName<<"\n";
        }
    }
    pair<int , int > ReadUSerId()
    {
        int UserId;
        cout << "Enter User id or -1 to cancel: ";
		cin >> UserId;
        if(UserId==-1)
        {
            return make_pair(-1,-1);
        }
        for(auto & pair : NameUserObjectMap)
        {
            if(pair.second.UserId=UserId)
                {
                    return make_pair(UserId,pair.second.AllowAnonymousQestions);
                }
        }
        return ReadUSerId();
    }
    void UpdateDataBase(User &_user)
    {
        string line =_user.IntegersUserInfoToString();
        vector<string>lines(1,line);
        WriteFileLines("users.txt",lines);

    }

};
struct System
{
   MangeUser  usermanger;   // object of mangeuser class
   ManageQuestions questionmanger;  //object of mangequestion class

   void LoadDataBase(bool fillUserQuestion=false)
   {
    usermanger.LoadDtataBase();
    questionmanger.LoadDataBase();

    if(fillUserQuestion)
    {
        questionmanger.FillUserQuestion(usermanger.CurrentUser);

    }
   }
   void RunSystem()
    {
        LoadDataBase();
        usermanger.WaytoAccessSystem();
        questionmanger.FillUserQuestion(usermanger.CurrentUser);
        vector<string>menu;
        menu.push_back("Print Questions To Me");
		menu.push_back("Print Questions From Me");
		menu.push_back("Answer Question");
		menu.push_back("Delete Question");
		menu.push_back("Ask Question");
		menu.push_back("List System Users");
		menu.push_back("Feed");
		menu.push_back("Logout");
        while(true)
        {
            int choice=ShowReadMenu(menu);
            LoadDataBase(true);
            	if (choice == 1)
				questionmanger.PrintUserToQuestion(usermanger.CurrentUser);
			else if (choice == 2)
				questionmanger.PrintUserFromQuestion(usermanger.CurrentUser);
			else if (choice == 3) {
				questionmanger.AnswerQuestion(usermanger.CurrentUser);
				questionmanger.UpdateDatabase();
			} else if (choice == 4) {
				questionmanger.DeleteQuestion(usermanger.CurrentUser);
				// Let's build again (just easier, but slow)
				questionmanger.FillUserQuestion(usermanger.CurrentUser);
				questionmanger.UpdateDatabase();
			} else if (choice == 5) {
				pair<int, int> to_user_pair = usermanger.ReadUSerId();
				if (to_user_pair.first != -1) {
					questionmanger.AskQuestion(usermanger.CurrentUser, to_user_pair);
					questionmanger.UpdateDatabase();
				}
			} else if (choice == 6)
				usermanger.ListUsersNamesAndIds();
			else if (choice == 7)
				questionmanger.ListFeed();
			else
				break;

        }
        RunSystem();
    }
   
};
int main()
{
    System service;
    service.RunSystem();
    return 0;
}


