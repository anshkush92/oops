#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll p = 31;
const ll mod = 1e9 + 9;

class admin
{
public:
};

class inside
{
public:
    string name, age, gender, address, phno, temp, purpose, entime, extime, male = "male", female = "female";
    string username, password;

    // Username is made using first name and the first 2 letters of the numbers
    // password will be made using the concept of hashing in the string, for odd index (0 based) use character otherwise hashed value
    // https://cp-algorithms.com/string/string-hashing.html

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

    void display() // For outputing the details of the person
    {
        cout << "Name\t\tAge\t\tGender\t\tAddress\t\tPhone Number\t\tTemperature\t\tPurpose\t\tEntry Time\t\tExit Time\n";
        cout << name << "\t" << age << "\t\t" << gender << "\t\t" << address << "\t" << phno << "\t" << temp << "\t\t" << purpose << "\t" << entime << "\t" << extime << "\n";
    }

    bool check() // For checking if the details entereed are correct or not
    {
        int i;
        bool result = true;

        for(i=0; i<name.size(); i++) // Checking wheter the name is correct or not
        {
            if(name[i] == ' ')
            continue;
            else if(!isalpha(name[i]))
            {
                result = false;
                cout<<"Name cannot contain numbers or special characters\n";
                break;
            }
        }

        for(i=0; i<age.size(); i++)
        {
            if(!isdigit(age[i]))
            {
                result = false;
                cout<<"Age cannot contain alphabets or special characters\n";
                break;
            }
        }

        for(i=0; i<gender.size(); i++)
        {
            if(gender.size() == 1)
            {
                if(gender != "M" || gender != "F")
                {
                    result = false;
                    cout<<"Gender (M/F) input is wrong\n";
                    break;
                }
            }

            else if(gender.size() == 4)
            {
                if(gender[i] == male[i] || gender[i] == (male[i] - 32))
                continue;
                else
                {
                    result = false;
                    cout<<"Spelling of Male is wrong\n";
                    break;
                }
            }

            else if(gender.size() == 6)
            {
                if(gender[i] == female[i] || gender[i] == (female[i] - 32))
                continue;
                else
                {
                    result = false;
                    cout<<"Spelling of Female is Wrong\n";
                    break;
                }
            }

            else if((ll)gender.size() != 4 || (ll)gender.size() != 6 || (ll)gender.size() != 1)
            {
                result = false;
                cout<<"Gender (size) input is wrong\n";
                break;
            }
        }

        for(i=0; i<phno.size(); i++)
        {
            if(phno.size() != 10 || phno[0] == '0')
            {
                result = false;
                cout<<"Phone number is not of 10 digits\n";
                break;
            }

            else
            {
                if(!isdigit(phno[i]))
                {
                    result = false;
                    cout<<"Phone number cannot contain alphabets or special characters\n";
                    break;
                }
            }
        }

        if(!result)
        cout<<"Sorry !!! Some of entries are not correct, Fill again with the correct entry\n";

        return result;
    }

    void generate() // For generating username and password for checking his details
    {
        ll p_pow = 1, i;
        p_pow = 1;
        for (i = 0; i < name.size(); i++)
        {
            if (name[i] == ' ')
                break;

            else
            {
                if (i % 2)
                    password += to_string(((name[i] - 'a' + 1) * (p_pow)) % mod);
                else
                    password += (char (name[i]));

                (p_pow) = (p_pow * p) % mod;
            }
        }

        username += name.substr(0, i) + phno.substr(0, 2);
        cout << "Username : " << username << " password : " << password << "\n";
    }
};

// class outside
// {
// public:
//     string name, age, gender, address, phno, temp, purpose, entime, extime;
//     string username, password;

//     // Username is made using first name and the first 2 letters of the numbers
//     // password will be made using the concept of hashing in the string, for odd index (0 based) use character otherwise hashed value

//     outside()
//     {
//         name = "";
//         age = "";
//         gender = "";
//         address = "";
//         phno = "";
//         temp = "";
//         purpose = "";
//         entime = "";
//         extime = "";
//     }

   
//    void entry()
//     {
//         cout << "Enter your name : ";
//         getline(cin, name);

//         cout << "Enter your age : ";
//         getline(cin, age);
        
//         cout << "Enter your Gender : ";
//         getline(cin, gender);
        
//         cout << "Enter your Address : ";
//         getline(cin, address);
        
//         cout << "Enter your phone number : ";
//         getline(cin, phno);
        
//         cout << "Enter your temperature : ";
//         getline(cin, temp);
        
//         cout << "Enter your purpose of activity : ";
//         getline(cin, purpose);
        
//         cout << "Enter check - in time : ";
//         getline(cin, entime);
        
//         cout << "Enter exit time : ";
//         getline(cin, extime);
        
//     }



//     void display()
//     {
//         cout << "Name\t\tAge\t\tGender\t\tAddress\t\tPhone Number\t\tTemperature\t\tPurpose\t\tEntry Time\t\tExit Time\n";
//         cout << name << "\t" << age << "\t\t" << gender << "\t\t" << address << "\t" << phno << "\t" << temp << "\t\t" << purpose << "\t" << entime << "\t" << extime << "\n";
//     }

//     void generate()
//     {
//         ll p_pow = 1, i;
//         p_pow = 1;
//         for (i = 0; i < name.size(); i++)
//         {
//             if (name[i] == ' ')
//                 break;

//             else
//             {
//                 username += to_string(name[i]);

//                 if (i % 2)
//                     password += ((name[i] - 'a' + 1) * (p_pow)) % mod;
//                 else
//                     password += to_string(name[i]);

//                 (p_pow) = (p_pow * p) % mod;
//             }
//         }

//         username += phno.substr(0, 2);
//         cout << "Username : " << username << " password : " << password << "\n";
//     }
// };

int main()
{
    string yes = "Yes", no = "No", ans;
    inside obj1;

    start:

    obj1.entry();
    obj1.display();

    if(obj1.check())
    obj1.generate();
    else
    {
        cout<<"Want to enter new entry (Yes/No) ?\n";
        cin>>ans;

        if(ans == "Yes")
        goto start;
        else
        cout<<"Exiting\n";
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
