#include "Leaderboard.h"

Leaderboard::Leaderboard()
{
	inputFile.open(PATH_TO_LEADERBOARD);
	if (is_empty(inputFile))
	{
		max_score = 0;
	}
	else
	{
		getline(inputFile, maxScoreFromFile);
		max_score = std::stoi(maxScoreFromFile, nullptr, 10);
	}
	charScore = new char[10];
}

Leaderboard::~Leaderboard()
{
	inputFile.close();
}

void Leaderboard::updateFile()
{
	std::ofstream fileStrm(PATH_TO_LEADERBOARD, std::ios::out);
	fileStrm << max_score;
	fileStrm.close();
}

bool Leaderboard::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void Leaderboard::checkScore(int newScore)
{
	if (newScore > max_score) {
		max_score = newScore;
		updateFile();
	}
}

char* Leaderboard::getMaxScore()
{
	return itoa(max_score, charScore, 10);
}

void Leaderboard::resetScore()
{
	max_score = 0;
	updateFile();
}