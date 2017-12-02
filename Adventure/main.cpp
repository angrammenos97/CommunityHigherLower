#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;


class Sentence {

	string sent;
	int saidAns;
	int correctAns;
	int res;
	
public:
	Sentence(string sent , int saidAns, int correctAns){
		this->sent = sent;
		this->correctAns = correctAns;
		this->saidAns = saidAns;
		if (correctAns > saidAns)
			res = 1;
		else
			res = 0;
	}

	~Sentence(){}

	int checkAnswer() {
		cout << "Question: " << this->sent << endl;
		char myAnswer[256];
		std::cin >> myAnswer;
		if ((myAnswer[0] == 'h' || myAnswer[0] == 'H') && this->res == 1) {
			cout << endl << "Spot on!" << endl;
			cout << "The correct answer was " << this->correctAns << " ." << endl;
			int newPoints = (int)((this->correctAns - this->saidAns)*(this->correctAns - this->saidAns));
			return newPoints;
		}
		else if ((myAnswer[0] == 'h' || myAnswer[0] == 'H') && this->res == 0) {
			cout << endl << "That was embarassing..." << endl;
			cout << "The correct answer was " << this->correctAns << " ." << endl;
			return -1;
		}
		else if ((myAnswer[0] == 'l' || myAnswer[0] == 'L') && this->res == 0) {
			cout << endl << "Spot on!" << endl;
			cout << "The correct answer was " << this->correctAns << " ." << endl;
			int newPoints = (int)((this->correctAns - this->saidAns)*(this->correctAns - this->saidAns));
			return newPoints;
		}
		else if ((myAnswer[0] == 'l' || myAnswer[0] == 'L') && this->res == 1) {
			cout << endl << "That was embarassing..." << endl;
			cout << "The correct answer was " << this->correctAns << " ." << endl;
			return -1;
		}
		else {
			cout << "You need to write a proper answer! You lose one life >:( ." << endl;
			return -1;
		}
	}

	string getSentence()	{
		return this->sent;
	}

	int getCorrAnsw()	{
		return this->correctAns;
	}

	int getSaidAnsw()	{
		return this->saidAns;
	}
	int getRes() {
		return this->res;
	}
};

int main()
{
	cout << "Welcome to the *cough* only *cough* open-source Higher-Lower game! We use GitHub's repository environment along with Visual Studio's integration." << endl;
	cout << "The basic concept is to enable anyone, regardless of coding skills, to contribute by adding his own questions via an easy-to-use, human-friendly text file." << endl;
	cout << "Let's begin!!" << endl;
	std::cin.get();

	// DOWNLOAD FILE FROM NET
	const char command[] = "Powershell -command \"Invoke-WebRequest -Uri \"https://raw.githubusercontent.com/angrammenos97/CommunityHigherLower/master/Adventure/Q%26A.txt\" -OutFile \".\\QnA.txt\"\"";
	system(command);

	// LOADING QUESTIONS FROM FILE		
	fstream QnAfile;
	QnAfile.open("QnA.txt");
	if (!QnAfile.is_open()) {
		cout << "Cannot find the file \"QnA.txt\"! Make sure it's with the same directory with the programm." << endl;
		system("pause");
		return -1;
	}
	cout << "Loading Questions..." << endl;
	vector<Sentence> mySentences;
	string line, sent;
	int saidAns, correctAnsw;

	while (getline(QnAfile, sent)) {
		getline(QnAfile, line);
		saidAns = stoi(line);
		getline(QnAfile, line);
		correctAnsw = stoi(line);
		//cout << sent << "\t" << saidAns << "\t" << correctAnsw << endl;
		mySentences.push_back(Sentence(sent, saidAns, correctAnsw));
	}
	QnAfile.close();
	// FINISHED LOADING

	// GENERAL GAME VARIABLES
	int lives = 3;
	int points = 0;
	vector<int> crossedOut;
	srand(time(NULL));

	// SHUFFLING QUESTIONS
	cout << "Shuffling questions.." << endl;
	while (crossedOut.size() != mySentences.size()) {		
		bool alreadyExists;
		int select;
		do {
			alreadyExists = false;
			select = rand() % mySentences.size();
			for (int i = 0; i < crossedOut.size(); i++)
				if (select == crossedOut[i])
					alreadyExists = true;

		} while (alreadyExists);
		crossedOut.push_back(select);
	}
	cout << "Done!" << endl << endl;

	// START ASKING
	for (int i = 0; i < mySentences.size(); i++) {
		int result = mySentences[crossedOut[i]].checkAnswer();
		if (result > 0) {			
			points += result;
			cout << "... which nets you " << result << " points for a total of " << points << " !" << endl << endl;
		}
		else {
			cout << "Your lives get reduced to " << --lives << " !" << endl << endl;
		}
		if (lives == 0) {
			cout << "You have no lives..";
			break;
		}
	}

	// GAME OVER
	if (lives > 0)
		cout << "We're all out of questions! Good job for getting this far..." << endl;
	cout << "Game Over!" << endl << "Your final count is " << points << " points!" << endl << endl;
	

	cout << "Press any key to exit." << endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cin.get();
	return 0;
}