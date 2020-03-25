#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
#define CLEAR system("cls");
#define SLEEP Sleep(1500);
void Init();
void AddNewQuiz();
void TakeTheQuiz();
void ShowAllTittlesQuiz();
struct Question {
	string question;
	string answer;
};
struct Quiz {
	string Tittle;
	Question Questions[5];
};
