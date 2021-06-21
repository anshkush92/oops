#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll p = 31;
const ll mod = 1e9 + 9;

string name, age, gender, address, phno, temp, purpose, entime, extime, male = "male", female = "female";
string username, password;

class decoration
{
    public:

    void decor()
    {
        cout<<"\t\t\t\t\t\t*******************************************************************\n";
        cout<<"\t\t\t\t\t\t*                                                                 *\n";
        cout<<"\t\t\t\t\t\t*                 Entry/ Exit Management System                   *\n";
        cout<<"\t\t\t\t\t\t*                                                                 *\n";
        cout<<"\t\t\t\t\t\t*******************************************************************\n";
    }
};

class afterchoosing
{
    public:

    void decor(string str)
    {
        cout<<"\t\t\t\t\t\t*******************************************************************\n";
        cout<<"\t\t\t\t\t\t*                          "<<str<<"                         *\n";
        cout<<"\t\t\t\t\t\t*******************************************************************\n";
    }
};

class mainmenu
{
    public:
    int choice;

    int menu()
    {
        cout<<"\t\t\t\t\t\t\t\t\tSelect who are you ?\n";
        cout<<"\t\t\t\t\t\t\t\t\t1. Admin\n";
        cout<<"\t\t\t\t\t\t\t\t\t2. Inside IIITM\n";
        cout<<"\t\t\t\t\t\t\t\t\t3. Outside IIITM\n";
        cin>>choice;

        return choice;
    }
};

class admin // admin who can change the details of the person
{
    public:
    string adminid = "admin", adminpass = "admin", passadmin, idadmin, ans;
    afterchoosing obj;

    void adminchecker() // function to check whether he is admin or not
    {
        start:
        cout<<"ID: ";
        getline(cin, idadmin);
        cout<<"PASSWORD: ";
        getline(cin, passadmin);

        if(adminid != idadmin || passadmin != adminpass)
        {
            cout<<"Wrong ID or PASSWORD\n";
            cout<<"Want to try again(Yes/No) ?\n";
            cin>>ans;

            if(ans == "Yes")
            {
                cin.ignore();
                goto start;
            }

            else
            obj.decor("Access Denied");
        }

        else
        {
            obj.decor("Access Granted");
        }
        
    }
};

class checkdetails
{
    public:
    bool check() // For checking if the details entereed are correct or not
    {
        int i;
        bool result = true;

        for (i = 0; i < name.size(); i++) // Checking wheter the name is correct or not
        {
            if (name[i] == ' ')
                continue;
            else if (!isalpha(name[i]))
            {
                result = false;
                cout << "Name cannot contain numbers or special characters\n";
                break;
            }
        }

        for (i = 0; i < age.size(); i++)
        {
            if (!isdigit(age[i]))
            {
                result = false;
                cout << "Age cannot contain alphabets or special characters\n";
                break;
            }
        }

        for (i = 0; i < gender.size(); i++)
        {
            if (gender.size() == 1)
            {
                if (gender != "M" || gender != "F")
                {
                    result = false;
                    cout << "Gender (M/F) input is wrong\n";
                    break;
                }
            }

            else if (gender.size() == 4)
            {
                if (gender[i] == male[i] || gender[i] == (male[i] - 32))
                    continue;
                else
                {
                    result = false;
                    cout << "Spelling of Male is wrong\n";
                    break;
                }
            }

            else if (gender.size() == 6)
            {
                if (gender[i] == female[i] || gender[i] == (female[i] - 32))
                    continue;
                else
                {
                    result = false;
                    cout << "Spelling of Female is Wrong\n";
                    break;
                }
            }

            else if ((ll)gender.size() != 4 || (ll)gender.size() != 6 || (ll)gender.size() != 1)
            {
                result = false;
                cout << "Gender (size) input is wrong\n";
                break;
            }
        }

        for (i = 0; i < phno.size(); i++)
        {
            if (phno.size() != 10 || phno[0] == '0')
            {
                result = false;
                cout << "Phone number is not of 10 digits\n";
                break;
            }

            else
            {
                if (!isdigit(phno[i]))
                {
                    result = false;
                    cout << "Phone number cannot contain alphabets or special characters\n";
                    break;
                }
            }
        }

        if (!result)
            cout << "Sorry !!! Some of entries are not correct, Fill again with the correct entry\n";

        return result;
    }
};

