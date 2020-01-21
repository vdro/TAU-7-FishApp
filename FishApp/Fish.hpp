#pragma once
#include <string>

class Fish {

public:
    int id;
    std::string name;
    int quantity;
    int price; 

    Fish (std::string name, int quanity, int price);
    ~Fish();
};