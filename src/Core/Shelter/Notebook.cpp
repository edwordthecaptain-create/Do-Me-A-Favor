#include "Notebook.h"

void Notebook::AddEvidence(Evidence* evidence) {}
void Notebook::RemoveEvidence(Evidence* evidence) {}
void Notebook::FindEvidence(Evidence* evidence) {}

const std::vector<Evidence*>& Notebook::GetEvidence() const {
    return evidences;
}