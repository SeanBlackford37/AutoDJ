cmake_minimum_required(VERSION 3.15)
project(CS220FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS220FinalProject Library.cpp Library.h Song.cpp Song.h Tests.cpp Playlist.cpp Playlist.h ArrayList.cpp ArrayList.h ArrayLib.cpp ArrayLib.h PlaylistArrayList.cpp PlaylistArrayList.h TestLib.cpp TestLib.h)

