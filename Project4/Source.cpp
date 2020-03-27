#include"Quiz.h"

int main() {
	Init();
	int action = 0;
	do {
		CLEAR
		cout << "Enter action:\n1.Show all quiz\n2.Add new quiz\n3.Take the quiz\n4.Exit\n";
		cin >> action;
		CLEAR
		switch (action) {
		case 1:
			ShowAllTittlesQuiz();
			cout << "\nPress space to continue.\n";
			while (_getch() != 32);
			break;
		case 2:
			AddNewQuiz();
			break;
		case 3:
			TakeTheQuiz();
			cout << "\nPress space to continue.\n";
			while (_getch() != 32);
			break;
		case 4:
			cout << "Bye";
			break;
		default:
			cout << "Invalid value.";
			SLEEP;
		}
	} while (action != 4);

	return 0;
}