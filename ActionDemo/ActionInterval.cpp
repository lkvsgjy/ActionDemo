//
//  ActionInterval.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-26.
//
//

#include "ActionInterval.h"
#include "ActionBase.h"
#include "MainMenu.h"
#include "OrbitCamera.h"
#include "CardinalSpline.h"
#include "ActionEase.h"
#include "ActionSequence.h"
#include "ActionDelayTime.h"
#include "ActionTargeted.h"
#include "ActionProgressTo.h"
#include "ActionGridBase.h"
CCScene * ActionInterval::scene()
{
    CCScene *scene = CCScene::create();
    ActionInterval *interval = ActionInterval::create();
    scene->addChild(interval);
    return scene;
}

bool ActionInterval::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
   
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionInterval::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("actionBase");
        CCMenuItemFont *item2 = CCMenuItemFont::create("orbitCamera");
        CCMenuItemFont *item3 = CCMenuItemFont::create("cardinalSpline");
        CCMenuItemFont *item4 = CCMenuItemFont::create("actionEase");
        CCMenuItemFont *item5 = CCMenuItemFont::create("sequence");
        CCMenuItemFont *item6 = CCMenuItemFont::create("delayTime");
        CCMenuItemFont *item7 = CCMenuItemFont::create("targeted");
        CCMenuItemFont *item8 = CCMenuItemFont::create("progressTo");
        CCMenuItemFont *item9 = CCMenuItemFont::create("gridBase");
        
        item1->setTarget(this, menu_selector(ActionInterval::base));
        item2->setTarget(this, menu_selector(ActionInterval::orbitCamera));
        item3->setTarget(this, menu_selector(ActionInterval::cardinalSpline));
        item4->setTarget(this, menu_selector(ActionInterval::actionEase));
        item5->setTarget(this, menu_selector(ActionInterval::sequence));
        item6->setTarget(this, menu_selector(ActionInterval::delayTime));
        item7->setTarget(this, menu_selector(ActionInterval::targetedAction));
        item8->setTarget(this, menu_selector(ActionInterval::progressTo));
        item9->setTarget(this, menu_selector(ActionInterval::gridBase));
        
        
        
        CCMenu *menu = CCMenu::create(item1,item2,item3,item4,item5,item6,item7,item8,item9,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(2,1,2,2,2);
        menu->setPosition(ccp(240,160));
        this->addChild(menu);

        return true;
    }
    
    return false;
}

void ActionInterval::base()
{
    CCDirector::sharedDirector()->replaceScene(ActionBase::scene());
}
void ActionInterval::orbitCamera()
{
    CCDirector::sharedDirector()->replaceScene(OrbitCamera::scene());
}
void ActionInterval::cardinalSpline()
{
    CCDirector::sharedDirector()->replaceScene(CardinalSpline::scene());
}
void ActionInterval::actionEase()
{
     CCDirector::sharedDirector()->replaceScene(ActionEase::scene());
}
void ActionInterval::sequence()
{
     CCDirector::sharedDirector()->replaceScene(ActionSequence::scene());
}
void ActionInterval::delayTime()
{
     CCDirector::sharedDirector()->replaceScene(ActionDelayTime::scene());
}
void ActionInterval::targetedAction()
{
    CCDirector::sharedDirector()->replaceScene(ActionTargeted::scene());
}
void ActionInterval::progressTo()
{
    CCDirector::sharedDirector()->replaceScene(ActionProgressTo::scene());
}
void ActionInterval::gridBase()
{
    CCDirector::sharedDirector()->replaceScene(ActionGridBase::scene());
}
void ActionInterval::back()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}