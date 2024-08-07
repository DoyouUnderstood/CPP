#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() 
{
    Data myData;
    myData.id = 1;
    myData.name = "Test";
    myData.value = 42.42f;

    Data* dataPtr = &myData;

    // Sérialisation
    uintptr_t raw = Serializer::serialize(dataPtr);
    std::cout << "Serialized: " << raw << std::endl;

    // Désérialisation
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized - ID: " << deserializedData->id
              << ", Name: " << deserializedData->name
              << ", Value: " << deserializedData->value << std::endl;

    if (dataPtr == deserializedData) {
        std::cout << " deserialized pointer est egale au pointeur original." << std::endl;
    } else {
        std::cout << " deserialized pointer est PAS EGALE au pointeur original." << std::endl;
    }

    return 0;
}
