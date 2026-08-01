#pragma once

class Sitemap{
private:
    int currentSite = 0;
public:
    Sitemap() = default;
    ~Sitemap() = default;

    void ChangeSite(int cameraId);
    void InteractObject();

    int GetCurrentSite() const;
};