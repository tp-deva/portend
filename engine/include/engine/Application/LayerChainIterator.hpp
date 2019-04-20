#ifndef ENGINE_LAYERCHAINITERATOR_HPP
#define ENGINE_LAYERCHAINITERATOR_HPP

#include <vector>

#include "engine/Application/ILayer.hpp"

namespace engine {

class LayerChainIterator {
public:
    LayerChainIterator(std::vector<ILayer*>* layers, std::vector<ILayer*>* overlays);

    void reset();

    ILayer* get_next();
    bool has_more();

private:
    std::vector<ILayer*>* m_layers;
    std::vector<ILayer*>* m_overlays;
};

}

#endif // ENGINE_LAYERCHAINITERATOR_HPP
