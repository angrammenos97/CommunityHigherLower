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

void game() {
	cout << "Welcome to the *cough* only *cough* open-source Higher-Lower game! We use..." << endl;
	cin.get();
	cout << "Loading Questions..." << endl;
	// LOADING QUESTIONS FROM FILE
	fstream QnAfile;
	QnAfile.open("Q&A.txt");
	string line, sent;
	int saidAns, correctAnsw;

	vector<Sentence> mySentences;
	// GENERAL GAME VARIABLES
	int lives = 3;
	int points = 0;
	int new_points = 0;
	vector<int> crossedOut;
	bool flag = false;
	
	while (getline(QnAfile, sent))
	{
		getline(QnAfile, line);
		saidAns = stoi(line);
		getline(QnAfile, line);
		correctAnsw = stoi(line);
		//cout << sent << "\t" << saidAns << "\t" << correctAnsw << endl;
		mySentences.push_back(Sentence(sent, saidAns, correctAnsw));
	}

	// FINISHED LOADING
	
	
	
	while (lives > 0) {
		int select;
		
		do {
			flag = false;
			srand(time(NULL));
			select = rand() % mySentences.size();
			for (int i = 0; i < crossedOut.size(); i++) {
				if (select == crossedOut[i])
					flag = true;
			}
		} while (flag == true);

		crossedOut.push_back(select);
		cout << "Question:" << endl;
		cout << mySentences[select].getSentence() << endl;
		char myAnswer[256];
		int translation;
		cin >> myAnswer;
		if (myAnswer[0] == 'h' || myAnswer[0] == 'H')
			translation = 1;
		else if (myAnswer[0] == 'l' || myAnswer[0] == 'L')
			translation = 0;
		else {
			cout << "You need to write a proper answer! You lose one life >:( " << endl;
			translation = 2;
		}

		if (translation == mySentences[select].getRes()) {
			new_points = (int)(mySentences[select].getCorrAnsw() - mySentences[select].getSaidAnsw())*(mySentences[select].getCorrAnsw() - mySentences[select].getSaidAnsw());
			points += new_points;
			cout << endl << "Spot on!" << endl;
			cout << "The correct answer was " << mySentences[select].getCorrAnsw() << endl;
			cout << "... which nets you " << new_points << " points for a total of " << points << " !" << endl;
		}
		else {
			cout << endl << "That was embarassing..." << endl;
			cout << "Your lives get reduced to " << --lives << " !" << endl;
		}
		
		system("pause");
		if (crossedOut.size() == mySentences.size()) {
			cout << "We're all out of questions! Good job for getting this far..." << endl;
			lives = 0;
		}
		
		
		/*cout << mySentences[select].getSentence() << endl;
		int myAnswer;
		cin >> myAnswer;
		if (myAnswer == mySentences[select].getRes()) {
			new_points = (int)(mySentences[select].getCorrAnsw() - mySentences[select].getSaidAnsw())*(mySentences[select].getCorrAnsw() - mySentences[select].getSaidAnsw());
			points += new_points;
			cout << endl << "Spot on!" << endl;
			cout << "The correct answer was " << mySentences[select].getCorrAnsw() << endl;
			cout << "... which nets you " << new_points << " points for a total of " << points << " !" << endl;
		}
			
		else {
			cout << endl << "That was embarassing..." << endl;
			cout << "Your lives get reduced to " << --lives << " !" << endl;
		}*/
		
	}

	cout << "Game Over!" << endl << "Your final count is " << points << " points!" << endl;
	
	//cin.get();*/
}


int main()
{
	/*char c;
	fstream QnAfile;
	QnAfile.open("Q&A.txt");
	string line , sent;
	int saidAns, correctAnsw;

	vector<Sentence> mySentences;

	while (getline(QnAfile, sent))
	{
		getline(QnAfile, line);
		saidAns = stoi(line);
		getline(QnAfile, line);
		correctAnsw = stoi(line);
		//cout << sent << "\t" << saidAns << "\t" << correctAnsw << endl;
		mySentences.push_back(Sentence(sent, saidAns, correctAnsw));
	}


	srand(time(NULL));
	int select = rand() % mySentences.size();
	cout << select << endl;

	
	cin >> c;
	QnAfile.close();
	return 0;*/
	game();
	
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	return 0;
}

