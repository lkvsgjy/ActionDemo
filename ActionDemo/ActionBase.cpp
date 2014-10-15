//
//  ActionBase.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-26.
//
//

#include "ActionBase.h"
#include "ActionInterval.h"
CCScene * ActionBase::scene()
{
    CCScene *scene = CCScene::create();
    ActionBase *interval = ActionBase::create();
    scene->addChild(interval);
    return scene;
}

bool ActionBase::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
 
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionBase::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("Move");
        CCMenuItemFont *item2 = CCMenuItemFont::create("Rotate");
        CCMenuItemFont *item3 = CCMenuItemFont::create("Scale");
        CCMenuItemFont *item4 = CCMenuItemFont::create("Jump");
        CCMenuItemFont *item5 = CCMenuItemFont::create("Blink");
        CCMenuItemFont *item6 = CCMenuItemFont::create("Skew");
        CCMenuItemFont *item7 = CCMenuItemFont::create("Tint");
        CCMenuItemFont *item8 = CCMenuItemFont::create("Bezier");
        CCMenuItemFont *item9 = CCMenuItemFont::create("recover");
        
        item1->setTarget(this, menu_selector(ActionBase::actionMove));
        item2->setTarget(this, menu_selector(ActionBase::actionRotate));
        item3->setTarget(this, menu_selector(ActionBase::actionScale));
        item4->setTarget(this, menu_selector(ActionBase::actionJump));
        item5->setTarget(this, menu_selector(ActionBase::actionBlink));
        item6->setTarget(this, menu_selector(ActionBase::actionSkew));
        item7->setTarget(this, menu_selector(ActionBase::actionTint));
        item8->setTarget(this, menu_selector(ActionBase::actionBezier));
        item9->setTarget(this, menu_selector(ActionBase::recover));
        
        CCMenu *menu = CCMenu::create(item1,item2,item3,item4,item5,item6,item7,item8,item9,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(3,3,3);
        menu->setPosition(ccp(240,60));
        this->addChild(menu);
        
        mySprite=CCSprite::create("bird.png");
        mySprite->setPosition(ccp(240,160));
        this->addChild(mySprite);
        return true;
    }
    return false;
}

void ActionBase::actionMove()
{
    mySprite->setPosition(ccp(240, 160));
    CCMoveTo *move = CCMoveTo::create(1.0, ccp(360, 240));
    mySprite->runAction(move);
}

void ActionBase::actionRotate()
{
    mySprite->setRotation(0);
    CCRotateTo *rotateTo = CCRotateTo::create(1.0, 180);
    mySprite->runAction(rotateTo);
}

void ActionBase::actionScale()
{
    mySprite->setScale(0);
    CCScaleTo *scaleTo = CCScaleTo::create(1.0, 1.0);
    mySprite->runAction(scaleTo);
}

void ActionBase::actionJump()
{
    mySprite->setPosition(ccp(240, 160));
    CCJumpTo *jumpTo = CCJumpTo::create(1.0, ccp(260, 160), 50, 3);
    mySprite->runAction(jumpTo);
}

void ActionBase::actionBlink()
{
    CCBlink *blink = CCBlink::create(1.0, 3);
    mySprite->runAction(blink);
}

void ActionBase::actionSkew()
{
    CCSkewTo *skewTo = CCSkewTo::create(1.0,37.2, -37.2);
    mySprite->runAction(skewTo);
}

void ActionBase::actionTint()
{
    CCTintTo *tintTo = CCTintTo::create(1.0, 0, 0, 0);
    mySprite->runAction(tintTo);
}

void ActionBase::actionBezier()
{
    ccBezierConfig bezier;
    bezier.controlPoint_1 = CCPointMake(100, 160);
    bezier.controlPoint_2 = CCPointMake(300, -80);
    bezier.endPosition = CCPointMake(300, 100);
    CCBezierTo *bezierTo = CCBezierTo::create(1.0, bezier);
    mySprite->runAction(bezierTo);
}

void ActionBase::recover()
{
    if(mySprite)
    {
        mySprite->removeFromParent();
        mySprite = CCSprite::create("bird.png");
        mySprite->setPosition(ccp(240,160));
        this->addChild(mySprite);
    }
}
void ActionBase::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}