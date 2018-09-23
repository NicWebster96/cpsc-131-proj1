#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
    float _taxRate;

public:
    GroceryInventory(){
	_inventory = {};
	_taxRate = 0.0;
    }

    GroceryItem& getEntry(const string& _grocItem){
	for ( int i = 0; i < _inventory.size(); i++){
		if (_inventory.at(i).getName() != _grocItem)
			throw std::range_error("Item name does not match inventory");
		else 
			return _inventory.at(i);
	}
    }		

    void addEntry(const string& entry_name, const int& entry_quantity, const float& entry_price, const bool& entry_tax){
	GroceryItem groc_entry(entry_name,entry_quantity,entry_price,entry_tax);
	_inventory.push_back(groc_entry);
    }

    float getTaxRate() const{
	return _taxRate;
    }

    void setTaxRate(const float& _itemTax){
	_taxRate = _itemTax;
    }

    void createListFromFile(const string&);

    float calculateUnitRevenue() const{
	float _unitRevenue = 0.0;
	for (int i = 0; i < _inventory.size(); i++){
		_unitRevenue += _inventory.at(i).getQuantity() * _inventory.at(i).getUnitPrice();
   	}
	return _unitRevenue;
    }

    float calculateTaxRevenue() const{
	float _taxRevenue = 0.0;
	for (int i = 0; i < _inventory.size(); i++){
		if(_inventory.at(i).isTaxable() == true) {
			_taxRevenue += .01 * _taxRate * _inventory.at(i).getQuantity() * _inventory.at(i).getUnitPrice();    
		}

	}
	return _taxRevenue;
    }

    float calculateTotalRevenue() const{
	return calculateUnitRevenue() + calculateTaxRevenue();

    }

    GroceryItem& operator[](const int&);
};

void GroceryInventory::createListFromFile(const string& filename) {
    ifstream input_file(filename);

    if (input_file.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        int quantity;
        float unit_price;
        bool taxable;
        while (input_file >> name >> quantity >> unit_price >> taxable) {
            addEntry(name, quantity, unit_price, taxable);
        }
        input_file.close();
    } else {
        throw invalid_argument("Could not open file " + filename);
    }
}
