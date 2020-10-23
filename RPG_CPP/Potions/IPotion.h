#pragma 
#include "..\IItem.h"
#include "..\Character.h"

class IPotion : public IItem
{
public: IPotion(std::string _name, int _price);
protected: virtual bool PotionAction(Character& CharRef) = 0;
};

