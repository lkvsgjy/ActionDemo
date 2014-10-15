//
//  ActionSequence.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionSequence__
#define __ActionDemo__ActionSequence__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionSequence:public CCLayer
{
public:
    static CCScene *scene();
    bool init();
    CREATE_FUNC(ActionSequence);
    void back();
    void showSequence();
    void showSpawn();
private:
    CCSprite *mySprite;
};
#endif /* defined(__ActionDemo__ActionSequence__) */
