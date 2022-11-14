#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

// Functions to be implemented:

bool inSet(std::set<std::string> countries, std::string check){
    for (auto& country : countries){
        if(check == country){
            return true;
        }
        //std::cout << "Country:" << country << "; ";
    }

    return false;

}

bool inMap(std::map<std::string, int> cases, std::string check){
    for (const auto& n : cases){
        //std::cout << '[' << n.first << "] = " << n.second << "; ";
        if(check == n.first){
            return true;
        }
    }
    return false;
}

int casesForProvinceState(std::map<std::string, int> cases, std::string check){
    for (const auto& n : cases){
        //std::cout << '[' << n.first << "] = " << n.second << "; ";
        if(check == n.first){
            return n.second;
        }
    }
    return 0;
}

std::string maxCasesForProvinceState(std::map<std::string, int> cases){
    std::string maxCountry;
    int maxCases = 0;    
    for (const auto& n : cases){
        //std::cout << '[' << n.first << "] = " << n.second << "; ";
        if(maxCases < n.second){
            maxCountry = n.first;
            maxCases = n.second;
        }
    }
    return maxCountry;
}

//FIPS,Admin2,Province_State,Country_Region,Last_Update,Lat,Long_,Confirmed,Deaths,Recovered,Active,Combined_Key,Incidence_Rate,Case-Fatality_Ratio
// UID,iso2,iso3,code3,FIPS,Admin2,Province_State,Country_Region,Lat,Long_,Combined_Key,Population
int main(){
    std::set<std::string> countries;

    std::map<std::string, int> cases;

    std::ifstream data;

    std::string line;

    data.open("covid_from_repo.csv");
    std::getline(data, line);
    // std::cout << line << std::endl;
    while (std::getline(data, line)){
    // This is where you will implement your code for
    // insertion into maps and sets
        // std::cout << line << std::endl;
        int counter = 1;
        std::string Province_State;
        std::string* Province_State_pointer = nullptr;
        std::string Country;
        std::string entry;
        int tempCases;
        std::stringstream streamline(line);
        while(std::getline(streamline, entry, ',')){
            // std::cout << entry << std::endl;
            switch(counter){
                case 3:
                    if(entry != ""){
                        // std::cout << "entry" << entry << std::endl;
                        Province_State = entry;
                        Province_State_pointer = &Province_State;
                    }
                    //std::cout << "Province_State" << Province_State_pointer << std::endl;
                    break;
                case 4: 
                    Country = entry;
                    if(Province_State_pointer == nullptr){
                        Province_State = Country;
                        Province_State_pointer = &Province_State;
                    }
                    break;
                case 8:
                    tempCases = std::stoi(entry);
                default:
                    // std::cout << "I did not need:" << entry << std::endl;
                    break;                    
            }
            counter++;
        }
        countries.insert(Country);
        cases.insert({Province_State, tempCases});
        // if((*Province_State_pointer) != Country){
        //     std::cout << "Province or State is " << Province_State << "," << Country << std::endl;
        //     std::cout << "Cases " << tempCases << std::endl;
        // } else {
        //     // countries.insert(Country);
        //     std::cout << "Country is " << Country  << ", there was no Province or State but it will be recorded as " << ((Province_State_pointer != nullptr)?Province_State:"Null") << std::endl;
        //     std::cout << "Cases " << tempCases << std::endl;
        // }
        // std::cout << std::endl;
    }
    data.close();

    //Space for custom test cases:
    std::string maxProvinceOrState = maxCasesForProvinceState(cases);
    
    std::cout << "Max Province or State: " << maxProvinceOrState << " with a case of " << casesForProvinceState(cases, maxProvinceOrState) << std::endl;
    //Test Case 1

        if (!inSet(countries, "Afghanistan")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (!inSet(countries, "Botswana")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (!inSet(countries, "United Kingdom")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (inSet(countries, "Queensland")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the the countries set." << std::endl;
        return 1;
    }
    if (inSet(countries, "Mayotte")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the the countries set." << std::endl;
        return 1;
    }
    if (inSet(countries, "Sichuan")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the countries set." << std::endl;
        return 1;
    }

    //Test Case 2:
    if (!inMap(cases, "Zimbabwe")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Zimbabwe not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (!inMap(cases, "Greenland")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Greenland not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (!inMap(cases, "Botswana")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Botswana not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (inMap(cases, "United Kingdom")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }
    if (inMap(cases, "China")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }
    if (inMap(cases, "US")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }

    //Test Case 3:
    if (countries.size() != 190){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of set incorrect. Check your insertion" << std::endl;
        return 1;
    }

    if (cases.size() != 729){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of map incorrect. Check your insertion" << std::endl;
        return 1;
    }

    //Test Case 4:
    if (casesForProvinceState(cases, "Kazakhstan") != 110684){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of map incorrect. Check your insertion" << std::endl;
        return 1;
    }


    std::cout << "All tests passed!" << std::endl;
}