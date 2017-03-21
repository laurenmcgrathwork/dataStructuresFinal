//
//  HighestScore.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include "HighestScore.h"
#include <iostream>
#include <fstream>
#include <sstream>


HighestScore::HighestScore()
{
}


HighestScore::~HighestScore()
{
}

void HighestScore::printScores()
{
	std::cout << "High Rollers!" << std::endl;
	//open instream
	std::ifstream infile("Highscores.txt");
	int rank = 1; //prints rank for the highscores
	if (infile) {
		while (infile) {
			std::string strInput;
			std::getline(infile, strInput, '#'); //breaks lines at '#' character
												 //checks if it is the last line of the file and stops there
			if (strInput == "last") {
				break;
			}
			//prints out each name and score from the file
			std::cout << rank << ": " << lineReader(strInput) << std::endl;
			rank++;
		}
	}
}

//checks to see if the user's score is greater than any of the scores in the high score file
//and saves the score in the correct place and moves the other scores down, losin the lowest score
void HighestScore::saveScores(std::string name, int score)
{
	//open instream from a file
	std::ifstream infile("Highscores.txt");
	int index = 0; //index is used to place namesAndScores into the proper places in the arrays
	std::string* namesAndScores = new std::string[10];
	std::string* arrayOfNames = new std::string[10];
	int* arrayOfScores = new int[10];
	if (infile) {
		while (infile) {
			std::string strInput;
			std::getline(infile, strInput, '#');
			if (strInput == "last") {
				break;
			}
			namesAndScores[index] = strInput;
			index++;

		}
	}
	infile.close();
	std::string toBeCast = "";
	for (int i = 0; i < 10; i++) {
		std::stringstream splitter(namesAndScores[i]);
		std::getline(splitter, arrayOfNames[i], ',');
		std::getline(splitter, toBeCast, ',');
		arrayOfScores[i] = std::stoi(toBeCast);
	}
	for (int i = 0;i < 10; i++) {
		//checks if the given score is higher than any of the scores
		if (score >= arrayOfScores[i]) {
			for (int j = 10; j != i; j--) {
				//gets rid of the last element and moves up the highscore list from the last spot
				//while moving the names and scores down
				arrayOfNames[j] = arrayOfNames[j - 1];
				arrayOfScores[j] = arrayOfScores[j - 1];
			}
			//sets the new name and score into the arrays
			arrayOfNames[i] = name;
			arrayOfScores[i] = score;
			break;
		}
	}


	//opens outstream
	std::ofstream highscoreWriter;
	highscoreWriter.open("Highscores.txt");
	//saves each spot in the arrays and puts it in the file
	for (int i = 0; i < 10; i++) {
		highscoreWriter << arrayOfNames[i] << "," << arrayOfScores[i] << "#";
	}
	highscoreWriter << "last" << "#";
	arrayOfNames = nullptr;
	arrayOfScores = nullptr;
	namesAndScores = nullptr;
	highscoreWriter.close();
}

std::string HighestScore::lineReader(std::string line)
{
	if (line.length() > 0) {
		std::stringstream splitter(line);
		std::string name, score;
		std::getline(splitter, name, ',');
		std::getline(splitter, score, ',');
		return name + ' ' + score;
	}
	return "Error";
}

