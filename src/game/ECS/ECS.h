#pragma once
#pragma once
#include <vector>
#include <map>
#include <any>
#include "SDL.h"
#include "EntityType.h"
#include "EnumClassIterator.h"
#include <typeinfo>
#include <typeindex>
#include <memory>

class Manager;
class Component;
class Entity;

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

        // Each entity has a type, in order to be able to group them with other
        // entities. The different valid enums are listed in the EntityType.h.
        EntityType type;

        SDL_Renderer* renderer;

    public:
       
        // If no argument is parsed for the entity type, we simply assign it as generic.
        Entity(SDL_Renderer* renderer) { 
            type = EntityType::Generic;
            renderer = renderer;
            init();
        }

        // Else we assign it as the type of entity that it is.
        Entity(EntityType entType, SDL_Renderer* renderer) { 
            type = entType;
            renderer = renderer;
            init();
        }

        virtual void init() {};

        SDL_Renderer* getRenderer() { return renderer; }

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
        std::map<EntityType, std::vector<std::shared_ptr<Entity>>> entities;
        SDL_Renderer* renderer;

    public:

        Manager(SDL_Renderer* gameRenderer) { renderer = gameRenderer ;}

        void update() {
            for (auto& elem: entities) {
                for (auto& e : elem.second) e->update();
            };
        }

        void draw(SDL_Renderer* renderer) {
            for (auto& elem: entities) {
                for (auto& e : elem.second) e->draw(renderer);
            }
        }
        
        void refresh() {
            for (auto& elem: entities) {
                // Iterating from behind, we remove any inactive entities 
                for (int i = elem.second.size() - 1; i >= 0; i--) {
                    if (!elem.second[i]->isActive()) {
                        elem.second.erase(elem.second.begin()+i);
                    }
                }
            }
        }

        template <typename T>
        std::vector<std::shared_ptr<T>> getEntitiesByType(EntityType entType) {
            auto& ents = entities.at(entType);
            return ents;
        };
        
        template <typename T>
        std::vector<std::shared_ptr<T>> emptySharedPtrVec() {
            return std::vector<std::shared_ptr<T>>();
        }
        
        template <typename T>
        std::shared_ptr<T> addEntity(EntityType entType) {
            // First we check wether we have any entities in the map already,
            // we just simply add the new entity if we do, or create a new entity 
            // type in the map if we don't.
            auto entity = std::make_shared<T>(renderer);
            if (entities.find(entType) == entities.end()) {
                // If not found
                auto vec = emptySharedPtrVec<Entity>();
                vec.push_back(entity);
                entities.insert({entType, vec});

            } else {
                // If found
                auto& ents = entities.at(entType);
                ents.push_back(std::make_shared<T>());
            }
            return entity;
        }

};
