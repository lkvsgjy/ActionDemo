//
//  CardinalSpline.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "CardinalSpline.h"
#include "ActionInterval.h"
CCScene * CardinalSpline::scene()
{
    CCScene *scene = CCScene::create();
    CardinalSpline *layer = CardinalSpline::create();
    scene->addChild(layer);
    return scene;
}

bool CardinalSpline::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(CardinalSpline::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("CCCardinalSpline");
        item1->setTarget(this, menu_selector(CardinalSpline::show1));
        CCMenuItemFont *item2 = CCMenuItemFont::create("CCCatmullRom");
        item2->setTarget(this, menu_selector(CardinalSpline::show2));
        CCMenu *menu = CCMenu::create(item1,item2,NULL);
        menu->setPosition(ccp(240, 60));
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsHorizontallyWithPadding(30);
        this->addChild(menu);
        
        mySprite = CCSprite::create("bird.png");
        mySprite->setPosition(ccp(240, 160));
        this->addChild(mySprite);
        return true;
    }
    return false;
}
void  CardinalSpline::show1()
{
    CCPointArray *array = CCPointArray::create(20);
    array->addControlPoint(ccp(0,0));
    array->addControlPoint(ccp(210,0));
    array->addControlPoint(ccp(210,240));
    array->addControlPoint(ccp(0,240));
    array->addControlPoint(ccp(0,0));
    CCCardinalSplineTo *action = CCCardinalSplineTo::create(3, array, 0);
    mySprite->runAction(action);
}
void  CardinalSpline::show2()
{
    CCPointArray *array = CCPointArray::create(20);
    array->addControlPoint(ccp(0,0));
    array->addControlPoint(ccp(210,0));
    array->addControlPoint(ccp(210,240));
    array->addControlPoint(ccp(0,240));
    array->addControlPoint(ccp(0,0));
    CCCatmullRomTo *action = CCCatmullRomTo::create(3, array);
    mySprite->runAction(action);
}
void CardinalSpline::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}