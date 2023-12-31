/***********
 * Author :   Mohammed Akram
 * Date  :   28 OCT,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 OCT, 2023               Mohammed Akram
***************************************************************************/

#ifndef USER_HPP
#define USER_HPP

#include "HelperFunctions.hpp"


class User
{
    private:
    int UserId;
    string UserName;
    string Password;
    string Name;
    string UserEmail;
    int AllowAnonymousQestions;
    vector<int>QuestionsIdForUser; // vector to store the questions IDs for this user

    map<int,vector<int>>QuestionThreadToIdKey; // From question id to list of questions IDS on this question (thread questions) - All users
    public:
    User();
    User(const   string &line);
    string IntegersUserInfoToString()const;
    void PrintUserInfo()const;
    void AddToQuestions(const vector<int> & Toquestions);
    void AddToThreadMap(const vector<pair<int,int>> & Toquestion);
    int GetAllowAnonymousQestions()const;
    void ReadUserInfo(const string & name , int id);
    void SetAllowAnonymousQestions(int _AllowAnonymousQestions);
    const string &  GetUserEmail()const;
    void SetUserEmail(const string & email);
    void SetName(const string & name);
    const string & GetName()const;
    void SetPasswrd(const string & _password);
    const string & GetPassword()const;
    void SetUSerName(const string & _username);
    const string & GetUsername()const;
    void SetUserId(int _id);
    int GetUserId()const;
    const map<int , vector<int>>& GetQuestionThreadToIdKey()const;
    const vector<int> & GetQuestionsIdForUser()const;


};

class UserManager
{
    private :
        map<string,User>UserNameToUserObjectMap;
        User CurrentUser;
        int LastId;
    public :
    UserManager();
    void LoadDataBase();
    void AccessSystem();
    void Login();
    void SignUp();
    void AddToQuestionsToCurrentUser(const vector<int> & Toquestions);
    void AddToThreadMapToCurrentUser(const vector<pair<int,int>> & Toquestion);
    void DisplayUserNameAndIds()const;
    pair<int , int > ReadUserId()const;
    void UpDataDataBase(const User & user);
    const User& GetCurrentUser();
};



#endif