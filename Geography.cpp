#include "Geography.h"
#include <math.h>
const static double EarthRadiusKm = 6372.8;


double Geography::GetDistance(City& CityFrom, City& CityTo)
{
    double Lat1 = CityFrom.Latitude;
    double Lat2 = CityTo.Latitude;
    double Lon1 = CityFrom.Longitude;
    double Lon2 = CityTo.Longitude;

    double latRad1 = M_PI * Lat1 / 180;
    double latRad2 = M_PI * Lat2 / 180;
    double lonRad1 = M_PI * Lon1 / 180;
    double lonRad2 = M_PI * Lon2 / 180;

    double diffLat = latRad2 - latRad1;
    double diffLon = lonRad2 - lonRad1;

    double comp = asin(sqrt(sin(diffLat / 2) * sin(diffLat / 2) + cos(latRad1) * cos(latRad2) * sin(diffLon/2) * sin(diffLon/2)));

    return 2 * EarthRadiusKm * comp;
}
