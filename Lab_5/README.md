МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 5<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы 191(2)  
Михерский Михаил Ростиславович
направления подготовки 09.03.04 "Программная инженерия"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2020

# Лабораторная работа №5 Работа с текстовыми файлами

**Цель:**

1. Научиться работать с текстовыми файлами;

2. Закрепить навыки работы со структурами. 

   #### Ход работы

   1.

   ```c++
   #include<iostream>
   #include<string>
   #include<fstream>
   #include<vector>
   #include<math.h>
   double finding_digits(std::string str)// функция ищет первое число в строке и преобразует его в double
   {
   	double result = 0;
   	int counter = 0;
   	bool check = false;
   	bool check_point = false;
   	for (size_t i = 0; str[i]; i++)
   	{
   		switch (str[i])
   		{
   		case'0':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   			}
   			else
   			{
   				result = result * 10;
   			}
   			break;
   		}
   		case'1':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 1 / pow(10, counter);
   			}
   			else 
   			{
   				result = result * 10 + 1;
   			}
   			break;
   		}
   		case'2':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 2 * 1 / pow(10, counter);
   			}
   			else 
   			{
   				result = result * 10 + 2;
   			}
   			break;
   		}
   		case'3':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 3 * 1 / pow(10, counter);
   			}
   			else
   			{
   				result = result * 10 + 3;
   			}
   			break;
   		}
   		case'4':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 4 * 1 / pow(10, counter);
   			}
   			else
   			{
   				result = result * 10 + 4;
   			}
   			break;
   		}
   		case'5':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 5 * 1 / pow(10, counter);
   			}
   			else
   			{
   				result = result * 10 + 5;
   			}
   			break;
   		}
   		case'6':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 6 * 1 / pow(10, counter);
   			}
   			else
   			{
   				result = result * 10 + 6;
   			}
   			break;
   		}
   		case'7':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 7 * 1 / pow(10, counter);
   			}
   			else
   			{
   				result = result * 10 + 7;
   			}
   			break;
   		}
   		case'8':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 8 * 1 / pow(10, counter);
   			}
   			else
   			{
   				result = result * 10 + 8;
   			}
   			break;
   		}
   		case'9':
   		{
   			check = true;
   			if (check_point)
   			{
   				counter++;
   				result += 9 * 1 / pow(10, counter);
   			}
   			else 
   			{
   				result = result * 10 + 9;
   			}
   			break;
   		}
   		case'.':
   		{
   			check_point = true;
   			break;
   		}
   		default:
   		{
   			if (check) 
   			{
   				return result;
   			}
   			break;
   		}
   		}
   
   	}
   	if (check)
   	{
   		return result;
   	}
   	else
   	{
   		return -1;
   	}
   	
   }
   enum Sex
   {
   	M,
   	F,
   	SEX_UNKNOWN
   };
   enum Embarked
   {
   	CHERBOURG,
   	SOUTHAMPTON,
   	QUEENSTOWN,
   	EMB_UNKNOWN
   };
   enum Pclass
   {
   	UNKNOWN,
   	HIGH,
   	AVERAGE,
   	LOW
   };
   
   struct Passenger
   {
   	int PassengerId = 0;//индетификатор пассажира
   	bool Survived;// выжил или нет
   	Pclass Pclass;// социально-экономический статус 1.Высокий 2.Средний 3.Низкий
   	std::string Name;//имя
   	Sex Sex;//пол
   	int Age;//возраст 
   	int SibSp;//кол-во родствеников 2-го порядка (муж,жена,братья)
   	int Parch;//кол-во родствеников 1-го порядка(мать, отец, дети)
   	std::string Ticket;//номер билета
   	double Fare;//цена билета
   	std::string Cabin;//каюта 
   	Embarked Embarked;//порт посадки 
   };
   int main()
   {
   	setlocale(LC_ALL, "Russian");
   	std::vector <Passenger> passenger_list;
   	std::ifstream file;
   	file.open("train.csv");
   	Passenger alone;
   	bool check = false;
   	if (file.is_open())
   	{
   		std::cout << "Файл усешно открыт" << std::endl;
   		while (!file.eof())
   		{	
   			if (!check)
   			{
   				file.ignore(100, '\r');
   			}
   			check = true;
   			std::string id;
   			std::getline(file, id, ',');
   			alone.PassengerId = finding_digits(id);
   
   			std::string sur;
   			std::getline(file, sur, ',');
   			alone.Survived = finding_digits(sur);
   
   			std::string status;
   			std::getline(file, status, ',');
   			finding_digits(status) >= 1 ? alone.Pclass = static_cast <Pclass>(static_cast <int>(finding_digits(status))) : alone.Pclass = UNKNOWN;
   			
   			std::string name, name_2;
   			while (file.peek() == '"')
   			{
   				file.ignore(100, '"');
   				std::getline(file, name, '"');
   				
   				if (file.peek()=='"')
   				{
   					
   					std::getline(file, name_2, ',');
   					name_2.erase (name_2.size()-1,1);
   					alone.Name = name + name_2;
   				}
   				else
   				{
   					file.ignore(100, ',');
   					alone.Name = name;
   				}
   				int temp = -1;
   				int counter = 0;
   				for (size_t i = 0; alone.Name[i]; i++)
   				{
   					if (alone.Name[i] == '"')
   					{
   						counter++;
   						temp = i;
   					}
   				}
   				if (counter % 2 != 0)
   				{
   					alone.Name.erase(temp, 1);
   				}
   			}
   
   			std::string sex;
   			std::getline(file, sex, ',');
   			sex == "female" ? alone.Sex = F : sex == "male" ? alone.Sex = M : alone.Sex = SEX_UNKNOWN;
   			
   			std::string age;
   			std::getline(file, age, ',');
   			alone.Age = finding_digits(age);// если Age равен -1 значит возраст неизвестен
   			
   			std::string sib_sp;
   			std::getline(file, sib_sp, ',');
   			alone.SibSp = finding_digits(sib_sp);// елси SibSp равен -1 значит кол-во родствеников 2-го порядка (муж,жена,братья,сёстры) неизвестно
   			
   			std::string parch;
   			std::getline(file, parch, ',');
   			alone.Parch = finding_digits(parch);// елси Parch равен -1 значит кол-во родствеников 1-го порядка (мать, отец, дети) неизвестно
   			
   			std::getline(file, alone.Ticket, ',');
   			
   			std::string fare;
   			std::getline(file, fare, ',');
   			alone.Fare = finding_digits(fare);
   			
   			std::getline(file, alone.Cabin, ',');
   			
   			std::string embarked;
   			std::getline(file, embarked, '\r');
   			
   			if (embarked == "C")
   			{
   				alone.Embarked = CHERBOURG;
   			}
   			else if(embarked == "S")
   			{
   				alone.Embarked = SOUTHAMPTON;
   			}
   			else if(embarked == "Q")
   			{
   				alone.Embarked = QUEENSTOWN;
   			}
   			else
   			{
   				alone.Embarked = EMB_UNKNOWN;
   			}
   			passenger_list.push_back(alone);
   			
   		}
   	}
   	else
   	{
   		std::cout << "Файл не открыт" << std::endl;
   		exit(1);
   	}
   	file.close();
   	int in_total_survivor{ 0 }, class_1_survivor{ 0 }, class_2_survivor{ 0 }, class_3_survivor{ 0 };
   	int  M_survivor{ 0 }, F_survivor{ 0 };
   	double average_Age{ 0 }, M_average_Age{ 0 }, F_average_Age{ 0 };
   	int counter{ 0 }, counter_M{ 0 }, counter_F{ 0 };
   	int C{ 0 }, S{ 0 }, Q{ 0 };
   	std::vector <int> minor_passengers;
   
   	for (size_t i = 0; i < passenger_list.size(); i++)
   	{
   		if (passenger_list[i].Survived)
   		{
   			in_total_survivor++;
   			if (passenger_list[i].Pclass == HIGH)
   			{
   				class_1_survivor++;
   			}
   			else if (passenger_list[i].Pclass == AVERAGE)
   			{
   				class_2_survivor++;
   			}
   			else if (passenger_list[i].Pclass == LOW)
   			{
   				class_3_survivor++;
   			}
   			if(passenger_list[i].Sex == M)
   			{
   				M_survivor++;
   			}
   			else if (passenger_list[i].Sex == F)
   			{
   				F_survivor++;
   			}
   		}
   		if (passenger_list[i].Age != -1)
   		{
   			counter++;
   			average_Age += passenger_list[i].Age;
   			if (passenger_list[i].Sex == F)
   			{
   				counter_F++;
   				F_average_Age += passenger_list[i].Age;
   			}
   			else if (passenger_list[i].Sex == M)
   			{
   				counter_M++;
   				M_average_Age += passenger_list[i].Age;
   			}
   		}
   		if (passenger_list[i].Embarked == CHERBOURG)
   		{
   			C++;
   		}
   		else if (passenger_list[i].Embarked == SOUTHAMPTON)
   		{
   			S++;
   		}
   		else if (passenger_list[i].Embarked == QUEENSTOWN)
   		{
   			Q++;
   		}
   		if (passenger_list[i].Age < 18 && passenger_list[i].Age != -1)
   		{
   			minor_passengers.push_back(passenger_list[i].PassengerId);
   		}
   	}
   	average_Age /= counter;
   	M_average_Age /= counter_M;
   	F_average_Age /= counter_F;
   	std::ofstream file_tally;
   	file_tally.open("tally.txt");
   	if (file_tally.is_open())
   	{
   		std::cout << "Файл открыт" << std::endl;
   		file_tally << "Общее число выживших: " << in_total_survivor << '\n';
   		file_tally << "Число выживших из 1 класса: " << class_1_survivor << '\n';
   		file_tally << "Число выживших из 2 класса: " << class_2_survivor << '\n';
   		file_tally << "Число выживших из 3 класса: " << class_3_survivor << '\n';
   		file_tally << "Количество выживших женщин: " << F_survivor << '\n';
   		file_tally << "Количество выживших мужчин: " << M_survivor << '\n';
   		file_tally << "Средний возраст пассажира: " << average_Age << '\n';
   		file_tally << "Средний возраст пассажира женского пола: " << F_average_Age << '\n';
   		file_tally << "Средний возраст пассажира мужского пола: " << M_average_Age << '\n';
   		file_tally << "Штат, в котором село больше всего пассажиров: " << (C > S ? C > Q ? "Cherbourg" : "Queenstown" : S > Q ? "Southampton" : "Queenstown") << '\n';
   		file_tally << "Список идентификаторов несовершеннолетних (младше 18) пассажиров: ";
   		for (size_t i = 0; i < minor_passengers.size(); i++)
   		{
   			if (minor_passengers.size() - i == 1)
   			{
   				file_tally << minor_passengers[i] << ".";
   			}
   			else
   			{
   				file_tally << minor_passengers[i] << ", ";
   
   			}
   
   		}
   	}
   	else
   	{
   		std::cout << "Файл не открыт!" << std::endl;
   		exit(1);
   	}
   	file_tally.close();
   }
   ```

