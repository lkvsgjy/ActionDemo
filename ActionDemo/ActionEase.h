//
//  ActionEase.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionEase__
#define __ActionDemo__ActionEase__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionEase:CCLayer
{
public:
    static CCScene *scene();
    bool init();
    CREATE_FUNC(ActionEase);
    void back();
    void showBase();
    void showExponential();
    void showSine();
    void showBounce();
    void showElastic();
    void showBack();
public:
    CCSprite *mySprite1;
    CCSprite *mySprite2;
};
#endif /* defined(__ActionDemo__ActionEase__) */
