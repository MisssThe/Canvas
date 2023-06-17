//
// Created by MisThe on 2023/6/13.
//

#ifndef CANVAS_1_0_MAPSERIALIZE_H
#define CANVAS_1_0_MAPSERIALIZE_H


class MapSerialize {
public:
    template<class A, class B>
    static void Read(cereal::BinaryInputArchive &archive, Map<A, B>* map, std::function<void(A&,B&)> call) {
        if (map == nullptr)
            return;
        int size = 0;
        archive(size);
        for (int index = 0; index < size; ++index) {
            A a;
            B b;
            call(a, b);
            map->Insert(a, b);
        }
    }
    template<class A, class B>
    static Map<A, B>* Read(cereal::BinaryInputArchive &archive, std::function<void(A&,B&)> call) {
        Map<A, B> *map = new Map<A, B>();
        MapSerialize::Read(archive, map, call);
        return map;
    }
    template<class A, class B>
    static void Write(cereal::BinaryOutputArchive &archive, Map <A,B> *map, std::function<void(A&,B&)> call) {
        if (map == nullptr)
            return;
        archive(map->Size());
        map->Iterator([&call](A a, B b) {
            call(a, b);
        });
    }
};


#endif //CANVAS_1_0_MAPSERIALIZE_H
