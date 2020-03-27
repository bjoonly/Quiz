#include"Quiz.h"
Quiz* AllQuiz = nullptr;
int Size_Quiz = 0;
string FileName = "Quiz.txt";

void Init() {
	ifstream fin;
	
	string data;

		fin.open(FileName);
		bool isOpen = fin.is_open();
		if (!isOpen) {
			cout << "The file couldn't be opened.\n";
			return;
		}
			while (!fin.eof()) {	
				Quiz getQuiz;
				getline(fin,getQuiz.Tittle);
				cout << getQuiz.Tittle << endl;
				if (getQuiz.Tittle != "") {
					fin >> getQuiz.Count_Question;
					cout << getQuiz.Count_Question << endl;

					getQuiz.Questions = new Question[getQuiz.Count_Question];
					for (int i = 0; i < getQuiz.Count_Question; i++) {
						fin.ignore(1321312, '\n');
						getline(fin, getQuiz.Questions[i].question);
						cout << getQuiz.Questions[i].question << endl;
						fin >> getQuiz.Questions[i].Count_Answer;
						cout << getQuiz.Questions[i].Count_Answer<<endl;
						getQuiz.Questions[i].answer = new string[getQuiz.Questions[i].Count_Answer];
						getQuiz.Questions[i].Correct_answer = new bool[getQuiz.Questions[i].Count_Answer];

						for (int j = 0; j < getQuiz.Questions[i].Count_Answer; j++) {
							fin.ignore(13123, '\n');
							getline(fin, getQuiz.Questions[i].answer[j]);
							cout << getQuiz.Questions[i].answer[j] << endl;
							fin >> getQuiz.Questions[i].Correct_answer[j];
							cout << getQuiz.Questions[i].Correct_answer[j]<<endl;
						}
					}
					fin.ignore(12323, '\n');
				}
				else {
					break;
				}
				  AddQuiz(getQuiz);
			}
		}

void AddQuiz(Quiz NewQuiz) {
	Quiz* res = new Quiz[++Size_Quiz];
	for (int i = 0; i < Size_Quiz - 1; i++)
		res[i] = AllQuiz[i];

	res[Size_Quiz - 1] = NewQuiz;
	delete[]AllQuiz;
	AllQuiz = res;
	
}
void AddNewQuiz(){
	ofstream fout;
	fout.open("Quiz.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen) {
		Quiz* res = new Quiz[++Size_Quiz];
		for (int i = 0; i < Size_Quiz - 1; i++)
			res[i] = AllQuiz[i];


		cout << "Enter title for quiz->_";
		cin.ignore(11323, '\n');
		getline(cin, res[Size_Quiz - 1].Tittle);
		CLEAR
		cout << "Enter number of question in quiz->_";
		cin >> res[Size_Quiz - 1].Count_Question;
		res[Size_Quiz - 1].Questions = new Question[res[Size_Quiz - 1].Count_Question];
		CLEAR
			for (int i = 0; i < res[Size_Quiz - 1].Count_Question; i++) {
				CLEAR
				cout << "Enter question N" << i + 1 << "->_";
				cin.ignore(132323, '\n');
				getline(cin, res[Size_Quiz - 1].Questions[i].question);
				cout << "Enter number of answer for this question->_";
				cin >> res[Size_Quiz - 1].Questions[i].Count_Answer;
				res[Size_Quiz - 1].Questions[i].answer = new string[res[Size_Quiz - 1].Questions[i].Count_Answer];
				res[Size_Quiz - 1].Questions[i].Correct_answer= new bool[res[Size_Quiz - 1].Questions[i].Count_Answer];

				for (int j = 0; j < res[Size_Quiz - 1].Questions[i].Count_Answer; j++) {
					CLEAR
					cout << "Enter answer N"<<j+1<<"->_";
					cin.ignore(12233, '\n');
					getline(cin, res[Size_Quiz - 1].Questions[i].answer[j]);
					cout << "Is this answer correct(0-no/1-yes)";
					cin >> res[Size_Quiz - 1].Questions[i].Correct_answer[j];
				}
			}
		fout << res[Size_Quiz - 1].Tittle << endl;
		fout << res[Size_Quiz - 1].Count_Question << endl;
		for (int i = 0; i < res[Size_Quiz - 1].Count_Question; i++) {
			fout << res[Size_Quiz - 1].Questions[i].question << endl;
			fout<<res[Size_Quiz - 1].Questions[i].Count_Answer << endl;
			for (int j = 0; j < res[Size_Quiz - 1].Questions[i].Count_Answer; j++) {
				fout << res[Size_Quiz - 1].Questions[i].answer[j] << endl;
				fout << res[Size_Quiz - 1].Questions[i].Correct_answer[j] << endl;
			}
		}
		fout.close();
		delete[]AllQuiz;
		AllQuiz = res;
	}
	else
		cout << "The file couldn't be opened.\n";

}
void ShowAllTittlesQuiz() {
	for (int i = 0; i < Size_Quiz; i++)
		cout << i + 1 <<". "<< AllQuiz[i].Tittle << endl;
}
void TakeTheQuiz(){
	int res = 0;
	int num = 0;
	int answer;
	ShowAllTittlesQuiz();
	cout << "Enter number of quiz (1-" << Size_Quiz << ")->_";
	cin >> num;
	cin.ignore(12233, '\n');
	CLEAR
		for (int i = 0; i < AllQuiz[num - 1].Count_Question; i++) {
			CLEAR
				cout << AllQuiz[num - 1].Questions[i].question << ":\n";
			for (int j = 0; j < AllQuiz[num - 1].Questions[i].Count_Answer; j++) 
				cout<<j+1<<". "<<AllQuiz[num - 1].Questions[i].answer[j]<<endl;

			cout << "Enter number of answer(1-"<< AllQuiz[num - 1].Questions[i].Count_Answer<<")->_";
			cin >> answer;
			if (AllQuiz[num - 1].Questions[i].Correct_answer[answer - 1])
				++res;
		}
	CLEAR
	cout << "Your result: " << res << endl;
}
