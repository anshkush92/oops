#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <conio.h>
using namespace std;

#define ll long long int

const ll p = 31;
const ll mod = 1e9 + 9;
int index = 1;
// decoration
// afterchoosing decoration
// mainmenu
// inside
// mainmenuadmin
// admin
// checkdetails
// generateidpass

const char separator = ' ';
template <typename T>
void print(T t, const int &width) // Copied from Stack Overflow for formatting in tabular
{
    cout << left << setw(width) << setfill(separator) << t;
}

string name, age, gender, address, phno, temp, purpose, entime, extime, male = "male", female = "female", permission;
string username, password;

// =======================================================================================================================================

class decoration
{
public:
    void decor()
    {
        cout << "\t\t\t\t\t\t*******************************************************************\n";
        cout << "\t\t\t\t\t\t*                                                                 *\n";
        cout << "\t\t\t\t\t\t*                 Entry/ Exit Management System                   *\n";
        cout << "\t\t\t\t\t\t*                                                                 *\n";
        cout << "\t\t\t\t\t\t*******************************************************************\n";
    }
};

// =======================================================================================================================================

class afterchoosing
{
public:
    void decor(string str)
    {
        cout << "\t\t\t\t\t\t*******************************************************************\n";
        cout << "\t\t\t\t\t\t                          " << str << "                            \n";
        cout << "\t\t\t\t\t\t*******************************************************************\n";
    }
};

// =======================================================================================================================================

class mainmenu
{
public:
    int choice;

    int menu()
    {
        cout << "\t\t\t\t\t\t\t\t\tSelect who are you ?\n";
        cout << "\t\t\t\t\t\t\t\t\t1. Admin\n";
        cout << "\t\t\t\t\t\t\t\t\t2. Inside IIITM\n";
        cout << "\t\t\t\t\t\t\t\t\t3. Outside IIITM\n";
        cin >> choice;

        return choice;
    }
};

// =======================================================================================================================================

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

        if(stoi(temp) >= 100)
        permission = "No";
        else
        permission = "Yes";
    }

    void file_entry()
    {
        // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("record.csv", ios::out | ios::app);

        fout <<index << "," << name << "," << age << "," << gender << "," << address << "," << phno << "," << temp << "," << purpose << "," << entime << "," << extime <<","<<permission<<"\n";
        index++;
    }

    void file_delete()
    {
        // Open FIle pointers
        fstream fin, fout;

        // Open the existing file
        fin.open("record.csv", ios::in);

        // Create a new file to store the non-deleted data
        fout.open("recordnew.csv", ios::out);

        int marks, count = 0, i;
        string dname, name1;
        char sub;
        int index, new_marks;

        string line, word;
        vector<string> row;

        cout << "Enter the index of the record to be deleted: ";
        cin >> dname;

        // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        while (!fin.eof())
        {
            row.clear();
            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int row_size = row.size();
            name1 = row[0];

            // writing all records,
            // except the record to be deleted,
            // into the new file 'recordnew.csv'
            // using fout pointer
            if (name1 != dname)
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {
                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                count = 1;
            }
            if (fin.eof())
                break;
        }
        if (count == 1)
            cout << "Record deleted\n";
        else
            cout << "Record not found\n";

        // Close the pointers
        fin.close();
        fout.close();

        // removing the existing file
        remove("record.csv");

        // renaming the new file with the existing file name
        rename("recordnew.csv", "record.csv");
    }

    void file_display()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("record.csv", ios::in);

        print("Name", 15);
        print("Age", 15);    
        print("Gender", 15);
        print("Address", 15);
        print("Phone Number", 15);
        print("Temperature", 15);
        print("Purpose", 15);
        print("Check In", 15);
        print("Check Out", 15);
        print("Permission", 15);

        string temp1;
        string oname;
        string oage;
        string ogender;
        string oaddress;
        string ophno;
        string otemp;
        string opurp;
        string oentm;
        string oextm;
        string end;
        string opermission;

        

        while (getline(fin, temp1, ','))
        {
            getline(fin, oname, ',');
            getline(fin, oage, ',');
            getline(fin, ogender, ',');
            getline(fin, oaddress, ',');
            getline(fin, ophno, ',');
            getline(fin, otemp, ',');
            getline(fin, opurp, ',');
            getline(fin, oentm, ',');
            getline(fin, oextm, ',');
            getline(fin, opermission, '\n');

            cout<<"\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------\n";

            print(oname, 15);
            print(oage, 15);
            print(ogender, 15);
            print(oaddress, 15);
            print(ophno, 15);
            print(otemp, 15);
            print(opurp, 15);
            print(oentm, 15);
            print(oextm, 15);
            print(opermission, 15);
            
        }

        cout<<"\n";
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------\n";
        fin.close();
    }

    void file_modify()
    {
        // File pointer
        fstream fin, fout;

        // Open an existing record
        fin.open("record.csv", ios::in);

        // Create a new file to store updated data
        fout.open("recordnew.csv", ios::out);

        string mname, mname1;
        int count = 0, i;
        int sub;
        int index;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the index of the record to be updated: ";
        cin >> mname;

        // Get the data to be updated
        cout << "Enter the field number to be updated [name(1),age(2),gender(3),address(4),phone_no(5),temperature(6),purpose(7),entry_time(8),exit_time(9)]: ";
        cin >> sub;

        index = sub;

        if (sub >= 1 && sub <= 9)
        {
        }
        else
        {
            cout << "Wrong choice.Enter again\n";
            file_modify();
        }

        string mentry;

        cout << "Enter the updated entry: ";
        cin >> mentry;

        // Traverse the file
        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            mname1 = row[0];
            int row_size = row.size();

            if (mname1.compare(mname) == 0)
            {
                count = 1;
                stringstream convert;

                convert << mentry;

                row[index] = mentry;

                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        fout << row[i] << ", ";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }
        if (count == 0)
            cout << "Record not found\n";
        else
            cout << "Record updated";

        fin.close();
        fout.close();

        // removing the existing file
        remove("record.csv");

        // renaming the updated file with the existing file name
        rename("recordnew.csv", "record.csv");
    }
};

