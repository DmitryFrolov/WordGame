#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <iostream>
#include <vector>
#include "cocos2d.h"
#include "Classes\WordTask.h"
#include "Classes\TaskManager.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
private:
	TaskManager tm;
	static const int maxHealth = 5;
	int numOfHealth;
	std::vector<Node*> icons;
	Label *taskLabel;
	Label *scorePtsLabel;
	int score;
	Vec2 origin;  //coord system
	Size visibleSize;
	WordTask task;


	void updateTask(float dt);
	void initPosMove();
public:
	//HelloWorld() { currentHealth = maxHealth; }
	static cocos2d::Scene* createScene();
	virtual bool init();
	void MoveObject(Sprite *obj, Vec2 moveto, Vec2 scaleby);
	Label *CreateTextLabel(char *text, char *ff, int fsize, Vec2 pos);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void drawHealth();
	void updateHealth();

	void addScore(int s);
	void setScore(int s);

	void ShowAnswer();
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__