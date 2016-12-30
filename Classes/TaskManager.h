#ifndef _TASK_MANAGER_
#define _TASK_MANAGER_
#include "WordTask.h"
#include "TaskGenerator.h"

class TaskManager
{
private:
	WordTask *listOfTasks;
	TaskGenerator *generator;
	int numTasks;
public:
	int getNumTasks();
	void setNumTasks(int);
	void init();
	WordTask getTask(int);
	WordTask getRandTask();

	TaskManager();
	~TaskManager();
	
};

#endif //_TASK_MANAGER_