// =======================================================================================================================================


class outside // person who are not member of IIITM
{
public:
    // Username is made using first name and the first 2 letters of the numbers
    // Password made using name + age + phno first 2 digits

    outside()
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

        if(stoi(temp) >= 100)
        permission = "No";
        else
        permission = "Yes";
    }

    void file_entry()
    {
        // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("record.csv", ios::out | ios::app);
        

        fout <<index << "," << name << "," << age << "," << gender << "," << address << "," << phno << "," << temp << "," << purpose << "," << entime << "," << extime << "," <<permission<<"\n";
        index++;
    }

    void file_delete()
    {
        // Open FIle pointers
        fstream fin, fout;

        // Open the existing file
        fin.open("record.csv", ios::in);

        // Create a new file to store the non-deleted data
        fout.open("recordnew.csv", ios::out);

        int marks, count = 0, i;
        string dname, name1;
        char sub;
        int index, new_marks;

        string line, word;
        vector<string> row;

        cout << "Enter the index of the record to be deleted: ";
        cin >> dname;

        // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        while (!fin.eof())
        {
            row.clear();
            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int row_size = row.size();
            name1 = row[0];

            // writing all records,
            // except the record to be deleted,
            // into the new file 'recordnew.csv'
            // using fout pointer
            if (name1 != dname)
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {
                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                count = 1;
            }
            if (fin.eof())
                break;
        }
        if (count == 1)
            cout << "Record deleted\n";
        else
            cout << "Record not found\n";

        // Close the pointers
        fin.close();
        fout.close();

        // removing the existing file
        remove("record.csv");

        // renaming the new file with the existing file name
        rename("recordnew.csv", "record.csv");
    }

    void file_display()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("record.csv", ios::in);

        print("Name", 15);
        print("Age", 15);    
        print("Gender", 15);
        print("Address", 15);
        print("Phone Number", 15);
        print("Temperature", 15);
        print("Purpose", 15);
        print("Check In", 15);
        print("Check Out", 15);
        print("Permission", 15);

        string temp1;
        string oname;
        string oage;
        string ogender;
        string oaddress;
        string ophno;
        string otemp;
        string opurp;
        string oentm;
        string oextm;
        string end;
        string opermission;

        

        while (getline(fin, temp1, ','))
        {
            getline(fin, oname, ',');
            getline(fin, oage, ',');
            getline(fin, ogender, ',');
            getline(fin, oaddress, ',');
            getline(fin, ophno, ',');
            getline(fin, otemp, ',');
            getline(fin, opurp, ',');
            getline(fin, oentm, ',');
            getline(fin, oextm, ',');
            getline(fin, opermission, '\n');

            cout<<"\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------\n";

            print(oname, 15);
            print(oage, 15);
            print(ogender, 15);
            print(oaddress, 15);
            print(ophno, 15);
            print(otemp, 15);
            print(opurp, 15);
            print(oentm, 15);
            print(oextm, 15);
            print(opermission, 15);
            
        }

        cout<<"\n";
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------\n";
        fin.close();
    }

    void file_modify()
    {
        // File pointer
        fstream fin, fout;

        // Open an existing record
        fin.open("record.csv", ios::in);

        // Create a new file to store updated data
        fout.open("recordnew.csv", ios::out);

        string mname, mname1;
        int count = 0, i;
        int sub;
        int index;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the index of the record to be updated: ";
        cin >> mname;

        // Get the data to be updated
        cout << "Enter the field number to be updated [name(1),age(2),gender(3),address(4),phone_no(5),temperature(6),purpose(7),entry_time(8),exit_time(9)]: ";
        cin >> sub;

        index = sub;

        if (sub >= 1 && sub <= 9)
        {
        }
        else
        {
            cout << "Wrong choice.Enter again\n";
            file_modify();
        }

        string mentry;

        cout << "Enter the updated entry: ";
        cin >> mentry;

        // Traverse the file
        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            mname1 = row[0];
            int row_size = row.size();

            if (mname1.compare(mname) == 0)
            {
                count = 1;
                stringstream convert;

                convert << mentry;

                row[index] = mentry;

                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        fout << row[i] << ", ";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }
        if (count == 0)
            cout << "Record not found\n";
        else
            cout << "Record updated";

        fin.close();
        fout.close();

        // removing the existing file
        remove("record.csv");

        // renaming the updated file with the existing file name
        rename("recordnew.csv", "record.csv");
    }
};

