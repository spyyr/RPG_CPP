#include "Human.h"

const std::map<int, int> Human::LevelingExpScheme = {
	{1,20},
	{2,50},
	{3, 100},
	{4, 200},
	{5, 400},
	{6, 1000}
};

Human::Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance):Character(_name, _hp, 1, 7, _defense, _critChance)
{	
	this->MP = _mp;	
	this->MaxMP = _mp;
	this->LvlExpBound = LevelingExpScheme.at(_lvl);
	if (_lvl == 1)
		this->Exp = 0;
	else
	{
		this->Exp = LevelingExpScheme.at(_lvl - 1);
		for (int i = 1; i < _lvl; i++)
		{
			this->LevelUp();
		}		
	}
	this->EqAddAttack = 0;
	this->EqAddDefense = 0;
	this->Gold = 0;
	this->Exp = 0;
}

Human::Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance, int _exp, int _gold):Human(_name, _hp, _mp, _lvl, _defense, _critChance)
{
	this->Exp += _exp;
	this->Gold = _gold;
	this->CheckCondition();
}

void Human::PrintCharacterProps() 
{
	std::cout << "Name: " << this->Name << '\n' <<
		"HP: " << this->HP << '/' << this->MaxHP << '\n' <<
		"MP: " << this->MP << '/' << this->MaxMP << '\n' <<
		"Attack: " << this->Attack << " + (" << this->EqAddAttack << ")" << '\n' <<
		"Defense: " << this->Defense << " + (" << this->EqAddDefense << ")" << '\n' <<
		"Crit chance: " << this->CritChance << '%' << " + " << this->EqAddCritChance << '%' << '\n' <<
		"Lvl: " << this->Lvl << '\n' <<
		"Exp: " << this->Exp << '/' << this->LvlExpBound << '\n' <<
		"Gold: " << this->Gold << '\n' << '\n';
}

void Human::CheckCondition()
{
	Character::CheckCondition();
	if (this->Exp > this->LvlExpBound)
		this->LevelUp();
}

void Human::Dead() 
{
	/*system("cls");	
	std::cout << this->Name << " died!" << '\n'
		<< "This is the end of your story... \n";
	this->IsDead = true;*/
}

void Human::GotExp(int _givenExpPoints)
{
	this->Exp += _givenExpPoints;
}

void Human::GotGold(int _givenGold)
{
	this->Gold += _givenGold;
}

void Human::LevelUp()
{
	ScreenPrint::Print("Level UP! " + std::to_string(this->Lvl) + "->" + std::to_string((this->Lvl) + 1), 14, 1, 0, 1);
	system("PAUSE");
	this->Lvl++;
	this->Attack += 2;	
	this->MaxHP += 10; //change healing and hp maxing to distinct methods, same with MP 
	this->Heal(10);
	this->MP += 5;
	this->MaxMP += 5;
	
	if (this->Defense + 1 <= this->MaxDef)
		this->Defense += 1;
	else
		this->Defense = this->MaxDef;

	this->LvlExpBound = this->LevelingExpScheme.at(this->Lvl);
}

int Human::GetLevel()
{
	return this->Lvl;
}

void Human::Equip(IItem* itemToEquip)
{
	std::string EqType = typeid(*itemToEquip).name();	
	if (typeid(*itemToEquip) == typeid(Weapon))//(EqType == "class Weapon")
	{
		this->EqAddAttack = static_cast<Weapon*>(itemToEquip)->GetAttack(); //operator should be +=, later write method uneqip which should decrease EqAddAttack value
		this->EqAddCritChance = static_cast<Weapon*>(itemToEquip)->GetAdditionalCritChance();
		Weapon* weaponPtr = static_cast<Weapon*>(itemToEquip);
		this->HandsEq[0] = new Weapon(*weaponPtr);
	}

	if (EqType == "class Armor") //those if's should be switches, equip action for weapon or armor should be distinct protected methods
	{
		this->ArmorChest = static_cast<Armor*>(itemToEquip);
		this->EqAddDefense = static_cast<Armor*>(itemToEquip)->GetArmorValue();
	}
	ScreenPrint::Print(itemToEquip->GetItemName() + " equipped!", 14, true, false, true);


}

int Human::CalculateEqAttack()
{
	return 0;
}

IItem* Human::GetHandsEquipment(short index)
{
	if (this->HandsEq[index] == NULL)
		return this->HandsEq[0];// nullptr;
	else
	{		
		return HandsEq[index];// this->HandsEq[index];
	}
}

double Human::GetEqAddAttack()
{
	return this->EqAddAttack;
}

double Human::GetEqAddCritChance()
{
	return this->EqAddCritChance;
}

double Human::GetWholeAttackValue()
{
	return Character::GetWholeAttackValue() + this->EqAddAttack;
}

double Human::GetWholeCritChance()
{
	return Character::GetWholeCritChance() + this->EqAddCritChance;
}

double Human::GetEqAddDefense()
{
	return this->EqAddDefense;
}

double Human::GetWholeDefenseValue()
{
	return Character::GetWholeDefenseValue() + this->EqAddDefense;
}

Armor* Human::GetArmorChest()
{
	return static_cast<Armor*>(this->ArmorChest);
}

bool Human::AddToBackpack(IItem* item)
{
	if (this->Backpack.size() < this->MaxBackpackItems)
	{
		//auto tmp = *item;
		//auto it = item->clone();
		/*IItem& x = *item;
		std::unique_ptr<IItem> y = x.clone();*/
		auto ptr = item->clone();
		this->Backpack.push_back(ptr.get()); //item should be copied, maybe using overriden "clone" method. Now only pointer to item is stored. 
		ptr.release();
		return true;
	}
	else
	{
		ScreenPrint::Print("You cannot add anymore items to backpack. Please sell or drop some items", 4, 1, 0, 1);
		return false;
	}
}

bool Human::RemoveFromBackpack(int index)
{
	delete this->Backpack.at(index);
	this->Backpack.erase(this->Backpack.begin()+index, this->Backpack.begin()+index+1);

	return true;
}

void Human::PrintBackpack()
{
	ScreenPrint::Print("Items in backpack: " + std::to_string(this->Backpack.size()) + '/' + std::to_string(this->MaxBackpackItems), 13, 1, 0, 1);
	//ScreenPrint::Print(std::string("Left","Right"), 12, 11, 1, 1);
	for(auto item: this->Backpack)
	{
		item->PrintItemProps();
		std::cout << typeid(*item).name() << '\n';
	}
}

bool Human::UsePotion(IPotion* Potion)
{
	Potion->PotionAction(*this);
	return true;
}
