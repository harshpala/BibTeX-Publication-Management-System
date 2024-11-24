#include "../include/Publication.h"
#include "../include/Author.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Hardcoded author data
    Author author1("Arani Bhattacharya", "IIIT-Delhi");
    Author author2("James Gross", "SRMIST");
    Author author3("Vivek Ashok Bohara", "IEEE");

    // Hardcoded publication data
    vector<Author> authors1 = {author1, author2};
    vector<Author> authors2 = {author3};

    Publication publication1(
        "Fast Efficient Online Selection of Sensors for Transmitter Localization",
        "International Conference on Communication Systems & Networks",
        2022,
        authors1,
        nullopt,  // No volume
        nullopt,  // No number
        nullopt,  // No pages
        "10.1109/COMSNETS53615.2022.9668385"
    );

    Publication publication2(
        "Flow-based Rate Maximization for Link Aggregation Enabled Hybrid LiFi-WiFi Network",
        "IEEE Transactions on Vehicular Technology",
        2024,
        authors2,
        "75",  // Volume
        "4",   // Number
        "1-13",  // Pages
        "10.1109/TVT.2024.3477310"
    );

    std::vector<Publication> publications = {publication1, publication2};

    for (const auto& publication : publications) {
        if (publication.hasInstituteAuthor("IIIT-Delhi")) {
            publication.display();
        } else {
            string title = publication.getPublicationTitle();
            cout << "**********Publication \""<<title<<"\" does not meet affiliation requirements**********" << std::endl;
        }
    }
    
    return 0;
}
