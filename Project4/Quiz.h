#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
#define CLEAR system("cls");
#define SLEEP Sleep(1500);
struct Question {
	string question;
	string*answer=nullptr;
	bool* Correct_answer=nullptr;
	int Count_Answer;
};
struct Quiz {
	string Tittle;
	Question*Questions=nullptr;
	int Count_Question;
};
void Init();
void AddNewQuiz();
void TakeTheQuiz();
void ShowAllTittlesQuiz();
void AddQuiz(Quiz NewQuiz);