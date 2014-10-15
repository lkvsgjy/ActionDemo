//
//  ActionProgressTo.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionProgressTo.h"
#include "ActionInterval.h"
CCScene * ActionProgressTo::scene()
{
    CCScene *scene = CCScene::create();
    ActionProgressTo *layer = ActionProgressTo::create();
    scene->addChild(layer);
    return scene;
}
bool ActionProgressTo::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionProgressTo::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("show");
        item1->setTarget(this, menu_selector(ActionProgressTo::show));
        CCMenu *menu = CCMenu::create(item1,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(1,1);
        menu->setPosition(ccp(240,80));
        this->addChild(menu);
        
        
 
        
        return true;
    }
    return false;
}
void ActionProgressTo::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}
void ActionProgressTo::show()
{
    CCProgressTo *progressTo = CCProgressTo::create(2, 100);
    timer = CCProgressTimer::create(CCSprite::create("bird.png"));
    timer->setType(kCCProgressTimerTypeRadial);
    timer->setPosition(ccp(240,240));
    this->addChild(timer);
    CCSequence *seq = CCSequence::create(progressTo,CCDelayTime::create(2),NULL);
    timer->runAction(CCRepeatForever::create(seq));
    
    
    CCProgressTo *progressTo1 = CCProgressTo::create(2, 100);
    timer1 = CCProgressTimer::create(CCSprite::create("grass.png"));
    timer1->setType(kCCProgressTimerTypeBar);
    timer1->setMidpoint(ccp(0,0.5));
    timer1->setPosition(ccp(240,160));
    this->addChild(timer1);
    CCSequence *seq1 = CCSequence::create(progressTo1,CCDelayTime::create(2),NULL);
    timer1->runAction(CCRepeatForever::create(seq1));
}
