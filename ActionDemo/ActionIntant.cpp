//
//  ActionIntant.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionIntant.h"
#include "MainMenu.h"
CCScene * ActionIntant::scene()
{
    CCScene *scene = CCScene::create();
    ActionIntant *layer = ActionIntant::create();
    scene->addChild(layer);
    return scene;
}

bool ActionIntant::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionIntant::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
          
        CCMenuItemFont *item1 = CCMenuItemFont::create("CallFunc");
        item1->setTarget(this, menu_selector(ActionIntant::show1));
        CCMenuItemFont *item2 = CCMenuItemFont::create("CallFuncN");
        item2->setTarget(this, menu_selector(ActionIntant::show2));
        CCMenuItemFont *item3 = CCMenuItemFont::create("CallFuncND");
        item3->setTarget(this, menu_selector(ActionIntant::show3));
        CCMenu *menu = CCMenu::create(item1,item2,item3,NULL);
        menu->setPosition(ccp(240, 60));
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsHorizontallyWithPadding(30);
        this->addChild(menu);
        
        mySprite1 = CCSprite::create("bird.png");
        mySprite1->setPosition(ccp(160, 160));
        this->addChild(mySprite1);
        
        mySprite2 = CCSprite::create("bird2.png");
        mySprite2->setPosition(ccp(320, 160));
        this->addChild(mySprite2);

        return true;
    }
    return false;
}



void ActionIntant::callback1()
{
    CCJumpTo *jumpTo = CCJumpTo::create(2, mySprite1->getPosition(), 50, 5);
    mySprite1->runAction(jumpTo);
}

void ActionIntant::callback2(CCNode* sender)
{
    CCJumpTo *jumpTo = CCJumpTo::create(2, mySprite1->getPosition(), 50, 5);
    sender->runAction(jumpTo);
}

void ActionIntant::callback3(CCNode* sender, CCObject *sprite)
{
    CCScaleTo *scalTo = CCScaleTo::create(1, 0.1);
    CCScaleTo *scalTo1 = CCScaleTo::create(1, 1.0);
    CCSequence *seq = CCSequence::create(scalTo,scalTo1,NULL);
    ((CCSprite *)sprite)->runAction(seq);
}

void ActionIntant::show1()
{
    CCCallFunc *func = CCCallFunc::create(this, callfunc_selector(ActionIntant::callback1));
    this->runAction(func);
}
void ActionIntant::show2()
{
    CCCallFuncN *funcN = CCCallFuncN::create(this, callfuncN_selector(ActionIntant::callback2));
    mySprite1->runAction(funcN);
}
void ActionIntant::show3()
{
    CCCallFuncND *funcND = CCCallFuncND::create(this,callfuncND_selector(ActionIntant::callback3), mySprite2);
    this->runAction(funcND);
}
void ActionIntant::back()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
