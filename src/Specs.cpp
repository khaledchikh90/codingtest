#include "Specs.h"

#include "Specs.h"

/*** Parse function  **/
void Specs::parseFromFile(const std::string file_path) {
    std::ifstream ifs(file_path);

    bool begin = false;
    std::string line;
    /** read text file line by line **/
    while (std::getline(ifs, line)) {
        /** ignore until the keyword = begin **/
        if (line == "begin") {
            begin = true;
        }
    /** finding the pattern ~~ (begin) !-! (separator) ?? **/
    std::regex reg(" ~~ ([0-9]+)!-!([0-9]+)");
    std::smatch matches;
    /** push all the data into specs vectors **/
    if (begin) {
        if (std::regex_search(line, matches, reg)) {
            this->widths.push_back(std::stoi(matches[1]));
            this->heigths.push_back(std::stoi(matches[2]));
        }
    }
    /** ignore all the lines after keyword = end **/
    if (line == "end")
      break;
  }
}

int Specs::getMaxWidth() const {
    return *std::max_element(this->widths.begin(), this->widths.end());
}

int Specs::getMaxHeight() const {
    return *std::max_element(this->heigths.begin(), this->heigths.end());
}

int Specs::getAvgWidth() const {
    return std::accumulate(this->widths.begin(), this->widths.end(), 0) / this->widths.size();
}

int Specs::getAvgHeight() const {
  return std::accumulate(this->heigths.begin(), this->heigths.end(), 0) / this->heigths.size();
}