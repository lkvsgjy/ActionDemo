//
//  OrbitCamera.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__OrbitCamera__
#define __ActionDemo__OrbitCamera__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class OrbitCamera:CCLayer
{
public:
    bool init();
    static CCScene * scene();
    CREATE_FUNC(OrbitCamera);
    void  show();
    void  back();
private:
    CCSprite *mySprite;
};
#endif /* defined(__ActionDemo__OrbitCamera__) */
