#include "WordTask.h"
#define KEYCODE_OFFSET 27 //разница между char-кодом в cocos и ANSI(смещение)

WordTask::WordTask()
{
	this->key = ' ';
	this->answer = "";
	this->task = "";
}

bool WordTask::isKeyCorrect(EventKeyboard::KeyCode keyCode)
{
	if ((EventKeyboard::KeyCode)(this->key + KEYCODE_OFFSET) == keyCode)
	{
		return true;
	}
	return false;
}

int WordTask::init(char* t, char* ans, char k)
{
	this->key = k;
	this->answer = ans;
	this->task = t;
	return 0;
}

int WordTask::setKey(char k)
{
	this->key = k;
	return 0;
}

int WordTask::setAnswer(char* ans)
{
	this->answer = ans;
	return 0;
}

int WordTask::setTask(char* t)
{
	this->task = t;
	return 0;
}
