//
// Created by MisThe on 2023/5/11.
// 单位默认为毫秒
//

#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H

#include <functional>
#include <string>

class Time {
private:
    static unsigned long int begin;
    static unsigned long int now;
    static unsigned long int last;
    static unsigned long int frame;
public:
    static unsigned long int CanvasTime();                               //程序运行时间
    static std::string CanvasTimeWithStr();                              //程序运行时间(输出格式（时：分：秒：毫秒）)
    static std::string CanvasTimeToStr(unsigned long int time);          //程序运行时间(输出格式（时：分：秒：毫秒）)
    static unsigned long int UseTime(std::function<void()> func);        //function执行时间
    static unsigned long int FrameTime();                                //上一帧花费时间
public:
    static void UpdateFrame();                                           //刷新帧间隔时间
};


#endif //ENGINE_TIME_H
