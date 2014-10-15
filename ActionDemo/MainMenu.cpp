//
//  MainMenu.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-26.
//
//

#include "MainMenu.h"
#include "ActionInterval.h"
#include "ActionIntant.h"
#include "ActionSpeed.h"
#include "ActionFollow.h"
#include "ActionManager.h"
CCScene * MainMenu::scene()
{
    CCScene *scene = CCScene::create();
    MainMenu *mainMenu = MainMenu::create();
    scene->addChild(mainMenu);
    return scene;
}

bool MainMenu::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("interval");
        CCMenuItemFont *item2 = CCMenuItemFont::create("intant");
        CCMenuItemFont *item3 = CCMenuItemFont::create("speed");
        CCMenuItemFont *item4 = CCMenuItemFont::create("follow");
        CCMenuItemFont *item5 = CCMenuItemFont::create("manager");
        
        item1->setTarget(this, menu_selector(MainMenu::actionIntervalCallBack));
        item2->setTarget(this, menu_selector(MainMenu::actionIntantCallBack));
        item3->setTarget(this, menu_selector(MainMenu::actionSpeedCallBack));
        item4->setTarget(this, menu_selector(MainMenu::actionFollowCallBack));
        item5->setTarget(this, menu_selector(MainMenu::actionManagerCallBack));
        
        CCMenu *menu = CCMenu::create(item1,item2,item3,item4,item5,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(1,2,2);
        menu->setPosition(ccp(240,160));
        this->addChild(menu);
        return true;
    }
    return false;
}

void MainMenu::actionIntervalCallBack()
{
    CCLOG("actionIntervalCallBack");
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}

void MainMenu::actionIntantCallBack()
{
    CCLOG("actionIntantCallBack");
    CCDirector::sharedDirector()->replaceScene(ActionIntant::scene());
}

void MainMenu::actionSpeedCallBack()
{
    CCLOG("actionSpeedCallBack");
    CCDirector::sharedDirector()->replaceScene(ActionSpeed::scene());
}
void MainMenu::actionFollowCallBack()
{
    CCLOG("actionFollowCallBack");
    CCDirector::sharedDirector()->replaceScene(ActionFollow::scene());
}
void MainMenu::actionManagerCallBack()
{
    CCLOG("actionManagerCallBack");
    CCDirector::sharedDirector()->replaceScene(ActionManager::scene());
}