//
//  ActionManager.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionManager.h"
#include "MainMenu.h"
CCScene *ActionManager::scene()
{
    CCScene *scene = CCScene::create();
    ActionManager *layer = ActionManager::create();
    scene->addChild(layer);
    return scene;
}
bool ActionManager::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionManager::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        mySprite = CCSprite::create("bird.png");
        mySprite->setTag(13);
        this->addChild(mySprite);
       
        
        return true;
    }
    return false;
}

void ActionManager::onEnter()
{
    CCLayer::onEnter();
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    mySprite->setPosition(ccp(s.width/2, s.height/2));
    
    mySprite->runAction(CCRotateBy::create(5, 1440));
    
    CCDirector * pDirector = CCDirector::sharedDirector();
    pDirector->getActionManager()->pauseTarget(mySprite);
    this->schedule(schedule_selector(ActionManager::resumeGrossini),3.0);
}

void ActionManager::back()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
void ActionManager::resumeGrossini(float time)
{
    this->unschedule(schedule_selector(ActionManager::resumeGrossini));
    CCNode *p = this->getChildByTag(13);
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->getActionManager()->resumeTarget(p);
}
