/*
	121044017HW05.cpp
	created by Okan Akdogan

*/

#include <iostream>

using namespace std;

class Planet{
public:
	bool setName(const string name);
	//sets name of planet
	bool setDiameter(const int diameter);
	//sets diameter of planet
	bool setDistance(const int distance);
	//sets distance between planet and its orbit center
	bool setWeight(const int weight);
	//sets weight of planet

	string getName() const { return _name;};
	//returns name of planet
	int getDiameter() const { return _diameter; };
	//returns diameter of planet
	int getDistance() const {return _distanceFromCenter;};
	//returns distance between planet and its orbit center
	int getWeight() const {return _weight;};
	//returns weigh of planet

	friend ostream & operator <<(ostream & outputStream , const Planet & aPlanet);
	friend istream & operator >>(istream & inputStream , const Planet & aPlanet);

    int operator ++(){return ++_diameter;}; //postfix
    int operator ++(int){return _diameter++;};//prefix

    bool operator ==(const Planet other) const;
    bool operator<(const Planet other)const {return this._weight<};
private:
	string _name;
	int _diameter;
	int _distanceFromCenter;
	int _weight;
};


int main (){


	return 0;
}

ostream &  operator <<(ostream & outputStream, const Planet & aPlanet){

	outputStream<<endl;
	outputStream<<"Planet Name: "<<aPlanet.getName()<<endl;
	outputStream<<"Planet Diameter: "<<aPlanet.getDiameter()<<endl;
	outputStream<<"Planet Distance from center: "<<aPlanet.getDistance()<<endl;
	outputStream<<"Planet Weight: "<<aPlanet.getWeight()<<endl;

	return outputStream;
}

istream & operator >>(istream & inputStream, Planet & aPlanet){
    string name;
    int dia,dist,weight;
    inputStream>>name>>dia>>dist>>weight;

    aPlanet.setName(name);
    aPlanet.setDiameter(dia);
    aPlanet.setDistance(dist);
    aPlanet.setWeight(weight);

    return inputStream;
}
