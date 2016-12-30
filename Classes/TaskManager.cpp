#include "TaskManager.h"
TaskManager::TaskManager()
{
	generator = new TaskGenerator();
	generator->init();
	listOfTasks = NULL;
	numTasks = generator->getSize();
}

TaskManager::~TaskManager()
{
	delete[] listOfTasks;
	listOfTasks = NULL;
}

void TaskManager::init()
{
	listOfTasks = new WordTask[numTasks];
	char *tasks[] = { "c_llege", "f_sh", "p_one" };
	char *ans[] = { "college", "fish", "phone" };
	char key[] = { 'o', 'i', 'h' };

	for (int i = 0; i < numTasks; i++)
	{
		//listOfTasks[i].init(tasks[i], ans[i], key[i]);
		listOfTasks[i].init(generator->getTask(), generator->getAnswer(), generator->getKey());
		generator->upgradeToRand();
	}
}

int TaskManager::getNumTasks()
{
	return numTasks;
}

void TaskManager::setNumTasks(int num)
{
	numTasks = num;
}

WordTask TaskManager::getRandTask()
{
	int randCnt = rand() % numTasks;
	return getTask(randCnt);
}

WordTask TaskManager::getTask(int count)
{
	return listOfTasks[count];
}