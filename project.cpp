#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
class questions
{
private:
    string question;
    string answer;
    string option[4];
    string level;

public:
    questions()
    {
        question = "";
        answer = "";
        for (int i = 0; i < 4; i++)
        {
            option[i] = "";
        }
        level = "";
    }
    questions(const string a, const string b, string c[], string d)
    {
        question = a;
        answer = b;
        for (int i = 0; i < 4; i++)
        {
            option[i] = c[i];
        }
        level = d;
    }
    void display()
    {
        cout << "Q: " << question << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << "- " << option[i];
            cout << endl;
        }
        cout << "Level : " << level << endl;
    }
    int check_answer(int a)
    {
        if (a < 1 || a > 4)
        {
            return -1;
        }
        else if (option[a - 1] == answer)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    string get_answer()
    {
        return answer;
    }
};
class player // another class
{
private:
    string name;
    int score = 0;

public:
    player()
    {
        name = "";
    }
    player(string a)
    {
        name = a;
    }
    void update_score()
    {
        score++;
    }
    void set_name(string a)
    {
        name = a;
    }
    void set_score(int a)
    {
        score = a;
    }
    int get_score()
    {
        return score;
    }
    string get_name()
    {
        return name;
    }
};

class quiz
{
private:
    player p;       // here using composition not inheritance because of has-a relation
    questions q[5]; // creating the array of question bank
public:
    int total;
    quiz() // default constructor
    {
        p = player();
    }
    quiz(string playername, int difficulty)
    {
        p = player(playername);
        if (difficulty == 1)
        {
            total = 5;
            // hard coded questions

            string op1[4] = {"2 bytes", "4 bytes", "8 bytes", "depend on the compiler"};
            q[0] = questions("What is the output of sizeof(void*) on a 64-bit system?", "8 bytes", op1, "Hard");

            string op2[4] = {"Function overloading", "Operator overloading", "Virtual functions", "Templates"};
            q[1] = questions("Which C++ feature allows a function to behave differently based on the calling object at runtime?", "Virtual functions", op2, "Hard");

            string op3[4] = {"Memory allocation", "Speed", "Access Specifier", "Inheritance not allowed in struct"};
            q[2] = questions("What is the main difference between struct and class in C++?", "Access Specifier", op3, "Hard");

            string op4[4] = {"Memory leak", "Diamond problem", "Slow execution", "Compilation error"};
            q[3] = questions("Why is multiple inheritance considered risky in C++?", "Diamond problem", op4, "Hard");

            string op5[4] = {"Copy primitive variables", "Prevent object creation", "Initialize an object using another object", "Destroy temporary objects"};
            q[4] = questions("What is the main purpose of a copy constructor?", "Initialize an object using another object", op5, "Hard");
        }
        else if (difficulty == 2)
        {
            total = 5;
            // medium coded questions
            string op1[4] = {"1990", "1980", "2000", "1970"};
            q[0] = questions("When C++ was created", "1980", op1, "Medium");

            string op2[4] = {"Encapsulation", "Compilation", "Linking", "Execution"};
            q[1] = questions("Which OOP concept binds data and functions together?", "Encapsulation", op2, "Medium");

            string op3[4] = {"class", "struct", "object", "function"};
            q[2] = questions("Which keyword is used to define a class in C++?", "class", op3, "Medium");

            string op4[4] = {"public", "private", "protected", "static"};
            q[3] = questions("Which access specifier allows members to be inherited but not accessed directly?", "protected", op4, "Medium");

            string op5[4] = {"malloc", "calloc", "new", "alloc"};
            q[4] = questions("Which operator is used for dynamic memory allocation in C++?", "new", op5, "Medium");
        }

        else if (difficulty == 3)
        {
            total = 5;
            // easy coded question
            string op1[4] = {"Programming Language", "Operating System", "Compiler", "Browser"};
            q[0] = questions("What is C++?", "Programming Language", op1, "Easy");

            string op2[4] = {"OOP", "Functional", "Procedural", "Logic"};
            q[1] = questions("C++ is primarily which programming paradigm?", "OOP", op2, "Easy");

            string op3[4] = {"cout", "cin", "printf", "scanf"};
            q[2] = questions("Which is used to print in C++?", "cout", op3, "Easy");

            string op4[4] = {"int", "str", "char", "float"};
            q[3] = questions("Which data type stores numbers with decimals?", "float", op4, "Easy");

            string op5[4] = {"#include", "using", "main()", "return"};
            q[4] = questions("Which function is the entry point of a C++ program?", "main()", op5, "Easy");
        }
        else
        {
            cout << "Select the above option from (1-3)..." << endl;
        }
    }
    void set_name(string a)
    {
        p.set_name(a);
    }
    string get_name()
    {
        return p.get_name();
    }
    int get_score() // get the score from player class
    {
        return p.get_score();
    }
    void set_score(int a) // use to set the score of player class
    {
        p.set_score(a);
    }
    void start()
    {
        int choice;
        for (int i = 0; i < total; i++)
        {
            q[i].display();
            cout << "Select the option : ";
            cin >> choice;

            int result = q[i].check_answer(choice);

            if (result == 1)
            {
                cout << "Correct" << endl;
                p.update_score();
            }
            else if (result == 0)
            {
                cout << "Not Correct!" << endl;
                cout << "Correct answer is : " << q[i].get_answer() << endl;
            }
            else
            {
                cout << "Please select the option from 1-5" << endl;
            }
        }
        cout << p.get_name() << " your total score is " << p.get_score() << "/" << total << endl;
        if (p.get_score() >= 0 && p.get_score() <= 3)
        {
            cout << "Average..." << endl;
        }
        else if (p.get_score() == 4)
        {
            cout << "Good..." << endl;
        }
        else
        {
            cout << "Excellent..." << endl;
        }
    }
};
void menu() // normal function for showing menu
{
    cout << "----------------------------------------QUIZ GAME----------------------------------------" << endl;
    cout << "1- Start Game" << endl;
    cout << "2- Update Name" << endl;
    cout << "3- Check Score" << endl;
    cout << "4- Reset Score" << endl;
    cout << "5- Exit" << endl;
}
void difficulty() // function for showing the difficulty level
{
    cout << "1- Hard" << endl;
    cout << "2- Medium" << endl;
    cout << "3- Easy" << endl;
}

