cmake_minimum_required(VERSION 3.25)
project(Canvas_1_0)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../CanvasOutput)


include_directories(ThirdParty/Include)

add_executable(Canvas_1_0 main.cpp Source/GarbageCollection.cpp Include/Core/GarbageCollection/GarbageCollection.h Source/CustomPtr.cpp Include/Core/GarbageCollection/CustomPtr.h Source/Canvas.cpp Include/Canvas.h Include/General/Container/Vector.h Include/General/Container/Queue.h Source/Serialize.cpp Include/Core/Asset/Serialize.h Source/Asset.cpp Include/Core/Asset/Asset.h Include/General/Container/Map.h Include/General/Debug.h Source/Debug.cpp Source/Time.cpp Source/Transform.cpp Include/Core/Scene/Transform.h Source/Scene.cpp Include/Core/Scene/Scene.h Include/Core/Asset/DefaultAsset.cpp Include/Core/Asset/DefaultAsset.h)
