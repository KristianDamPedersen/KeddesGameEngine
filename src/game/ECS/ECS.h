#pragma once
#include <vector>
#include <map>
#include "SDL.h"
#include <typeinfo>
#include <typeindex>
#include <memory>

class Component;
class Entity;
class Manager;

class Component {
    public:
        Entity* entity; // ?
        Component() {}
        virtual void update() {}
        virtual void draw(SDL_Renderer* renderer) {}
        virtual ~Component() {}
};

class Entity {
    private: 
        bool active = true;
        // {GravityComponent, *GravityComponent}
        std::map<std::type_index, std::unique_ptr<Component>> components;
    public:
        void update() {
            for(auto& c : components) {
                c.second->update();
            }
        };
        void draw(SDL_Renderer* renderer) {
            for(auto& c : components) {
                c.second->draw(renderer);
            }
        };
        bool isActive() { return active; }
        void destroy() { active = false; }
        bool hasComponent(std::type_info typeID) {
            return components.find(typeID) != components.end();   
        }

        Component* addComponent(std::unique_ptr<Component> component) {
            auto id = std::type_index(typeid(*component.get()));
            components.emplace(typeid(*component.get()), std::move(component));
            return getComponentByType(id);
        }

        Component* getComponentByType(std::type_index typeID) {
            auto& val = components.at(typeID);
            return val.get();
        }

        template<typename T>
        T* getComponent() {
            return dynamic_cast<T*>(getComponentByType(typeid(T)));
        }

};

class Manager {
    private:
        std::vector<std::shared_ptr<Entity>> entities;
    public:
        void update() {
            for (auto& e: entities) e->update();
        }
        void draw(SDL_Renderer* renderer) {
            for (auto& e : entities) e->draw(renderer);
        }
        void refresh() {
            // Iterating from behind, we remove any inactive entities 
            for (int i = entities.size() - 1; i >= 0; i--) {
                if (!entities[i]->isActive()) {
                    entities.erase(entities.begin()+i);
                }
            }
        }

        std::shared_ptr<Entity> addEntity() {
            entities.emplace_back(std::make_shared<Entity>());
            return entities.back();
        }
};
