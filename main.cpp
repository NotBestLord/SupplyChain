#include <iostream>
#include "transaction_manager.h"
#include "product.h"
#include "factory.h"
#include "store.h"
#include "delivery_vehicle.h"
#include "delivery_guy.h"
#include "customer.h"
#include "date.h"

using namespace std;

// ---------- input helpers ----------

Product* inputProduct(const Supplier* supplier)
{
	Product p(supplier);
    cout << "Enter New Product: ";
    cin >> p;
	return new Product(p);
}

Date inputDate()
{
	Date date;
	cout << "Enter Birth date (dd mm yyyy): ";
	cin >> date;
	return date;
}

eGender inputGender()
{
	int g;
	cout << "Gender (0=Male, 1=Female, 2=Other): ";
	cin >> g;
	while (g < 0 || g > 2)
	{
		cout << "Invalid. Enter 0, 1 or 2: ";
		cin >> g;
	}
	return static_cast<eGender>(g);
}

// ---------- menu actions ----------

void addProduct(TransactionManager& tm, const Supplier* supplier)
{
	Product* p = inputProduct(supplier);
    if (tm.getProduct(p->getName()) != nullptr)
    {
        delete p;
        return;
    }
    tm += *p;
	cout << "Product added: " << *p << "\n";
}

void addFactory(TransactionManager& tm, Factory*& outFactory)
{
	char name[100];
	double balance;
	int maxProducts, maxDeliverers, maxIngredients;

	cout << "Factory name: ";
	cin >> name;
	cout << "Balance: ";
	cin >> balance;
	cout << "Max supply: ";
	cin >> maxProducts;
	cout << "Max deliverers: ";
	cin >> maxDeliverers;
	cout << "Max ingredients: ";
	cin >> maxIngredients;

	outFactory = new Factory(balance, maxProducts, name, maxDeliverers, maxIngredients);
	tm += *outFactory;
	cout << "Factory added: " << *outFactory << "\n";
}

void addStore(TransactionManager& tm, Store*& outStore)
{
	char name[100];
	double balance;
	int maxProducts, maxDeliverers;

	cout << "Store name: ";
	cin >> name;
	cout << "Balance: ";
	cin >> balance;
	cout << "Max supply: ";
	cin >> maxProducts;
	cout << "Max deliverers: ";
	cin >> maxDeliverers;

	outStore = new Store(balance, maxProducts, name, maxDeliverers);
	tm += *outStore;
	cout << "Store added: " << *outStore << "\n";
}

void addDeliveryMethod(Supplier* supplier)
{
	if (!supplier)
	{
		cout << "No supplier available. Add a factory or store first.\n";
		return;
	}
	cout << "Delivery method type (0=Vehicle, 1=DeliveryGuy): ";
	int choice;
	cin >> choice;

	if (choice == 0)
	{
		int maxProducts;
		cout << "Max products to carry: ";
		cin >> maxProducts;
		DeliveryVehicle* v = new DeliveryVehicle(maxProducts);
		*supplier += v;
		cout << "Delivery vehicle added.\n";
	}
	else if (choice == 1)
	{
		char name[100];
		cout << "Courier name: ";
		cin >> name;
		eGender gender = inputGender();
		Date bd = inputDate();
		int maxProducts;
		cout << "Max products to carry: ";
		cin >> maxProducts;
		DeliveryGuy* d = new DeliveryGuy(name, gender, bd, maxProducts);
		*supplier += d;
		cout << "Delivery guy added.\n";
	}
	else
	{
		cout << "Invalid choice.\n";
	}
}

void addCustomer(TransactionManager& tm)
{
	char name[100];
	double balance;

	cout << "Customer name: ";
	cin >> name;
	eGender gender = inputGender();
	Date bd = inputDate();
	cout << "Balance: ";
	cin >> balance;

	Customer* c = new Customer(name, gender, bd, balance);
	tm += *c;
	cout << "Customer added: " << *c << "\n";
}

