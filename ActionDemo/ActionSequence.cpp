//
//  ActionSequence.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionSequence.h"
#include "ActionInterval.h"
CCScene *ActionSequence::scene()
{
    CCScene *scene = CCScene::create();
    ActionSequence *layer = ActionSequence::create();
    scene->addChild(layer);
    return scene;

}
bool ActionSequence::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionSequence::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("CCSequence");
        CCMenuItemFont *item2 = CCMenuItemFont::create("CCSpawn");
       
        
        item1->setTarget(this, menu_selector(ActionSequence::showSequence));
        item2->setTarget(this, menu_selector(ActionSequence::showSpawn));
        
        
        CCMenu *menu = CCMenu::create(item1,item2,NULL);
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

void ActionSequence::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}

void ActionSequence::showSequence()
{
    
    mySprite->setPosition(ccp(60, 60));
    mySprite->setScale(1.0);
    CCMoveTo *moveTo = CCMoveTo::create(2, ccp(360,280));
    CCScaleTo *scaleTo = CCScaleTo::create(2, 0.5);
    CCSequence *seq = CCSequence::create(moveTo,scaleTo,NULL);
    mySprite->runAction(seq);
     
}
void ActionSequence::showSpawn()
{
    
    mySprite->setPosition(ccp(60, 60));
    mySprite->setScale(0.5);
    CCMoveTo *moveTo = CCMoveTo::create(2, ccp(360,280));
    CCScaleTo *scaleTo = CCScaleTo::create(2, 1);
    CCSpawn *seq = CCSpawn::create(moveTo,scaleTo,NULL);
    mySprite->runAction(seq);
     
}