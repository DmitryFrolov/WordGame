#ifndef _TASK_GENERATOR_
#define _TASK_GENERATOR_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <iterator>
#include <time.h>

#define PATH_TO_FILE "../Resources/Vocabulary.txt"

class TaskGenerator
{
private:
	std::deque<char*> answers;
	std::ifstream inputFile;
	std::string textFromFile;
	char *cstr;
	int currentIndex;
	char *task;
	char key;

public:
	TaskGenerator();
	~TaskGenerator();
	const void readToStr();	
	const void init();
	void spliter();
	void upgradeToRand();
	char generateTask(char *task);

	const int getWordSize(char* word);
	const int getRandNumber(int min, int max);
	char *getTask();
	char *getAnswer();
	char getKey();
	const int getSize();
};

#endif // _FILES_