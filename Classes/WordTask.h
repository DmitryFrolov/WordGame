#ifndef _WORD_TASK_H_
#define _WORD_TASK_H_

#include "cocos2d.h"
using namespace	cocos2d;

class WordTask
{
private:
	char *task;
	char *answer;
	char key;
public:
	WordTask();
	~WordTask() {}

	int init(char*, char*, char);
	bool isKeyCorrect(EventKeyboard::KeyCode keyCode);
	
	char getKey() { return key; }
	char *getAnswer() { return answer; }
	char *getTask() { return task; }

	int setKey(char);
	int setAnswer(char*);
	int setTask(char*);

};
#endif // _WORD_TASK_H_