void produceInFactory(Factory* factory, TransactionManager& tm)
{
	if (!factory)
	{
		cout << "No factory available. Add a factory first.\n";
		return;
	}
	Product* p = inputProduct(factory);
	factory->produce(p);
	tm += *p;
	cout << "Product produced: " << *p << "\n";
}

void sellThroughDelivery(const TransactionManager& tm, Supplier* supplier)
{
	if (!supplier)
	{
		cout << "No supplier available.\n";
		return;
	}
	tm.printConsumers();
	cout << "Select consumer index: ";
	int index;
	cin >> index;
	const Consumer* consumer = tm.getConsumer(index);
	if (!consumer)
	{
		cout << "Invalid index.\n";
		return;
	}
	DeliveryMethod* dm = supplier->sell(const_cast<Consumer*>(consumer));
	if (!dm)
	{
		cout << "No delivery method available.\n";
		return;
	}
	dm->deliver(const_cast<Consumer*>(consumer));
	cout << "Delivered.\n";
}

void sellInPerson(Store* store, const TransactionManager& tm)
{
	if (!store)
	{
		cout << "No store available. Add a store first.\n";
		return;
	}
	tm.printConsumers();
	cout << "Select customer index: ";
	int index;
	cin >> index;
	const Consumer* consumer = tm.getConsumer(index);
	Customer* customer = dynamic_cast<Customer*>(const_cast<Consumer*>(consumer));
	if (!customer)
	{
		cout << "Invalid index or not a customer.\n";
		return;
	}
	store->sellInPerson(*customer);
	cout << "Sale complete.\n";
}

// ---------- main ----------

int main()
{
	TransactionManager tm;

	Factory* activeFactory = nullptr;
	Store* activeStore = nullptr;

	int choice = -1;
	while (choice != 0)
	{
		cout << "\n===== Supply & Transaction System =====\n";
		cout << "1. Add product\n";
		cout << "2. Add factory\n";
		cout << "3. Add store\n";
		cout << "4. Add delivery method\n";
		cout << "5. Add customer\n";
		cout << "6. Produce in factory\n";
		cout << "7. Sell through delivery\n";
		cout << "8. Sell in person\n";
		cout << "9. Print all\n";
		cout << "0. Exit\n";
		cout << "Choice: ";
		cin >> choice;
		try
		{
			switch (choice)
			{
			case 1:
				addProduct(tm, activeFactory);
				break;
			case 2:
				addFactory(tm, activeFactory);
				break;
			case 3:
				addStore(tm, activeStore);
				break;
			case 4:
			{
				cout << "Assign to (0=Factory, 1=Store): ";
				int s;
				cin >> s;
				if (s == 0)
				{
					addDeliveryMethod(activeFactory);
				}
				else
				{
					addDeliveryMethod(activeStore);
				}
				break;
			}
			case 5:
				addCustomer(tm);
				break;
			case 6:
				produceInFactory(activeFactory, tm);
				break;
			case 7:
			{
				cout << "Sell from (0=Factory, 1=Store): ";
				int s;
				cin >> s;
				if (s == 0)
				{
					sellThroughDelivery(tm, activeFactory);
				}
				else
				{
					sellThroughDelivery(tm, activeStore);
				}
				break;
			}
			case 8:
				sellInPerson(activeStore, tm);
				break;
			case 9:
				cout << tm;
				break;
			case 0:
				cout << "Goodbye.\n";
				break;
			default:
				cout << "Invalid choice. Please enter 0-9.\n";
				break;
			}
		}
		catch (const std::invalid_argument& e)
		{
			cout << "Invalid input: " << e.what() << "\n";
		}
		catch (const std::overflow_error& e)
		{
			cout << "Capacity error: " << e.what() << "\n";
		}
		catch (const std::exception& e)
		{
			cout << "Error: " << e.what() << "\n";
		}
	}

	return 0;
}