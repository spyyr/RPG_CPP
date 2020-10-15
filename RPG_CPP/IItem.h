#pragma once
#include<string>
#include<iostream>

class IItem
{
protected: int Price;
protected: std::string Name;

public: IItem(std::string _name, int _price);
public: virtual void PrintItemProps() = 0;
};

