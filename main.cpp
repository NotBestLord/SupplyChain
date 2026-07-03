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

Product* inputProduct(const Supplier& supplier)
{
	char name[100];
	double cost, weight;
	int minAge;

	cout << "Product name: ";
	cin >> name;
	cout << "Cost: ";
	cin >> cost;
	cout << "Weight: ";
	cin >> weight;
	cout << "Minimum age for use: ";
	cin >> minAge;
	
	return new Product(name, cost, weight, minAge, supplier);
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

// ---------- lookup helpers ---------- 

Product* lookupProduct(TransactionManager& tm) {
	if (tm.getProduct(0) == nullptr)
	{
		cout << "No products available. Add one first.\n";
		return nullptr;
	}
	tm.printProducts();
	char name[100];
	cout << "Enter product name: ";
	cin >> name;
	if (tm.getProduct(name) == nullptr)
	{
		cout << "This product does not exist.\n";
		return nullptr;
	}
	return tm.getProduct(name);
}

Supplier* lookupSupplier(TransactionManager& tm) {
	if (tm.getSupplier(0) == nullptr)
	{
		cout << "No supplier available. Add a factory or store first.\n";
		return nullptr;
	}
	tm.printSuppliers();
	int index;
	cout << "Enter supplier number: ";
	cin >> index;
	if (index < 0 || tm.getSupplier(index) == nullptr)
	{
		cout << "Supplier of this index does not exist.\n";
		return nullptr;
	}
	return tm.getSupplier(index);
}

Factory* lookupFactory(TransactionManager& tm) {
	if (tm.getFactory(0) == nullptr)
	{
		cout << "No factory available. Add one first.\n";
		return nullptr;
	}
	tm.printFactories();
	int index;
	cout << "Enter factory number: ";
	cin >> index;
	if (index < 0 || tm.getFactory(index) == nullptr)
	{
		cout << "Factory of this index does not exist.\n";
		return nullptr;
	}
	return tm.getFactory(index);
}

Store* lookupStore(TransactionManager& tm) {
	if (tm.getStore(0) == nullptr)
	{
		cout << "No store available. Add one first.\n";
		return nullptr;
	}
	tm.printStores();
	int index;
	cout << "Enter store number: ";
	cin >> index;
	if (index < 0 || tm.getStore(index) == nullptr)
	{
		cout << "Store of this index does not exist.\n";
		return nullptr;
	}
	return tm.getStore(index);
}

Consumer* lookupConsumer(TransactionManager& tm) {
	if (tm.getConsumer(0) == nullptr)
	{
		cout << "No consumers available. Add one first.\n";
		return nullptr;
	}
	tm.printConsumers();
	int index;
	cout << "Enter consumer number: ";
	cin >> index;
	if (index < 0 || tm.getConsumer(index) == nullptr)
	{
		cout << "Consumer of this index does not exist.\n";
		return nullptr;
	}
	return tm.getConsumer(index);
}

Customer* lookupCustomer(TransactionManager& tm) {
	if (tm.getCustomer(0) == nullptr)
	{
		cout << "No customers available. Add one first.\n";
		return nullptr;
	}
	tm.printCustomers();
	int index;
	cout << "Enter customer number: ";
	cin >> index;
	if (index < 0 || tm.getCustomer(index) == nullptr)
	{
		cout << "Customer of this index does not exist.\n";
		return nullptr;
	}
	return tm.getCustomer(index);
}

// ---------- menu actions ----------

void addProduct(TransactionManager& tm)
{
	Supplier* supplier = lookupSupplier(tm);
	if (supplier == nullptr)
	{
		return;
	}
	Product* p = inputProduct(*supplier);
    if (tm.getProduct(p->getName()) != nullptr)
    {
        delete p;
        return;
    }
    tm += *p;
	cout << "Product added: " << p << "\n";
}

void addFactory(TransactionManager& tm)
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

	Factory* factory = new Factory(balance, maxProducts, name, maxDeliverers, maxIngredients);
	tm += *factory;
	cout << "Factory added: " << *factory << "\n";
}

void addStore(TransactionManager& tm)
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

	Store* store = new Store(balance, maxProducts, name, maxDeliverers);
	tm += *store;
	cout << "Store added: " << *store << "\n";
}

void addDeliveryMethod(TransactionManager& tm)
{
	Supplier* supplier = lookupSupplier(tm);
	if (supplier == nullptr)
	{
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

void addProductIngredient(TransactionManager& tm)
{
	Product* product = lookupProduct(tm);
	if (product == nullptr)
	{
		return;
	}
	char c;
	while (true)
	{
		cout << "Product: " << product << "\nDo you want to add an ingredient? [y/n]: ";
		cin >> c;
		if (c == 'y')
		{
			cout << "Choose ingredient:";
			Product* ingredient = lookupProduct(tm);
			if (ingredient != nullptr)
			{
				product->addIngredient(ingredient);
			}
		}
		else
		{
			break;
		}
	}
}

void produceInFactory(TransactionManager& tm)
{
	Factory* factory = lookupFactory(tm);
	if (factory == nullptr)
	{
		return;
	}
	Product* p = lookupProduct(tm);
	factory->produce(p);
	tm += *p;
	cout << "Product produced: " << *p << "\n";
}

void sellThroughDelivery(TransactionManager& tm)
{
	Supplier* supplier = lookupSupplier(tm);
	if (supplier == nullptr)
	{
		return;
	}
	Consumer* consumer = lookupConsumer(tm);
	if (consumer == nullptr)
	{
		return;
	}
	DeliveryMethod* dm = supplier->sell(consumer);
	if (dm == nullptr)
	{
		cout << "No delivery method available.\n";
		return;
	}
	dm->deliver(consumer);
	cout << "Delivered.\n";
}

void sellInPerson(TransactionManager& tm)
{
	Store* store = lookupStore(tm);
	if (store == nullptr)
	{
		return;
	}
	Customer* customer = lookupCustomer(tm);
	if (customer == nullptr)
	{
		return;
	}
	store->sellInPerson(*customer);
	cout << "Sale complete.\n";
}

// ---------- main ----------

int main()
{
	Date d1(1,2,1980);
	Customer p1("gogo", eGender::Male, d1, 176);
	Customer p2("gogo", eGender::Male, Date(1,1,1980), 176);

	TransactionManager tm;

	int choice = -1;
	while (choice != 0)
	{
		cout << "\n===== Supply & Transaction System =====\n";
		cout << "1. Add product\n";
		cout << "2. Add factory\n";
		cout << "3. Add store\n";
		cout << "4. Add delivery method\n";
		cout << "5. Add customer\n";
		cout << "6. Add product ingredients\n";
		cout << "7. Produce in factory\n";
		cout << "8. Sell through delivery\n";
		cout << "9. Sell in person\n";
		cout << "10. Print all\n";
		cout << "0. Exit\n";
		cout << "Choice: ";
		cin >> choice;
		try
		{
			switch (choice)
			{
			case 1:
				addProduct(tm);
				break;
			case 2:
				addFactory(tm);
				break;
			case 3:
				addStore(tm);
				break;
			case 4:
				addDeliveryMethod(tm);
				break;
			case 5:
				addCustomer(tm);
				break;
			case 6:
				addProductIngredient(tm);
				break;
			case 7:
				produceInFactory(tm);
				break;
			case 8:
				sellThroughDelivery(tm);
				break;
			case 9:
				sellInPerson(tm);
				break;
			case 10:
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