// =======================================================================================================================================


class displaydetails
{
public:
    void display() // For outputing the details of the person
    {
        print("Name", 15);
        print("Age", 15);    
        print("Gender", 15);
        print("Address", 15);
        print("Phone Number", 15);
        print("Temperature", 15);
        print("Purpose", 15);
        print("Check In", 15);
        print("Check Out", 15);
        print("Permission", 15);

        cout<<"\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------\n";

        print(name, 15);
        print(age, 15);    
        print(gender, 15);
        print(address, 15);
        print(phno, 15);
        print(temp, 15);
        print(purpose, 15);
        print(entime, 15);
        print(extime, 15);
        print(permission, 15);

        cout<<"\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------\n";

    }
};

// =======================================================================================================================================

class mainmenuadmin
{
public:
    int choice;

    int menu()
    {
        cout << "\t\t\t\t\t\t\t\t\tSelect who are you ?\n";
        cout << "\t\t\t\t\t\t\t\t\t1. Inside IIITM\n";
        cout << "\t\t\t\t\t\t\t\t\t2. Outside IIITM\n";

        cin >> choice;
        return choice;
    }
};

// =======================================================================================================================================

class admin // admin who can change the details of the person
{
public:
    string adminid = "admin", adminpass = "admin", passadmin, idadmin, ans;
    afterchoosing obj;

    bool adminchecker() // function to check whether he is admin or not
    {
    start:
        cout << "ID: ";
        getline(cin, idadmin);
        cout << "PASSWORD: ";
        getline(cin, passadmin);

        if (adminid != idadmin || passadmin != adminpass)
        {
            cout << "Wrong ID or PASSWORD\n";
            cout << "Want to try again(Yes/No) ?\n";
            cin >> ans;

            if (ans == "Yes")
            {
                cin.ignore();
                goto start;
            }

            else
            {
                obj.decor("Access Denied");
                return false;
            }
        }

        else
        {
            obj.decor("Access Granted");
            return true;
        }
    }

