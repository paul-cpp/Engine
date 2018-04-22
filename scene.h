/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _SCENE_H_INCLUDED_
#define _SCENE_H_INCLUDED_

#include "animation.h"
#include "image.h"
#include "game-object.h"
#include "incremeter.h"
#include "SceneLoader.h"
#include <map>
#include <memory>
#include <cstdint>
#include <utility>

using namespace std;

class Scene
{
    Incrementer<uint32_t> gen_id;
    std::map<uint32_t, shared_ptr<GameObject>> objects;
    SceneLoader m_loader;
public:
    Scene();
    // returns new object id
    uint32_t AddObject(shared_ptr<GameObject>& obj);
    void RemoveObject(uint32_t key);
    shared_ptr<GameObject> GetObject(uint32_t key);
    void Draw();
    size_t Count() const;
    bool FromFile(const std::string& filename);
};

#endif // _SCENE_H_INCLUDED_
