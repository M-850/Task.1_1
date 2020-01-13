// 27. Лут-бокс.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

enum ItemType
{
	SWORD,
	BOW,
	SPELL
};
struct Sword
{
	int damage;
};
struct Bow
{
	int damage;
	int charge_time;
	double distance;
};
enum Element
{
	FIRE,
	AIR,
	WATER,
	SOIL
};
struct Spell
{
	int damage;
	Element element;
	double distance;
};
struct Item
{
	ItemType type;
	union {
		Sword sword;
		Bow bow;
		Spell spell;
	};
	
	Item getRandomItem()
	{
		Item item;
		item.type = ItemType(rand() % 4);
		
		if (item.type == SWORD)
		{
			item.sword.damage = rand() % 1001;
		}
		else if (item.type == BOW)
		{
			item.bow.damage = rand() % 1001;
			item.bow.charge_time = rand() % 1001;
			item.bow.distance = rand() % 1001;
		}
		else
		{
			item.spell.damage = rand() % 1001;
			item.spell.distance = rand() % 1001;
			item.spell.element = Element(rand() % 5);
		}
		return item;
	}
	void printItem(Item loot)
	{
		
		if (loot.type == SWORD)
		{
			std::cout << "---" << "SWORD" << "---" << std::endl;
			std::cout <<"Damege: "<< loot.sword.damage << std::endl;
		}
		else if (loot.type == BOW)
		{
			std::cout << "---" << "BOW" << "---" << std::endl;
			std::cout <<"Damage: "<< loot.sword.damage << std::endl;
			std::cout<<"Charge time: " << loot.bow.charge_time << std::endl;
			std::cout << "Distance: " << loot.bow.distance << std::endl;
		}
		else
		{
			std::cout << "---" << "SPELL" << "---" << std::endl;
			std::cout << "Damage: " << loot.spell.damage << std::endl;
			std::cout << "Element: ";
			loot.spell.element == FIRE ? std::cout << "Fire" :
			loot.spell.element == AIR ? std::cout << "Air" : 
			loot.spell.element == WATER ? std::cout << "Water" :
			std::cout << "Earth";
			std::cout << std::endl;
			std::cout << "Distance: " << loot.spell.distance << std::endl;
		}
	}
};

int main()
{
	srand(time(NULL));
	Item arr[5];
	for (size_t i = 0; i < 5; i++)
	{
		arr[i] = arr[i].getRandomItem();
		arr[i].printItem(arr[i]);
		std::cout << std::endl;
	}
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
