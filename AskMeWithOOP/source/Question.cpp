  /***********
 * Author :   Mohammed Akram
 * Date  :   28 OCT,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 OCT, 2023               Mohammed Akram
***************************************************************************/

  #include "../header/Question.hpp"
  Question ::  Question()
  :QuestionId{-1},ParentQestionId{-1},QuestionFromUserId{-1},QuestionToUserId{-1}, AnonymousOrNot{1}
 {

 }
   Question :: Question(string line)
 {
      vector<string>substrings=SpilitStringToVector(line);
      assert(substrings.size()==7);

      QuestionId = StringToInt(substrings[0]);
      ParentQestionId = StringToInt(substrings[1]);
      QuestionFromUserId = StringToInt(substrings[2]);
      QuestionToUserId = StringToInt(substrings[3]);
      AnonymousOrNot = StringToInt(substrings[4]);
      QuestionText = StringToInt(substrings[5]);
      AnswerText = StringToInt(substrings[6]);

 }
    string Question :: INtegersQuestionInfoToString()
 {
    ostringstream stri;
    stri<<QuestionId<< ","<<ParentQestionId<< ","<<QuestionFromUserId<< ","<<QuestionToUserId<< ","<<AnonymousOrNot<< ","<<QuestionText<< ","<<AnswerText;
      return stri.str();
 }
 void Question :: PrintToQuestion()
 {
    string prefix = "";

		if (ParentQestionId != -1)
			prefix = "\tThread: ";

		cout << prefix << "Question Id (" << QuestionId << ")";
		if (!AnonymousOrNot)
			cout << " from user id(" << QuestionFromUserId << ")";
		cout << "\t Question: " << QuestionText << "\n";

		if (AnswerText != "")
			cout << prefix << "\tAnswer: " << AnswerText << "\n";
		cout << "\n";
 }
 void Question :: PrintFromQuestion()
 {
    cout << "Question Id (" << QuestionId << ")";
		if (!AnonymousOrNot)
			cout << " !AQ";

		cout << " to user id(" << QuestionToUserId << ")";
		cout << "\t Question: " << QuestionText;

		if (AnswerText != "")
			cout << "\tAnswer: " << AnswerText << "\n";
		else
			cout << "\tNOT Answered YET\n";
 }
 void Question :: PrintFeedQuestion() const
 {
  if (ParentQestionId != -1)
			cout << "Thread Parent Question ID (" << ParentQestionId << ") ";

		cout << "Question Id (" << QuestionId << ")";
		if (!AnonymousOrNot)
			cout << " from user id(" << QuestionFromUserId << ")";

		cout << " To user id(" << QuestionToUserId << ")";

		cout << "\t Question: " << QuestionText << "\n";
		if (AnswerText != "")
			cout << "\tAnswer: " << AnswerText << "\n";
 }
 void Question :: setQuestionId(int _id)
 {
          QuestionId=_id;
 }
 int Question :: GetQuestionId()const
 {
    return QuestionId;
 }
 void Question :: setParentQuestionId(int _id)
 {
      ParentQestionId=_id;
 }
 int  Question ::GetParentQuestionId()const
 {
    return ParentQestionId;
 }
 void Question ::setQuestionFromUserId(int _id)
 {
    QuestionFromUserId=_id;
 }
 int Question :: GetQuestionFromUserId()const
 {
    return QuestionFromUserId;
 }
 void Question :: setQuestionToUserId(int _id)
 {
      QuestionToUserId=_id;
 }
 int Question :: GetQuestionToUserId()const
 {
    return QuestionToUserId;
 }
 void Question :: setAnonymousOrNot(int options)
 {
      AnonymousOrNot=options;
 }
 int Question :: GetAnonymousOrNot()const
 {
      return AnonymousOrNot;
 }
 void Question :: SetQuestionText(const string & _text)
 {
        QuestionText=_text;
 }
 const string & Question :: GetQuestionText()const 
 {
      return QuestionText;
 }
 void Question :: SetAnswerText(const string & _text)
 {
      AnswerText=_text;
 }
 const string & Question :: GetAnswerText()const 
 {
     return AnswerText;
 }



ManageQuestions ::ManageQuestions()
{
    LastQuestionId=0;
}
void ManageQuestions :: LoadDataBase()
{
  LastQuestionId = 0;
		QuestionIdQestionsThreadMap.clear();
		QuestionsIdQuestionObject.clear();

		vector<string> lines = ReadFileLines("questions.txt");
		for (const auto &line : lines) {
			Question question(line);
			LastQuestionId = max(LastQuestionId, question.GetQuestionId());

			QuestionsIdQuestionObject[question.GetQuestionId()] = question;

			if (question.GetParentQuestionId() == -1)
				QuestionIdQestionsThreadMap[question.GetQuestionId()].push_back(question.GetQuestionId());
			else
				QuestionIdQestionsThreadMap[question.GetParentQuestionId()].push_back(question.GetQuestionId());
		}
}
vector<int> ManageQuestions ::  GetUserToQuestions(const User &user) const
 {
		vector<int> question_ids;

		for (const auto &pair : QuestionIdQestionsThreadMap ) {	// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>

				// Get the question from the map. & means same in memory, DON'T COPY
				const Question &question = QuestionsIdQuestionObject.find(question_id)->second;

				if (question.GetQuestionFromUserId() == user.GetUserId())
					question_ids.push_back(question.GetQuestionId());
			}
		}
		return question_ids;
}
vector<pair<int, int>> ManageQuestions :: GetUserFromQuestions(const User &user) const {
		vector<pair<int, int>> question_ids;

		for (const auto &pair : QuestionIdQestionsThreadMap) {	// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>
				// Get the question from the map. & means same in memory, DON'T COPY
				const Question &question = QuestionsIdQuestionObject.find(question_id)->second;

				if (question.GetQuestionToUserId() == user.GetUserId()) {
					if (question.GetParentQuestionId() == -1)
						question_ids.push_back(make_pair(question.GetQuestionId(), question.GetQuestionId()));
					else
						question_ids.push_back(make_pair(question.GetParentQuestionId(), question.GetQuestionId()));
				}
			}
		}
		return question_ids;
	}

