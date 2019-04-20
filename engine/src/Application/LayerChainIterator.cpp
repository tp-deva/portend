#include "engine/Application/LayerChainIterator.hpp"


namespace engine {

LayerChainIterator::LayerChainIterator(std::vector<ILayer*>* layers, std::vector<ILayer*>* overlays) {
    (void)layers;
    (void)overlays;
}


void LayerChainIterator::reset() {

}


ILayer* LayerChainIterator::get_next() {
    return nullptr;
}


bool LayerChainIterator::has_more() {
    return false;
}

} // namespace engine
