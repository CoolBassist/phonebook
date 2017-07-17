#include <iostream>
#include <string>
#include <list>
#include <fstream>

struct Entry{
    std::string name;
    std::string number;
};

class Phonebook{
    private:
        std::list<Entry> phonebook;
    public:
        void read_phonebook();
        void store_entry(Entry entry);
        void add_entry();
        Entry create_entry();
        void view_entry();
        void print_phonebook();
} phonebook;

std::string get_input()
{
    std::string data;
    std::getline (std::cin,data);
    return data;
}

void Phonebook::read_phonebook()
{
    std::ifstream file ("file.csv");
    std::string data;
    if(!file)
    {
        std::cout << "phone book not found\n";
    }else{
        Entry entry;

        while ( file.good() )
        {
            getline (file, data, ',');
            entry.name = data;
            getline (file, data, ',');
            entry.number = data;
            phonebook.push_back(entry);
        }
    }
}

void Phonebook::store_entry(Entry entry)
{
    std::ofstream file ("file.csv", std::ios::app);
    if(!file)
    {
        std::cout << "entry could not be stored\n";
    }else{
        file << entry.name << "," << entry.number << ",";
    } 

}

void Phonebook::add_entry()
{
    Entry entry;
    entry = create_entry();
    store_entry(entry);
    phonebook.push_back(entry);
}

Entry Phonebook::create_entry()
{
    std::string name;
    std::string number;
    std::cout << "Name: ";
    name = get_input();
    std::cout << "Number: ";
    number = get_input();
    Entry entry;
    entry.name = name;
    entry.number = number;
    return entry;
}

void Phonebook::view_entry()
{
    std::string name;
    std::cout << "Enter name: ";
    name = get_input();
    for(Entry const& e : phonebook)
    {
        if(name == e.name)
        {
            std::cout << e.name << "\t" << e.number << '\n';
        }
    }
}

void Phonebook::print_phonebook()
{
    std::cout << "printing phonebook\n";
    for(Entry const& e : phonebook)
    {
        std::cout << e.name << "\t" << e.number << '\n';
    }
}

int main()
{
    phonebook.read_phonebook();
    while(1)
    {
        char com;
        std::cout << ">> ";
        std::cin >> com;
        std::cin.ignore();
        switch(com){
            case 'e' : return 0; break;
            case 'a' : phonebook.add_entry(); break;
            case 'v' : phonebook.view_entry(); break;
            case 'p' : phonebook.print_phonebook(); break;
            default : std::cout << "\nplease type a(add entry), v(view entry), p(print phonebook) or e(exit)" << std::endl;
        }
    }
    return 0;
}

