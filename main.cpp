#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "main.h"
#include "Country.h"
#include "City.h"

using namespace std;

const string CitySaveFile = "Cities.dat";
std::vector<Country*> Countries;
std::vector<City*> Cities;

int main()
{
    PopulateCountries();

    bool ExitRequested = false;

    while (!ExitRequested)
    {
        ExitRequested = PrintMenu();
    }

    cout << endl << "Exiting..." << endl;
}

bool PrintMenu()
{
    int menuChoice = 0;
    cout << endl;
    cout << "*******Main Menu*******" << endl;
    cout << "(1): Populate Cities with Default Data" << endl;
    cout << "(2): Populate Cities with Saved Data" << endl;
    cout << "(3): Change Garage in City" << endl;
    cout << "(4): Print Current Cities" << endl;
    cout << "(5): Save" << endl;
    cout << "(6): Save and Exit" << endl;
    cout << "(7): Exit without Save" << endl;
    cout << endl;
    cin >> menuChoice;

    switch(menuChoice)
    {
    case 1:
        PopulateCities();
        cout << endl << "Created " << Cities.size() << " cities in " << Countries.size() << " countries." << endl;
        break;
    case 2:
        Deserialize();
        cout << endl << "Created " << Cities.size() << " cities in " << Countries.size() << " countries." << endl;
        break;
    case 3:
    {
        int country = GetCountry();
        int city = GetCity(country);
        Countries[country]->CountryCities[city]->ChangeGarage();
    }


    break;
    case 4:
        for(Country* c : Countries)
        {
            for(City* y: c->CountryCities)
            {
                cout << endl;
                cout << y->Name << ", " << c->Name << endl;
                cout << y->Latitude << " " << y->Longitude << endl;

                switch(y->GarageType())
                {
                case Garage::GarageType::None:
                    cout << "No Garage" << endl;
                    break;
                case Garage::GarageType::NotAllowed:
                    cout << "Garage Not Allowed" << endl;
                    break;
                case Garage::GarageType::Tiny:
                    cout << "Tiny Garage" << endl;
                    break;
                case Garage::GarageType::Small:
                    cout << "Small Garage" << endl;
                    break;
                case Garage::GarageType::Large:
                    cout << "Large Garage" << endl;
                    break;
                }

                cout << endl;
            }
        }
        break;
    case 5:
        //TODO: create back up if file already exists
        Serialize();
        break;
    case 6:
        //TODO: create back up if file already exists
        //We need to create a confirmation, should be pretty simple...
        Serialize();
        return true;
        break;
    case 7:
        //We need a confirmation
        return true;
    default:
        cout << "ERROR! You have selected an invalid choice." << endl;
        break;
    }

    return false;
}

void PopulateCountries()
{
    Countries.push_back(new Country("Austria"));
    Countries.push_back(new Country("Belgium"));
    Countries.push_back(new Country("Czech Republic"));
    Countries.push_back(new Country("Denmark"));
    Countries.push_back(new Country("Estonia"));
    Countries.push_back(new Country("Finland"));
    Countries.push_back(new Country("France"));
    Countries.push_back(new Country("Germany"));
    Countries.push_back(new Country("Hungary"));
    Countries.push_back(new Country("Italy"));
    Countries.push_back(new Country("Latvia"));
    Countries.push_back(new Country("Lithuania"));
    Countries.push_back(new Country("Luxembourg"));
    Countries.push_back(new Country("Netherlands"));
    Countries.push_back(new Country("Norway"));
    Countries.push_back(new Country("Poland"));
    Countries.push_back(new Country("Russia"));
    Countries.push_back(new Country("Slovakia"));
    Countries.push_back(new Country("Sweden"));
    Countries.push_back(new Country("Switzerland"));
    Countries.push_back(new Country("United Kingdom"));
}

