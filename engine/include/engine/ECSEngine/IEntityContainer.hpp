#ifndef ENGINE_IENTITYCONTAINER_HPP
#define ENGINE_IENTITYCONTAINER_HPP

#include "engine/ECSEngine/IEntity.hpp"

namespace engine {

class IEntityContainer {
public:
    virtual ~IEntityContainer() {
    }

    virtual const char* get_content_type_name() const = 0;
};

} // namespace engine

#endif // ENGINE_IENTITYCONTAINER_HPP
