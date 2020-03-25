#include"Quiz.h"
Quiz* AllQuiz = nullptr;
int Size_Quiz = 0;
string FileName = "Quiz.txt";

void Init(){
	ifstream fin;
	fin.open(FileName);
	bool isOpen = fin.is_open();
	if(!isOpen)
		cout << "The file couldn't be opened.\n";
	else {
		int currentString = 0, indexQuiz = 0, indexQuestion = 0, countString = 0;
		string data;
		while (getline(fin, data)) {
			countString++;
		}
		if (countString > 0) {
			fin.close();
			fin.open(FileName);
			Size_Quiz = countString / 10;

			Quiz* res = new Quiz[Size_Quiz];
			while (getline(fin, data)) {
				++currentString;

				if (currentString == 1)
					res[indexQuiz].Tittle = data;


				else if (currentString < 11 && currentString % 2 == 0)
					res[indexQuiz].Questions[indexQuestion].question = data;


				else if (currentString <= 11 && currentString % 2 != 0) {
				res[indexQuiz].Questions[indexQuestion].answer = data;
				indexQuestion++;
			}
				
				if(currentString==11){
					currentString = 0;
					indexQuiz++;
					indexQuestion = 0;
				}

			}
			delete[]AllQuiz;
			AllQuiz = res;
		}
		else {
			CLEAR
		    cout << "File is empty.\n";
			SLEEP
		}
	}
	fin.close();
}

void AddNewQuiz(){
	ofstream fout;
	fout.open("Quiz.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen) {
		Quiz* res = new Quiz[++Size_Quiz];
		for (int i = 0; i < Size_Quiz - 1; i++)
			res[i] = AllQuiz[i];


		cout << "Enter title for quiz: ";
		getline(cin, res[Size_Quiz - 1].Tittle);
		CLEAR
		for (int i = 0; i < 5; i++) {
			cout << "Enter question N " << i + 1 << ": ";
			getline(cin, res[Size_Quiz - 1].Questions[i].question);
			cout << "Enter the correct answer: ";
			getline(cin, res[Size_Quiz - 1].Questions[i].answer);
		}
		fout << res[Size_Quiz - 1].Tittle << endl;
		for (int i = 0; i < 5; i++) {
			fout << res[Size_Quiz - 1].Questions[i].question << endl;
			fout << res[Size_Quiz - 1].Questions[i].answer << endl;
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
	string answer;
	ShowAllTittlesQuiz();
	cout << "Enter number of quiz (1-" << Size_Quiz << ")->_";
	cin >> num;
	cin.ignore(12233, '\n');
	CLEAR
	for (int i = 0; i < 5; i++) {
		CLEAR
		cout << AllQuiz[num - 1].Questions[i].question << "->_";
		getline(cin,answer);
		Sleep(500);
		if (answer == AllQuiz[num - 1].Questions[i].answer)
		++res;
	}
	CLEAR
	cout << "Your result: " << res << endl;
}
