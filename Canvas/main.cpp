#include <iostream>
#include "Head/Canvas.h"
#include "Head/Tool/Debug.h"

int main() {
    Debug::Info("你好呀");
    Debug::Warm("我不好");
    Debug::Error("怎么啦");
    Canvas::Start();
    return 0;
}
