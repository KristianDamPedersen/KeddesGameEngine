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
        Entity* entity; // Parent entity
        Component() {}
        virtual void update() {}
        virtual void draw(SDL_Renderer* renderer) {}
        virtual ~Component() {}
};

class Entity {
    private: 
        bool active = true;
        // Because it is important that we can only ever have 1 component of a given
        // type attached to an entity, we use a map to keep track of the type of component,
        // and the component itself. Insantiating a new component of the same type will overwrite,
        // the old one. The output looks something like:
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
        // Add a component to the entity. Writes the component to the correct spot
        // corresponding with the type of the component pointed to by the unique_ptr.
        Component* addComponent(std::unique_ptr<Component> component) {
            auto id = std::type_index(typeid(*component.get()));
            components.emplace(typeid(*component.get()), std::move(component));
            return getComponentByType(id);
        }

        // Retrieves the component by the type
        Component* getComponentByType(std::type_index typeID) {
            auto& val = components.at(typeID);
            return val.get();
        }

        // Generic template that retrieves a component based on type of component. I.e:
        // getComponent<GravityComponent>() will return the gravity component attached to the entity.
        template<typename T>
        T* getComponent() {
            return dynamic_cast<T*>(getComponentByType(typeid(T)));
        }

};

class Manager {
    private:
        // We need shared pointers as the entities are accessed by multiple instances.
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
