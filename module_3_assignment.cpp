/*
 ======================================================================================
 Name       : module_3_assignment.cpp
 Author     : Om
 Module     : Foundations of OOP using C++
 Description: Building a Cricket Game
 ======================================================================================
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

string currentBatsman;
string currentBowler;

class Team {
	public:
		string teamName;
		string playerOne;
		string playerTwo;
		string playerThree;
		long totalRuns;
};

void welcomeMsg();
void teamDetails(Team);
void selectPlayers1(Team, Team);
void selectPlayers2(Team, Team);
int playInningA();
int playInningB();

int main() {

	welcomeMsg();

	Team teamA;
	teamA.teamName = "Team India";
	teamA.playerOne = "Virat Kohli";
	teamA.playerTwo = "Hardik Pandya";
	teamA.playerThree = "Jasprit Bumrah";

	Team teamB;
	teamB.teamName = "Team Australia";
	teamB.playerOne = "Ricky Ponting";
	teamB.playerTwo = "Shane Warne";
	teamB.playerThree = "Shane Watson";

	Sleep(5000);
	cout << "Let's take a look at the teams" << endl << flush;
	Sleep(1000);
	cout << "The teams are:" << endl << flush;
	Sleep(1000);
	cout << "Team A:\n" << flush;
	teamDetails(teamA);

	cout << "Team B:	" << endl;
	teamDetails(teamB);

	Sleep(2000);

	// Selecting Random Players
	selectPlayers1(teamA, teamB);

	cout << "So let's begin with first inning" << endl << endl << flush;

	Sleep(1000);

	// Display Current Players
	cout << "Current Batsman:" << currentBatsman << endl << flush;
	cout << "Team Name:" << teamA.teamName << endl << endl << flush;
	cout << "Current Bowler:" << currentBowler << endl << flush;
	cout << "Team Name:" << teamB.teamName << endl << endl << flush;

	Sleep(2000);

	int runA = playInningA();

	Sleep(1000);

	cout << endl <<"Total Runs scored by Team INDIA:" << runA << endl << endl << flush;

	Sleep(2000);

	cout << "Time for the Second Inning" << endl << endl << flush;

	Sleep(1000);

	selectPlayers2(teamB, teamA);

	// Display Current Players
	cout << "Current Batsman:" << currentBatsman << endl << flush;
	cout << "Team Name:" << teamB.teamName << endl << endl << flush;
	cout << "Current Bowler:" << currentBowler << endl << flush;
	cout << "Team Name:" << teamA.teamName << endl << endl << flush;

	Sleep(2000);

	int runB = playInningB();

	Sleep(1000);

	cout << endl << "Total Runs scored by Team AUSTRALIA:" << runB << endl << endl << flush;

	Sleep(1000);

	if (runA > runB) {
		cout << "Team India wins the game" << endl << endl << flush;
	}
	else if (runA < runB) {
		cout << "Team Australia takes the Match" << endl << endl << flush;
	}
	else {
		cout << "This is a Tie" << endl << endl << flush;
	}
}

void welcomeMsg() {

	cout << "Welcome to GULLY CRICKET" << endl << flush;
	Sleep(1000);
	cout << "Create your own cricket team, challenge friends, and unlock exciting rewards. "
			"Welcome to the ultimate cricket experience." << endl << endl << flush;
	Sleep(3000);
	cout << "Let's take a look at the rules of the game:" << endl << flush;
	Sleep(1000);
	cout << "1.There are two teams with 3 players in each team.\n"
			"2.There should be 2 innings with each inning of exactly 6 balls.\n"
			"3.In each Inning one batsman from the batting team for 6 balls and one bowler from the bowling team will bowl 6 deliveries\n"
			"4.One batsman from the batting team and one bowling from the bowling team will be selected randomly for each inning\n"
			"5.Team A will always bat first and Team B will always bowl first\n"
			"6.In each delivery, runs can be scored from 0-6\n"
			"7.There will be no criteria for wickets. In simple words, once a batsman starts his inning, he will bat for 6 balls without getting out/dismissed/hurt,etc.\n"
			"8.After completing two innings, that is each team has done batting, scored runs will be compared to decide the winner or to decide if there is a tie.\n\n"
			 << flush;
}

void teamDetails(Team tm) {
	cout << "Team Name: " << tm.teamName << endl << flush;
	cout << "Player 1: " << tm.playerOne << endl << flush;
	cout << "Player 2: " << tm.playerTwo << endl << flush;
	cout << "Player 3: " << tm.playerThree << endl << endl << flush;
}

void selectPlayers1 (Team teamB, Team teamA) {
	srand(time(NULL));

	int bat = (rand() % 3) + 1;

	if (bat == 1) {
		currentBatsman = teamB.playerOne;
	}
	else if (bat == 2) {
		currentBatsman = teamB.playerTwo;
	}
	else {
		currentBatsman = teamB.playerThree;
	}

	//Selecting random bowler

	int ball = (rand() % 3) + 1;

	if (ball == 1) {
		currentBowler = teamA.playerOne;
	}
	else if (bat == 2) {
		currentBowler = teamA.playerTwo;
	}
	else {
		currentBowler = teamA.playerThree;
	}
}

void selectPlayers2 (Team teamA, Team teamB) {
	srand(time(NULL));

	int bat = (rand() % 3) + 1;

	if (bat == 1) {
		currentBatsman = teamA.playerOne;
	}
	else if (bat == 2) {
		currentBatsman = teamA.playerTwo;
	}
	else {
		currentBatsman = teamA.playerThree;
	}

	//Selecting random bowler

	int ball = (rand() % 3) + 1;

	if (ball == 1) {
		currentBowler = teamB.playerOne;
	}
	else if (bat == 2) {
		currentBowler = teamB.playerTwo;
	}
	else {
		currentBowler = teamB.playerThree;
	}
}
int playInningA() {
	int totalRunsA  = 0;

	srand(time(NULL));

	for (int i = 0; i < 6; i++) {
		int runsA = rand() % 7;
		cout << "Ball " << i+1 << ":" << runsA << "runs" << endl << flush;
		totalRunsA = totalRunsA + runsA;
		Sleep(1000);
	}
	return totalRunsA;
}

int playInningB() {
	int totalRunsB = 0;

	srand(time(NULL));

	for (int i = 0; i < 6; i++) {
		int runsB = rand() % 7;
		cout << "Ball " << i+1 << ":" << runsB << "runs" << endl << flush;
		totalRunsB = totalRunsB + runsB;
		Sleep(1000);
	}
	return totalRunsB;
}
