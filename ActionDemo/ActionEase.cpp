//
//  ActionEase.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionEase.h"
#include "ActionInterval.h"
CCScene * ActionEase::scene()
{
    CCScene *scene = CCScene::create();
    ActionEase *layer = ActionEase::create();
    scene->addChild(layer);
    return scene;
}

bool ActionEase::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionEase::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("EaseIn");
        CCMenuItemFont *item2 = CCMenuItemFont::create("ExponentialIn");
        CCMenuItemFont *item3 = CCMenuItemFont::create("SineIn");
        CCMenuItemFont *item4 = CCMenuItemFont::create("BounceIn");
        CCMenuItemFont *item5 = CCMenuItemFont::create("ElasticIn");
        CCMenuItemFont *item6 = CCMenuItemFont::create("BackIn");
        
        item1->setTarget(this, menu_selector(ActionEase::showBase));
        item2->setTarget(this, menu_selector(ActionEase::showExponential));
        item3->setTarget(this, menu_selector(ActionEase::showSine));
        item4->setTarget(this, menu_selector(ActionEase::showBounce));
        item5->setTarget(this, menu_selector(ActionEase::showElastic));
        item6->setTarget(this, menu_selector(ActionEase::showBack));
        
        CCMenu *menu = CCMenu::create(item1,item2,item3,item4,item5,item6,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(2,2,2);
        menu->setPosition(ccp(240,80));
        this->addChild(menu);
        
        mySprite1 = CCSprite::create("bird.png");
        mySprite1->setPosition(ccp(60, 180));
        this->addChild(mySprite1);
        
        mySprite2 = CCSprite::create("bird.png");
        mySprite2->setPosition(ccp(60, 240));
        this->addChild(mySprite2);

        return true;
    }
    return false;
}

void ActionEase::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}

void ActionEase::showBase()
{
    mySprite1->setPosition(ccp(60, 180));
    mySprite2->setPosition(ccp(60, 240));
    CCMoveTo *moveTo1 = CCMoveTo::create(2, ccp(360, 180));
    CCMoveTo *moveTo2 = CCMoveTo::create(2, ccp(360, 240));
    mySprite1->runAction(moveTo1);
    CCEaseIn *action = CCEaseIn::create(moveTo2, 2.5f);
    mySprite2->runAction(action);
}

void ActionEase::showExponential()
{
    mySprite1->setPosition(ccp(60, 180));
    mySprite2->setPosition(ccp(60, 240));
    CCMoveTo *moveTo1 = CCMoveTo::create(2, ccp(360, 180));
    CCMoveTo *moveTo2 = CCMoveTo::create(2, ccp(360, 240));
    mySprite1->runAction(moveTo1);
    CCEaseExponentialIn *action = CCEaseExponentialIn::create(moveTo2);
    mySprite2->runAction(action);
}
void ActionEase::showSine()
{
    mySprite1->setPosition(ccp(60, 180));
    mySprite2->setPosition(ccp(60, 240));
    CCMoveTo *moveTo1 = CCMoveTo::create(2, ccp(360, 180));
    CCMoveTo *moveTo2 = CCMoveTo::create(2, ccp(360, 240));
    mySprite1->runAction(moveTo1);
    CCEaseSineIn *action = CCEaseSineIn::create(moveTo2);
    mySprite2->runAction(action);
}

void ActionEase::showBounce()
{
    mySprite1->setPosition(ccp(60, 180));
    mySprite2->setPosition(ccp(60, 240));
    CCMoveTo *moveTo1 = CCMoveTo::create(2, ccp(360, 180));
    CCMoveTo *moveTo2 = CCMoveTo::create(2, ccp(360, 240));
    mySprite1->runAction(moveTo1);
    CCEaseBounceIn *action = CCEaseBounceIn::create(moveTo2);
    mySprite2->runAction(action);
}

void ActionEase::showElastic()
{
    mySprite1->setPosition(ccp(60, 180));
    mySprite2->setPosition(ccp(60, 240));
    CCMoveTo *moveTo1 = CCMoveTo::create(2, ccp(360, 180));
    CCMoveTo *moveTo2 = CCMoveTo::create(2, ccp(360, 240));
    mySprite1->runAction(moveTo1);
    CCEaseElasticIn *action = CCEaseElasticIn::create(moveTo2);
    mySprite2->runAction(action);

}

void ActionEase::showBack()
{
    mySprite1->setPosition(ccp(60, 180));
    mySprite2->setPosition(ccp(60, 240));
    CCMoveTo *moveTo1 = CCMoveTo::create(2, ccp(360, 180));
    CCMoveTo *moveTo2 = CCMoveTo::create(2, ccp(360, 240));
    mySprite1->runAction(moveTo1);
    CCEaseBackIn *action = CCEaseBackIn::create(moveTo2);
    mySprite2->runAction(action);
}