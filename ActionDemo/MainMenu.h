//
//  MainMenu.h
//  ActionDemo
//
//  Created by yangxin on 13-8-26.
//
//

#ifndef __ActionDemo__MainMenu__
#define __ActionDemo__MainMenu__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class MainMenu:CCLayer
{
public:
    bool init();
    static CCScene * scene();
    CREATE_FUNC(MainMenu);
    void actionIntervalCallBack();
    void actionIntantCallBack();
    void actionSpeedCallBack();
    void actionFollowCallBack();
    void actionManagerCallBack();
};
#endif /* defined(__ActionDemo__MainMenu__) */
