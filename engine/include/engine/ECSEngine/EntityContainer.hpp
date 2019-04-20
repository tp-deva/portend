#ifndef ENGINE_ENTITYCONTAINER_HPP
#define ENGINE_ENTITYCONTAINER_HPP

#include <set>

#include "engine/ECSEngine/IEntityContainer.hpp"

namespace engine {

template<class E>
class EntityContainer : public IEntityContainer {
public:
    EntityContainer() {
    }

    EntityContainer(const EntityContainer&) = delete;

    virtual ~EntityContainer() {
    }

    EntityContainer& operator=(EntityContainer&) = delete;

    virtual const char* get_content_type_name() const override {
        static const char* entity_type_name{ typeid(T).name() };
        return entity_type_name;
    }

public:
    std::set<E> container;
};

} // namespace engine

#endif // ENGINE_IENTITYCONTAINER_HPP
