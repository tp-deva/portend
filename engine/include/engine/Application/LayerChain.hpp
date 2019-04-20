#ifndef ENGINE_LAYERCHAIN_HPP
#define ENGINE_LAYERCHAIN_HPP

#include <vector>

#include "engine/Application/ILayer.hpp"
#include "engine/Application/LayerChainIterator.hpp"

namespace engine {

class LayerChain {
public:
    LayerChain();
    ~LayerChain();

    void push_layer(ILayer* layer);
    void push_overlay(ILayer* overlay);
    void pop_layer(ILayer* layer);
    void pop_overlay(ILayer* overlay);

    LayerChainIterator get_iterator();

private:
    std::vector<ILayer*> m_layers;
    std::vector<ILayer*> m_overlays;
};

} // namespace engine

#endif // ENGINE_LAYERCHAIN_HPP
