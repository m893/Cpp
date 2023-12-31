/***********
 * Author :   Mohammed Akram
 * Date  :   28 OCT,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 OCT, 2023               Mohammed Akram
***************************************************************************/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "HelperFunctions.hpp"
#include "Question.hpp"
#include "User.hpp"

class AskMeSystem {

private:
	UserManager users_manager;
	ManageQuestions questions_manager;

	void LoadDatabase(bool fill_user_questions = false) ;

	
	void ResetCurrentUserQuestions();

public:
	void Run() ;
};

#endif