void ManageQuestions :: PrintUserToQuestion(const User &user)
{
	cout << "\n";

		if (user.GetQuestionThreadToIdKey().size() == 0)
			cout << "No Questions";
	

		for (const auto &pair : user.GetQuestionThreadToIdKey()) {		// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>

				// Get the question from the map. & means same in memory, DON'T COPY
				// Accessing questionid_questionobject_map[] change the map by adding if not exist. You can't use in const function
				// Here we just find, which return iterator (second is like a pointer to object)
				 Question &question = QuestionsIdQuestionObject.find(question_id)->second;
				question.PrintToQuestion();
			}
		}
		cout << "\n" ;
}
void ManageQuestions :: PrintUserFromQuestion(const User &_User)
{
	cout << "\n";
		if (_User.GetQuestionsIdForUser().size() == 0)
			cout << "No Questions";

		for ( auto &question_id : _User.GetQuestionsIdForUser()) {		//  vector<Question>
			 Question &question = QuestionsIdQuestionObject.find(question_id)->second;
			question.PrintFromQuestion();
		}
		cout << "\n";

}
int ManageQuestions :: ReadQuestionId( User & user)
{

 int question_id;
		cout << "Enter Question id or -1 to cancel: ";
		cin >> question_id;

		if (question_id == -1)
			return -1;

		if (!QuestionsIdQuestionObject.count(question_id)) {
			cout << "\nERROR: No question with such ID. Try again\n\n";
			return ReadQuestionId(user);
		}
		const Question &question = QuestionsIdQuestionObject.find(question_id)->second;

		if (question.GetQuestionToUserId() != user.GetUserId()) {
			cout << "\nERROR: Invalid question ID. Try again\n\n";
			return ReadQuestionId(user);
		}
		return question_id;
}
void ManageQuestions :: AnswerQuestion(const  User &user) 
{
	User u1 = user;
	int question_id = ReadQuestionId(u1);

		if (question_id == -1)
			return;

		Question &question = QuestionsIdQuestionObject.find(question_id)->second;

		question.PrintToQuestion();

		if (question.GetAnswerText() != "")
			cout << "\nWarning: Already answered. Answer will be updated\n";

		cout << "Enter answer: ";	// if user entered comma, system fails :)

		string line;
		getline(cin, line);
		getline(cin, line);
		question.SetAnswerText(line);

}
void ManageQuestions :: DeleteQuestion(const User &user) 
{
	User u1 =user;

	int question_id = ReadQuestionId(u1);

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
		for (const auto &id : ids_to_remove)
			QuestionsIdQuestionObject.erase(id);
}
int ManageQuestions :: ReadQuestionIdThread(const User &user) const {
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
void ManageQuestions :: AskQuestion(const User &user, pair<int, int> to_user_pair) 
{
  Question question;

		if (!to_user_pair.second) {
			cout << "Note: Anonymous questions are not allowed for this user\n";
			question.setAnonymousOrNot(0);
		} else {
			cout << "Is anonymous questions?: (0 or 1): ";
			int st;
			cin >> st;
			question.setAnonymousOrNot(st);
		}

		question.setParentQuestionId(ReadQuestionIdThread(user));

		cout << "Enter question text: ";	// if user entered comma, system fails :)
		string line;
		getline(cin, line);
		getline(cin, line);
		question.SetQuestionText(line);

		question.setQuestionFromUserId(user.GetUserId());
		question.setQuestionToUserId(to_user_pair.first);

		// What happens in 2 parallel sessions who asked question?
		// They are given same id. This is wrong handling :)
		question.setQuestionId(++LastQuestionId);

		QuestionsIdQuestionObject[question.GetQuestionId()] = question;

		if (question.GetParentQuestionId() == -1)
			QuestionIdQestionsThreadMap[question.GetQuestionId()].push_back(question.GetQuestionId());
		else
			QuestionIdQestionsThreadMap[question.GetParentQuestionId()].push_back(question.GetQuestionId());

}
void ManageQuestions :: ListFeed() 
{
  for (const auto &pair : QuestionsIdQuestionObject) {
			const Question &question = pair.second;

			if (question.GetAnswerText() == "")
				continue;
        question.PrintFeedQuestion();
			
		}

}
void ManageQuestions :: UpdateDatabase() 
{
  vector<string> lines;

		for ( auto &pair : QuestionsIdQuestionObject)
    
			lines.push_back(pair.second.INtegersQuestionInfoToString());

		WriteFileLines("questions.txt", lines, false);
	
}