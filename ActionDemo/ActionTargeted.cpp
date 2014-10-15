//
//  ActionTargeted.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionTargeted.h"
#include "ActionInterval.h"
CCScene * ActionTargeted::scene()
{
    CCScene *scene = CCScene::create();
    ActionTargeted *layer = ActionTargeted::create();
    scene->addChild(layer);
    return scene;
}
bool ActionTargeted::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionTargeted::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("show");
        item1->setTarget(this, menu_selector(ActionTargeted::show));
        CCMenu *menu = CCMenu::create(item1,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(1,1);
        menu->setPosition(ccp(240,80));
        this->addChild(menu);
        
        mySprite1 = CCSprite::create("bird.png");
        mySprite1->setPosition(ccp(160, 160));
        this->addChild(mySprite1);
        
        mySprite2 = CCSprite::create("bird.png");
        mySprite2->setPosition(ccp(320, 160));
        this->addChild(mySprite2);
        
        return true;
    }
    return false;
}
void ActionTargeted::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}
void ActionTargeted::show()
{
    CCJumpBy *jump1 = CCJumpBy::create(2, ccp(0, 0), 100, 3);
    CCJumpBy *jump2 = (CCJumpBy*)jump1->copy()->autorelease();
    CCRotateBy *rot1 = CCRotateBy::create(1, 360);
    CCRotateBy *rot2 = (CCRotateBy *)rot1->copy()->autorelease();
    
    CCTargetedAction *t1 = CCTargetedAction::create(mySprite1, jump2);
    CCTargetedAction *t2 = CCTargetedAction::create(mySprite1, rot2);
    
    CCSequence *seq = CCSequence::create(jump1,t1,rot1,t2,NULL);
    CCRepeatForever *always = CCRepeatForever::create(seq);
    
    mySprite2->runAction(always);
}
