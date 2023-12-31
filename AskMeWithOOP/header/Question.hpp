/***********
 * Author :   Mohammed Akram
 * Date  :   28 OCT,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 OCT, 2023               Mohammed Akram
***************************************************************************/

#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "HelperFunctions.hpp"
#include "User.hpp"

class Question 
{
    private:
    int QuestionId;
    int ParentQestionId;
    int QuestionFromUserId;
    int QuestionToUserId;
    int AnonymousOrNot;
    string QuestionText;
    string AnswerText;

    public :  
     Question();
    Question(string line);
    string INtegersQuestionInfoToString();
    void PrintToQuestion();
    void PrintFromQuestion();
    void PrintFeedQuestion()const;
    void setQuestionId(int _id);
    int GetQuestionId()const;
    void setParentQuestionId(int _id);
    int GetParentQuestionId()const;
    void setQuestionFromUserId(int _id);
    int GetQuestionFromUserId()const;
    void setQuestionToUserId(int _id);
    int GetQuestionToUserId()const;
    void setAnonymousOrNot(int _id);
    int GetAnonymousOrNot()const;
    void SetQuestionText(const string & _text);
    const string & GetQuestionText()const ;
    void SetAnswerText(const string & _text);
    const string & GetAnswerText()const ;


};

class ManageQuestions
{
    private:
    map<int , vector<int>>QuestionIdQestionsThreadMap; // map to store the question id as a key and vector of strings of answers as a value 

    map<int, Question>QuestionsIdQuestionObject;        // map to store the question id as key and vector of string of object of this question

    int LastQuestionId;

    public:
    ManageQuestions();
    void LoadDataBase();
    void FillUserQuestion(User & _user);
    void PrintUserToQuestion( const User &_User);
    void PrintUserFromQuestion(const User &_User);
    int ReadQuestionId(User & _user);
    int  ReadQuestionIdThread(const User &user) const;

	void AnswerQuestion(const  User &user) ;

	void DeleteQuestion( const User &user) ;

	void AskQuestion(const  User &user, pair<int, int> to_user_pair) ;

	void ListFeed() ;

	void UpdateDatabase() ;
    vector<int> GetUserToQuestions(const User &user) const ;
    vector<pair<int, int>> GetUserFromQuestions(const User &user) const;
};


#endif