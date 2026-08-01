#include "Shelter.h"

const Generator& Shelter::GetGenerator() const {
    return generator;
}

const Protection& Shelter::GetBarricade() const {
    return barricade;
}

const Population& Shelter::GetPopulation() const {
    return population;
}

const Inventory& Shelter::GetInventory() const {
    return inventory;
}

const Sitemap& Shelter::GetSitemap() const {
    return sitemap;
}

const Notebook& Shelter::GetNotebook() const {
    return notebook;
}

