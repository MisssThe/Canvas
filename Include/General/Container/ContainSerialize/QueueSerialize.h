//
// Created by MisThe on 2023/6/13.
//

#ifndef CANVAS_1_0_QUEUESERIALIZE_H
#define CANVAS_1_0_QUEUESERIALIZE_H


class QueueSerialize {
public:
    template<class T>
    static void Read(cereal::BinaryInputArchive &archive, Queue<T>* queue, std::function<T()> call) {
        if (queue == nullptr)
            return;
        int size = 0;
        archive(size);
        for (int index = 0; index < size; ++index) {
            T temp = call();
            queue->Push(temp);
        }
    };
    template<class T>
    static Queue<T>* Read(cereal::BinaryInputArchive &archive, std::function<T()> call) {
        Queue<T>* queue = new Queue<T>();
        QueueSerialize::Read<T>(archive, queue, call);
        return queue;
    }
    template<class T>
    static void Write(cereal::BinaryOutputArchive &archive, Queue<T> *queue, std::function<void(T)> call) {
        if (queue == nullptr)
            return;
        archive(queue->Size());
        queue->IteratorWithout([&call](T temp) {
            call(temp);
        });
    }
};


#endif //CANVAS_1_0_QUEUESERIALIZE_H
