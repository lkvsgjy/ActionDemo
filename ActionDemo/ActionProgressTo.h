//
//  ActionProgressTo.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionProgressTo__
#define __ActionDemo__ActionProgressTo__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionProgressTo:public CCLayer
{
public:
    static CCScene * scene();
    bool init();
    CREATE_FUNC(ActionProgressTo);
    void back();
    void show();
private:
     CCProgressTimer *timer;
     CCProgressTimer *timer1;
};

#endif /* defined(__ActionDemo__ActionProgressTo__) */
