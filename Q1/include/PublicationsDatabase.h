#ifndef PUBLICATIONSDATABASE_H
#define PUBLICATIONSDATABASE_H

#include <unordered_map>
#include <string>
#include <vector>
#include "Publication.h"

class PublicationsDatabase {
private:
    std::unordered_map<std::string, std::vector<Publication>> publicationsByAuthor;

public:
    void addPublication(const Publication& publication) {
        for (const auto& author : publication.getAuthors()) {
            publicationsByAuthor[author.getName()].push_back(publication);
        }
    }

    std::vector<Publication> getPublicationsByAuthor(const std::string& authorName) {
        if (publicationsByAuthor.find(authorName) != publicationsByAuthor.end()) {
            return publicationsByAuthor[authorName];
        }
        return {};
    }
};

#endif // PUBLICATIONSDATABASE_H
