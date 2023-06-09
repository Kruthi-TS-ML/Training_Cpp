/* Program to demonstrate vectors and maps */

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<map<int, string>> vector_of_maps;

void insert_pandavas(map<int, string> *mapObj)
{
    mapObj->insert({1, "Arjuna"});
    mapObj->insert({2, "Bheema"});
    mapObj->insert({3, "Nakula"});
    mapObj->insert({4, "Sahadeva"});
    mapObj->insert({5, "Dharmaraya"});
} 

void insert_kauravas(map<int, string> *mapObj)
{
    mapObj->insert({1, "Dushyasana"});
    mapObj->insert({2, "Duryodhana"});
} 

void insert_acharyas(map<int, string> *mapObj)
{
    mapObj->insert({1, "Drona"});
    mapObj->insert({2, "Durvasa"});
    mapObj->insert({3, "Bheeshma"});
} 

int main()
{
    map<int, string> Emp[3];
    insert_pandavas(&Emp[0]);
    vector_of_maps.push_back(Emp[0]);
    insert_kauravas(&Emp[1]);
    vector_of_maps.push_back(Emp[1]);
    insert_acharyas(&Emp[2]);
    vector_of_maps.push_back(Emp[2]);

    //Iterate through list of vectors
    for(vector<map<int,string>>::iterator it = vector_of_maps.begin() ; it != vector_of_maps.end(); it++)
    {
        //Iterate through elements of each map
        for(map<int,string>::iterator mp = it->begin(); mp != it->end(); mp++)
        {
            cout << "Mahabharat Character ID: " << mp->first << "\t Name: " << mp->second << endl;
        }
    }   
    return 0;
}