project(engine)

cmake_minimum_required(VERSION 2.6)

add_executable(engine main.cpp 
					  src/point2f.cpp 
					  src/color4.cpp 
					  src/rectf.cpp 
					  src/image.cpp 
					  src/render.cpp 
					  src/scene.cpp 
					  src/animation.cpp 
					  src/engine.cpp 
					  src/SceneLoader.cpp
					  src/polygon.cpp
                                          src/point-object.cpp
                                          src/line-object.cpp
                                          )

install(TARGETS engine RUNTIME DESTINATION bin)
set_property(TARGET engine PROPERTY CXX_STANDARD 14)
target_include_directories(engine PUBLIC ./ include)
target_link_libraries(engine PUBLIC pthread glut GL GLU SDL SDL_image config++)
target_compile_options(engine PUBLIC -Wall -g)
