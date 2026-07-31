#include "Sitemap.h"

void Sitemap::ChangeSite(int cameraId) {
    if(cameraId >= 0){
        currentSite = cameraId;
    }
}

void Sitemap::InteractObject() {}

int Sitemap::GetCurrentSite() const {
    return currentSite; 
}