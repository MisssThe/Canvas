cmake_minimum_required(VERSION 3.24)
project(Canvas)

set(CMAKE_CXX_STANDARD 17)

add_executable(Canvas main.cpp Source/Platform.cpp Head/Core/Platform/Platform.h Head/Canvas.h Source/Setting.cpp Head/Core/Setting/Setting.h Source/Physical.cpp Head/Core/Physical/Physical.h Source/Music.cpp Head/Core/Music/Music.h Source/Graphic.cpp Head/Core/Graphic/Graphic.h Source/Asset.cpp Head/Asset/Asset.h Source/AssetLoader.cpp Head/Tool/AssetLoader/AssetLoader.h Source/Debug.cpp Head/Tool/Debug.h)