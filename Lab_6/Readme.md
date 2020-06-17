МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 6<br/> по дисциплине "Программирование"

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







# Лабораторная работа №6 

## Погодный информер



**Цель:** Закрепить навыки работы многофайловых приложений, изучить способы работы с API web-сервисами, изучить процесс сериализации/десериализации данных.

**Ход работы**

1. API-ключ от openweathermap.org   **4d9f1c0322f3d5bc02bdbdb394aad2f0**

2. Исходный код программы:

   ```c++
   #include <iostream>
   #include<httplib/httplib.h>
   #include<nlohmann/json.hpp>
   #include<fstream>
   using json = nlohmann::json;
   using namespace httplib;
   void gen_response(const Request& req, Response& res)
   {
   		httplib::Client cli("api.openweathermap.org", 80);
   		auto res_ = cli.Get("/data/2.5/forecast?q=Simferopol&APPID=4d9f1c0322f3d5bc02bdbdb394aad2f0&units=metric");
   
   		json j = json::parse(res_->body);
   		std::string str; 
   		std::string str_;
   		std::ifstream file;
   		file.open("informer_template.html");
   		bool check = true;
   		std::string time_str = "00:00:00";
   		int i = 0;
   		int temp = 0;
   		
   			while (!file.eof())
   			{
   				str = "";
   				std::getline(file, str, '\n');
   
   				if (str.find("{city.name}", 0) != -1)
   				{
   					str.insert(str.find("{city.name}", 0), j["city"]["name"].dump());
   					str.erase(str.find("{city.name}", 0), std::size("{city.name}") - 1);
   				}
   				for (i; i < 40; i++)
   				{
   					if (str.find("{list.dt}", 0) != -1 && (check || j["list"][i]["dt_txt"].dump().substr(12, 8) == time_str))
   					{
   						std::cout << j["list"][i]["dt_txt"].dump().substr(12, 8) << std::endl;
   						str.insert(str.find("{list.dt}", 0), j["list"][i]["dt_txt"].dump().substr(1,10));
   						str.erase(str.find("{list.dt}", 0), std::size("{list.dt}") - 1);
   						check = true;
   						temp = i;
   						break;
   					}
   					if (str.find("{list.weather.icon}", 0) != -1 && check)
   					{
   						str.insert(str.find("{list.weather.icon}", 0), j["list"][i]["weather"][0]["icon"]);
   						str.erase(str.find("{list.weather.icon}", 0), std::size("{list.weather.icon}") - 1);
   						break;
   					}
   					if (str.find("{list.main.temp}", 0) != -1 && check)
   					{
   						str.insert(str.find("{list.main.temp}", 0), j["list"][i]["main"]["temp"].dump());
   						str.erase(str.find("{list.main.temp}", 0), std::size("{list.main.temp}") - 1);
   						check = false;
   						temp++;
   						break;	
   					}
   				}
   				i = temp;
   				std::cout << str << std::endl;
   				str_ = str_ + str;
   			}
   		if (res_ && res_->status == 200)
   		{
   			res.set_content(str_, "text/html");
   		}
   		file.close();
   }
   
   int main()
   {
   	Server svr;
   	svr.Get("/", gen_response);
   	svr.listen("localhost", 3000);
   	httplib::Client cli("api.openweathermap.org", 80);
   }
   
   ```

   3.
   
   https://raw.githubusercontent.com/M-850/Task.1_1/master/Lab_6/Weather%20in%20Simferopol.png



**Вывод:** научился работать с функциями find(), substr(), insert() и erase(). Закрепил навыки подключения библиотек к проекту. Изучил способы работы  c API web-сервисами.