#include <iostream>
#include <string>

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

string cls_code;
string typ_code;

bool find(tree *root, string k_tipe, string k_kelas)
{
    v_type *temp = nullptr;

    // Transverse type
    if (root->left && root->left->type == k_tipe)
    {
        temp = root->left;
        typ_code = "T";
    }
    else if (root->middle && root->middle->type == k_tipe)
    {
        temp = root->middle;
        typ_code = "P";
    }
    else if (root->right && root->right->type == k_tipe)
    {
        temp = root->right;
        typ_code = "B";
    }

    if (!temp)
    {
        cout << "Type not found" << endl;
        return false;
    }

    // Transverse class
    if (temp->left && temp->left->clss == k_kelas)
    {
        cls_code = "R";
    }
    else if (temp->middle && temp->middle->clss == k_kelas)
    {
        cls_code = "P";
    }
    else if (temp->right && temp->right->clss == k_kelas)
    {
        cls_code = "V";
    }
    else
    {
        cout << "Class not found" << endl;
        return false;
    }

    return true;
}

void code_generator(int seat, string time)
{
    cout << "Ticket Code: " << typ_code << cls_code << seat << "-" << time << endl;
}

void user_input()
{
    string type;
    string cls;
    int seat;
    string time;

    cout << "Jenis Kendaraan : ";
    cin >> type;
    cout << "Kelas           : ";
    cin >> cls;
    cout << "Nomor Kursi     : ";
    cin >> seat;
    cout << "Waktu           : ";
    cin >> time;

    if (find(root, type, cls))
    {
        code_generator(seat, time);
    }
    else
    {
        cout << "Error Type / Class" << endl;
    }
}

int main()
{
    treeStruct();
    user_input();
    return 0;
}
