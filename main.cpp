#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "engine.h"
//#include "game-object.h"
#include "SceneLoader.h"
#include <vector>

using namespace std;
int main(int argc, char** argv)
{

    SceneLoader ldr;
    ldr.ParseScene("sample_scene.scn");

    Engine e(argc, argv);

    vector<Image> v1(9), v2(7);

    v1[0] = e.LoadImage("./data/cowboy_01.png");
    v1[1] = e.LoadImage("./data/cowboy_02.png");
    v1[2] = e.LoadImage("./data/cowboy_03.png");
    v1[3] = e.LoadImage("./data/cowboy_04.png");
    v1[4] = e.LoadImage("./data/cowboy_05.png");
    v1[5] = e.LoadImage("./data/cowboy_06.png");
    v1[6] = e.LoadImage("./data/cowboy_07.png");
    v1[7] = e.LoadImage("./data/cowboy_08.png");
    v1[8] = e.LoadImage("./data/cowboy_09.png");

    v2[0] = e.LoadImage("./data/cowboy_87.png");
    v2[1] = e.LoadImage("./data/cowboy_88.png");
    v2[2] = e.LoadImage("./data/cowboy_89.png");
    v2[3] = e.LoadImage("./data/cowboy_91.png");
    v2[4] = e.LoadImage("./data/cowboy_92.png");
    v2[5] = e.LoadImage("./data/cowboy_93.png");
    v2[6] = e.LoadImage("./data/cowboy_94.png");

    Animation a(100);
    Animation b(80);
    Animation c{100};

    a.AddImage(v2);
    c.AddImage(v1);
    b.AddImage(v2);

    a.setPosition({100,300});
    b.setPosition({300,300});
    c.setPosition({300,100});

     v2[0].setPosition({100,100});

    e.AddObject(a);
    e.AddObject(b);
    e.AddObject(c);
    // static image
    e.AddObject(v2[0]);

    Engine::Run();

    return 0;
}