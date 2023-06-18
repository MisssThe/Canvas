cmake_minimum_required(VERSION 3.2)
project(Canvas_1_0)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../CanvasOutput)


IF (WIN32)
    set(GLFW_H ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_Windows/include/)
ELSEIF (APPLE)
    set(GLFW_H ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_MacOS/include/)
ENDIF()

# 添加头文件
set(GLAD_H ${PROJECT_SOURCE_DIR}/ThirdParty/glad/4.6/include/)
set(CEREAL_H ${PROJECT_SOURCE_DIR}/ThirdParty/cereal/)
set(ASSIMP_H ${PROJECT_SOURCE_DIR}/ThirdParty/assimp/5.2.5/include)
set(STB_IMAGE_H ${PROJECT_SOURCE_DIR}/ThirdParty/stb_image)

include_directories(${GLFW_H} ${GLAD_H} ${CEREAL_H} ${STB_IMAGE_H} ${ASSIMP_H})

IF (APPLE)
    set(GLFW_LINK ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_MacOS/lib/libglfw.3.dylib)
    set(ASSIMP_LINK ${PROJECT_SOURCE_DIR}/ThirdParty/assimp/5.2.5/lib/libassimp.dylib)
    link_libraries(${OPENGL} ${GLFW_LINK} ${ASSIMP_LINK})
ENDIF()

add_executable(Canvas_1_0 main.cpp Source/GarbageCollection.cpp Include/Core/Framework/GarbageCollection.h Source/CustomPtr.cpp Include/Core/Framework/CustomPtr.h Source/Canvas.cpp Include/Canvas.h Include/General/Container/Vector.h Include/General/Container/Queue.h Source/Serialize.cpp Include/Core/Asset/Serialize.h Include/Core/Asset/Asset.h Include/General/Container/Map.h Include/General/Debug.h Source/Debug.cpp Source/Time.cpp Source/Scene.cpp Include/Core/Scene/Scene.h Source/Component.cpp Include/Core/Invoker/Component/Component.h Source/Entity.cpp Include/Core/Scene/Entity/Entity.h Include/General/IO.h Source/IO.cpp Source/ThreadPool.cpp Include/Core/Framework/ThreadPool.h Source/AssetManager.cpp Include/Core/Asset/AssetManager.h Source/Components.cpp Include/Core/Invoker/Component/Components.h Source/Graphic.cpp Include/Core/Invoker/Graphic/Graphic.h Source/Psycho.cpp Include/Core/Invoker/Psycho/Psycho.h Source/Transform.cpp Include/Core/Scene/Entity/Transform.h Source/SceneManager.cpp Source/GraphicSetting.cpp Include/Core/Setting/GraphicSetting.h Source/SettingManager.cpp Include/Core/Setting/SettingManager.h Include/Core/Invoker/Graphic/Core/GraphicCore.h Source/OpenGLGraphicCore.cpp Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLGraphicCore.h Source/GraphicData.cpp Include/Core/Invoker/Graphic/GraphicData.h ThirdParty/glad/4.6/src/glad.c Source/GraphicFeatures.cpp Include/Core/Invoker/Graphic/Feature/GraphicFeatures.h Source/Feature.cpp Include/Core/Invoker/Graphic/Feature/Feature.h Source/Static.cpp Include/Core/Framework/Static.h Source/SceneSetting.cpp Include/Core/Setting/SceneSetting.h Source/ReflectFactory.cpp Include/Core/Framework/ReflectFactory.h Source/Mesh.cpp Include/Core/Invoker/Graphic/Elements/Mesh.h Source/Material.cpp Include/Core/Invoker/Graphic/Elements/Material.h Source/GraphicCore.cpp Source/Shader.cpp Include/Core/Invoker/Graphic/Elements/Detail/Shader.h Source/Texture.cpp Include/Core/Invoker/Graphic/Elements/Detail/Texture.h Source/Renderer.cpp Include/Core/Invoker/Graphic/Renderer.h Source/String.cpp Include/General/String.h Source/SceneInfo.cpp Include/Core/Scene/SceneInfo.h Source/OpenGLMesh.cpp Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLMesh.h Source/OpenGLShader.cpp Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLShader.h Include/General/Container/ContainSerialize/MapSerialize.h Include/General/Container/ContainSerialize/QueueSerialize.h Include/General/Container/ContainSerialize/VectorSerialize.h ThirdParty/stb_image/stb_image.h Source/AssetSetting.cpp Source/OpenGLTexture.cpp)

## 添加目标链接
IF (WIN32)
    set(GLFW_LINK ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_Windows/lib-mingw-w64/libglfw3.a)
    target_link_libraries(Canvas_1_0 ${GLFW_LINK})
ENDIF()