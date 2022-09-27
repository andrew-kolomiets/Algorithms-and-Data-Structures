
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#define line cout << endl<<"___________________________________________________________________"<< endl; //мені ліньки :)
#define ON 1
#define OFF 0
#define ON_1 1
#define OFF_1 0
#define ON_2 1
#define OFF_2 0

using namespace std;

int save_first_result;
int search = 0;//тригерні данні
int all = 0;// тригерні дані

//Змінні для збереження адресів відповідних операцій----------------------------------------------------------------------------------------------------
unsigned long int save_start;
unsigned long int save_finish;
unsigned long int save_search;
unsigned long int save_address_add;
unsigned long int save_address_delete;
unsigned long int save_delete_head;
unsigned long int save_insert_head;
//Функціонал списку-------------------------------------------------------------------------------------------------------------------------------------

struct element // структура елементів списка
{
	string data;  //дані
	element* next;    //наступний елемент  (адрес)  
	element* previous;  //попередній елемент (адрес)
};

element *list(string data) //функція, що створює корінь списка
{
	// створення кореня списку який вказуватиме на його початок
	element *current; //поточний елемент списку
	current = new element;  //виділення під поточний елемент пам'яті
	current->data = data; // поле данних
	current->next = NULL; // вказівник на наступний вузол
	current->previous = NULL; // вказівник на попередній вузол
	return current; //результат функції це адреса кореневого елементу списка, цей результат функції ми підставимо далі в функцію додавання елементу списка
}

