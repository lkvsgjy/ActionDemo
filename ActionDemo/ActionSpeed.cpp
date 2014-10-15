//
//  ActionSpeed.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionSpeed.h"
#include "MainMenu.h"
CCScene * ActionSpeed::scene()
{
    CCScene *scene = CCScene::create();
    ActionSpeed *layer = ActionSpeed::create();
    scene->addChild(layer);
    return scene;
}
bool ActionSpeed::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionSpeed::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        mySprite = CCSprite::create("bird.png");
        mySprite->setPosition(ccp(240, 160));
        this->addChild(mySprite);
        
        return true;
    }
    return false;
}

void ActionSpeed::onEnter()
{
    CCLayer::onEnter();
    CCMoveTo *moveTo = CCMoveTo::create(2, ccp(300, 280));
    CCMoveTo *moveTo1 = CCMoveTo::create(2,ccp(120, 160));
    CCSequence *seq = CCSequence::create(moveTo,moveTo1,NULL);
    CCSpeed *action = CCSpeed::create(CCRepeatForever::create(seq),1.0);
    mySprite->runAction(action);
    action->setTag(10);
    this->schedule(schedule_selector(ActionSpeed::changedSpeed), 1.0f);
}
 
void ActionSpeed::changedSpeed()
{
    CCSpeed *action = (CCSpeed *)mySprite->getActionByTag(10);
    if(action)
        action->setSpeed(CCRANDOM_0_1()*2);
}
void ActionSpeed::back()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}