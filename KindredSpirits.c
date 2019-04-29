// Alexandra Harvey
// COP3502 - Spring 2019
// al608050


#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

int isReflection(node *a, node *b);

node *makeReflection(node *root);

int kindredSpirits(node *a, node *b);

//test case 08
node *create_node(int data)
{
    node *n = malloc(sizeof(node));

    n->data = data;
    n->left = n->right = NULL;

    return n;
}

// Free all the nodes in a binary tree.
node *forest_fire(node *root)
{
    if (root == NULL)
        return NULL;

    forest_fire(root->left);
    forest_fire(root->right);
    free(root);

    return NULL;
}

int main(void)
{
    node *root1, *root2;

    // Let's create a slightly more complex tree than in previous test cases.
    // This is the tree from Figure 4 in the assignment PDF. This approach is
    // super hacky and terrible, and you should never do something like this!
    root1 = create_node(2);
    root1->left = create_node(14);
    root1->right = create_node(14);
    root1->left->left = create_node(62);
    root1->left->right = create_node(62);
    root1->right->left = create_node(62);
    root1->right->right = create_node(62);
    root1->left->left->left = create_node(34);
    root1->left->left->right = create_node(34);
    root1->left->right->left = create_node(34);
    root1->left->right->right = create_node(34);
    root1->right->left->left = create_node(34);
    root1->right->left->right = create_node(34);
    root1->right->right->left = create_node(34);
    root1->right->right->right = create_node(34);

    // Reflect the tree.
    root2 = makeReflection(root1);

    // Ensure these are reflections.
    if (isReflection(root1, root2))
        printf("Success!\n");
    else
        printf("fail whale :(\n");

    // Clean up after yourself.
    forest_fire(root1);
    forest_fire(root2);

    return 0;
}

//creates a new tree which is a reflection of the tree rooted at root
//must create an entirely new tree without destroying or altering the OG tree
//returns pointer to the root of the new tree
node *makeReflection(node *root)
{
    if (root == NULL)
        return NULL;

    node *newNode = malloc(sizeof(node));
    newNode->data = root->data;
    //newNode->left = newNode->right = NULL;

    newNode->right = makeReflection(root->left);
    newNode->left = makeReflection(root->right);

    return newNode;
}

//determines whether the trees rooted at a and b are reflections
//must be implemented recursively
//returns 1 if they're reflections, 0 otherwise
int isReflection(node *a, node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    if (a->data == b->data)
    {
        isReflection(a->left, b->right);
        isReflection(a->right, b->left);
    }

    return 1;
}

//determines whether the trees rooted at a and b are kidnred spirits
//worst-case runtime must be O(n) and must handle large trees
//helper functions recommended - returns 1 if true, otherwise 0
int kindredSpirits(node *a, node *b)
{

}


double difficultyRating(void)
{
    return 3.0;
}

double hoursSpent(void)
{
    return 6.5;
}
