//
//  ActionDelayTime.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionDelayTime.h"
#include "ActionInterval.h"
CCScene * ActionDelayTime::scene()
{
    CCScene *scene = CCScene::create();
    ActionDelayTime *layer = ActionDelayTime::create();
    scene->addChild(layer);
    return scene;
}
bool ActionDelayTime::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionDelayTime::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("show");
                
        
        item1->setTarget(this, menu_selector(ActionDelayTime::show));
       
        
        
        CCMenu *menu = CCMenu::create(item1,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(1,1);
        menu->setPosition(ccp(240,80));
        this->addChild(menu);
        
        mySprite = CCSprite::create("bird.png");
        mySprite->setPosition(ccp(60, 180));
        this->addChild(mySprite);
        
        return true;
    }
    return false;
}
void ActionDelayTime::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}
void ActionDelayTime::show()
{
    CCMoveTo *moveTo = CCMoveTo::create(2, ccp(360, 240));
    CCRotateBy *rotateBy = CCRotateBy::create(2, 720);
    CCSequence *seq = CCSequence::create(moveTo,CCDelayTime::create(2),rotateBy,NULL);
    mySprite->runAction(seq);
}
