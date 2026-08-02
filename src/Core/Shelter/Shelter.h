#pragma once

class Generator;
class Protection;
class Population;
class Inventory;
class Sitemap;
class Notebook;

class Shelter{
private:
    Generator generator;
    Protection barricade;
    Population population;
    Inventory inventory;
    Sitemap sitemap;
    Notebook notebook;
public:
    Shelter();
    ~Shelter();

    const Generator& GetGenerator() const;
    const Protection& GetBarricade() const;
    const Population& GetPopulation() const;
    const Inventory& GetInventory() const;
    const Sitemap& GetSitemap() const;
    const Notebook& GetNotebook() const;
};