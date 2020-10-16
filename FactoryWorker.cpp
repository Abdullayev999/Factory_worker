#include<iostream>
#include<iomanip>

using namespace std;

 /*
        ДОМАШНЕЕ ЗАДАНИЕ: Данные о рабочих на заводе*
        1. Создайте две структуры: Factory и Worker
        2. Каждый завод должен содержать массив,который* содержит в себе список рабочих на этом заводе и название завода*.
        3. Каждый рабочий имеет следующие данные:
        3.1 Имя
        3.2 Возраст
        3.3 Специальность
        3.4 Зарплата
        4. Программа должна вывести следующую информацию по каждой
        специальности для каждого завода в отдельности:
        4.1 Название специальности и далее средний возраст и среднюю зарплата
        рабочих.
  */

enum { QuantityWorker = 2 };

struct Worker
{
    char workerName[20];
    unsigned int age;
    char workSpecial[20];
    unsigned int workSalary;
};

struct Factory
{
    char factoryName[20];
    Worker set[QuantityWorker];
};


int main()
{
    double averagSalary, averageAge;
    int quantity;
    cout << "Enter quantity factory\n";
    cin >> quantity;

    Factory** arr = new Factory * [quantity];

    for (size_t i = 0; i < quantity; i++)
    {
        arr[i] = new Factory;

        cout << "Enter name factory\n";
        cin >> arr[i]->factoryName;

        for (size_t j = 0; j < QuantityWorker; j++)
        {
            cout << "Enter worker name\n";
            cin >> arr[i]->set[j].workerName;

            cout << "Enter worker age\n";
            cin >> arr[i]->set[j].age;

            cout << "Enter worker specialization\n";
            cin >> arr[i]->set[j].workSpecial;

            cout << "Enter worker salary\n";
            cin >> arr[i]->set[j].workSalary;
        }
    }

    for (size_t i = 0, b = 1; i < quantity; i++, b++)
    {

        averagSalary = 0, averageAge = 0;
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << "\n" << b << ") " << " Factory name\t";
        cout << arr[i]->factoryName << endl;

        cout << "\n\nName\t\t\tAge\t\t\tSpecial\t\t\tSalary\n";
        for (size_t j = 0; j < QuantityWorker; j++)
        {
            averageAge += arr[i]->set[j].age;
            averagSalary += arr[i]->set[j].workSalary;

            cout << arr[i]->set[j].workerName << "\t\t\t";
            cout << arr[i]->set[j].age << "\t\t\t";
            cout << arr[i]->set[j].workSpecial << "\t\t\t";
            cout << arr[i]->set[j].workSalary << "\n";
        }
        cout << "\nAverage salary of workers  =   " << averagSalary / QuantityWorker << " azn " << endl;
        cout << "Average age of workers     =   " << averageAge / QuantityWorker << " year " << endl;
    }

    for (size_t i = 0; i < quantity; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

}