#pragma once

class Sitemap{
private:
    int currentSite;
public:
    Sitemap();
    ~Sitemap();

    void ChangeSite(int cameraId);
    void InteractObject();

    int GetCurrentSite() const;
};