//
//  OrbitCamera.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "OrbitCamera.h"
#include "ActionInterval.h"
CCScene * OrbitCamera::scene()
{
    CCScene *scene = CCScene::create();
    OrbitCamera *layer = OrbitCamera::create();
    scene->addChild(layer);
    return scene;
}

bool OrbitCamera::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(OrbitCamera::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);

        
        CCMenuItemFont *item = CCMenuItemFont::create("show");
        item->setTarget(this, menu_selector(OrbitCamera::show));
        CCMenu *menu = CCMenu::create(item,NULL);
        menu->setPosition(ccp(240, 60));
        this->addChild(menu);
        
        mySprite = CCSprite::create("bird.png");
        mySprite->setPosition(ccp(240, 160));
        this->addChild(mySprite);
        return true;
    }
    return false;
}

void  OrbitCamera::show()
{
    CCOrbitCamera *orbit = CCOrbitCamera::create(2, 1, 0, 0, 180, -45, 0);
    CCSequence *seq = CCSequence::create(orbit,orbit->reverse(),NULL);
    mySprite->runAction(seq);
}

void  OrbitCamera::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}