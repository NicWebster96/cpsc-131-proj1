#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
	BrowserHistory();

	void visitSite(Webpage newSite);
	string back();
	string forward();

	void readHistory(string fileName);

	string getUrl();
	size_t getNavSize();
	list<Webpage> getSitesVisited();

private:
	list<Webpage> navHistory;
	list<Webpage>::iterator navPos;
	list<Webpage> sitesVisited;
	int numSites;
};

void BrowserHistory::readHistory(string fileName) {
	string temp;
	int newTime;
	Webpage newSite;
	ifstream inFile(fileName.c_str());

	while (inFile >> temp) {
		if (temp == "new") {
			inFile >> temp >> newTime;
			newSite = Webpage(temp, time_t(newTime));
			visitSite(newSite);
		}
		else if (temp == "back") {
			back();
		}
		else if (temp == "forward") {
			forward();
		}
		else {
			throw logic_error("invalid command");
		}
	}
}

BrowserHistory::BrowserHistory(){
	navHistory = {};
	navPos = {};
	sitesVisited = {};
	numSites = 0;
}

void BrowserHistory::visitSite(Webpage newsite) {
	
	if ( navPos != navHistory.end()) { 
		for (navPos = navHistory.begin(); navPos != navHistory.end(); navPos++) {       //wrong
			navHistory.push_back(newsite);
			navHistory.pop_back();
		}
	}
	else
		navHistory.push_back(newsite);
}

string BrowserHistory::back() {
	if (navPos != navHistory.begin()) {
		navPos--;
		return navPos->getUrl();
	}
	else
		throw invalid_argument("You cannot go back");
}
string BrowserHistory::forward() {
	if (navPos != navHistory.end()) {
		navPos++;
		return navPos->getUrl();

		}
	else 
		throw invalid_argument("You cannot go forward");
}

 string BrowserHistory::getUrl()
{
	
}

size_t BrowserHistory::getNavSize(){
	return navHistory.size();
}

list<Webpage> BrowserHistory::getSitesVisited() {
	return sitesVisited;
}





