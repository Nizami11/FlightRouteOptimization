#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

//Represent route between airports
struct Route{
    string destination;  
    int weight;  //(distance,cost or time)
};

//Flight graph class
class FlightNetwork{
    private:

//list to store graph
unordered_map<string,list<Route>> graph;

public:
//add route between two airports
void addRoute(const string& source, const string& destination, int weight){
//from source to destination
graph[source].push_back({destination,weight});

//from destination to source
graph[destination].push_back({source,weight});
}

//Displaying routes
void displayRoute() const{
    for(const auto&[airport,routes]:graph){
        cout<<airport<<"->";
        for(const auto& route :routes){
            cout<<"(" <<route.destination<<"," <<route.weight<<")";
        }
        cout<<endl;
    }
}

};