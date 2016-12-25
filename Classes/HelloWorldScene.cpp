#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	newGame();
	addBackgroundAudio();
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	Vec2 scorePosition = Vec2(origin.x + visibleSize.width * 9 / 10, origin.y + visibleSize.height * 9.3 / 10);
	Label *scoreLabel = CreateTextLabel("Score:", LABEL_FONTNAME, LABEL_FONTSIZE, scorePosition);
	scorePtsLabel = CreateTextLabel("0", LABEL_FONTNAME, LABEL_FONTSIZE, scorePosition + Vec2(47, 0));

	createBackground();

	Vec2 taskPos = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 20);
	taskLabel = CreateTextLabel("Hi", LABEL_FONTNAME, LABEL_FONTSIZE, taskPos);
	taskLabel->setAnchorPoint(Vec2(0.5, 1));
	Vec2 taskMoveTo = origin + Vec2(visibleSize.width / 2, 0);
	MoveObject((Sprite*)taskLabel, taskMoveTo, Vec2(3, 3));
	
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this); 
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	drawHealth();

	tm.init();
	task = tm.getRandTask();
	taskLabel->setString(task.getTask());
	schedule(schedule_selector(HelloWorld::checkDownScreenCollision), 0); //костыль?

	return true;
}

void HelloWorld::checkDownScreenCollision(float dt)
{
	if (taskLabel->getPositionY() <= 0) {
		numOfHealth--;																					
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("life_lose.wav");
		updateHealth();
		updateTask(0);
	}
}

void HelloWorld::ShowAnswer()
{
	taskLabel->setString(task.getAnswer());
	taskLabel->stopAllActions();
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (EventKeyboard::KeyCode::KEY_ESCAPE == keyCode) {
		audio->end();
		exit(0);
	}
	if (task.isKeyCorrect(keyCode))
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("tower_place.wav");
		ShowAnswer();
		addScore(SCORE_STEP);
		scheduleOnce(schedule_selector(HelloWorld::updateTask), 0);
	}
	else
	{
		widthdrawHealth();
	}
}

void HelloWorld::MoveObject(Sprite *obj, Vec2 moveto, Vec2 scaleby)
{
	auto acMoveTo = MoveTo::create(4, moveto);
	auto acScaleBy = ScaleBy::create(2, scaleby.x, scaleby.y);
	obj->runAction(acScaleBy);
	obj->runAction(acMoveTo);
}

void HelloWorld::drawHealth()
{
	icons.reserve(numOfHealth);
	Vec2 defaultPosition = Vec2(origin.x + 30, origin.y + visibleSize.height * 9.3 / 10);
	for (int i = 0; i < numOfHealth; i++)
	{
		icons.push_back(Sprite::create("heart.png"));
		icons[i]->setPosition(defaultPosition);
		icons[i]->setScale((float)0.15);
		this->addChild(icons[i], 0);
		defaultPosition += Vec2(14, 0);
	}
}

void HelloWorld::updateHealth()
{
	if (numOfHealth < 1) {
		scheduleOnce(schedule_selector(HelloWorld::showEnd), 0);
	}

	for (int i = maxHealth-1; i >= numOfHealth; i--)
		icons[i]->setOpacity(1);
}

Label *HelloWorld::CreateTextLabel(char *text, char *ff, int fsize, Vec2 pos)
{
	Label *label = Label::createWithTTF(text, ff, fsize);
	label->setPosition(pos);
	this->addChild(label, 1, "text_label");
	return label;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	audio->end();
	Director::getInstance()->end();
}

void HelloWorld::updateTask(float dt)
{
	task = tm.getRandTask();
	taskLabel->setString(task.getTask());
	initPosMove();
	schedule(schedule_selector(HelloWorld::checkDownScreenCollision), 0);    //костыль
}

void HelloWorld::initPosMove()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Vec2 taskPos = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 20);
	taskLabel->setPosition(taskPos);
	taskLabel->setScale(1);

	Vec2 taskMoveTo = origin + Vec2(visibleSize.width / 2, 0);
	MoveObject((Sprite*)taskLabel, taskMoveTo, Vec2(3, 3));
}

void HelloWorld::addScore(int s)
{
	setScore(score + s);
}

void HelloWorld::setScore(int s)
{
	score = s;
	scorePtsLabel->setString(std::to_string(score));
}

void HelloWorld::createEndScene()
{
	endScene = Scene::create();

	Label *lbEnd = Label::createWithTTF("End", LABEL_FONTNAME, 3 * LABEL_FONTSIZE);
	Vec2 pos = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 60);
	lbEnd->setPosition(pos);
	endScene->addChild(lbEnd);

	auto replayItem = MenuItemImage::create("replayNormal.png", "replayNormal.png", CC_CALLBACK_1(HelloWorld::menuReplayCallback, this));
	replayItem->setPosition(Vec2(pos.x, pos.y-lbEnd->getContentSize().height-10));
	
	auto menu = Menu::create(replayItem, NULL);
	menu->setPosition(Vec2::ZERO);
	endScene->addChild(menu, 1);
}

void HelloWorld::showEnd(float dt)
{
	createEndScene();
	Director::getInstance()->pushScene(endScene);
	newGame();
}

void HelloWorld::menuReplayCallback(cocos2d::Ref* pSender) //call game scene
{
	Director::getInstance()->popScene();
	setScore(0);
	updateTask(0);
	for (int i = 0; i < maxHealth; i++)
		icons[i]->setOpacity(255);
}

void HelloWorld::newGame()
{
	numOfHealth = maxHealth;
}

void HelloWorld::createBackground()
{
	auto backgtoundImage = Sprite::create(BACKGROUND_NAME);
	backgtoundImage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(backgtoundImage, -1);
}

void HelloWorld::addBackgroundAudio()
{
	audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("8bitDungeonLevel.mp3", true);
}

void HelloWorld::widthdrawHealth()
{
	numOfHealth--;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("life_lose.wav");
	updateHealth();
}