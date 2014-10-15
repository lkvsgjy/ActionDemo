//
//  ActionIntant.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionIntant__
#define __ActionDemo__ActionIntant__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionIntant:CCLayer
{
public:
    bool init();
    static CCScene *scene();
    CREATE_FUNC(ActionIntant);
    void show1();
    void show2();
    void show3();
    void callback1();
    void callback2(CCNode* sender);
    void callback3(CCNode* sender, CCObject *sprite);
    void back();
private:
    CCSprite *mySprite1;
    CCSprite *mySprite2;
};
#endif /* defined(__ActionDemo__ActionIntant__) */