element *search_element(string data, element * start) // функція пошуку елементів списку
{
	element *search_result; // тимчасова змінна для збереження адреси

	search_result = start; // пошук починаємо з початкового елементу
	if (search_result == NULL)
	{
		return NULL;
	}
	while (search_result != 0)
	{

		if (data == search_result->data)
		{ 
			
			save_search = (unsigned long int)search_result; //збережемо такий адрес на майбутнє для видалення чи вставки
			if (search_result!= NULL) 
			{
				return search_result; // функція повертає значення адреси котру знайшла з такими данними, які введені за нашим запитом
			}
			
			
		}
		else
		{
			search_result = search_result->next; // перехід на наступний елемент при неспівпадінні елементів
			if (search_result == 0)
			{
				return NULL;
			}
		}

	}
	
	
}

 element * add(element *current, string data) // функція, що додає потрібний елемент та данні
{
	element *new_current, *reserv;//можна заплутатися в передачі адресації див. уважно
	new_current = new element;
	reserv = current->next; // збереження вказівника на наступний вузол
	current->next = new_current; // попередній вузол вказує на створюваний
	new_current->data = data; // збереження поля данних для добавленого елемента
	new_current->next = reserv; // створений вузол  вказує на наступний вузол
	new_current->previous = current; // створений вузол  вказує на попередній вузол
	// цю функцію можна озброїти і вставкою в якийсь кусок списку навіть якщо це початок і кінець, але адрес в нас зміниться 
	if (reserv!= NULL) 
		reserv->previous = new_current;
	return(new_current);//результат функції є адрессою нового вузла, який необхідний для підстановки в цю саму функцію в разі створення нового елементу
}

 element * add_start(element *start,string data)
 {
	 element *new_start; //новий корінь
	 new_start = new element;//
	 start->previous=new_start;// присвоюємо вказівник на попередній елемент в якості кореня
	 new_start->next = start;
	 new_start->data = data;
	 new_start->previous = NULL;
	 save_start = (unsigned long int)new_start;
	 cout << endl << "Insert start secussesfull." << endl;
	 return(new_start); // новый корень списка
 }

 element  *delete_element(element *delete_element) // функція видалення елемента списка
 {
	 element *previous, *next; // попередній та наступний елемент дивлячись зі сторони видаляємого

	 previous = delete_element->previous; // вузол, що є попереднім delete_element

	 next = delete_element->next; // вузол, що є наступним за delete_element

	 if (previous != NULL)
	 {
		 previous->next = delete_element->next; // переставляємо вказівник
	 }
	 if (next != NULL)
	 {
		 next->previous = delete_element->previous; // переставляємо вказівник 
	 }
	 delete delete_element; // очистимо пам'ять від непотрібного вузла тобто того, що видаляємо;

	 return(previous); // повернути значення попереднього

 }

 element * delete_start(element *start)
 {
	 element *new_start; //новий корінь
	 new_start = start->next;// присвоюємо вказівник на наступний елемент в якості кореня
	 new_start->previous = NULL;
	 delete start;   //вивільнення пам'яті від поточного кореня
	 cout << endl << "Delete all elements is succesfull." << endl; 
	 save_start = (unsigned long int)new_start;
	 return(new_start); // новый корень списка
 }

 
 // Функціонал користувача-----------------------------------------------------------------------------------------------------------------------------

 void delete_similar(element *similar)//видалення елементів подібних з першим в списку
 {
	 unsigned long int ecv = (unsigned long int)similar;

	 element *similar_ = similar;

	 similar_ = similar->next;
	 while (similar_ != NULL)
	 {
		 if ((((element*)ecv)->data)==(similar_->data))
		 {
			 element *previous, *next; // попередній та наступний елемент дивлячись зі сторони видаляємого

			 previous = similar_->previous; // вузол, що є попереднім delete_element

			 next = similar_->next; // вузол, що є наступним за delete_element

			 if (previous != NULL)
			 {
				 previous->next = similar_->next; // переставляємо вказівник
			 }
			 if (next != NULL)
			 {
				 next->previous = similar_->previous; // переставляємо вказівник 
			 }
			 delete similar_; // очистимо пам'ять від непотрібного вузла тобто того, що видаляємо;
			 similar_ = previous->next;
		 }
		 else
		 {
			 similar_ = similar_->next;
		 }

	 }
	
 }

 element *delete_all_list(element* list)//видалення всіх елементів в списку в разі наявності лише одного елементу
 {
	 delete list;

	 cout << endl << "Deliting of all list is sucsessfull." << endl;
	 
	 return NULL;
 }

 element *change_data(element* list)
 {
	 while (list != NULL)
	 {
	 
	 if ((((list->data).length())-1) % 2)// якщо парна кількість символів подвоюємо першу літеру
	 {
		 list->data = (list->data)[0] + list->data;

	 }
	 else
	 {
		 int v = (((list->data).length()) - 1);//якщо непарна кількість літер то видаляємо останнє слово
		 (list->data).erase(v, 1); // видалення символу за індексом, де параметр індекса лівий
	 }

	 list = list->next;

	 }

	 return NULL;
 }

 int size_list(element* list) // розмір списку
 {
	 int result = 0;//кількість елементів списку
	 
	 // захистимося в випадку, якщо вказано не адресу, а щось інше
	 if (!list)
	 {
		 cout << "List is empty.";

	 }

	 // якщо адрес списку вірний, то починаємо підрахунок елементів списку по черзі, тобто від поточного до натупного, від поточного до наступного
	 while (list != NULL)
	 {
		 result++;
		 list = list->next;
	 }
	 save_first_result = result;
	 // тут відбувається вивід кількості елементів підрахованих
	 return result;

 }

 void output_list(element* start, unsigned long int save_start) //функція виводу елементів
 {
	
	 // вивід списку починаючи з початкового елементу для перевірки адресації
	 while (start != 0)
	 {
		 cout << endl << "Elements: " << start->previous << " " << start->data << " " << start->next << " address of current element " << start << endl;
		 start = start->next;
	 }
	 //кількість елементів списку
	 cout << endl << "Number of element list: " << size_list((element*)save_start) << endl; 
 }

 void output_commander()// діалогове вікно типу допомоги в консолі
 {
	 string question;

	 do {
		 cout << endl << "Attention!< All operation work in order of up to down>" << endl;
		 cout << endl << "Do you want work with search elements or all on addrese?(Search | All)" << endl;
		 cin >> question;

		 if (question == "Search")
		 {

			 cout << endl << "All operation which we can use: " << endl;
			 cout << "[Search]-search element;" << endl;
			 cout << "[Add_search]-add element;" << endl;
			 cout << "[Delete_search]-delete element;" << endl;
			 cout << "[Delete_start]-delete start element of the list;" << endl;
			 cout << "[Insert_start]-insert new start element;" << endl;
			 search = search + 1;
		 }
		 else
			 if (question == "All")
			 {
				 cout << endl << "All operation which we can use : " << endl;
				 cout << "[Add_address]-add element;" << endl;
				 cout << "[Delete_address]-delete element;" << endl;
				 cout << "[Delete_start]-delete start element of the list;" << endl;
				 cout << "[Insert_start]-insert new start element;" << endl;
				 all = all + 1;
			 }
			 else
			 {
				 cout << endl << "You input noncorrect command." << endl;
			 }

	 } while (question != "Search" & question != "All");
	 
 }

