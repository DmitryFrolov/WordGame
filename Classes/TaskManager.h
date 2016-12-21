#ifndef _TASK_MANAGER_
#define _TASK_MANAGER_
#include "WordTask.h"

class TaskManager
{
private:
	WordTask *listOfTasks;
	int numTasks;
public:
	int getNumTasks();
	void setNumTasks(int);
	void init();
	WordTask getTask(int);
	WordTask getRandTask();
	

	TaskManager() 
	{
		listOfTasks = NULL;
		numTasks = 3;
	};

	~TaskManager() 
	{ 
		delete[] listOfTasks; 
		listOfTasks = NULL; 
	}
};

#endif //_TASK_MANAGER_