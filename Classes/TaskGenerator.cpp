#include "TaskGenerator.h"
#include "io.h"

TaskGenerator::TaskGenerator()
{
	srand(time(NULL));
	inputFile.open(PATH_TO_FILE);
	currentIndex = 0;
}

TaskGenerator::~TaskGenerator()
{
	inputFile.close();
	delete[] cstr;
	delete[] task;
}

const void TaskGenerator::init()
{
	readToStr();
	spliter();
	upgradeToRand();
}

const void TaskGenerator::readToStr()
{
	getline(inputFile, textFromFile);
}

void TaskGenerator::spliter()
{
	cstr = new char[textFromFile.length() + 1];
	std::strcpy(cstr, textFromFile.c_str());

	char *p = std::strtok(cstr, " ");
	while (p != 0)
	{
		p = std::strtok(NULL, " ");
		answers.push_back(p); //its ok
	}
}

void TaskGenerator::upgradeToRand()
{
	currentIndex = getRandNumber(0, answers.size() - 1);
	task = new char[getWordSize(answers[currentIndex]) + 1];
	strcpy(task, answers[currentIndex]);
	key = generateTask(task);
}

const int TaskGenerator::getRandNumber(int min, int max)
{
	int randNum = rand() % (max - min) + min;
	return randNum;
}

const int TaskGenerator::getWordSize(char* word)
{
	int size = 0;
	while (word[size] != '\0')
	{
		size++;
	}
	return size;
}

//метод принимает указатель на task, изменяет значение и возвращает key
char TaskGenerator::generateTask(char *task)
{
	int rand = getRandNumber(0, getWordSize(task) - 1);
	char key = task[rand];
	task[rand] = '-';
	return key;
}

char *TaskGenerator::getTask() { return task; }
char *TaskGenerator::getAnswer() { return answers[currentIndex]; } //-1 because of upgrade always run 1st
char TaskGenerator::getKey() { return key; }
const int TaskGenerator::getSize() { return answers.size(); }