//
//  ActionTargeted.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionTargeted__
#define __ActionDemo__ActionTargeted__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionTargeted:public CCLayer
{
public:
    static CCScene * scene();
    bool init();
    CREATE_FUNC(ActionTargeted);
    void back();
    void show();
private:
    CCSprite *mySprite1;
    CCSprite *mySprite2;
};

#endif /* defined(__ActionDemo__ActionTargeted__) */
