// Погодный информер.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
