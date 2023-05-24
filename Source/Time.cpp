//
// Created by MisThe on 2023/5/11.
//

#include "../Include/General/Time.h"

unsigned long int NowTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

unsigned long int Time::begin = NowTime();
unsigned long int Time::now = NowTime();
unsigned long int Time::last = NowTime();
unsigned long int Time::frame = 0;

std::string Time::CanvasTimeWithStr() {
    unsigned long int time = CanvasTime();
    return Time::CanvasTimeToStr(time);
}

unsigned long int Time::CanvasTime() {
    return NowTime() - Time::begin;
}

std::string Time::CanvasTimeToStr(unsigned long int time) {
    int millisecond = time % (1000);
    time /= 1000;
    int second = time % 60;
    time /= 60;
    int minute = time % 60;
    int hour = time / 60;
    return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second) + ":" + std::to_string(millisecond);
}

unsigned long int Time::UseTime(std::function<void()> func) {
    unsigned long int start = CanvasTime();
    func();
    unsigned long int end = CanvasTime();
    return end - start;
}

void Time::UpdateFrame() {
    Time::now = NowTime();
    frame = Time::now - Time::last;
    Time::last = Time::now;
}

unsigned long int Time::FrameTime() {
    return Time::frame;
}
