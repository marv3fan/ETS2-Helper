#include <iostream>
#include <vector>

#include "main.h"
#include "Country.h"
#include "City.h"
#include "Garage.h"

using namespace std;


int main()
{
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
    cout << "(1): Populate Map Data" << endl;
    cout << "(2): Print Current Cities" << endl;
    cout << "(3): Save and Exit" << endl;
    cout << "(4): Exit without Save" << endl;
    cout << endl;
    cin >> menuChoice;

    switch(menuChoice)
    {
    case 1:
        PopulateCountries();
        PopulateCities();
        cout << endl << "Created " << Cities.size() << " cities in " << Countries.size() << " countries." << endl;
        break;
    case 2:
        //TODO: We need to clear the console here.
        for(Country c : Countries)
        {
            for(City y: c.CountryCities)
            {
                cout << endl;
                cout << y.Name << ", " << c.Name << endl;
                cout << y.Latitude << " " << y.Longitude << endl;

                switch(y.GarageType())
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
    case 3:
        //TODO: Include code to serialize cities and countries.
        return true;
        break;
    case 4:
        //We need to create a confirmation, should be pretty simple... might wanna look at clearing the console, first
        return true;
        break;
    default:
        cout << "ERROR! You have selected an invalid choice." << endl;
        break;
    }

    return false;
}

void PopulateCountries()
{
    Countries.emplace_back("Austria");
    Countries.emplace_back("Belgium");
    Countries.emplace_back("Czech Republic");
    Countries.emplace_back("Denmark");
    Countries.emplace_back("Estonia");
    Countries.emplace_back("Finland");
    Countries.emplace_back("France");
    Countries.emplace_back("Germany");
    Countries.emplace_back("Hungary");
    Countries.emplace_back("Italy");
    Countries.emplace_back("Latvia");
    Countries.emplace_back("Lithuania");
    Countries.emplace_back("Luxembourg");
    Countries.emplace_back("Netherlands");
    Countries.emplace_back("Norway");
    Countries.emplace_back("Poland");
    Countries.emplace_back("Russia");
    Countries.emplace_back("Slovakia");
    Countries.emplace_back("Sweden");
    Countries.emplace_back("Switzerland");
    Countries.emplace_back("United Kingdom");
}

void PopulateCities()
{
    CreateCity("Aalborg", "Denmark", 57.0482, 9.91939);
    CreateCity("Aberdeen", "United Kingdom", 57.1482, -2.09281);
    CreateCity("Amsterdam", "Netherlands", 52.3745, 4.89798);
    CreateCity("Ancona", "Italy", 43.617, 13.5171);
    CreateCity("Banská Bystrica", "Slovakia", 48.7384, 19.1573);
    CreateCity("Bari", "Italy", 41.1258, 16.862);
    CreateCity("Bergen", "Norway", 60.3943, 5.32581);
    CreateCity("Berlin", "Germany", 52.517, 13.3889);
    CreateCity("Bern", "Switzerland", 46.9483, 7.45145);
    CreateCity("Białystok", "Poland", 53.1275, 23.1471);
    CreateCity("Birmingham", "United Kingdom", 52.4775, -1.89405);
    CreateCity("Bologna", "Italy", 44.4937, 11.343);
    CreateCity("Bordeaux", "France", 44.8412, -0.580036);
    CreateCity("Bourges", "France", 47.0806, 2.39893, Garage::GarageType::NotAllowed);
    CreateCity("Bratislava", "Slovakia", 48.1359, 17.1597);
    CreateCity("Bremen", "Germany", 53.0758, 8.80716);
    CreateCity("Brest", "France", 48.3905, -4.48601);
    CreateCity("Brussel", "Belgium", 50.8466, 4.3517);
    CreateCity("Brno", "Czech Republic", 49.1922, 16.6113);
    CreateCity("Budapest", "Hungary", 47.4984, 19.0405);
    CreateCity("Calais", "France", 50.9488, 1.87468);
    CreateCity("Cambridge", "United Kingdom", 52.2035, 0.123582);
    CreateCity("Cardiff", "United Kingdom", 51.4817, -3.17919);
    CreateCity("Carlisle", "United Kingdom", 54.8948, -2.93623);
    CreateCity("Cassino", "Italy", 41.4926, 13.8305);
    CreateCity("Catania", "Italy", 37.5022, 15.0874);
    CreateCity("Catanzaro", "Italy", 38.9076, 16.596);
    CreateCity("Clermont-Ferrand", "France", 45.7775, 3.08194);
    CreateCity("Civaux", "France", 46.4448, 0.664645, Garage::GarageType::NotAllowed);
    CreateCity("Daugavpils", "Latvia", 55.8712, 26.5159);
    CreateCity("Debrecen", "Hungary", 47.5314, 21.626);
    CreateCity("Dijon", "France", 47.3216, 5.04147);
    CreateCity("Dortmund", "Germany", 51.5142, 7.46528);
    CreateCity("Dover", "United Kingdom", 51.13, 1.30832);
    CreateCity("Dresden", "Germany", 51.0493, 13.7381);
    CreateCity("Duisburg", "Germany", 51.435, 6.75956);
    CreateCity("Düsseldorf", "Germany", 51.2254, 6.77631);
    CreateCity("Edinburgh", "United Kingdom", 55.9533, -3.18837);
    CreateCity("Erfurt", "Germany", 50.9778, 11.0287);
    CreateCity("Esbjerg", "Denmark", 55.4665, 8.45208, Garage::GarageType::NotAllowed);
    CreateCity("Felixstowe", "United Kingdom", 51.9639, 1.35151);
    CreateCity("Firenze", "Italy", 43.7699, 11.2556);
    CreateCity("Frankfurt am Main", "Germany", 50.1106, 8.68209);
    CreateCity("Frederikshavn", "Denmark", 57.4412, 10.5336, Garage::GarageType::NotAllowed);
    CreateCity("Gdańsk", "Poland", 54.3614, 18.6282);
    CreateCity("Gedser", "Denmark", 54.5761, 11.9322, Garage::GarageType::NotAllowed);
    CreateCity("Genève", "Switzerland", 46.2018, 6.1466);
    CreateCity("Genova", "Italy", 44.4073, 8.93386);
    CreateCity("Glasgow", "United Kingdom", 55.8567, -4.24358);
    CreateCity("Golfech", "France", 44.1147, 0.851944, Garage::GarageType::NotAllowed);
    CreateCity("Göteborg", "Sweden", 57.7072, 11.967);
    CreateCity("Graz", "Austria", 47.0703, 15.4386);
    CreateCity("Grimsby", "United Kingdom", 53.5677, -0.0736289);
    CreateCity("Groningen", "Netherlands", 53.2218, 6.55825);
    CreateCity("Hamburg", "Germany", 53.5503, 10.0007);
    CreateCity("Hannover", "Germany", 52.3745, 9.73855);
    CreateCity("Helsingborg", "Sweden", 56.0442, 12.7041);
    CreateCity("Helsinki", "Finland", 60.1674, 24.9426);
    CreateCity("Hirtshals", "Denmark", 57.5908, 9.96497, Garage::GarageType::NotAllowed);
    CreateCity("Innsbruck", "Austria", 47.2695, 11.3971);
    CreateCity("Jönköping", "Sweden", 57.7815, 14.1628);
    CreateCity("Kaliningrad", "Russia", 54.7066, 20.5105);
    CreateCity("Kalmar", "Sweden", 56.6629, 16.3662);
    CreateCity("Kapellskär", "Sweden", 59.7204, 19.0608, Garage::GarageType::NotAllowed);
    CreateCity("Karlskrona", "Sweden", 56.1621, 15.5866);
    CreateCity("Kaunas", "Lithuania", 54.8982, 23.9045);
    CreateCity("Kassel", "Germany", 51.3077, 9.46247);
    CreateCity("Katowice", "Poland", 50.2599, 19.0216);
    CreateCity("Kiel", "Germany", 54.3227, 10.1356);
    CreateCity("Klagenfurt am Wörthersee", "Austria", 46.6228, 14.308);
    CreateCity("Klaipėda", "Lithuania", 55.7128, 21.135);
    CreateCity("København", "Denmark", 55.6867, 12.5701);
    CreateCity("Köln", "Germany", 50.9384, 6.95997);
    CreateCity("Košice", "Slovakia", 48.7172, 21.2497);
    CreateCity("Kotka", "Finland", 60.4674, 26.9451);
    CreateCity("Kouvola", "Finland", 60.8702, 26.7018);
    CreateCity("Kraków", "Poland", 50.0469, 19.9971);
    CreateCity("Kristiansand", "Norway", 58.1461, 7.99573);
    CreateCity("Kunda", "Estonia", 59.5055, 26.5292, Garage::GarageType::NotAllowed);
    CreateCity("Lahti", "Finland", 60.9839, 25.6562);
    CreateCity("La Rochelle", "France", 46.1591, -1.15204);
    CreateCity("Leipzig", "Germany", 51.3406, 12.3747);
    CreateCity("Le Havre", "France", 49.4939, 0.107973);
    CreateCity("Le Mans", "France", 48.0073, 0.196738);
    CreateCity("Liège", "Belgium", 50.6451, 5.57342);
    CreateCity("Liepāja", "Latvia", 56.5048, 21.0071);
    CreateCity("Lille", "France", 50.6305, 3.07064);
    CreateCity("Limoges", "France", 45.8354, 1.26448);
    CreateCity("Linköping", "Sweden", 58.4098, 15.6245);
    CreateCity("Linz", "Austria", 48.3059, 14.2862);
    CreateCity("Liverpool", "United Kingdom", 53.4055, -2.98054);
    CreateCity("Livorno", "Italy", 43.5507, 10.3091);
    CreateCity("Łódź", "Poland", 51.7731, 19.4784);
    CreateCity("London", "United Kingdom", 51.5073, -0.127647);
    CreateCity("Loviisa", "Finland", 60.4562, 26.2268, Garage::GarageType::NotAllowed);
    CreateCity("Lublin", "Poland", 51.2182, 22.5547);
    CreateCity("Luga", "Russia", 58.7357, 29.8475);
    CreateCity("Luxembourg", "Luxembourg", 49.8159, 6.12968);
    CreateCity("Lyon", "France", 45.7578, 4.83201);
    CreateCity("Magdeburg", "Germany", 52.1316, 11.64);
    CreateCity("Malmö", "Sweden", 55.6053, 13.0002);
    CreateCity("Manchester", "United Kingdom", 53.4791, -2.2441);
    CreateCity("Mannheim", "Germany", 49.4896, 8.46724);
    CreateCity("Marseille", "France", 43.2962, 5.36995);
    CreateCity("Mažeikiai", "Lithuania", 56.3116, 22.3383, Garage::GarageType::NotAllowed);
    CreateCity("Messina", "Italy", 38.1938, 15.5542);
    CreateCity("Metz", "France", 49.1197, 6.17636);
    CreateCity("Milano", "Italy", 45.4668, 9.1905);
    CreateCity("Montpellier", "France", 43.6112, 3.87673);
    CreateCity("München", "Germany", 48.1371, 11.5754);
    CreateCity("Naantali", "Finland", 60.4689, 22.0291, Garage::GarageType::NotAllowed);
    CreateCity("Nantes", "France", 47.2186, -1.55414);
    CreateCity("Napoli", "Italy", 40.8359, 14.2488);
    CreateCity("Narva", "Estonia", 59.3794, 28.1994, Garage::GarageType::NotAllowed);
    CreateCity("Newcastle-upon-Tyne", "United Kingdom", 54.9771, -1.61421);
    CreateCity("Nice", "France", 43.7009, 7.26839);
    CreateCity("Nürnberg", "Germany", 49.4539, 11.0773);
    CreateCity("Nynäshamn", "Sweden", 58.9056, 17.9471, Garage::GarageType::NotAllowed);
    CreateCity("Odense", "Denmark", 55.3997, 10.3852);
    CreateCity("Olkiluoto", "Finland", 61.2341, 21.4906, Garage::GarageType::NotAllowed);
    CreateCity("Olsztyn", "Poland", 53.777, 20.4779);
    CreateCity("Örebro", "Sweden", 59.2747, 15.215);
    CreateCity("Oslo", "Norway", 59.9133, 10.739);
    CreateCity("Osnabrück", "Germany", 52.2668, 8.04974);
    CreateCity("Ostrava", "Czech Republic", 49.8349, 18.282);
    CreateCity("Paldiski", "Estonia", 59.3589, 24.0983, Garage::GarageType::NotAllowed);
    CreateCity("Palermo", "Italy", 38.1112, 13.3524);
    CreateCity("Panevėžys", "Lithuania", 55.7345, 24.3578);
    CreateCity("Parma", "Italy", 44.8014, 10.3281, Garage::GarageType::NotAllowed);
    CreateCity("Pärnu", "Estonia", 58.3835, 24.5082);
    CreateCity("Pescara", "Italy", 42.4696, 14.2059);
    CreateCity("Paluel", "France", 49.8327, 0.629538, Garage::GarageType::NotAllowed);
    CreateCity("Paris", "France", 48.8566, 2.3515);
    CreateCity("Pécs", "Hungary", 46.0763, 18.2281);
    CreateCity("Plymouth", "United Kingdom", 50.3713, -4.14257);
    CreateCity("Pori", "Finland", 61.4867, 21.791);
    CreateCity("Poznań", "Poland", 52.4007, 16.9198);
    CreateCity("Praha", "Czech Republic", 50.0875, 14.4213);
    CreateCity("Pskov", "Russia", 57.8174, 28.3344);
    CreateCity("Reims", "France", 49.2578, 4.03193);
    CreateCity("Rennes", "France", 48.1113, -1.68002);
    CreateCity("Rēzekne", "Latvia", 56.5063, 27.3307);
    CreateCity("Rīga", "Latvia", 56.9494, 24.1052);
    CreateCity("Roma", "Italy", 41.8948, 12.4853);
    CreateCity("Roscoff", "France", 48.7256, -3.98292, Garage::GarageType::NotAllowed);
    CreateCity("Rostock", "Germany", 54.0924, 12.1286);
    CreateCity("Rotterdam", "Netherlands", 51.9278, 4.48862);
    CreateCity("Saint-Alban-du-Rhône", "France", 45.4243, 4.76, Garage::GarageType::NotAllowed);
    CreateCity("Saint-Laurent", "France", 47.9267, -3.92795, Garage::GarageType::NotAllowed);
    CreateCity("Saint Petersburg", "Russia", 59.9387, 30.3162);
    CreateCity("Salzburg", "Austria", 47.7981, 13.0465);
    CreateCity("Sheffield", "United Kingdom", 53.3807, -1.47023);
    CreateCity("Šiauliai", "Lithuania", 55.9341, 23.3158);
    CreateCity("Södertälje", "Sweden", 59.1964, 17.6272, Garage::GarageType::NotAllowed);
    CreateCity("Sosnovy Bor", "Russia", 59.8778, 29.1306, Garage::GarageType::NotAllowed);
    CreateCity("Southampton", "United Kingdom", 50.9025, -1.40419);
    CreateCity("Stavanger", "Norway", 58.968, 5.73247);
    CreateCity("Strasbourg", "France", 48.5846, 7.75071);
    CreateCity("Stockholm", "Sweden", 59.3251, 18.0711);
    CreateCity("Stuttgart", "Germany", 48.7784, 9.18001);
    CreateCity("Suzzara", "Italy", 44.9919, 10.7431, Garage::GarageType::NotAllowed);
    CreateCity("Swansea", "United Kingdom", 51.6211, -3.94678);
    CreateCity("Szeged", "Hungary", 46.2546, 20.1486);
    CreateCity("Szczecin", "Poland", 53.4297, 14.5929);
    CreateCity("Tallinn", "Estonia", 59.4372, 24.7454);
    CreateCity("Tampere", "Finland", 61.498, 23.7603);
    CreateCity("Taranto", "Italy", 40.4712, 17.2432);
    CreateCity("Tartu", "Estonia", 58.3801, 26.7224);
    CreateCity("Terni", "Italy", 42.5641, 12.6405, Garage::GarageType::NotAllowed);
    CreateCity("Torino", "Italy", 45.0678, 7.68249);
    CreateCity("Toulouse", "France", 43.6045, 1.44425);
    CreateCity("Travemünde", "Germany", 53.9396, 10.8588, Garage::GarageType::NotAllowed);
    CreateCity("Trelleborg", "Sweden", 55.3759, 13.1462, Garage::GarageType::NotAllowed);
    CreateCity("Turku", "Finland", 60.4518, 22.2671);
    CreateCity("Uppsala", "Sweden", 59.8594, 17.6411);
    CreateCity("Utena", "Lithuania", 55.4984, 25.6026, Garage::GarageType::NotAllowed);
    CreateCity("Valmiera", "Latvia", 57.5392, 25.4216);
    CreateCity("Västerås", "Sweden", 59.6111, 16.5464);
    CreateCity("Växjö", "Sweden", 56.8787, 14.8094);
    CreateCity("Venezia", "Italy", 45.4372, 12.3346);
    CreateCity("Ventspils", "Latvia", 57.3904, 21.5636, Garage::GarageType::NotAllowed);
    CreateCity("Verona", "Italy", 45.4385, 10.9924);
    CreateCity("Villa San Giovanni", "Italy", 38.2201, 15.6374, Garage::GarageType::NotAllowed);
    CreateCity("Vilnius", "Lithuania", 54.687, 25.2829);
    CreateCity("Vyborg", "Russia", 60.7092, 28.7441, Garage::GarageType::NotAllowed);
    CreateCity("Warszawa", "Poland", 52.2337, 21.0714);
    CreateCity("Wien", "Austria", 48.2084, 16.3725);
    CreateCity("Wrocław", "Poland", 51.1263, 16.9782);
    CreateCity("Zürich", "Switzerland", 47.3769, 8.54141);
}


void CreateCity(const char* Name, const char* InCountry, double Lat, double Lon)
{
    CreateCity(Name, InCountry, Lat, Lon, Garage::GarageType::None);
}

void CreateCity(const char* Name, const char* InCountry, double Lat, double Lon, Garage::GarageType garageType)
{
    for(uint i = 0; i < Countries.size(); i++)
    {
        if(Countries[i].Name == InCountry)
        {
            City ReturnCity(Name, Countries[i], Lat, Lon, garageType);
            Cities.push_back(ReturnCity);
            Countries[i].AddCity(Cities.back());
            return;
        }
    }
    throw "City's Country Not Found!";
}