class generateidpass
{
    public:
    void generate() // For generating username and password for checking his details
    {
        ll p_pow = 1, i;
        p_pow = 1;
        for (i = 0; i < name.size(); i++)
        {
            if (name[i] == ' ')
            break;
        }

        username += name.substr(0, i) + phno.substr(0, 2);
        password += name.substr(0, i) + name.substr(i+1, name.size()) + age + phno.substr(0, 2);
        cout << "Username : " << username << " password : " << password << "\n";
    }
};

class displaydetails
{
    public:
    void display() // For outputing the details of the person
    {
        cout << "Name\t\tAge\t\tGender\t\tAddress\t\tPhone Number\t\tTemperature\t\tPurpose\t\tEntry Time\t\tExit Time\n";
        cout << name << "\t" << age << "\t\t" << gender << "\t\t" << address << "\t" << phno << "\t" << temp << "\t\t" << purpose << "\t" << entime << "\t" << extime << "\n";
    }
};

class inside // person who are member of IIITM
{
public:
    // Username is made using first name and the first 2 letters of the numbers
    // Password made using name + age + phno first 2 digits

    inside()
    {
        name = "";
        age = "";
        gender = "";
        address = "";
        phno = "";
        temp = "";
        purpose = "";
        entime = "";
        extime = "";
    }

    void entry() // For inputting the details of the person
    {
        // Learnt a lot about the cin and getline error
        // http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/ReadingLineOfText.pdf
        // https://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm

        cout << "Enter your name : ";
        getline(cin, name);

        cout << "Enter your age : ";
        getline(cin, age);

        cout << "Enter your Gender : ";
        getline(cin, gender);

        cout << "Enter your Address : ";
        getline(cin, address);

        cout << "Enter your phone number : ";
        getline(cin, phno);

        cout << "Enter your temperature in Fahrenheit : ";
        getline(cin, temp);

        cout << "Enter your purpose of activity : ";
        getline(cin, purpose);

        cout << "Enter check - in time : ";
        getline(cin, entime);

        cout << "Enter exit time : ";
        getline(cin, extime);
    }
};

int main()
{
    int choice;
    string yes = "Yes", no = "No", ans;

    // Object Declaration part with respective to the classes
    admin admin1;
    decoration dec;
    mainmenu menu1;
    inside inside1;
    checkdetails check1;
    displaydetails detail1;
    generateidpass generate1;
    

    // Decoration + Mainmenu Part
    dec.decor();
    choice = menu1.menu();

    system("CLS"); // command to clear the screen 

    if(choice == 1)
    {
        cin.ignore(); // IMP Don't remove refer void entry article for more info
        cout<<"Chosen Admin\n";
        admin1.adminchecker();
    }

    else if(choice == 2)
    {
        cin.ignore(); // IMP Don't remove refer void entry article for more info
        cout<<"Chosen Inside IIITM\n";
    }

    else if(choice == 3)
    {
        cin.ignore(); // IMP Don't remove refer void entry article for more info
        cout<<"Outside IIITM\n";
    }

start:

    inside1.entry();
    detail1.display();

    if (check1.check())
        generate1.generate();
    else
    {
        cout << "Want to enter new entry (Yes/No) ?\n";
        cin >> ans;

        if (ans == "Yes")
            goto start;
        else
            cout << "Exiting\n";
    }

    return 0;
}

/*
Ansh Singh
19
Male 
E-1778 
9794925108
98.6 F
Nothing
10:30 AM
10:30 PM */
