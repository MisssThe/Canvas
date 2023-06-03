cmake_minimum_required(VERSION 3.25)
project(Canvas_1_0)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../CanvasOutput)


include_directories(ThirdParty/Include)

add_executable(Canvas_1_0 main.cpp Source/GarbageCollection.cpp Include/Core/GarbageCollection/GarbageCollection.h Source/CustomPtr.cpp Include/Core/GarbageCollection/CustomPtr.h Source/Canvas.cpp Include/Canvas.h Include/General/Container/Vector.h Include/General/Container/Queue.h Source/Serialize.cpp Include/Core/Asset/Serialize.h Include/Core/Asset/Asset.h Include/General/Container/Map.h Include/General/Debug.h Source/Debug.cpp Source/Time.cpp Source/Scene.cpp Include/Core/Scene/Scene.h Source/Component.cpp Include/Core/Invoker/Component/Component.h Source/Entity.cpp Include/Core/Scene/Entity/Entity.h Include/General/IO.h Source/IO.cpp Source/ThreadPool.cpp Include/Core/GarbageCollection/ThreadPool.h Source/AssetManager.cpp Include/Core/Asset/AssetManager.h Source/Components.cpp Include/Core/Invoker/Component/Components.h Source/Graphic.cpp Include/Core/Invoker/Graphic/Graphic.h Source/Psycho.cpp Include/Core/Invoker/Psycho/Psycho.h Source/Invoker.cpp Source/Transform.cpp Include/Core/Scene/Entity/Transform.h Source/SceneManager.cpp Source/GraphicSetting.cpp Include/Core/Setting/GraphicSetting.h Source/SettingManager.cpp Include/Core/Setting/SettingManager.h Include/Core/Setting/Setting.h Include/Core/Invoker/Graphic/Core/GraphicCore.h Source/OpenGLGraphicCore.cpp Include/Core/Invoker/Graphic/Core/OpenGLGraphicCore.h Source/GraphicData.cpp Include/Core/Invoker/Graphic/GraphicData.h)
