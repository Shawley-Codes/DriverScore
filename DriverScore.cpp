//Scott Hawley
//This program will calculate a divers score based on 5 referees
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	//declarations
	float referee[5];
	const float MULTIPLIER = 1.6;
	float highestScore;
	float lowestScore;
	char play;
	const int REFEREES = 5;
	float sum;

	//introduction
	cout << "\tWelcome to Diver Score Calculator Program\n";
	cout << "\t=========================================\n\n";

	do
	{
		//reset variables;
		highestScore = 0.0;
		lowestScore = 10.0;
		sum = 0.0;

		//get the input for each of the referees and validation
		cout << "\nPlease input the score from each referee. (0-10 only)";
		for (int i = 0; i < REFEREES; i++)
		{
			cout << "\nEnter Score for Referee " << i + 1 << ".\n";
			cin >> referee[i];
			while (referee[i] > 10.0 || referee[i] < 0) {
				cout << "\nInput invalid! Please try again. (0 - 10 only)\n";
				cin >> referee[i];
			}
		}

		//get the highest score and lowest score
		for (int k = 0; k < REFEREES; k++)
		{
			if (referee[k] > highestScore) {
				highestScore = referee[k];
			}
			//this is not else if becuase the value that is 
			//currently highest may also be currently lowest
			if (referee[k] < lowestScore) {
				lowestScore = referee[k];
			}
		}

		//calculate final score - first add
		for (int j = 0; j < REFEREES; j++)
		{
			sum += referee[j];
		}

		//subtract highest and lowest scores from the final
		sum -= highestScore;
		sum -= lowestScore;

		//multiply the score by the score MULTIPLIER
		sum *= MULTIPLIER;

		//print score with 2 decimals
		cout << "\nThe divers final score is ";
		cout << fixed << setprecision(2) << sum;

		//ask whether to repeat program
		cout << "\n\nCalculate next diver? y or n.\n";
		cin >> play;
	} while (play == 'y');

	return 0;
}