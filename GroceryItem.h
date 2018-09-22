#pragma once

#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

public:
    GroceryItem(){
	_name = "";
	_quantity = 0;
	_unitPrice = 0.0;
	_taxable = false;
    }
    GroceryItem(const string& _itemName, const int& _itemQuantity, const float& _itemPrice, const bool& _itemTaxable){
	_name = _itemName;
	_quantity = _itemQuantity;
	_unitPrice = _itemPrice;
	_taxable = _itemTaxable;
    }

    string getName() const{
	return _name;
    }
    void setName(const string& _itemName){
    	_name = _itemName;
    }
    int getQuantity() const{
	return _quantity;
    }
    void setQuantity(const int& _itemQuantity){
	_quantity = _itemQuantity;
    }
    float getUnitPrice() const{
	return _unitPrice;
    }
    void setUnitPrice(const float& _itemPrice){
	_unitPrice = _itemPrice;
    }
    bool isTaxable() const{
	return _taxable;
    }
    void setTaxable(const bool& _itemTaxable){
	_taxable = _itemTaxable;
    }
};
