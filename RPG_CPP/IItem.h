#pragma once
#include<string>
#include<iostream>

class IItem
{
protected: int Price;
protected: std::string Name;

public: IItem(std::string _name, int _price);
public: virtual void PrintItemProps() = 0;
public: std::string GetItemName();
public: virtual std::unique_ptr<IItem> clone() const = 0;
public: virtual IItem* cpy() = 0;
public: void SetName(std::string name);
};

