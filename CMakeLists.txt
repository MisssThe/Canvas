cmake_minimum_required(VERSION 3.25)
project(Canvas_1_0)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../CanvasOutput)

# 添加头文件
set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.8/include)
set(GLAD_H /opt/homebrew/Cellar/glad/include)
include_directories(${GLFW_H} ${GLAD_H})
include_directories(ThirdParty/Include)

# 添加目标链接
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.8/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLFW_LINK})

add_executable(Canvas_1_0 main.cpp Source/GarbageCollection.cpp Include/Core/Framework/GarbageCollection.h Source/CustomPtr.cpp Include/Core/Framework/CustomPtr.h Source/Canvas.cpp Include/Canvas.h Include/General/Container/Vector.h Include/General/Container/Queue.h Source/Serialize.cpp Include/Core/Asset/Serialize.h Include/Core/Asset/Asset.h Include/General/Container/Map.h Include/General/Debug.h Source/Debug.cpp Source/Time.cpp Source/Scene.cpp Include/Core/Scene/Scene.h Source/Component.cpp Include/Core/Invoker/Component/Component.h Source/Entity.cpp Include/Core/Scene/Entity/Entity.h Include/General/IO.h Source/IO.cpp Source/ThreadPool.cpp Include/Core/Framework/ThreadPool.h Source/AssetManager.cpp Include/Core/Asset/AssetManager.h Source/Components.cpp Include/Core/Invoker/Component/Components.h Source/Graphic.cpp Include/Core/Invoker/Graphic/Graphic.h Source/Psycho.cpp Include/Core/Invoker/Psycho/Psycho.h Source/Transform.cpp Include/Core/Scene/Entity/Transform.h Source/SceneManager.cpp Source/GraphicSetting.cpp Include/Core/Setting/GraphicSetting.h Source/SettingManager.cpp Include/Core/Setting/SettingManager.h Include/Core/Setting/Setting.h Include/Core/Invoker/Graphic/Core/GraphicCore.h Source/OpenGLGraphicCore.cpp Include/Core/Invoker/Graphic/Core/OpenGLGraphicCore.h Source/GraphicData.cpp Include/Core/Invoker/Graphic/GraphicData.h Source/glad.c Source/GraphicFeatures.cpp Include/Core/Invoker/Graphic/Feature/GraphicFeatures.h Source/Feature.cpp Include/Core/Invoker/Graphic/Feature/Feature.h Source/Static.cpp Include/Core/Framework/Static.h Source/SceneSetting.cpp Include/Core/Setting/SceneSetting.h Source/ReflectFactory.cpp Include/Core/Framework/ReflectFactory.h Source/Mesh.cpp Include/Core/Invoker/Graphic/Elements/Mesh.h Source/Material.cpp Include/Core/Invoker/Graphic/Elements/Material.h Source/GraphicCore.cpp Source/Shader.cpp Include/Core/Invoker/Graphic/Elements/Detail/Shader.h Source/Texture.cpp Include/Core/Invoker/Graphic/Elements/Detail/Texture.h Source/Renderer.cpp Include/Core/Invoker/Graphic/Renderer.h)
