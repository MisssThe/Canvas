//
// Created by MisThe on 2023/5/28.
//

#include "Test.h"
#include "../../../../General/Debug.h"

void Test::Initial() {

}

void Test::OnEnable() {

}

void Test::Invoke() {
    Debug::Info("test component", "invoke");
}

void Test::OnDisable() {

}

void Test::Destroy() {

}

void Test::CustomMark() {

}

Test::~Test() = default;

void Test::Read(cereal::BinaryInputArchive &archive) {
    Component::Read(archive);
}

void Test::Write(cereal::BinaryOutputArchive &archive) {
    Component::Write(archive);
}