*Код программы для решение заданной задачи* 

Результат работы программы представлен ниже в виде таблицы.

2.

<table>
<tr><th> Характеристика </th><th>Результат</th></tr> 
<tr><td>Общее число выживших:</td><td>342</td></tr>
<tr><td>Число выживших из 1 класса:</td><td>136</td></tr>
<tr><td>Число выживших из 2 класса:</td><td>87</td></tr>
<tr><td>Число выживших из 3 класса:</td><td>119</td></tr>
<tr><td>Количество выживших женщин:</td><td>233</td></tr>
<tr><td>Количество выживших мужчин:</td><td>109</td></tr>
<tr><td>Средний возраст пассажира:</td><td>29.6793</td></tr>
<tr><td>Средний возраст пассажира женского пола:</td><td>27.9042</td></tr>
<tr><td>Средний возраст пассажира мужского пола:</td><td>30.702</td></tr>
<tr><td>Штат, в котором село больше всего пассажиров:</td><td>Southampton</td></tr>
<tr><td>Список идентификаторов несовершеннолетних (младше 18) пассажиров:</td><td>8, 10, 11, 15, 17, 23, 25, 40, 44, 51, 59, 60, 64, 69, 72, 79, 85, 87, 112, 115, 120, 126, 139, 148, 157, 164, 165, 166, 172, 173, 183, 184, 185, 194, 206, 209, 221, 234, 238, 262, 267, 279, 283, 298, 306, 308, 330, 334, 341, 349, 353, 375, 382, 387, 390, 408, 420, 434, 436, 446, 447, 449, 470, 480, 481, 490, 501, 505, 531, 533, 536, 542, 543, 550, 551, 575, 619, 635, 643, 645, 684, 687, 690, 692, 721, 722, 732, 747, 751, 752, 756, 765, 778, 781, 782, 788, 789, 792, 803, 804, 814, 820, 825, 828, 831, 832, 842, 845, 851, 853, 854, 870, 876.</td></tr>
</table>

*Таблица 1. Рассчитанные характеристики 

3.Ссылка на файл  с рассчитанными характеристиками 

https://github.com/M-850/Task.1_1/blob/master/Lab_5/Лабараторная_5_Работа%20с%20текстовыми%20файлами/tally.txt

**Вывод:**  изучил основные принципы записи в файл и чтения из него, закрепил навыки работы со структурами и перечислениями.



