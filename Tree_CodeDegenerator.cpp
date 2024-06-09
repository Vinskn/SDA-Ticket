#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct cls_attribute;
struct tree;

struct v_type
{
    string type;
    tree *parent;
    cls_attribute *left = nullptr, *right = nullptr, *middle = nullptr;
};

struct cls_attribute
{
    string clss;
    int seat;
    int price;
    string time;
    string code;
    v_type *parent = nullptr;
};

struct tree
{
    string label;
    tree *parent = nullptr;
    v_type *left = nullptr, *middle = nullptr, *right = nullptr;
};

tree *root = nullptr;

void treeStruct()
{
    // initialize root
    root = new tree;
    root->label = "Ticket Module";
    root->parent = nullptr;
    root->left = new v_type; // Train
    root->middle = new v_type; // Plane
    root->right = new v_type; // Bus

    // init v_type
    root->left->type = "Train";
    root->left->parent = root;

    root->middle->type = "Plane";
    root->middle->parent = root;

    root->right->type = "Bus";
    root->right->parent = root;

    // init class -> train
    root->left->left = new cls_attribute;
    root->left->left->clss = "Regular";
    root->left->left->parent = root->left;

    root->left->middle = new cls_attribute;
    root->left->middle->clss = "Premium";
    root->left->middle->parent = root->left;

    root->left->right = new cls_attribute;
    root->left->right->clss = "VIP";
    root->left->right->parent = root->left;

    // init class -> plane
    root->middle->left = new cls_attribute;
    root->middle->left->clss = "Regular";
    root->middle->left->parent = root->middle;

    root->middle->middle = new cls_attribute;
    root->middle->middle->clss = "Premium";
    root->middle->middle->parent = root->middle;

    root->middle->right = new cls_attribute;
    root->middle->right->clss = "VIP";
    root->middle->right->parent = root->middle;

    // init class -> bus
    root->right->left = new cls_attribute;
    root->right->left->clss = "Regular";
    root->right->left->parent = root->right;

    root->right->middle = new cls_attribute;
    root->right->middle->clss = "Premium";
    root->right->middle->parent = root->right;

    root->right->right = new cls_attribute;
    root->right->right->clss = "VIP";
    root->right->right->parent = root->right;
}

void degenerator (string k_type, string k_cls, string k_jam, int k_seat)
{
    v_type *Ttemp = nullptr;
    cls_attribute *Ctemp = nullptr;
    

    // Type transverse
    if (k_type == "T") 
    {
        Ttemp = root->left;
    }
    else if (k_type == "P")
    {
        Ttemp = root->middle;
    }
    else if (k_type == "B")
    {
        Ttemp = root->right;
    }
    if (Ttemp == nullptr)
    {
        cout << "Error Type" << endl;
        return;
    }

    // Class transverse
    if (k_cls == "R")
    {
        Ctemp = Ttemp->left;
    }
    else if (k_cls == "P")
    {
        Ctemp = Ttemp->middle;
    }
    else if (k_cls == "V")
    {
        Ctemp = Ttemp->right;
    }
    if (Ctemp == nullptr)
    {
        cout << "Error Class" << endl;
        return;
    }

    //Dataex
    Ctemp->seat = k_seat;
    Ctemp->time = k_jam;

    // Data input
    cout << "\n\nCode Degenerator" << endl;
    cout << "Vehicle Type   : " << Ttemp->type <<endl;
    cout << "Class          : " << Ctemp->clss <<endl;
    cout << "Seat Number    : " << Ctemp->seat <<endl;
    cout << "Departure Time : " << Ctemp->time << endl;
}  

void parse (string code)
{
    stringstream ss (code);
    string type, cls, jam, temp;
    int seat;

    type = code.substr (0,1);
    cls = code.substr (1,1);
    
    getline(ss, temp, '-');
    seat = stoi(temp.substr (2));

    getline (ss, jam);

    degenerator(type, cls, jam, seat);
}

int main ()
{
    treeStruct();
    string Iparse;
    cout << "Input Code : "; cin >> Iparse;
    parse (Iparse);
    return 0;
}