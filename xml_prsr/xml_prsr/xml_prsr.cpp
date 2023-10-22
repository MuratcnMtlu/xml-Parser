#include "pugixml.hpp"
#include <iostream>
#include <vector>

void ft_printParam(size_t index, size_t mode);
void ft_dataInput();
const std::string PATH = "C:/Users/murat/Desktop/deneme.xml";
std::size_t mode{};
std::size_t index{};

struct st_student //vector
{
    std::string name;
    std::string surname;
    int number; 
};

struct st_child
{
    std::string childElement;
    int childCount;
};

std::vector<st_student> students;
st_child ch;
//std::vector<std::string> childElements;

int main()
{
    pugi::xml_document doc;
    ft_dataInput();
    if (doc.load_file(PATH.c_str())) 
    {

        for (pugi::xml_node node = doc.first_child(); node; node = node.next_sibling()) {
            ch.childElement = node.name();
        }
        pugi::xml_node root = doc.child("students");
        ch.childCount = std::distance(root.begin(), root.end()); 
        for (pugi::xml_node student = root.child("student"); student; student = student.next_sibling("student"))
        {
            students.push_back(st_student{ 
                student.child("name").text().as_string(),
                student.child("surname").text().as_string(), 
                student.child("number").text().as_int() 
                });
        }
        ft_printParam(index, mode);
    

    }
    else
    {
        std::cout << "Failed to load XML file." << std::endl;
    }

    return 0;
}

void ft_dataInput()
{
    std::cout << "Veri Stream Mod{ All : 1 | Spesific : 0} : ";
    std::cin >> mode;
    if (mode == 0)
    {
        std::cout << "Ozel Stream Mod : ";
        std::cin >> index;
    }

}

void ft_printParam(size_t index,size_t mode)
{

    switch (mode)
    {
    case 1:
        for (st_student student : students)
        {
            std::cout << "Name: " << student.name << std::endl;
            std::cout << "Surname: " << student.surname << std::endl;
            std::cout << "Number: " << student.number << std::endl;
            std::cout << "------------------------" << std::endl;
        }
        std::cout << "Child Number :" << ch.childCount << std::endl;
        std::cout << "Title :" << ch.childElement << std::endl;
        break;
    case 0:
        if (!students.empty())
        {
            st_student firstStudent = students[index];

            std::cout << "Name: " << firstStudent.name << std::endl;
            std::cout << "Surname: " << firstStudent.surname << std::endl;
            std::cout << "Number: " << firstStudent.number << std::endl;
            std::cout << "------------------------" << std::endl;
        }
        else
        {
            std::cout << "Error." << std::endl;
        }
        break;
    default:
        break;
    }
    /*döngüde tüm veri*/
  
    /*spesifik çekim*/

 

}