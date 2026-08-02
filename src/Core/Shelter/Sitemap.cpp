#include "Sitemap.h"

void Sitemap::ChangeSite(int cameraId) {
    if(cameraId >= 0){
        currentSite = cameraId;
    }
}

void Sitemap::InteractObject() {
    switch (currentSite){
    case 0:
        break;
    default:
        break;
    }
}

int Sitemap::GetCurrentSite() const {
    return currentSite; 
}