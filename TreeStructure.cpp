// UAS -> Struktur dasar tree

#include <iostream>
#include <string>
using namespace std;

struct cls_attribute;
struct tree;


struct v_type
{
    string type;    
    tree *parent;
    cls_attribute *left, *mid, *right;
};

struct cls_attribute
{
    string clss;
    int seat;
    int price;
    string time;
    string code;
    v_type *parent;
};


struct tree
{
    string label;
    tree *parent;
    v_type *left, *mid, *right;
};

tree *root;

void treeStruct ()
{
    // initialize root
    root = new tree;
    root->label = "Ticket Module";
    root->parent = NULL;
    root->left = new v_type; // Train
    root->mid = new v_type; // Plane
    root->right = new v_type; // Bus

    // initialize vtype
    root->left->type = "Train";
    root->left->parent = root;

    root->mid->type = "Plane";
    root->mid->parent = root;

    root->right->type = "Bus";
    root->right->parent = root;

    // initialize cls_attribute - train
    root->left->left = new cls_attribute; // regular
    root->left->left->clss = "Regular";
    root->left->left->seat = 100;
    root->left->left->price = 100000;
    root->left->left->time = "10:00";
    root->left->left->code = "TR100-10:00";
    root->left->left->parent = root->left;

    root->left->mid = new cls_attribute; // premium
    root->left->mid->clss = "Premium";
    root->left->mid->seat = 10;
    root->left->mid->price = 200000;
    root->left->mid->time = "11:00";
    root->left->mid->code = "TP10-11:00";
    root->left->mid->parent = root->left;

    root->left->right = new cls_attribute; // VIP
    root->left->right->clss = "VIP";
    root->left->right->seat = 1;
    root->left->right->price = 300000;
    root->left->right->time = "12:00";
    root->left->left->code = "TV1-12:00";
    root->left->left->parent = root->left;

    // initialize cls_attribute - plane
    root->mid->left = new cls_attribute; // Regular
    root->mid->left->clss = "Regular";
    root->mid->left->seat = 200;
    root->mid->left->price = 100000;
    root->mid->left->time = "10:00";
    root->mid->left->code = "PR200-10:00";
    root->mid->left->parent = root->mid;

    root->mid->mid = new cls_attribute; // Premium
    root->mid->mid->clss = "Premium";
    root->mid->mid->seat = 10;
    root->mid->mid->price = 200000;
    root->mid->mid->time = "11:00";
    root->mid->mid->code = "PP10-11:00";
    root->mid->mid->parent = root->mid;

    root->mid->right = new cls_attribute; // VIP
    root->mid->right->clss = "VIP";
    root->mid->right->seat = 1;
    root->mid->right->price = 300000;
    root->mid->right->time = "12:00";
    root->mid->right->code = "PV1-12:00";
    root->mid->right->parent = root->mid;

    // initialize cls_attribute - bus
    root->right->left = new cls_attribute; // Regular
    root->right->left->clss = "Regular";
    root->right->left->seat = 100;
    root->right->left->price = 100000;
    root->right->left->time = "10:00";
    root->right->left->code = "BR100-10:00";
    root->right->left->parent = root->right;

    root->right->mid = new cls_attribute; // Premium
    root->right->mid->clss = "Premium";
    root->right->mid->seat = 10;
    root->right->mid->price = 200000;
    root->right->mid->time = "11:00";
    root->right->mid->code = "BP10-11:00";
    root->right->mid->parent = root->right;

    root->right->right = new cls_attribute; // VIP
    root->right->right->clss = "VIP";
    root->right->right->seat = 1;
    root->right->right->price = 300000;
    root->right->right->time = "12:00";
    root->right->right->code = "BV1-12:00";
    root->right->right->parent = root->right;

}


int main ()
{
    treeStruct();
    cout << root->label << endl;
    cout << root->left->type << endl;
    cout << root->mid->type << endl;
    cout << root->right->type << endl;
}