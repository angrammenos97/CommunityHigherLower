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
	cout << "Press any key to show the first question!" << endl;
	cin.get();
	cout << "Question:" << endl;
	srand(time(NULL));
	int select = rand() % mySentences.size();
	cout << mySentences[select].getSentence() << endl;
	
	// pes apanthsh
	int myAnswer;
	cin >> myAnswer;
	if (myAnswer == mySentences[select].getCorrAnsw())
		cout << "YES CORRECT" << endl;
	else {
		cout << "NO WRONG" << endl;
	}
	//cin.get();
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

