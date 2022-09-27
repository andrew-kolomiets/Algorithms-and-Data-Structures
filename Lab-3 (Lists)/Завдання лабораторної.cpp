	

#include <iostream>
using namespace std;

#define line cout << endl<<"___________________________________________________________________"<< endl;


char string_[100];

// Змінні для збереження адресів відповідних операцій---------------------------------------------------------------------------------------------------

unsigned long int save_start;
unsigned long int save_finish;

//Функціонал списку-------------------------------------------------------------------------------------------------------------------------------------


struct element // структура елементів списка
{
	char data;  //дані
	element* next;    //наступний елемент  (адрес)  
	element* previous;  //попередній елемент (адрес)
};

element *list(char data) //функція, що створює корінь списка
{
	// створення кореня списку який вказуватиме на його початок

	element *current; //поточний елемент списку
	current = new element;  //виділення під поточний елемент пам'яті
	current->data = data; // поле данних
	current->next = NULL; // вказівник на наступний вузол
	current->previous = NULL; // вказівник на попередній вузол
	return current; //результат функції це адреса кореневого елементу списка, цей результат функції ми підставимо далі в функцію додавання елементу списка
}

element * add(element *current, char data) // функція, що додає потрібний елемент та данні
{
	element *new_current, *reserv;//можна заплутатися в передачі адресації див. уважно
	new_current = new element;
	reserv = current->next; // збереження вказівника на наступний вузол
	current->next = new_current; // попередній вузол вказує на створюваний
	new_current->data = data; // збереження поля данних для добавленого елемента
	new_current->next = reserv; // створений вузол  вказує на наступний вузол
	new_current->previous = current; // створений вузол  вказує на попередній вузол
	// цю функцію можна озброїти і вставкою в якийсь кусок списку навіть якщо це початок і кінець, але адрес в нас зміниться 
	if (reserv != NULL)
		reserv->previous = new_current;
	return(new_current);//результат функції є адрессою нового вузла, який необхідний для підстановки в цю саму функцію в разі створення нового елементу
}

void output_list(element* start) //функція виводу елементів
{
	int i = 0;

	// вивід списку починаючи з початкового елементу для перевірки адресації
	while (start != 0)
	{
		cout << endl << "Elements: " << start->previous << " " << start->data << " " << start->next << " address of current element " << start << endl;
		string_[i] = start->data;
		i = i + 1;
		start = start->next;
	}
	line
	cout << endl << string_;
	line
}

int main()
{
	element *start;//start присвоємо в цей вказівник адресу на корінь списку
	element *current;//current поточний елемент списку котрий ми проглядаємо  далі в циклі
	element *finish;//finish кінцевий елемент списку потрібний для перевірки списку на реверс
	char answer; // відповідь на запит, що ми створюємо
	char data; //данні які ми вводим
	
	line

	cout << endl << "Input data in list: " << endl;
	cin >> data;

	current = list(data);
	start = current;
	unsigned long int save_start = (unsigned long int)start; //поточний адрес на початку краще зберегти для обчислення кількості елементів списку, ну і його можна в подальшому змінювати


	for (; ;)
	{
		cout << endl << "Do you want to input new data? (N-for exit)" << endl;
		cin >> answer;
		if (answer =='N')
		{
			finish = current;
			break;
		}
		else
		{
			cout << endl << "Input data in list: " << endl;
			cin >> data;
			current = add(current, data);
		}

	}

	unsigned long int save_finish = (unsigned long int)finish; //поточний адрес на кінець краще зберегти, ну і його можна в подальшому змінювати і використовувати

	line

		output_list(start);

	line
	
	

}

