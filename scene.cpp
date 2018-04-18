#include "image.h"
#include "scene.h"
#include "render.h"
#include <memory>

using namespace std;

Scene::Scene()
{
}

uint32_t Scene::AddObject(shared_ptr<GameObject>& obj)
{
    uint32_t id = gen_id.get_next();
    objects.insert(std::make_pair(id, obj));
    return id;
}

void Scene::RemoveObject(uint32_t key)
{
    auto ptr = objects.find(key);
    if(ptr != objects.cend())
        objects.erase(ptr);
}

shared_ptr<GameObject> Scene::GetObject(uint32_t key)
{
    auto ptr = objects.find(key);
    if(ptr != objects.cend())
        return objects[key];
    return nullptr;
}

void Scene::Draw()
{
    for(auto& o:objects)
        {
            Render::DrawImage(o.second->getImage(), o.second->getPosition());
        }
}

size_t Scene::Count() const
{
    return objects.size();
}

bool Scene::FromFile(const std::string& filename)try
{
    auto rv = m_loader.ParseScene(filename);
    if(!rv)
    {
        cerr
        << __FUNCTION__
        << ": "
        << "can't load scene from file"
        << endl;
        return false;
    }
    auto images = m_loader.getImages();
    auto animations = m_loader.getAnimations();

    for(auto img:images)
    {
        std::shared_ptr<GameObject> im = make_shared<Image>();
        auto pi = std::static_pointer_cast<Image>(im);
        if(!pi->load(img.file))
            throw runtime_error(string("can't load image: ") + img.file);
        pi->setPosition(img.pos);
        this->AddObject(im);
    }
    // TODO: ANIMATIONS

    return true;
}
catch(const std::exception& e)
{
    cerr
    << "Scene::FromFile failed: "
    << e.what()
    << endl;
    return false;
}
