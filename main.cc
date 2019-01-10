#include "main.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "City.h"
#include "Country.h"

//TODO(1): Code needs to be in Google C++ Style

const std::string CitySaveFile = "Cities.dat";


int main()
{
    //TODO(2): We should automatically detect the Cities.dat file.
    ets2helper::Country::PopulateCountries();

    bool ExitRequested = false;

    while (!ExitRequested)
    {
        ExitRequested = PrintMenu();
    }

    std::cout << std::endl << "Exiting..." << std::endl;

    return 0;
}

bool PrintMenu()
{
    int menuChoice = 0;
    std::cout << std::endl;
    std::cout << "*******Main Menu*******" << std::endl;
    std::cout << "(1): Populate Cities with Default Data" << std::endl;
    std::cout << "(2): Populate Cities with Saved Data" << std::endl;
    std::cout << "(3): Change Garage in City" << std::endl;
    std::cout << "(4): Print Current Cities" << std::endl;
    std::cout << "(5): Suggest Next Garage" << std::endl;
    std::cout << "(6): Save" << std::endl;
    std::cout << "(7): Save and Exit" << std::endl;
    std::cout << "(8): Exit without Save" << std::endl;
    std::cout << std::endl;
    std::cin >> menuChoice;

    switch(menuChoice)
    {
    case 1:
        //TODO(5): Safeguard against repopulating data.
        ets2helper::City::PopulateCities();
        std::cout << std::endl << "Created " << ets2helper::City::AllCities.size() << " cities in " << ets2helper::Country::AllCountries.size() << " countries." << std::endl;
        break;
    case 2:
        Deserialize();
        std::cout << std::endl << "Created " << ets2helper::City::AllCities.size() << " cities in " << ets2helper::Country::AllCountries.size() << " countries." << std::endl;
        break;
    case 3:
    {
        int country = ets2helper::Country::GetCountryIndex();
        int city = ets2helper::City::GetCityIndex(country);
        ets2helper::Country::AllCountries[country]->CountryCities[city]->ChangeGarage();

        for (ets2helper::City* c : ets2helper::City::NoGarageCities)
        {
            c->CalculateNearestGarageDistance();
        }
    }

    break;
    case 4:
        for(ets2helper::Country* c : ets2helper::Country::AllCountries)
        {
            for(ets2helper::City* y: c->CountryCities)
            {
                std::cout << std::endl;
                std::cout << y->Name << ", " << c->Name << std::endl;
                std::cout << y->Coordinates.Latitude << " " << y->Coordinates.Longitude << std::endl;

                switch(y->GarageType())
                {
                case ets2helper::Garage::GarageType::None:
                    std::cout << "No Garage" << std::endl;
                    break;
                case ets2helper::Garage::GarageType::NotAllowed:
                    std::cout << "Garage Not Allowed" << std::endl;
                    break;
                case ets2helper::Garage::GarageType::Tiny:
                    std::cout << "Tiny Garage" << std::endl;
                    break;
                case ets2helper::Garage::GarageType::Small:
                    std::cout << "Small Garage" << std::endl;
                    break;
                case ets2helper::Garage::GarageType::Large:
                    std::cout << "Large Garage" << std::endl;
                    break;
                }

                std::cout << std::endl;
            }
        }
        break;
    case 5:
        //TODO(9):  This will segfault if the data has not been populated yet.
    {
        int greatestCityDistance = 0;
        ets2helper::City* greatestCity = nullptr;

        for(ets2helper::City* c: ets2helper::City::NoGarageCities)
        {
            if(c->DistanceFromGarage > greatestCityDistance)
            {
                greatestCityDistance = c->DistanceFromGarage;
                greatestCity = c;
            }
        }
        std::cout << std::endl;
        std::cout << greatestCity->Name << ", " << greatestCity->CountryName << " is the city farthest from a garage." << std::endl;

        greatestCity->AnnounceClosestGarage();
    }
    case 6:
        Serialize();
        break;
    case 7:
        //We need to create a confirmation, should be pretty simple...
        Serialize();
        return true;
        break;
    case 8:
        //We need a confirmation
        return true;
    default:
        std::cout << "ERROR! You have selected an invalid choice." << std::endl;
        break;
    }

    return false;
}

void Serialize()
{
    //TODO(3): When serializing data, we should check if the file already exists. If it does, we should move it to Cities.dat.bak and serialize the new data to the old file.
    //TODO(4): Simplify serializing: we only need to serialize what's not in its default state.
    std::cout << std::endl << "Saving City data..." << std::endl;

    std::ofstream savefile;
    savefile.open (CitySaveFile);

    if (savefile.is_open())
    {
        for (ets2helper::City* c: ets2helper::City::AllCities)
        {
            c->Serialize(savefile);
        }

        savefile.close();
    }
    else
    {
        throw "Error! File not open";
    }
}

void Deserialize()
{
    std::string line;
    std::ifstream savefile;
    savefile.open(CitySaveFile);
    if (savefile.is_open())
    {
        std::cout << "Opened save file..." << std::endl;

        int linenumber = 1;

        std::string fileCityName;
        std::string fileCountryName;
        double fileLatitude;
        double fileLongitude;
        ets2helper::Garage::GarageType fileGarageType;

        while (getline(savefile, line))
        {
            switch(linenumber)
            {
            case 1:
                fileCityName = line;
                linenumber++;
                break;
            case 2:
                fileCountryName = line;
                linenumber++;
                break;
            case 3:
                fileLatitude = stod(line);
                linenumber++;
                break;
            case 4:
                fileLongitude = stod(line);
                linenumber++;
                break;
            case 5:
                //This line casts the integer returned from parsing the line from the file string to int using stoi, and then casts that integer to the GarageType
                fileGarageType = static_cast<ets2helper::Garage::GarageType>(stoi(line));
                ets2helper::City::AllCities.push_back(new ets2helper::City(fileCityName, fileCountryName, fileLatitude, fileLongitude, fileGarageType));
                linenumber = 1;
                break;
            default:
                throw "Error reading from save file";
            }
        }
        ets2helper::City::InitializeCities();
    }
    else
    {
        throw "Error! File not open";
    }
}

