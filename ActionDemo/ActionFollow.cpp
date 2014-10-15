//
//  ActionFollow.cpp
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#include "ActionFollow.h"
#include "MainMenu.h"
CCScene * ActionFollow::scene()
{
    CCScene *scene = CCScene::create();
    ActionFollow *layer = ActionFollow::create();
    scene->addChild(layer);
    return scene;
}
bool ActionFollow::init()
{
    if(CCLayer::init())
    {
        CCSprite *bg = CCSprite::create("bg.png");
        bg->setPosition(ccp(240, 160));
        this->addChild(bg);
        
        CCMenuItemImage *itemImage = CCMenuItemImage::create("b1.png", "b2.png");
        itemImage->setTarget(this, menu_selector(ActionFollow::back));
        CCMenu *backMenu = CCMenu::create(itemImage,NULL);
        backMenu->setPosition(ccp(50,280));
        this->addChild(backMenu);
        
        CCMenuItemFont *item1 = CCMenuItemFont::create("CCCardinalSpline");
        item1->setTarget(this, menu_selector(ActionFollow::show));
        CCMenu *menu = CCMenu::create(item1,NULL);
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

void ActionFollow::show()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    mySprite1->setPosition(ccp(-200,winSize.height/2));
    CCMoveBy *moveBy = CCMoveBy::create(2, ccp(winSize.width *3, 0));
    CCActionInterval *moveBy1 = moveBy->reverse();
    CCSequence *seq = CCSequence::create(moveBy,moveBy1,NULL);
    CCAction *rep = CCRepeatForever::create(seq);
    mySprite1->runAction(rep);
    this->runAction(CCFollow::create(mySprite1,CCRectMake(0,0,winSize.width*2, winSize.height)));
}
void ActionFollow::back()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
