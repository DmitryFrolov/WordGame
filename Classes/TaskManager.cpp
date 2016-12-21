#include "TaskManager.h"

void TaskManager::init()
{
	listOfTasks = new WordTask[numTasks];
	char *tasks[] = { "c_llege", "f_sh", "p_one" };
	char *ans[] = { "college", "fish", "phone" };
	char key[] = { 'o', 'i', 'h' };

	for (int i = 0; i < numTasks; i++)
	{
		listOfTasks[i].init(tasks[i], ans[i], key[i]);
	}
	srand(time(0));
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