#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <iostream>
#include <vector>
#include "cocos2d.h"
#include "Classes\WordTask.h"
#include "Classes\TaskManager.h"
using namespace cocos2d;

#define LABEL_FONTNAME "fonts/Marker Felt.ttf"
#define LABEL_FONTSIZE 24
#define SCORE_LABEL_FONTSIZE 15
#define SCORE_STEP 10

class HelloWorld : public cocos2d::Layer
{
private:
	TaskManager						   tm;
	std::vector<Node*>				icons;
	static const int		maxHealth = 5;
	int						  numOfHealth;
	
	Label					   *taskLabel;
	Label				   *scorePtsLabel;
	int								score;
	Vec2						   origin;
	Size					  visibleSize;
	WordTask						 task;

	Scene						*endScene;

	void			 updateTask(float dt);
	void					initPosMove();
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void MoveObject(Sprite *obj, Vec2 moveto, Vec2 scaleby);
	Label *CreateTextLabel(char *text, char *ff, int fsize, Vec2 pos);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void drawHealth();
	void updateHealth();

	void addScore(int s);
	void setScore(int s);
	
	void newGame();
	void ShowAnswer();
	void createEndScene();
	void showEnd(float dt);
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuReplayCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__