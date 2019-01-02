#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <curl/curl.h>
#include <rapidjson/document.h>

#include "main.h"
#include "Country.h"
#include "City.h"

using namespace std;


int main()
{
    bool ExitRequested = false;

    while (!ExitRequested){
        ExitRequested = PrintMenu();
    }

    cout << endl << "Exiting..." << endl;
}

bool PrintMenu()
{
    int menuChoice = 0;

    cout << "*******Main Menu*******" << endl;
    cout << "(1): Populate Map Data" << endl;
    cout << "(2): Print Current Cities" << endl;
    cout << "(3): Save and Exit" << endl;
    cout << "(4): Exit without Save" << endl;
    cin >> menuChoice;

    switch(menuChoice)
    {
    case 1:
        PopulateCountries();
        PopulateCities();
        break;
    case 2:
        for(Country c : Countries)
        {
            for(City y: c.CountryCities)
            {
                cout << y.Name << ", " << c.Name << endl;
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
    CreateCity("Aalborg", "Denmark");
    CreateCity("Aberdeen", "United Kingdom");
    CreateCity("Amsterdam", "Netherlands");
    CreateCity("Ancona", "Italy");
    CreateCity("Banská Bystrica", "Slovakia");
    CreateCity("Bari", "Italy");
    CreateCity("Bergen", "Norway");
    CreateCity("Berlin", "Germany");
    CreateCity("Bern", "Switzerland");
    CreateCity("Białystok", "Poland");
    CreateCity("Birmingham", "United Kingdom");
    CreateCity("Bologna", "Italy");
    CreateCity("Bordeaux", "France");
    CreateCity("Bourges", "France");
    CreateCity("Bratislava", "Slovakia");
    CreateCity("Bremen", "Germany");
    CreateCity("Brest", "France");
    CreateCity("Brussel", "Belgium");
    CreateCity("Brno", "Czech Republic");
    CreateCity("Budapest", "Hungary");
    CreateCity("Calais", "France");
    CreateCity("Cambridge", "United Kingdom");
    CreateCity("Cardiff", "United Kingdom");
    CreateCity("Carlisle", "United Kingdom");
    CreateCity("Cassino", "Italy");
    CreateCity("Catania", "Italy");
    CreateCity("Catanzaro", "Italy");
    CreateCity("Clermont-Ferrand", "France");
    CreateCity("Civaux", "France");
    CreateCity("Daugavpils", "Latvia");
    CreateCity("Debrecen", "Hungary");
    CreateCity("Dijon", "France");
    CreateCity("Dortmund", "Germany");
    CreateCity("Dover", "United Kingdom");
    CreateCity("Dresden", "Germany");
    CreateCity("Duisburg", "Germany");
    CreateCity("Düsseldorf", "Germany");
    CreateCity("Edinburgh", "United Kingdom");
    CreateCity("Erfurt", "Germany");
    CreateCity("Esbjerg", "Denmark");
    CreateCity("Felixstowe", "United Kingdom");
    CreateCity("Firenze", "Italy");
    CreateCity("Frankfurt am Main", "Germany");
    CreateCity("Frederikshavn", "Denmark");
    CreateCity("Gdańsk", "Poland");
    CreateCity("Gedser", "Denmark");
    CreateCity("Genève", "Switzerland");
    CreateCity("Genova", "Italy");
    CreateCity("Glasgow", "United Kingdom");
    CreateCity("Golfech", "France");
    CreateCity("Göteborg", "Sweden");
    CreateCity("Graz", "Austria");
    CreateCity("Grimsby", "United Kingdom");
    CreateCity("Groningen", "Netherlands");
    CreateCity("Hamburg", "Germany");
    CreateCity("Hannover", "Germany");
    CreateCity("Helsingborg", "Sweden");
    CreateCity("Helsinki", "Finland");
    CreateCity("Hirtshals", "Denmark");
    CreateCity("Innsbruck", "Austria");
    CreateCity("Jönköping", "Sweden");
    CreateCity("Kaliningrad", "Russia");
    CreateCity("Kalmar", "Sweden");
    CreateCity("Kapellskär", "Sweden");
    CreateCity("Karlskrona", "Sweden");
    CreateCity("Kaunas", "Lithuania");
    CreateCity("Kassel", "Germany");
    CreateCity("Katowice", "Poland");
    CreateCity("Kiel", "Germany");
    CreateCity("Klagenfurt am Wörthersee", "Austria");
    CreateCity("Klaipėda", "Lithuania");
    CreateCity("København", "Denmark");
    CreateCity("Köln", "Germany");
    CreateCity("Košice", "Slovakia");
    CreateCity("Kotka", "Finland");
    CreateCity("Kouvola", "Finland");
    CreateCity("Kraków", "Poland");
    CreateCity("Kristiansand", "Norway");
    CreateCity("Kunda", "Estonia");
    CreateCity("Lahti", "Finland");
    CreateCity("La Rochelle", "France");
    CreateCity("Leipzig", "Germany");
    CreateCity("Le Havre", "France");
    CreateCity("Le Mans", "France");
    CreateCity("Liège", "Belgium");
    CreateCity("Liepāja", "Latvia");
    CreateCity("Lille", "France");
    CreateCity("Limoges", "France");
    CreateCity("Linköping", "Sweden");
    CreateCity("Linz", "Austria");
    CreateCity("Liverpool", "United Kingdom");
    CreateCity("Livorno", "Italy");
    CreateCity("Łódź", "Poland");
    CreateCity("London", "United Kingdom");
    CreateCity("Loviisa", "Finland");
    CreateCity("Lublin", "Poland");
    CreateCity("Luga", "Russia");
    CreateCity("Luxembourg", "Luxembourg");
    CreateCity("Lyon", "France");
    CreateCity("Magdeburg", "Germany");
    CreateCity("Malmö", "Sweden");
    CreateCity("Manchester", "United Kingdom");
    CreateCity("Mannheim", "Germany");
    CreateCity("Marseille", "France");
    CreateCity("Mažeikiai", "Lithuania");
    CreateCity("Messina", "Italy");
    CreateCity("Metz", "France");
    CreateCity("Milano", "Italy");
    CreateCity("Montpellier", "France");
    CreateCity("München", "Germany");
    CreateCity("Naantali", "Finland");
    CreateCity("Nantes", "France");
    CreateCity("Napoli", "Italy");
    CreateCity("Narva", "Estonia");
    CreateCity("Newcastle-upon-Tyne", "United Kingdom");
    CreateCity("Nice", "France");
    CreateCity("Nürnberg", "Germany");
    CreateCity("Nynäshamn", "Sweden");
    CreateCity("Odense", "Denmark");
    CreateCity("Olkiluoto", "Finland");
    CreateCity("Olsztyn", "Poland");
    CreateCity("Örebro", "Sweden");
    CreateCity("Oslo", "Norway");
    CreateCity("Osnabrück", "Germany");
    CreateCity("Ostrava", "Czech Republic");
    CreateCity("Paldiski", "Estonia");
    CreateCity("Palermo", "Italy");
    CreateCity("Panevėžys", "Lithuania");
    CreateCity("Parma", "Italy");
    CreateCity("Pärnu", "Estonia");
    CreateCity("Pescara", "Italy");
    CreateCity("Paluel", "France");
    CreateCity("Paris", "France");
    CreateCity("Pécs", "Hungary");
    CreateCity("Plymouth", "United Kingdom");
    CreateCity("Pori", "Finland");
    CreateCity("Poznań", "Poland");
    CreateCity("Praha", "Czech Republic");
    CreateCity("Pskov", "Russia");
    CreateCity("Reims", "France");
    CreateCity("Rennes", "France");
    CreateCity("Rēzekne", "Latvia");
    CreateCity("Rīga", "Latvia");
    CreateCity("Roma", "Italy");
    CreateCity("Roscoff", "France");
    CreateCity("Rostock", "Germany");
    CreateCity("Rotterdam", "Netherlands");
    CreateCity("Saint-Alban-du-Rhône", "France");
    CreateCity("Saint-Laurent", "France");
    CreateCity("Saint Petersburg", "Russia");
    CreateCity("Salzburg", "Austria");
    CreateCity("Sheffield", "United Kingdom");
    CreateCity("Šiauliai", "Lithuania");
    CreateCity("Södertälje", "Sweden");
    CreateCity("Sosnovy Bor", "Russia");
    CreateCity("Southampton", "United Kingdom");
    CreateCity("Stavanger", "Norway");
    CreateCity("Strasbourg", "France");
    CreateCity("Stockholm", "Sweden");
    CreateCity("Stuttgart", "Germany");
    CreateCity("Suzzara", "Italy");
    CreateCity("Swansea", "United Kingdom");
    CreateCity("Szeged", "Hungary");
    CreateCity("Szczecin", "Poland");
    CreateCity("Tallinn", "Estonia");
    CreateCity("Tampere", "Finland");
    CreateCity("Taranto", "Italy");
    CreateCity("Tartu", "Estonia");
    CreateCity("Terni", "Italy");
    CreateCity("Torino", "Italy");
    CreateCity("Toulouse", "France");
    CreateCity("Travemünde", "Germany");
    CreateCity("Trelleborg", "Sweden");
    CreateCity("Turku", "Finland");
    CreateCity("Uppsala", "Sweden");
    CreateCity("Utena", "Lithuania");
    CreateCity("Valmiera", "Latvia");
    CreateCity("Västerås", "Sweden");
    CreateCity("Växjö", "Sweden");
    CreateCity("Venezia", "Italy");
    CreateCity("Ventspils", "Latvia");
    CreateCity("Verona", "Italy");
    CreateCity("Villa San Giovanni", "Italy");
    CreateCity("Vilnius", "Lithuania");
    CreateCity("Vyborg", "Russia");
    CreateCity("Warszawa", "Poland");
    CreateCity("Wien", "Austria");
    CreateCity("Wrocław", "Poland");
    CreateCity("Zürich", "Switzerland");
}


void CreateCity(const char* Name, const char* InCountry)
{
    for(uint i = 0; i < Countries.size(); i++)
    {
        if(Countries[i].Name == InCountry)
        {
            City ReturnCity(Name, Countries[i]);
            Geocode(&ReturnCity);
            Cities.push_back(ReturnCity);
            Countries[i].AddCity(Cities.back());

            return;
        }
    }
    throw "City's Country Not Found!";
}


string data;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
    data = "";

    for (uint c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }

    //nominatim sends the JSON as an array with square brackets surrounding it.
    //I'm too stupid to figure out how to parse that correctly so...
    //I just remove the square brackets...
    //This may affect the data I can retrieve and parse
    //but since I'm only using it for lat and lon so far, it works.
    data = data.substr(1, data.size() - 2);

    return size*nmemb;
}

void Geocode(City* InCity)
{

    //CURL Initializatiion
    CURL* curl;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    //We need to concact a string to pass as a URL
    char str[200];
    strcpy(str, "https://nominatim.openstreetmap.org/search/");

    //URL encodes the city name
    char *urlCity = curl_easy_escape(curl, InCity->Name, 0);
    strcat(str, urlCity);
    strcat(str, ",%20");

    //...and the country name
    char *urlCountry = curl_easy_escape(curl, InCity->CityCountry.Name, 0);
    strcat(str, urlCountry);
    strcat(str, "?format=jsonv2&limit=1");

    //setting curl options
    curl_easy_setopt(curl, CURLOPT_URL, str);

    //freeing the easy escape string pointers, as per CURL documentation
    curl_free(urlCity);
    curl_free(urlCountry);

    curl_easy_setopt(curl, CURLOPT_USERAGENT, "ETS2 Helper/1.0");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);

    //performing curl operation
    curl_easy_perform(curl);


    //create a JSON document using RapidJSON library, and then parse the JSON received from nominatim
    rapidjson::Document d;
    if (d.Parse(data.c_str()).HasParseError())
        cout << "error" << '\n';

    //atof parses and converts a char array (the way nominatim sends longitudes and latitudes
    //into a double, the way we store Lat and Long to be able to process and do math on.

    InCity->Latitude = atof(d["lat"].GetString());
    InCity->Longitude = atof(d["lon"].GetString());

    //curl cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}