int main()
{
	element *start;//start присвоємо в цей вказівник адресу на корінь списку
	element *current;//current поточний елемент списку котрий ми проглядаємо  далі в циклі
	element *finish;//finish кінцевий елемент списку потрібний для перевірки списку на реверс
	element *cach_search;//зловлений адрес пошуку
	element *delete_head;//видалення адреси кореня(нової)
	element *add_head;//вставка адреси кореня(нової)
	string answer,ask; // відповідь на запит, що ми створюємо
	string data; //данні які ми вводим

	//cout << endl << "Do you want to enter word separete or all string?(Word|String)" << endl;
	//cin >> answer;
	//while (answer == "Word" || answer == "String")
	//{
	//	if (answer == "Word")
	//	{
	//		line
	//			//введення данних списку
	//			cout << endl << "Input data in list: " << endl;
	//		cin >> data;
	//		current = list(data);
	//		start = current;
	//		unsigned long int save_start = (unsigned long int)start; //поточний адрес на початку краще зберегти для обчислення кількості елементів списку, ну і його можна в подальшому змінювати
	//		for (; ;)
	//		{
	//			cout << endl << "Do you want to input new data? (No)" << endl;
	//			cin >> answer;
	//			if (answer == "No")
	//			{
	//				finish = current;
	//				break;
	//			}
	//			else
	//			{
	//				cout << endl << "Input data in list: " << endl;
	//				cin >> data;
	//				current = add(current, data);
	//			}

	//		}
	//		unsigned long int save_finish = (unsigned long int)finish; //поточний адрес на кінець краще зберегти, ну і його можна в подальшому змінювати і використовувати
	//		line
	//			output_list(start, save_start);//вивід списку на екран в першому своєму вигляді
	//		line
	//	}
	//	else if (answer == "String")
	//	{
	//		stringstream ss;
	//		cin >> data;
	//		ss << data;
	//		string input;
	//		int schothik = 0;
	//		while (ss >> input)
	//		{
	//			if (schothik == 0)
	//			{
	//				current = list(data);
	//				start = current;
	//			}

	//			schothik = schothik + 1;
	//		}

	//		line
	//			//введення данних списку
	//			cout << endl << "Input data in list: " << endl;
	//		cin >> data;
	//		current = list(data);
	//		start = current;
	//		unsigned long int save_start = (unsigned long int)start; //поточний адрес на початку краще зберегти для обчислення кількості елементів списку, ну і його можна в подальшому змінювати
	//		for (; ;)
	//		{
	//			cout << endl << "Do you want to input new data? (No)" << endl;
	//			cin >> answer;
	//			if (answer == "No")
	//			{
	//				finish = current;
	//				break;
	//			}
	//			else
	//			{
	//				cout << endl << "Input data in list: " << endl;
	//				cin >> data;
	//				current = add(current, data);
	//			}

	//		}
	//		unsigned long int save_finish = (unsigned long int)finish; //поточний адрес на кінець краще зберегти, ну і його можна в подальшому змінювати і використовувати
	//		line
	//			output_list(start, save_start);//вивід списку на екран в першому своєму вигляді
	//		line
	//	}
	//	else
	//	{
	//		cout << endl << "You input incorect answer." << endl;
	//	}
	//}

	line 
	//введення данних списку
	cout << endl << "Input data in list: " << endl;
	cin >> data;
	current = list(data);
	start = current;
	unsigned long int save_start = (unsigned long int)start; //поточний адрес на початку краще зберегти для обчислення кількості елементів списку, ну і його можна в подальшому змінювати
	for ( ; ;)
	{
		cout << endl << "Do you want to input new data? (No)" << endl;
		cin >> answer;
		if (answer == "No")
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
	output_list(start,save_start);//вивід списку на екран в першому своєму вигляді
	line
	unsigned int start_time = clock(); // начальное время
	cout << endl  << "On the screen we see the result of work program: " << endl;// реалізація завдання згідно варіанту
	if (save_first_result<2)
	{
		delete_all_list((element*)save_start);
	}// в випадку коли елементів менше за два, тобто один
	else
	{
		change_data((element*)save_start);
	}//зміна перших та останніх символів слів в залежності від парності
	delete_similar((element*)save_start);
	output_list((element*)save_start, save_start);//вивід списку на екран в першому своєму вигляді
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	cout << endl << "Time of work program in seconds (milliseconds need to multiply on 1000) : " << ((float)search_time) / 1000 << endl;

	cout << endl << "Operation on the list is made." << endl;
	line

	/*{
		line
			//тут вже не по програмі йде все
			output_commander();
		line
			//===================================================================================================================================================================================================================================
			// створимо штучний тригер під список визову відповідних команд
			if (search == ON && all == OFF)
			{


				cout << endl << "Work with search data search:" << endl;
				line

					for (; ;)
					{

						cout << endl << "Do you want to enter the opperation? (Yes|No)" << endl;
						cin >> answer;
						if (answer == "Yes")
						{

							for (; ;)
							{
								cout << endl << "Input opperation which we wannt: " << endl;
								cin >> ask;

								if (ask == "Search")
								{

									cout << endl << "Input data which we search: " << endl;
									cin >> data;
									cach_search = search_element(data, (element*)save_start);

									if (cach_search != NULL)
									{
										cout << endl << "Search element has address: " << cach_search << endl;

									}
									else
									{
										cout << endl << "This data in list is absent." << endl;
									}
								}

								if (ask == "Add_search")
								{
									cout << endl << "Input data insert: " << endl;
									cin >> data;
									add((element*)save_search, data);
									cout << endl << "Insertion is sucsesfful." << endl;
									output_list((element *)save_start, save_start);;
								}
								if (ask == "Delete_search")//якысь проблеми тут головне не видаляти початок 
								{
									delete_element((element*)save_search);
									cout << endl << "Deleting is secusesfful." << endl;
									output_list((element *)save_start, save_start);
								}
								if (ask == "Delete_start")
								{


									delete_head = delete_start((element*)save_start);
									save_start = (unsigned long int)delete_head;
									cout << delete_head;

									output_list(delete_head, (unsigned long int)delete_head);
								}
								if (ask == "Insert_start")
								{
									cout << endl << "Input data: " << endl;
									cin >> data;
									add_head = add_start((element *)save_start, data);
									save_start = (unsigned long int)add_head;
									output_list(add_head, (unsigned long int) add_head);

								}
								else if (ask != "Search" & ask != "Delete_search" & ask != "Add_search"& ask != "Delete_start"&ask != "Insert_start")
								{
									cout << endl << "You input incorect name operation." << endl;
								}

								cout << endl << "Do you want to select again?(No)" << endl;
								cin >> ask;
								if (ask == "No")
								{
									break;
								}

							}

						}
						else if (answer == "No")
						{
							cout << endl << "Operation on list is made." << endl;
							break;
						}
						else
						{
							cout << endl << "You input noncorrect information." << endl;
						}
					}

			}
			else
				if (all == ON && search == OFF)
				{

					cout << endl << "Work with  data all:" << endl;
					line
						for (; ;)
						{
							cout << endl << "Do you want to enter the opperation? (Yes|No)" << endl;
							cin >> answer;
							if (answer == "Yes")
							{

								for (; ;)
								{
									cout << endl << "Input opperation which we wannt: " << endl;
									cin >> ask;
									if (ask == "Add")
									{
										unsigned long int address;
										cout << endl << "Input adress in which you want add:" << endl;
										cin >> hex >> address;
										element *address_ = (element*)address;
										cout << endl << "Input data: " << endl;
										cin >> data;
										add(address_, data);
										cout << endl << "Insertion is sucsesfful." << endl;
										output_list(address_, save_start);
									}
									if (ask == "Delete")
									{
										unsigned long int address;

										cout << endl << "Input address which you want delete:" << endl;
										cin >> hex >> address;
										element* address_ = (element*)address;
										delete_element(address_);
										cout << endl << "Deleting is secusesfful." << endl;
										output_list((element*)save_start, save_start);
									}
									if (ask == "Delete_start")
									{
										delete_head = delete_start((element*)save_start);
										save_start = (unsigned long int)delete_head;
										cout << delete_head;
										output_list(delete_head, (unsigned long int)delete_head);
									}
									if (ask == "Insert_start")
									{
										cout << endl << "Input data: " << endl;
										cin >> data;
										add_head = add_start((element *)save_start, data);
										save_start = (unsigned long int)add_head;
										output_list(add_head, (unsigned long int) add_head);
									}

									else if (ask != "Add_address" & ask != "Delete_address"& ask != "Delete_start"&ask != "Insert_start")
									{
										cout << endl << "You input incorect name operation." << endl;
									}

									cout << endl << "Do you want to select again?(No)" << endl;
									cin >> ask;
									if (ask == "No")
									{
										break;
									}

								}

							}
							else if (answer == "No")
							{
								cout << endl << "Operation on list is made." << endl;
								break;
							}
							else
							{
								cout << endl << "You input noncorrect information." << endl;
							}
						}


				}
		//===================================================================================================================================================================================================================================
		line
	}*/ //  // використання інших файлів представлено в функція, якф закоментовано

	return 0;
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
