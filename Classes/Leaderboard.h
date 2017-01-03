#ifndef _LEADERBOARD_
#define _LEADERBOARD_
#include <fstream>
#include <string>
#include <cstdlib>
#define PATH_TO_LEADERBOARD "../Resources/Leaderboard.txt"
class Leaderboard
{
private:
	std::ifstream				inputFile;
	int							max_score;
	std::string			 maxScoreFromFile;
	char					   *charScore;
	
	bool   is_empty(std::ifstream& pFile);
	void                     updateFile();
public:
	Leaderboard();
	~Leaderboard();
	void checkScore(int newScore);
	char* getMaxScore();
	void resetScore();
};

#endif //_LEADERBOARD_