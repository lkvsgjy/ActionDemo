//
//  CardinalSpline.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__CardinalSpline__
#define __ActionDemo__CardinalSpline__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class CardinalSpline:CCLayer
{
public:
    bool init();
    static CCScene * scene();
    CREATE_FUNC(CardinalSpline);
    void  show1();
    void  show2();
    void  back();
private:
    CCSprite *mySprite;
};

#endif /* defined(__ActionDemo__CardinalSpline__) */
