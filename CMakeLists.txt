cmake_minimum_required(VERSION 4.1)
project(algorithm_journey)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm_journey
        src/class035/Code01_SetAllHashMap.cpp
        src/class035/Code02_LRU.cpp
        src/class035/Code03_InsertDeleteRandom.cpp
        src/class035/Code04_InsertDeleteRandomDuplicatesAllowed.cpp
        src/class035/Code05_MedianFinder.cpp
        src/class035/Code06_MaximumFrequencyStack.cpp
        src/class035/Code07_AllO1.cpp
        src/class036/Code01_LevelOrderTraversal.cpp
        src/class036/Code01_LevelOrderTraversal.cpp
        src/class036/Code02_ZigzagLevelOrderTraversal.cpp
        src/class036/Code03_WidthOfBinaryTree1.cpp
        src/class036/Code04_DepthOfBinaryTree.cpp
        src/class036/Code05_PreorderSerializeAndDeserialize.cpp
        src/class036/Code06_LevelorderSerializeAndDeserialize.cpp
        src/class036/Code07_PreorderInorderBuildBinaryTree.cpp
        src/class036/Code08_CompletenessOfBinaryTree.cpp
        src/class036/Code09_CountCompleteTreeNodes.cpp)