void PopulateCities()
{
    Cities.push_back(new City("Aalborg", "Denmark", 57.0482, 9.91939));
    Cities.push_back(new City("Aberdeen", "United Kingdom", 57.1482, -2.09281));
    Cities.push_back(new City("Amsterdam", "Netherlands", 52.3745, 4.89798));
    Cities.push_back(new City("Ancona", "Italy", 43.617, 13.5171));
    Cities.push_back(new City("Banská Bystrica", "Slovakia", 48.7384, 19.1573));
    Cities.push_back(new City("Bari", "Italy", 41.1258, 16.862));
    Cities.push_back(new City("Bergen", "Norway", 60.3943, 5.32581));
    Cities.push_back(new City("Berlin", "Germany", 52.517, 13.3889));
    Cities.push_back(new City("Bern", "Switzerland", 46.9483, 7.45145));
    Cities.push_back(new City("Białystok", "Poland", 53.1275, 23.1471));
    Cities.push_back(new City("Birmingham", "United Kingdom", 52.4775, -1.89405));
    Cities.push_back(new City("Bologna", "Italy", 44.4937, 11.343));
    Cities.push_back(new City("Bordeaux", "France", 44.8412, -0.580036));
    Cities.push_back(new City("Bourges", "France", 47.0806, 2.39893, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Bratislava", "Slovakia", 48.1359, 17.1597));
    Cities.push_back(new City("Bremen", "Germany", 53.0758, 8.80716));
    Cities.push_back(new City("Brest", "France", 48.3905, -4.48601));
    Cities.push_back(new City("Brussel", "Belgium", 50.8466, 4.3517));
    Cities.push_back(new City("Brno", "Czech Republic", 49.1922, 16.6113));
    Cities.push_back(new City("Budapest", "Hungary", 47.4984, 19.0405));
    Cities.push_back(new City("Calais", "France", 50.9488, 1.87468));
    Cities.push_back(new City("Cambridge", "United Kingdom", 52.2035, 0.123582));
    Cities.push_back(new City("Cardiff", "United Kingdom", 51.4817, -3.17919));
    Cities.push_back(new City("Carlisle", "United Kingdom", 54.8948, -2.93623));
    Cities.push_back(new City("Cassino", "Italy", 41.4926, 13.8305));
    Cities.push_back(new City("Catania", "Italy", 37.5022, 15.0874));
    Cities.push_back(new City("Catanzaro", "Italy", 38.9076, 16.596));
    Cities.push_back(new City("Clermont-Ferrand", "France", 45.7775, 3.08194));
    Cities.push_back(new City("Civaux", "France", 46.4448, 0.664645, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Daugavpils", "Latvia", 55.8712, 26.5159));
    Cities.push_back(new City("Debrecen", "Hungary", 47.5314, 21.626));
    Cities.push_back(new City("Dijon", "France", 47.3216, 5.04147));
    Cities.push_back(new City("Dortmund", "Germany", 51.5142, 7.46528));
    Cities.push_back(new City("Dover", "United Kingdom", 51.13, 1.30832));
    Cities.push_back(new City("Dresden", "Germany", 51.0493, 13.7381));
    Cities.push_back(new City("Duisburg", "Germany", 51.435, 6.75956));
    Cities.push_back(new City("Düsseldorf", "Germany", 51.2254, 6.77631));
    Cities.push_back(new City("Edinburgh", "United Kingdom", 55.9533, -3.18837));
    Cities.push_back(new City("Erfurt", "Germany", 50.9778, 11.0287));
    Cities.push_back(new City("Esbjerg", "Denmark", 55.4665, 8.45208, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Felixstowe", "United Kingdom", 51.9639, 1.35151));
    Cities.push_back(new City("Firenze", "Italy", 43.7699, 11.2556));
    Cities.push_back(new City("Frankfurt am Main", "Germany", 50.1106, 8.68209));
    Cities.push_back(new City("Frederikshavn", "Denmark", 57.4412, 10.5336, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Gdańsk", "Poland", 54.3614, 18.6282));
    Cities.push_back(new City("Gedser", "Denmark", 54.5761, 11.9322, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Genève", "Switzerland", 46.2018, 6.1466));
    Cities.push_back(new City("Genova", "Italy", 44.4073, 8.93386));
    Cities.push_back(new City("Glasgow", "United Kingdom", 55.8567, -4.24358));
    Cities.push_back(new City("Golfech", "France", 44.1147, 0.851944, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Göteborg", "Sweden", 57.7072, 11.967));
    Cities.push_back(new City("Graz", "Austria", 47.0703, 15.4386));
    Cities.push_back(new City("Grimsby", "United Kingdom", 53.5677, -0.0736289));
    Cities.push_back(new City("Groningen", "Netherlands", 53.2218, 6.55825));
    Cities.push_back(new City("Hamburg", "Germany", 53.5503, 10.0007));
    Cities.push_back(new City("Hannover", "Germany", 52.3745, 9.73855));
    Cities.push_back(new City("Helsingborg", "Sweden", 56.0442, 12.7041));
    Cities.push_back(new City("Helsinki", "Finland", 60.1674, 24.9426));
    Cities.push_back(new City("Hirtshals", "Denmark", 57.5908, 9.96497, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Innsbruck", "Austria", 47.2695, 11.3971));
    Cities.push_back(new City("Jönköping", "Sweden", 57.7815, 14.1628));
    Cities.push_back(new City("Kaliningrad", "Russia", 54.7066, 20.5105));
    Cities.push_back(new City("Kalmar", "Sweden", 56.6629, 16.3662));
    Cities.push_back(new City("Kapellskär", "Sweden", 59.7204, 19.0608, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Karlskrona", "Sweden", 56.1621, 15.5866));
    Cities.push_back(new City("Kaunas", "Lithuania", 54.8982, 23.9045));
    Cities.push_back(new City("Kassel", "Germany", 51.3077, 9.46247));
    Cities.push_back(new City("Katowice", "Poland", 50.2599, 19.0216));
    Cities.push_back(new City("Kiel", "Germany", 54.3227, 10.1356));
    Cities.push_back(new City("Klagenfurt am Wörthersee", "Austria", 46.6228, 14.308));
    Cities.push_back(new City("Klaipėda", "Lithuania", 55.7128, 21.135));
    Cities.push_back(new City("København", "Denmark", 55.6867, 12.5701));
    Cities.push_back(new City("Köln", "Germany", 50.9384, 6.95997));
    Cities.push_back(new City("Košice", "Slovakia", 48.7172, 21.2497));
    Cities.push_back(new City("Kotka", "Finland", 60.4674, 26.9451));
    Cities.push_back(new City("Kouvola", "Finland", 60.8702, 26.7018));
    Cities.push_back(new City("Kraków", "Poland", 50.0469, 19.9971));
    Cities.push_back(new City("Kristiansand", "Norway", 58.1461, 7.99573));
    Cities.push_back(new City("Kunda", "Estonia", 59.5055, 26.5292, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Lahti", "Finland", 60.9839, 25.6562));
    Cities.push_back(new City("La Rochelle", "France", 46.1591, -1.15204));
    Cities.push_back(new City("Leipzig", "Germany", 51.3406, 12.3747));
    Cities.push_back(new City("Le Havre", "France", 49.4939, 0.107973));
    Cities.push_back(new City("Le Mans", "France", 48.0073, 0.196738));
    Cities.push_back(new City("Liège", "Belgium", 50.6451, 5.57342));
    Cities.push_back(new City("Liepāja", "Latvia", 56.5048, 21.0071));
    Cities.push_back(new City("Lille", "France", 50.6305, 3.07064));
    Cities.push_back(new City("Limoges", "France", 45.8354, 1.26448));
    Cities.push_back(new City("Linköping", "Sweden", 58.4098, 15.6245));
    Cities.push_back(new City("Linz", "Austria", 48.3059, 14.2862));
    Cities.push_back(new City("Liverpool", "United Kingdom", 53.4055, -2.98054));
    Cities.push_back(new City("Livorno", "Italy", 43.5507, 10.3091));
    Cities.push_back(new City("Łódź", "Poland", 51.7731, 19.4784));
    Cities.push_back(new City("London", "United Kingdom", 51.5073, -0.127647));
    Cities.push_back(new City("Loviisa", "Finland", 60.4562, 26.2268, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Lublin", "Poland", 51.2182, 22.5547));
    Cities.push_back(new City("Luga", "Russia", 58.7357, 29.8475));
    Cities.push_back(new City("Luxembourg", "Luxembourg", 49.8159, 6.12968));
    Cities.push_back(new City("Lyon", "France", 45.7578, 4.83201));
    Cities.push_back(new City("Magdeburg", "Germany", 52.1316, 11.64));
    Cities.push_back(new City("Malmö", "Sweden", 55.6053, 13.0002));
    Cities.push_back(new City("Manchester", "United Kingdom", 53.4791, -2.2441));
    Cities.push_back(new City("Mannheim", "Germany", 49.4896, 8.46724));
    Cities.push_back(new City("Marseille", "France", 43.2962, 5.36995));
    Cities.push_back(new City("Mažeikiai", "Lithuania", 56.3116, 22.3383, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Messina", "Italy", 38.1938, 15.5542));
    Cities.push_back(new City("Metz", "France", 49.1197, 6.17636));
    Cities.push_back(new City("Milano", "Italy", 45.4668, 9.1905));
    Cities.push_back(new City("Montpellier", "France", 43.6112, 3.87673));
    Cities.push_back(new City("München", "Germany", 48.1371, 11.5754));
    Cities.push_back(new City("Naantali", "Finland", 60.4689, 22.0291, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Nantes", "France", 47.2186, -1.55414));
    Cities.push_back(new City("Napoli", "Italy", 40.8359, 14.2488));
    Cities.push_back(new City("Narva", "Estonia", 59.3794, 28.1994, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Newcastle-upon-Tyne", "United Kingdom", 54.9771, -1.61421));
    Cities.push_back(new City("Nice", "France", 43.7009, 7.26839));
    Cities.push_back(new City("Nürnberg", "Germany", 49.4539, 11.0773));
    Cities.push_back(new City("Nynäshamn", "Sweden", 58.9056, 17.9471, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Odense", "Denmark", 55.3997, 10.3852));
    Cities.push_back(new City("Olkiluoto", "Finland", 61.2341, 21.4906, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Olsztyn", "Poland", 53.777, 20.4779));
    Cities.push_back(new City("Örebro", "Sweden", 59.2747, 15.215));
    Cities.push_back(new City("Oslo", "Norway", 59.9133, 10.739));
    Cities.push_back(new City("Osnabrück", "Germany", 52.2668, 8.04974));
    Cities.push_back(new City("Ostrava", "Czech Republic", 49.8349, 18.282));
    Cities.push_back(new City("Paldiski", "Estonia", 59.3589, 24.0983, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Palermo", "Italy", 38.1112, 13.3524));
    Cities.push_back(new City("Panevėžys", "Lithuania", 55.7345, 24.3578));
    Cities.push_back(new City("Parma", "Italy", 44.8014, 10.3281, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Pärnu", "Estonia", 58.3835, 24.5082));
    Cities.push_back(new City("Pescara", "Italy", 42.4696, 14.2059));
    Cities.push_back(new City("Paluel", "France", 49.8327, 0.629538, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Paris", "France", 48.8566, 2.3515));
    Cities.push_back(new City("Pécs", "Hungary", 46.0763, 18.2281));
    Cities.push_back(new City("Plymouth", "United Kingdom", 50.3713, -4.14257));
    Cities.push_back(new City("Pori", "Finland", 61.4867, 21.791));
    Cities.push_back(new City("Poznań", "Poland", 52.4007, 16.9198));
    Cities.push_back(new City("Praha", "Czech Republic", 50.0875, 14.4213));
    Cities.push_back(new City("Pskov", "Russia", 57.8174, 28.3344));
    Cities.push_back(new City("Reims", "France", 49.2578, 4.03193));
    Cities.push_back(new City("Rennes", "France", 48.1113, -1.68002));
    Cities.push_back(new City("Rēzekne", "Latvia", 56.5063, 27.3307));
    Cities.push_back(new City("Rīga", "Latvia", 56.9494, 24.1052));
    Cities.push_back(new City("Roma", "Italy", 41.8948, 12.4853));
    Cities.push_back(new City("Roscoff", "France", 48.7256, -3.98292, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Rostock", "Germany", 54.0924, 12.1286));
    Cities.push_back(new City("Rotterdam", "Netherlands", 51.9278, 4.48862));
    Cities.push_back(new City("Saint-Alban-du-Rhône", "France", 45.4243, 4.76, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Saint-Laurent", "France", 47.9267, -3.92795, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Saint Petersburg", "Russia", 59.9387, 30.3162));
    Cities.push_back(new City("Salzburg", "Austria", 47.7981, 13.0465));
    Cities.push_back(new City("Sheffield", "United Kingdom", 53.3807, -1.47023));
    Cities.push_back(new City("Šiauliai", "Lithuania", 55.9341, 23.3158));
    Cities.push_back(new City("Södertälje", "Sweden", 59.1964, 17.6272, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Sosnovy Bor", "Russia", 59.8778, 29.1306, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Southampton", "United Kingdom", 50.9025, -1.40419));
    Cities.push_back(new City("Stavanger", "Norway", 58.968, 5.73247));
    Cities.push_back(new City("Strasbourg", "France", 48.5846, 7.75071));
    Cities.push_back(new City("Stockholm", "Sweden", 59.3251, 18.0711));
    Cities.push_back(new City("Stuttgart", "Germany", 48.7784, 9.18001));
    Cities.push_back(new City("Suzzara", "Italy", 44.9919, 10.7431, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Swansea", "United Kingdom", 51.6211, -3.94678));
    Cities.push_back(new City("Szeged", "Hungary", 46.2546, 20.1486));
    Cities.push_back(new City("Szczecin", "Poland", 53.4297, 14.5929));
    Cities.push_back(new City("Tallinn", "Estonia", 59.4372, 24.7454));
    Cities.push_back(new City("Tampere", "Finland", 61.498, 23.7603));
    Cities.push_back(new City("Taranto", "Italy", 40.4712, 17.2432));
    Cities.push_back(new City("Tartu", "Estonia", 58.3801, 26.7224));
    Cities.push_back(new City("Terni", "Italy", 42.5641, 12.6405, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Torino", "Italy", 45.0678, 7.68249));
    Cities.push_back(new City("Toulouse", "France", 43.6045, 1.44425));
    Cities.push_back(new City("Travemünde", "Germany", 53.9396, 10.8588, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Trelleborg", "Sweden", 55.3759, 13.1462, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Turku", "Finland", 60.4518, 22.2671));
    Cities.push_back(new City("Uppsala", "Sweden", 59.8594, 17.6411));
    Cities.push_back(new City("Utena", "Lithuania", 55.4984, 25.6026, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Valmiera", "Latvia", 57.5392, 25.4216));
    Cities.push_back(new City("Västerås", "Sweden", 59.6111, 16.5464));
    Cities.push_back(new City("Växjö", "Sweden", 56.8787, 14.8094));
    Cities.push_back(new City("Venezia", "Italy", 45.4372, 12.3346));
    Cities.push_back(new City("Ventspils", "Latvia", 57.3904, 21.5636, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Verona", "Italy", 45.4385, 10.9924));
    Cities.push_back(new City("Villa San Giovanni", "Italy", 38.2201, 15.6374, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Vilnius", "Lithuania", 54.687, 25.2829));
    Cities.push_back(new City("Vyborg", "Russia", 60.7092, 28.7441, Garage::GarageType::NotAllowed));
    Cities.push_back(new City("Warszawa", "Poland", 52.2337, 21.0714));
    Cities.push_back(new City("Wien", "Austria", 48.2084, 16.3725));
    Cities.push_back(new City("Wrocław", "Poland", 51.1263, 16.9782));
    Cities.push_back(new City("Zürich", "Switzerland", 47.3769, 8.54141));

    for (City* c : Cities)
    {
        c->NotifyCountry();
    }
}

void Serialize()
{
    cout << endl << "Saving City data..." << endl;

    ofstream savefile;
    savefile.open (CitySaveFile);

    if (savefile.is_open())
    {
        for (City* c: Cities)
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
    string line;
    ifstream savefile;
    savefile.open(CitySaveFile);
    if (savefile.is_open())
    {
        cout << "Opened save file..." << endl;

        int linenumber = 1;

        string fileCityName;
        string fileCountryName;
        double fileLatitude;
        double fileLongitude;
        Garage::GarageType fileGarageType;

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
                fileGarageType = static_cast<Garage::GarageType>(stoi(line));
                Cities.push_back(new City(fileCityName, fileCountryName, fileLatitude, fileLongitude, fileGarageType));
                linenumber = 1;
                break;
            default:
                throw "Error reading from save file";
            }
        }
    }
    else
    {
        throw "Error! File not open";
    }
}


int GetCountry()
{
    uint countrychoice = 9999;

    while((countrychoice < 1)| (countrychoice > Countries.size()))
    {
        cout << endl;

        for (uint i = 0; i < Countries.size(); i++)
        {
            cout << "(" << i + 1 << ") " << Countries[i]->Name << endl;
        }

        cout << endl;
        cout << "Please select a country: " << endl;

        cin >> countrychoice;
    }

    cout << endl;
    cout << "You chose " << Countries[countrychoice - 1]->Name << endl;
    cout << endl;

    return countrychoice - 1;
}

int GetCity(int countryIndex)
{
    uint citychoice = 9999;

    while((citychoice < 1)| (citychoice > Cities.size()))
    {
        cout << endl;
        cout << "Cities in " << Countries[countryIndex]->Name << ":" << endl;
        cout << endl;

        for (uint i = 0; i < Countries[countryIndex]->CountryCities.size(); i++)
        {
            cout << "(" << i + 1 << ") " << Countries[countryIndex]->CountryCities[i]->Name << endl;
        }

        cout << endl;
        cout << "Please select a city: " << endl;

        cin >> citychoice;
    }

    cout << endl;
    cout << "You chose " << Countries[countryIndex]->CountryCities[citychoice - 1]->Name << endl;
    cout << endl;

    return citychoice - 1;
}
