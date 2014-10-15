//
//  ActionGridBase.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionGridBase.h"
#include "ActionInterval.h"
CCScene * ActionGridBase::scene()
{
    CCScene *scene = CCScene::create();
    ActionGridBase *layer = ActionGridBase::create();
    scene->addChild(layer);
    return scene;
}
bool ActionGridBase::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        mySprite = CCSprite::create("water.png");
        mySprite->setPosition(ccp(240, 160));
        this->addChild(mySprite);

        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionGridBase::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("CCWaves");
        CCMenuItemFont *item2 = CCMenuItemFont::create("CCPageTurn3D");
        item1->setTarget(this, menu_selector(ActionGridBase::show1));
        item2->setTarget(this, menu_selector(ActionGridBase::show2));

        
        CCMenu *menu = CCMenu::create(item1,item2,NULL);
        menu->setColor(ccc3(0, 255, 0));
        menu->alignItemsInColumns(2);
        menu->setPosition(ccp(240,80));
        this->addChild(menu);
        
                
        
        return true;
    }
    return false;
}
void ActionGridBase::back()
{
    CCDirector::sharedDirector()->replaceScene(ActionInterval::scene());
}
void ActionGridBase::show1()
{
    CCSize size = CCSizeMake(50, 50);
    CCWaves *waves = CCWaves::create(1, size, 100, 1.0f, true, false);
    mySprite->runAction(waves);
}

void ActionGridBase::show2()
{
    CCSize size = CCSizeMake(10, 10);
    CCPageTurn3D *turn = CCPageTurn3D::create(2, size);
    mySprite->runAction(turn);
}