    void adminfunctionsdis()
    {
        int choice, ch;
        mainmenuadmin obj;
        inside inside1;
        outside outside1;
        displaydetails details1; // mainmenu class object declaration
        system("cls");

        while (true)
        {
            afterchoosing choicech;
            choicech.decor("Admin Functions");
            cout << "\t\t\t\t\t\t1. Add a new Entry\n";
            cout << "\t\t\t\t\t\t2. Delete a Entry\n";
            cout << "\t\t\t\t\t\t3. Modify a Entry\n";
            cout << "\t\t\t\t\t\t4. Display All Entries\n";
            cout << "\t\t\t\t\t\t5. Exit Admin\n";
            cout << "\t\t\t\t\t\t6. Exit program\n";

            cin >> ch;

            switch (ch)
            {
            case 1:
                choice = obj.menu();
                cin.ignore();

                if (choice == 1)
                {
                    cout << "Chosen Inside IIITM\n";

                    inside1.entry();
                    inside1.file_entry();
                    details1.display();
                }

                else if (choice == 2)
                {
                    cout << "Chosen Outside IIITM\n";

                    outside1.entry();
                    outside1.file_entry();
                    details1.display();
                }
                else
                    cout << "Invalid Choice\n";

                break;

            case 2:
                inside1.file_delete();
                break;

            case 3:
                inside1.file_modify();
                break;

            case 4:
                inside1.file_display();
                break;

            case 5:
                choicech.decor("Exiting Admin");
                return;

            case 6:
                choicech.decor("Exiting Program");
                exit(0);

            default:
                cout << "Wrong Entry, Please Enter Again !!\n";
            }

            // Sleep(5000);

            // system("cls");
        }
    }
};

// =======================================================================================================================================

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

// =======================================================================================================================================

int main()
{
    int choice;
    string yes = "Yes", no = "No", ans;

    // Object Declaration part with respective to the classes
    admin admin1;
    decoration dec;
    mainmenu menu1;
    inside inside1;
    outside outside1;
    checkdetails check1;
    displaydetails detail1;

    // Decoration + Mainmenu Part
    dec.decor();
start1:
    choice = menu1.menu();

    system("CLS"); // command to clear the screen

    if (choice == 1)
    {
        cin.ignore(); // IMP Don't remove refer void entry article for more info
        cout << "Chosen Admin\n";
        if (admin1.adminchecker())
            admin1.adminfunctionsdis();
    }

    else if (choice == 2)
    {
        cout << "Chosen Inside IIITM\n";
    start:
        cin.ignore(); // IMP Don't remove refer void entry article for more info

        inside1.entry();
        detail1.display();

        if (check1.check())
        {
            inside1.file_entry();
        }
            
        else
        {
            cout << "Want to modify previous entry (Yes/No) ?\n";
            cin >> ans;

            if (ans == "Yes")
                goto start;
            else
                cout << "Exiting\n";
        }

        cout << "Want to enter more entry (Yes/No) ?\n";
        cin >> ans;

        if (ans == "Yes")
            goto start;
        else
            cout << "Exiting\n";
    }

    else if (choice == 3)
    {
        cout << "Chosen Outside IIITM\n";
    start2:
        cin.ignore(); // IMP Don't remove refer void entry article for more info

        outside1.entry();
        detail1.display();

        if (check1.check())
        {
            outside1.file_entry();
        }
            
        else
        {
            cout << "Want to modify previous entry (Yes/No) ?\n";
            cin >> ans;

            if (ans == "Yes")
                goto start2;
            else
                cout << "Exiting\n";
        }

        cout << "Want to enter more entry (Yes/No) ?\n";
        cin >> ans;

        if (ans == "Yes")
            goto start2;
        else
            cout << "Exiting\n";
    }

    cout << "Want to Exit the program ?(Yes/ No)\n";
    cin >> ans;

    if (ans == "Yes")
    {
        afterchoosing exit1;
        exit1.decor("Exiting");
        exit(0);
    }

    goto start1;

    return 0;
}