// making the function for checking whether the user is entering the string or not
int check(const string &a)
{
    if (a.empty())
    {
        return 0; // user enter nothing
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (!isalpha(a[i]) && a[i] != ' ')
        {
            return 0; // user enter string
        }
    }

    return 1; // only condition that user enter string
}
int main()
{
    quiz qu;
    int choice;
    int option;
    string name;
    do
    {
        menu();
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int res;
            do
            {
                cout << "Enter your name : ";
                cin.ignore();
                getline(cin, name);
                res = check(name);

                if (res == 0)
                {
                    cout << "Please Enter the Alphabetic Name..." << endl;
                }
            } while (res != 1);
            cout << "Difficulty Option" << endl;
            difficulty();
            cout << "Select the difficulty level : ";
            cin >> option;
            qu = quiz(name, option);
            qu.start();
            break;
        }
        case 2:
        {
            int res;
            string temp;
            do
            {
                cout << "Enter your old Name :" << endl;
                cin.ignore();
                getline(cin, temp);
                res = check(temp);
                if (res == 0)
                {
                    cout << "Please enter the Alphabetic Name..." << endl;
                }
            } while (res != 1);
            if (temp == qu.get_name())
            {
                do
                {
                    cout << "Enter new name : ";
                    getline(cin, temp);
                    qu.set_name(temp);
                    res = check(temp);
                    if (res == 0)
                    {
                        cout << "Please enter the Alphabetic Name..." << endl;
                    }
                } while (res != 1);
                cout << "Name has been Updated" << endl;
            }
            else
            {
                cout << "Name not found" << endl;
                return 0;
            }
            break;
        }
        case 3:
        {
            cout << "" << qu.get_name() << ", Your Current Score is " << qu.get_score() << endl;
            break;
        }
        case 4:
        {
            qu.set_score(0);
            break;
        }
        case 5:
        {
            cout << "---------------------------------Exiting game-----------------------------" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Option" << endl;
        }
        }
    } while (choice != 5);

    return 0;
}