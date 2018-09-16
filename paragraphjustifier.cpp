#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

	//Prompts user to enter text which is saved in a string
	cout << "Enter text, empty return will quit the input:" << endl;
	string input;
	getline (cin,input);
	input += ' ';	//This fixes a bug where the vector would
					//not show the last inputted word without
					//pressing space at the end of input

	//Convert the text from string to vector format
	string word;
	vector<string> w;
	for (int i = 0; i < input.length(); i++){
		if(isspace(input[i])) {
			w.push_back(word);
			word.clear();
		}
		else {
			word += input[i];
		}
	}

	//Prompt user for text width input and continuosly check wether input is 0 which ends the program
	int textwidth = 1;
	while (textwidth > 0) {
	cout << "Enter the width of text: ";
	cin >> textwidth;
	if (textwidth == 0){
		break;
	}

	//Prints the dashed line above text
	cout<< "|";
	for (int i = 0; i < textwidth ; i++) {
		cout << "-";
	}
	cout <<"|" <<endl;

	//Paragraph justifier logic
	int line = 0;
	for(int i=0; i < w.size(); i++){
		//Prints the first word of a line
		if(line==0){
			cout << "|" << w[i];
			line += w[i].length();
		}

		//Prints all words other than the last one of the line
		else if( line + w[i].length() + w[i+1].length() + 1 < textwidth){
			cout << " " << w[i];
			line++;
			line += w[i].length();
		}

		//Takes care of a specific case of printing the last word of a line
		else if(line + w[i].length() == textwidth){

			while(textwidth - line > 0){
				cout << " ";
				line++;
			}
			cout << "|" << endl  << "|" << w[i];
			line = w[i].length();
		}

		//Prints the last word of the line
		else {
			line += w[i].length();
			while(textwidth - line > 0){
				cout << " ";
				line++;
			}
			cout << w[i] << "|" <<endl;
			line =0;
		}

		//Prints the very last "|"
		if (i == w.size()-1){
			while(textwidth - line > 0){
				cout << " ";
				line++;
			}
			cout << "|";
		}
	}

	//Prints dashed line below text
	cout << endl << "|";
		for (int i = 0; i < textwidth ; i++) {
			cout << "-";
		}
		cout <<"|" <<endl;

	}

	return 0;

}
